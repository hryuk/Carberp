#include <windows.h>
#include <tlhelp32.h>

#include "procenum.h"
#include "dprint.h"

void FilteredEnumProcesses(
  ProcessFilterFunction filter, 
  DWORD*  pids, 
  DWORD   pids_length, 
  DWORD*  ret_length
  )
{
  HANDLE hSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  PROCESSENTRY32 ppe={0};
  HANDLE result = NULL;
  DWORD count = 0;
  
  ZeroMemory(&ppe, sizeof(ppe));
  ppe.dwSize=sizeof(PROCESSENTRY32);
  
  Process32First(hSnap,&ppe);
  do
  {      
    if (filter(&ppe))
    {
      if (count < pids_length)
      {
        pids[count] = ppe.th32ProcessID;
        count++;
      }
    }
  }
  while (Process32Next(hSnap,&ppe));
  CloseHandle(hSnap);

  *ret_length = count;
}

bool IsCurrentProcessCorrespondToFilter(ProcessFilterFunction filter)
{
  DWORD pids[200];
  DWORD pid_count = 0;
  
  FilteredEnumProcesses(filter, pids, ARRAYSIZE(pids), &pid_count);

  DWORD current_pid = ::GetCurrentProcessId();
  for (size_t i = 0; i < pid_count; i++)
  {
    if (current_pid == pids[i]) return true;
  }
  return false; 
}
