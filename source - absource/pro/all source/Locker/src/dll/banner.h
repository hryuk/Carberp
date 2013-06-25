#ifndef IE_WORKS_H_INCLUDED
#define IE_WORKS_H_INCLUDED

#define DESK_NAME TEXT("BE6C1CA5E1344E6DA")

bool BannerStarted();
void BannerSwitchToIeDesktop();
void TryInitBannerShowing();

void WINAPI Export_StartBanner(void* /*dll_body*/);

#endif // IE_WORKS_H_INCLUDED
