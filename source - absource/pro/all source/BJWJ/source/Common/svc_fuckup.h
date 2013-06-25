#ifndef SVC_FUCKUP_H_INCLUDED
#define SVC_FUCKUP_H_INCLUDED

typedef void (*ServiceMainFunction)();

bool SvcFuckupRun();
void SvcFuckupRunAsService(ServiceMainFunction service_main);

#endif // SVC_FUCKUP_H_INCLUDED
