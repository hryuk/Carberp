#ifndef UUID_DB88CB7560AA46F0B1F0AD27BF690BE7
#define UUID_DB88CB7560AA46F0B1F0AD27BF690BE7

#ifndef DISALLOW_COPY_AND_ASSIGN

# define DISALLOW_COPY_AND_ASSIGN(TypeName)        \
          TypeName(const TypeName&);               \
          void operator=(const TypeName&)

#endif

class CriticalSection
{
public:

	class Lock
	{
	public:

		explicit Lock(CriticalSection &csObject): m_csObject(csObject)
		{
			m_csObject.Enter();
		}
		
		~Lock()
		{
			m_csObject.Leave();
		}

	private :
		CriticalSection &m_csObject;

		// No copies do not implement
    DISALLOW_COPY_AND_ASSIGN(Lock);
	};

  CriticalSection()
  {
    m_cs_pointer = NULL;
    if (::InitializeCriticalSectionAndSpinCount(&m_cs, 4000))
    {
      m_cs_pointer = &m_cs;
    }
  }

  bool Init()
  {
    return (m_cs_pointer != NULL);
  }

	~CriticalSection()
	{
    if (m_cs_pointer) ::DeleteCriticalSection(&m_cs);
	}

	void Enter()
	{
		::EnterCriticalSection(m_cs_pointer);
	}
	
	void Leave()
	{
		::LeaveCriticalSection(m_cs_pointer);
	}

private:
	CRITICAL_SECTION  m_cs;
  CRITICAL_SECTION* m_cs_pointer;

  DISALLOW_COPY_AND_ASSIGN(CriticalSection);
};

struct AtomicCounter
{
  LONG m_counter;
  AtomicCounter() : m_counter(0) {};

  size_t Increment()
  {
    return ::InterlockedIncrement(&m_counter);
  }

  size_t Decrement()
  {
    return ::InterlockedDecrement(&m_counter);
  }

  DISALLOW_COPY_AND_ASSIGN(AtomicCounter);
};

class MultiReaderSingleWriter
{
public:
	MultiReaderSingleWriter()
	{
		m_cReaders = 0;
		InitializeCriticalSection(&m_csWrite);
		InitializeCriticalSection(&m_csReaderCount);
		m_hevReadersCleared = CreateEvent(NULL,TRUE,TRUE,NULL);
	}

	~MultiReaderSingleWriter()
	{
		WaitForSingleObject(m_hevReadersCleared,INFINITE);
		CloseHandle(m_hevReadersCleared);
		DeleteCriticalSection(&m_csWrite);
		DeleteCriticalSection(&m_csReaderCount);
	}


	void EnterReader(void)
	{
		EnterCriticalSection(&m_csWrite);
		EnterCriticalSection(&m_csReaderCount);
		if (++m_cReaders == 1)
			ResetEvent(m_hevReadersCleared);
		LeaveCriticalSection(&m_csReaderCount);
		LeaveCriticalSection(&m_csWrite);
	}

	void LeaveReader(void)
	{
		EnterCriticalSection(&m_csReaderCount);
		if (--m_cReaders == 0)
			SetEvent(m_hevReadersCleared);
		LeaveCriticalSection(&m_csReaderCount);
	}

	void EnterWriter(void)
	{
		EnterCriticalSection(&m_csWrite);
		WaitForSingleObject(m_hevReadersCleared,INFINITE);
	}

	void LeaveWriter(void)
	{
		LeaveCriticalSection(&m_csWrite);
	}

private:
	CRITICAL_SECTION m_csWrite;
	CRITICAL_SECTION m_csReaderCount;
	long m_cReaders;
	HANDLE m_hevReadersCleared;

  DISALLOW_COPY_AND_ASSIGN(MultiReaderSingleWriter);
  
};

#endif // #ifndef UUID_DB88CB7560AA46F0B1F0AD27BF690BE7