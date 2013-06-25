/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/commandlines/public/nsICommandLineRunner.idl
 */

#ifndef __gen_nsICommandLineRunner_h__
#define __gen_nsICommandLineRunner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICommandLine_h__
#include "nsICommandLine.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICommandLineRunner */
#define NS_ICOMMANDLINERUNNER_IID_STR "c1f4cfbf-a41f-4628-aa6c-9fb914478af8"

#define NS_ICOMMANDLINERUNNER_IID \
  {0xc1f4cfbf, 0xa41f, 0x4628, \
    { 0xaa, 0x6c, 0x9f, 0xb9, 0x14, 0x47, 0x8a, 0xf8 }}

/**
 * Extension of nsICommandLine that allows for initialization of new command lines
 * and running the command line actions by processing the command line handlers.
 *
 * @status INTERNAL - This interface is not meant for use by embedders, and is
 *                    not intended to be frozen. If you are an embedder and need
 *                    functionality provided by this interface, talk to Benjamin
 *                    Smedberg <benjamin@smedbergs.us>.
 */
class NS_NO_VTABLE nsICommandLineRunner : public nsICommandLine {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDLINERUNNER_IID)

  /**
   * This method assumes a native character set, and is meant to be called
   * with the argc/argv passed to main(). Talk to bsmedberg if you need to
   * create a command line using other data. argv will not be altered in any
   * way.
   *
   * On Windows, the "native" character set is UTF-8, not the native codepage.
   *
   * @param workingDir The working directory for resolving file and URI paths.
   * @param state      The nsICommandLine.state flag.
   */
  /* void init (in long argc, in nsCharPtrArray argv, in nsIFile workingDir, in unsigned long state); */
  NS_IMETHOD Init(PRInt32 argc, char* * argv, nsIFile *workingDir, PRUint32 state) = 0;

  /**
   * Set the windowContext parameter.
   */
  /* void setWindowContext (in nsIDOMWindow aWindow); */
  NS_IMETHOD SetWindowContext(nsIDOMWindow *aWindow) = 0;

  /**
   * Process the command-line handlers in the proper order, calling "handle()" on
   * each.
   *
   * @throws NS_ERROR_ABORT if any handler throws NS_ERROR_ABORT. All other errors
   *         thrown by handlers will be silently ignored.
   */
  /* void run (); */
  NS_IMETHOD Run(void) = 0;

  /**
   * Process and combine the help text provided by each command-line handler.
   */
  /* readonly attribute AUTF8String helpText; */
  NS_IMETHOD GetHelpText(nsACString & aHelpText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandLineRunner, NS_ICOMMANDLINERUNNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDLINERUNNER \
  NS_IMETHOD Init(PRInt32 argc, char* * argv, nsIFile *workingDir, PRUint32 state); \
  NS_IMETHOD SetWindowContext(nsIDOMWindow *aWindow); \
  NS_IMETHOD Run(void); \
  NS_IMETHOD GetHelpText(nsACString & aHelpText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDLINERUNNER(_to) \
  NS_IMETHOD Init(PRInt32 argc, char* * argv, nsIFile *workingDir, PRUint32 state) { return _to Init(argc, argv, workingDir, state); } \
  NS_IMETHOD SetWindowContext(nsIDOMWindow *aWindow) { return _to SetWindowContext(aWindow); } \
  NS_IMETHOD Run(void) { return _to Run(); } \
  NS_IMETHOD GetHelpText(nsACString & aHelpText) { return _to GetHelpText(aHelpText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDLINERUNNER(_to) \
  NS_IMETHOD Init(PRInt32 argc, char* * argv, nsIFile *workingDir, PRUint32 state) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(argc, argv, workingDir, state); } \
  NS_IMETHOD SetWindowContext(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindowContext(aWindow); } \
  NS_IMETHOD Run(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(); } \
  NS_IMETHOD GetHelpText(nsACString & aHelpText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHelpText(aHelpText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandLineRunner : public nsICommandLineRunner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDLINERUNNER

  nsCommandLineRunner();

private:
  ~nsCommandLineRunner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandLineRunner, nsICommandLineRunner)

nsCommandLineRunner::nsCommandLineRunner()
{
  /* member initializers and constructor code */
}

nsCommandLineRunner::~nsCommandLineRunner()
{
  /* destructor code */
}

/* void init (in long argc, in nsCharPtrArray argv, in nsIFile workingDir, in unsigned long state); */
NS_IMETHODIMP nsCommandLineRunner::Init(PRInt32 argc, char* * argv, nsIFile *workingDir, PRUint32 state)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWindowContext (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsCommandLineRunner::SetWindowContext(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void run (); */
NS_IMETHODIMP nsCommandLineRunner::Run()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String helpText; */
NS_IMETHODIMP nsCommandLineRunner::GetHelpText(nsACString & aHelpText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICommandLineRunner_h__ */
