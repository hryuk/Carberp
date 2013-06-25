/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsISound.idl
 */

#ifndef __gen_nsISound_h__
#define __gen_nsISound_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURL; /* forward declaration */


/* starting interface:    nsISound */
#define NS_ISOUND_IID_STR "b01adad7-d937-4738-8508-3bd5946bf9c8"

#define NS_ISOUND_IID \
  {0xb01adad7, 0xd937, 0x4738, \
    { 0x85, 0x08, 0x3b, 0xd5, 0x94, 0x6b, 0xf9, 0xc8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISound : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOUND_IID)

  /* void play (in nsIURL aURL); */
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL) = 0;

  /**
   * for playing system sounds
   */
  /* void playSystemSound (in AString soundAlias); */
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) = 0;

  /* void beep (); */
  NS_SCRIPTABLE NS_IMETHOD Beep(void) = 0;

  /**
    * Not strictly necessary, but avoids delay before first sound.
    * The various methods on nsISound call Init() if they need to.
	*/
  /* void init (); */
  NS_SCRIPTABLE NS_IMETHOD Init(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISound, NS_ISOUND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOUND \
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL); \
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias); \
  NS_SCRIPTABLE NS_IMETHOD Beep(void); \
  NS_SCRIPTABLE NS_IMETHOD Init(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOUND(_to) \
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL) { return _to Play(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) { return _to PlaySystemSound(soundAlias); } \
  NS_SCRIPTABLE NS_IMETHOD Beep(void) { return _to Beep(); } \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return _to Init(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOUND(_to) \
  NS_SCRIPTABLE NS_IMETHOD Play(nsIURL *aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->Play(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD PlaySystemSound(const nsAString & soundAlias) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlaySystemSound(soundAlias); } \
  NS_SCRIPTABLE NS_IMETHOD Beep(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Beep(); } \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSound : public nsISound
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOUND

  nsSound();

private:
  ~nsSound();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSound, nsISound)

nsSound::nsSound()
{
  /* member initializers and constructor code */
}

nsSound::~nsSound()
{
  /* destructor code */
}

/* void play (in nsIURL aURL); */
NS_IMETHODIMP nsSound::Play(nsIURL *aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void playSystemSound (in AString soundAlias); */
NS_IMETHODIMP nsSound::PlaySystemSound(const nsAString & soundAlias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beep (); */
NS_IMETHODIMP nsSound::Beep()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (); */
NS_IMETHODIMP nsSound::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SYSSOUND_PREFIX          NS_LITERAL_STRING("_moz_")
#define NS_SYSSOUND_MAIL_BEEP       NS_LITERAL_STRING("_moz_mailbeep")
#define NS_SYSSOUND_ALERT_DIALOG    NS_LITERAL_STRING("_moz_alertdialog")
#define NS_SYSSOUND_CONFIRM_DIALOG  NS_LITERAL_STRING("_moz_confirmdialog")
#define NS_SYSSOUND_PROMPT_DIALOG   NS_LITERAL_STRING("_moz_promptdialog")
#define NS_SYSSOUND_SELECT_DIALOG   NS_LITERAL_STRING("_moz_selectdialog")
#define NS_SYSSOUND_MENU_EXECUTE    NS_LITERAL_STRING("_moz_menucommand")
#define NS_SYSSOUND_MENU_POPUP      NS_LITERAL_STRING("_moz_menupopup")
#define NS_IsMozAliasSound(aSoundAlias) \
          StringBeginsWith(aSoundAlias, NS_SYSSOUND_PREFIX)

#endif /* __gen_nsISound_h__ */
