#ifndef UUID_67CC7598B46343D4B3E09E57633401CB
#define UUID_67CC7598B46343D4B3E09E57633401CB

struct ScopedDebugPrivilege
{
  ScopedDebugPrivilege();
  ~ScopedDebugPrivilege();

  bool Enabled();

private:
  bool m_enabled;
};

#endif