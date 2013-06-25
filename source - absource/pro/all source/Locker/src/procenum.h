#ifndef UUID_23F6259644A849FDBCCC9F2B98C327C2
#define UUID_23F6259644A849FDBCCC9F2B98C327C2

#include <tlhelp32.h>

typedef bool (*ProcessFilterFunction)(const PROCESSENTRY32* ppe);

void FilteredEnumProcesses(
  ProcessFilterFunction filter, 
  DWORD*  pids, 
  DWORD   pids_length, 
  DWORD*  ret_length
  );

bool IsCurrentProcessCorrespondToFilter(ProcessFilterFunction filter);

#endif