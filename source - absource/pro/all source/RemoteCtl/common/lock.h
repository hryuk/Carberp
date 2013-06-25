#pragma once

class CLock
{
private:
	CRITICAL_SECTION m_Section;
public:
	CLock() { InitializeCriticalSection(&m_Section); }
	~CLock() { DeleteCriticalSection(&m_Section); }
	void Lock() { EnterCriticalSection(&m_Section); }
	void Unlock() { LeaveCriticalSection(&m_Section); }
};
