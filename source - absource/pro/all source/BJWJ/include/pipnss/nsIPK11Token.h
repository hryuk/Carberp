/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIPK11Token.idl
 */

#ifndef __gen_nsIPK11Token_h__
#define __gen_nsIPK11Token_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPK11Token */
#define NS_IPK11TOKEN_IID_STR "51191434-1dd2-11b2-a17c-e49c4e99a4e3"

#define NS_IPK11TOKEN_IID \
  {0x51191434, 0x1dd2, 0x11b2, \
    { 0xa1, 0x7c, 0xe4, 0x9c, 0x4e, 0x99, 0xa4, 0xe3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPK11Token : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPK11TOKEN_IID)

  enum { ASK_EVERY_TIME = -1 };

  enum { ASK_FIRST_TIME = 0 };

  enum { ASK_EXPIRE_TIME = 1 };

  /* readonly attribute wstring tokenName; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName) = 0;

  /* readonly attribute wstring tokenLabel; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenLabel(PRUnichar * *aTokenLabel) = 0;

  /* readonly attribute wstring tokenManID; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenManID(PRUnichar * *aTokenManID) = 0;

  /* readonly attribute wstring tokenHWVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenHWVersion(PRUnichar * *aTokenHWVersion) = 0;

  /* readonly attribute wstring tokenFWVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenFWVersion(PRUnichar * *aTokenFWVersion) = 0;

  /* readonly attribute wstring tokenSerialNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetTokenSerialNumber(PRUnichar * *aTokenSerialNumber) = 0;

  /* boolean isLoggedIn (); */
  NS_SCRIPTABLE NS_IMETHOD IsLoggedIn(PRBool *_retval NS_OUTPARAM) = 0;

  /* void login (in boolean force); */
  NS_SCRIPTABLE NS_IMETHOD Login(PRBool force) = 0;

  /* void logoutSimple (); */
  NS_SCRIPTABLE NS_IMETHOD LogoutSimple(void) = 0;

  /* void logoutAndDropAuthenticatedResources (); */
  NS_SCRIPTABLE NS_IMETHOD LogoutAndDropAuthenticatedResources(void) = 0;

  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

  /* readonly attribute long minimumPasswordLength; */
  NS_SCRIPTABLE NS_IMETHOD GetMinimumPasswordLength(PRInt32 *aMinimumPasswordLength) = 0;

  /* readonly attribute boolean needsUserInit; */
  NS_SCRIPTABLE NS_IMETHOD GetNeedsUserInit(PRBool *aNeedsUserInit) = 0;

  /* boolean checkPassword (in wstring password); */
  NS_SCRIPTABLE NS_IMETHOD CheckPassword(const PRUnichar *password, PRBool *_retval NS_OUTPARAM) = 0;

  /* void initPassword (in wstring initialPassword); */
  NS_SCRIPTABLE NS_IMETHOD InitPassword(const PRUnichar *initialPassword) = 0;

  /* void changePassword (in wstring oldPassword, in wstring newPassword); */
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(const PRUnichar *oldPassword, const PRUnichar *newPassword) = 0;

  /* long getAskPasswordTimes (); */
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimes(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long getAskPasswordTimeout (); */
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimeout(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void setAskPasswordDefaults ([const] in long askTimes, [const] in long timeout); */
  NS_SCRIPTABLE NS_IMETHOD SetAskPasswordDefaults(const PRInt32 askTimes, const PRInt32 timeout) = 0;

  /* boolean isHardwareToken (); */
  NS_SCRIPTABLE NS_IMETHOD IsHardwareToken(PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean needsLogin (); */
  NS_SCRIPTABLE NS_IMETHOD NeedsLogin(PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean isFriendly (); */
  NS_SCRIPTABLE NS_IMETHOD IsFriendly(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPK11Token, NS_IPK11TOKEN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPK11TOKEN \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName); \
  NS_SCRIPTABLE NS_IMETHOD GetTokenLabel(PRUnichar * *aTokenLabel); \
  NS_SCRIPTABLE NS_IMETHOD GetTokenManID(PRUnichar * *aTokenManID); \
  NS_SCRIPTABLE NS_IMETHOD GetTokenHWVersion(PRUnichar * *aTokenHWVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetTokenFWVersion(PRUnichar * *aTokenFWVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetTokenSerialNumber(PRUnichar * *aTokenSerialNumber); \
  NS_SCRIPTABLE NS_IMETHOD IsLoggedIn(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Login(PRBool force); \
  NS_SCRIPTABLE NS_IMETHOD LogoutSimple(void); \
  NS_SCRIPTABLE NS_IMETHOD LogoutAndDropAuthenticatedResources(void); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumPasswordLength(PRInt32 *aMinimumPasswordLength); \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsUserInit(PRBool *aNeedsUserInit); \
  NS_SCRIPTABLE NS_IMETHOD CheckPassword(const PRUnichar *password, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InitPassword(const PRUnichar *initialPassword); \
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(const PRUnichar *oldPassword, const PRUnichar *newPassword); \
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimes(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimeout(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetAskPasswordDefaults(const PRInt32 askTimes, const PRInt32 timeout); \
  NS_SCRIPTABLE NS_IMETHOD IsHardwareToken(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NeedsLogin(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsFriendly(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPK11TOKEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName) { return _to GetTokenName(aTokenName); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenLabel(PRUnichar * *aTokenLabel) { return _to GetTokenLabel(aTokenLabel); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenManID(PRUnichar * *aTokenManID) { return _to GetTokenManID(aTokenManID); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenHWVersion(PRUnichar * *aTokenHWVersion) { return _to GetTokenHWVersion(aTokenHWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenFWVersion(PRUnichar * *aTokenFWVersion) { return _to GetTokenFWVersion(aTokenFWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenSerialNumber(PRUnichar * *aTokenSerialNumber) { return _to GetTokenSerialNumber(aTokenSerialNumber); } \
  NS_SCRIPTABLE NS_IMETHOD IsLoggedIn(PRBool *_retval NS_OUTPARAM) { return _to IsLoggedIn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Login(PRBool force) { return _to Login(force); } \
  NS_SCRIPTABLE NS_IMETHOD LogoutSimple(void) { return _to LogoutSimple(); } \
  NS_SCRIPTABLE NS_IMETHOD LogoutAndDropAuthenticatedResources(void) { return _to LogoutAndDropAuthenticatedResources(); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumPasswordLength(PRInt32 *aMinimumPasswordLength) { return _to GetMinimumPasswordLength(aMinimumPasswordLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsUserInit(PRBool *aNeedsUserInit) { return _to GetNeedsUserInit(aNeedsUserInit); } \
  NS_SCRIPTABLE NS_IMETHOD CheckPassword(const PRUnichar *password, PRBool *_retval NS_OUTPARAM) { return _to CheckPassword(password, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InitPassword(const PRUnichar *initialPassword) { return _to InitPassword(initialPassword); } \
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(const PRUnichar *oldPassword, const PRUnichar *newPassword) { return _to ChangePassword(oldPassword, newPassword); } \
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimes(PRInt32 *_retval NS_OUTPARAM) { return _to GetAskPasswordTimes(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimeout(PRInt32 *_retval NS_OUTPARAM) { return _to GetAskPasswordTimeout(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetAskPasswordDefaults(const PRInt32 askTimes, const PRInt32 timeout) { return _to SetAskPasswordDefaults(askTimes, timeout); } \
  NS_SCRIPTABLE NS_IMETHOD IsHardwareToken(PRBool *_retval NS_OUTPARAM) { return _to IsHardwareToken(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD NeedsLogin(PRBool *_retval NS_OUTPARAM) { return _to NeedsLogin(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsFriendly(PRBool *_retval NS_OUTPARAM) { return _to IsFriendly(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPK11TOKEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTokenName(PRUnichar * *aTokenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(aTokenName); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenLabel(PRUnichar * *aTokenLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenLabel(aTokenLabel); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenManID(PRUnichar * *aTokenManID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenManID(aTokenManID); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenHWVersion(PRUnichar * *aTokenHWVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenHWVersion(aTokenHWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenFWVersion(PRUnichar * *aTokenFWVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenFWVersion(aTokenFWVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetTokenSerialNumber(PRUnichar * *aTokenSerialNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenSerialNumber(aTokenSerialNumber); } \
  NS_SCRIPTABLE NS_IMETHOD IsLoggedIn(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLoggedIn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Login(PRBool force) { return !_to ? NS_ERROR_NULL_POINTER : _to->Login(force); } \
  NS_SCRIPTABLE NS_IMETHOD LogoutSimple(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogoutSimple(); } \
  NS_SCRIPTABLE NS_IMETHOD LogoutAndDropAuthenticatedResources(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogoutAndDropAuthenticatedResources(); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinimumPasswordLength(PRInt32 *aMinimumPasswordLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinimumPasswordLength(aMinimumPasswordLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsUserInit(PRBool *aNeedsUserInit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeedsUserInit(aNeedsUserInit); } \
  NS_SCRIPTABLE NS_IMETHOD CheckPassword(const PRUnichar *password, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckPassword(password, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InitPassword(const PRUnichar *initialPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPassword(initialPassword); } \
  NS_SCRIPTABLE NS_IMETHOD ChangePassword(const PRUnichar *oldPassword, const PRUnichar *newPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangePassword(oldPassword, newPassword); } \
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimes(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAskPasswordTimes(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAskPasswordTimeout(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAskPasswordTimeout(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetAskPasswordDefaults(const PRInt32 askTimes, const PRInt32 timeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAskPasswordDefaults(askTimes, timeout); } \
  NS_SCRIPTABLE NS_IMETHOD IsHardwareToken(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsHardwareToken(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD NeedsLogin(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NeedsLogin(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsFriendly(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFriendly(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPK11Token : public nsIPK11Token
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPK11TOKEN

  nsPK11Token();

private:
  ~nsPK11Token();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPK11Token, nsIPK11Token)

nsPK11Token::nsPK11Token()
{
  /* member initializers and constructor code */
}

nsPK11Token::~nsPK11Token()
{
  /* destructor code */
}

/* readonly attribute wstring tokenName; */
NS_IMETHODIMP nsPK11Token::GetTokenName(PRUnichar * *aTokenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenLabel; */
NS_IMETHODIMP nsPK11Token::GetTokenLabel(PRUnichar * *aTokenLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenManID; */
NS_IMETHODIMP nsPK11Token::GetTokenManID(PRUnichar * *aTokenManID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenHWVersion; */
NS_IMETHODIMP nsPK11Token::GetTokenHWVersion(PRUnichar * *aTokenHWVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenFWVersion; */
NS_IMETHODIMP nsPK11Token::GetTokenFWVersion(PRUnichar * *aTokenFWVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring tokenSerialNumber; */
NS_IMETHODIMP nsPK11Token::GetTokenSerialNumber(PRUnichar * *aTokenSerialNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLoggedIn (); */
NS_IMETHODIMP nsPK11Token::IsLoggedIn(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void login (in boolean force); */
NS_IMETHODIMP nsPK11Token::Login(PRBool force)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logoutSimple (); */
NS_IMETHODIMP nsPK11Token::LogoutSimple()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logoutAndDropAuthenticatedResources (); */
NS_IMETHODIMP nsPK11Token::LogoutAndDropAuthenticatedResources()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsPK11Token::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long minimumPasswordLength; */
NS_IMETHODIMP nsPK11Token::GetMinimumPasswordLength(PRInt32 *aMinimumPasswordLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean needsUserInit; */
NS_IMETHODIMP nsPK11Token::GetNeedsUserInit(PRBool *aNeedsUserInit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkPassword (in wstring password); */
NS_IMETHODIMP nsPK11Token::CheckPassword(const PRUnichar *password, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPassword (in wstring initialPassword); */
NS_IMETHODIMP nsPK11Token::InitPassword(const PRUnichar *initialPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changePassword (in wstring oldPassword, in wstring newPassword); */
NS_IMETHODIMP nsPK11Token::ChangePassword(const PRUnichar *oldPassword, const PRUnichar *newPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getAskPasswordTimes (); */
NS_IMETHODIMP nsPK11Token::GetAskPasswordTimes(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getAskPasswordTimeout (); */
NS_IMETHODIMP nsPK11Token::GetAskPasswordTimeout(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAskPasswordDefaults ([const] in long askTimes, [const] in long timeout); */
NS_IMETHODIMP nsPK11Token::SetAskPasswordDefaults(const PRInt32 askTimes, const PRInt32 timeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isHardwareToken (); */
NS_IMETHODIMP nsPK11Token::IsHardwareToken(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean needsLogin (); */
NS_IMETHODIMP nsPK11Token::NeedsLogin(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isFriendly (); */
NS_IMETHODIMP nsPK11Token::IsFriendly(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPK11Token_h__ */
