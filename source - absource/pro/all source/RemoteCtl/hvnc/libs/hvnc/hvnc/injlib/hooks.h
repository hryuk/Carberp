#ifndef HOOKS_H_INCLUDED
#define HOOKS_H_INCLUDED

void DoVNCHooks();
void DoCommonHooks();

#define ADD_HOOK(STRUCT,API) STRUCT.API.lpHandler=(LPVOID)API##_handler;\
                             STRUCT.API.lpRealAddr=&p##API;

#endif // HOOKS_H_INCLUDED
