#include "stdafx.h"
#include "protocol.h"


PacketBuffer::PacketBuffer()
	: m_dwLen( 0 )
	, m_pBuffer( 0 )
	, m_dwAllocated( 0 )
{
}


PacketBuffer::~PacketBuffer()
{
	if( m_dwAllocated > 0 &&
		m_pBuffer )
	{
		free( m_pBuffer );
	}
}

void PacketBuffer::Reset()
{
	if( m_dwAllocated > 0 &&
		m_pBuffer )
	{
		free( m_pBuffer );
	}
	m_dwLen = 0;
	m_pBuffer = 0;
	m_dwAllocated = 0;
}

bool PacketBuffer::Receive( SOCKET s, bool *pActivity )
{
	if( pActivity )
	{
		*pActivity = false;
	}

	long to_receive = 0;
	if( ioctlsocket( s, FIONREAD, (unsigned long *) &to_receive ) == 0 )
	{
		if( to_receive > 0 )
		{
			if( m_pBuffer == 0 )
			{
				m_dwLen = 0;
				m_dwAllocated = to_receive;
				m_pBuffer = (BYTE*)malloc( m_dwAllocated );
			}
			else
			{
				if( (m_dwLen + to_receive) > m_dwAllocated )
				{
					m_dwAllocated = m_dwLen + to_receive;
					m_pBuffer = (BYTE*)realloc( m_pBuffer, m_dwAllocated );
				}
			}

			if( recv(s,(char*)(m_pBuffer+m_dwLen),to_receive,0) == to_receive )
			{
				if( pActivity )
				{
					*pActivity = true;
				}
				m_dwLen += to_receive;
				return true;
			}
		}
		return true;
	}
	return false;
}

bool PacketBuffer::Send( SOCKET s )
{
	if( IsPacketCompleted() )
	{
		// TODO: break into smaller pieces
		if( send( s, (char*)m_pBuffer, m_dwLen, 0 ) == m_dwLen )
		{
			return true;
		}
	}
	return false;
}

void PacketBuffer::Create( int type, DWORD ts, DWORD size, void *data )
{
	if( m_pBuffer )
	{
		m_dwLen = m_dwAllocated = 0;
		free( m_pBuffer );
	}

	m_dwLen = m_dwAllocated = size + sizeof(Packet);
	m_pBuffer = (BYTE*)malloc( m_dwAllocated );

	PPacket p = (PPacket)m_pBuffer;

	p->type = type;
	p->size = size;
	p->timestamp = ts;

	if( size > 0 && data )
	{
		CopyMemory( p->data, data, size );
	}
}


bool PacketBuffer::IsPacketCompleted()
{
	if( m_dwLen >= sizeof(Packet) )
	{
		PPacket p = (PPacket)m_pBuffer;
		if( sizeof(Packet) + p->size <= m_dwLen )
		{
			return true;
		}
	}
	return false;
}


PPacket PacketBuffer::GetFirst()
{
	PPacket p = 0;
	if( IsPacketCompleted() )
	{
		p = (PPacket)m_pBuffer;
	}
	return p;
}


void PacketBuffer::DiscardFirst()
{
	PPacket p = GetFirst();
	if( p )
	{
		if( m_dwLen == sizeof(Packet) + p->size )
		{
			m_dwLen = 0;
		}
		else
		{
			// move memory
			DWORD iStart = sizeof(Packet) + p->size;
			DWORD iToMove = m_dwLen - iStart;
			for( DWORD i=0; i<iToMove; i++ )
			{
				m_pBuffer[i] = m_pBuffer[i+iStart];
			}
			m_dwLen -= iStart;

			/*
			MoveMemory( m_pBuffer, m_pBuffer + sizeof(Packet) + p->size, dwMove );
			*/
		}
	}
}

DWORD PacketBuffer::GetExpectedBytes()
{
	if( m_dwLen >= sizeof(Packet) )
	{
		PPacket p = (PPacket)m_pBuffer;
		return (sizeof(Packet) + p->size);
	}
	return 0;
}

DWORD PacketBuffer::GetReceivedBytes()
{
	return m_dwLen;
}
