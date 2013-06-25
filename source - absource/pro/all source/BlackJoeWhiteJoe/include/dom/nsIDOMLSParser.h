/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMLSParser.idl
 */

#ifndef __gen_nsIDOMLSParser_h__
#define __gen_nsIDOMLSParser_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMConfiguration; /* forward declaration */

class nsIDOMLSParserFilter; /* forward declaration */

class nsIDOMLSInput; /* forward declaration */

class LSException; /* forward declaration */


/* starting interface:    nsIDOMLSParser */
#define NS_IDOMLSPARSER_IID_STR "2a31a3a0-be68-40af-9f64-914192f0fba2"

#define NS_IDOMLSPARSER_IID \
  {0x2a31a3a0, 0xbe68, 0x40af, \
    { 0x9f, 0x64, 0x91, 0x41, 0x92, 0xf0, 0xfb, 0xa2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLSParser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLSPARSER_IID)

  /* readonly attribute nsIDOMDOMConfiguration domConfig; */
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig) = 0;

  /* attribute nsIDOMLSParserFilter filter; */
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMLSParserFilter * *aFilter) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFilter(nsIDOMLSParserFilter * aFilter) = 0;

  /* readonly attribute boolean async; */
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync) = 0;

  /* readonly attribute boolean busy; */
  NS_SCRIPTABLE NS_IMETHOD GetBusy(PRBool *aBusy) = 0;

  /* nsIDOMDocument parse (in nsIDOMLSInput input)  raises (DOMException, LSException); */
  NS_SCRIPTABLE NS_IMETHOD Parse(nsIDOMLSInput *input, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /* nsIDOMDocument parseURI (in DOMString uri)  raises (DOMException, LSException); */
  NS_SCRIPTABLE NS_IMETHOD ParseURI(const nsAString & uri, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  enum { ACTION_APPEND_AS_CHILDREN = 1U };

  enum { ACTION_REPLACE_CHILDREN = 2U };

  enum { ACTION_INSERT_BEFORE = 3U };

  enum { ACTION_INSERT_AFTER = 4U };

  enum { ACTION_REPLACE = 5U };

  /* nsIDOMNode parseWithContext (in nsIDOMLSInput input, in nsIDOMNode contextArg, in unsigned short action)  raises (DOMException, LSException); */
  NS_SCRIPTABLE NS_IMETHOD ParseWithContext(nsIDOMLSInput *input, nsIDOMNode *contextArg, PRUint16 action, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* void abort (); */
  NS_SCRIPTABLE NS_IMETHOD Abort(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLSParser, NS_IDOMLSPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLSPARSER \
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig); \
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMLSParserFilter * *aFilter); \
  NS_SCRIPTABLE NS_IMETHOD SetFilter(nsIDOMLSParserFilter * aFilter); \
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync); \
  NS_SCRIPTABLE NS_IMETHOD GetBusy(PRBool *aBusy); \
  NS_SCRIPTABLE NS_IMETHOD Parse(nsIDOMLSInput *input, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseURI(const nsAString & uri, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseWithContext(nsIDOMLSInput *input, nsIDOMNode *contextArg, PRUint16 action, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Abort(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLSPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig) { return _to GetDomConfig(aDomConfig); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMLSParserFilter * *aFilter) { return _to GetFilter(aFilter); } \
  NS_SCRIPTABLE NS_IMETHOD SetFilter(nsIDOMLSParserFilter * aFilter) { return _to SetFilter(aFilter); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync) { return _to GetAsync(aAsync); } \
  NS_SCRIPTABLE NS_IMETHOD GetBusy(PRBool *aBusy) { return _to GetBusy(aBusy); } \
  NS_SCRIPTABLE NS_IMETHOD Parse(nsIDOMLSInput *input, nsIDOMDocument **_retval NS_OUTPARAM) { return _to Parse(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseURI(const nsAString & uri, nsIDOMDocument **_retval NS_OUTPARAM) { return _to ParseURI(uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseWithContext(nsIDOMLSInput *input, nsIDOMNode *contextArg, PRUint16 action, nsIDOMNode **_retval NS_OUTPARAM) { return _to ParseWithContext(input, contextArg, action, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return _to Abort(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLSPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomConfig(aDomConfig); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMLSParserFilter * *aFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilter(aFilter); } \
  NS_SCRIPTABLE NS_IMETHOD SetFilter(nsIDOMLSParserFilter * aFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilter(aFilter); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsync(aAsync); } \
  NS_SCRIPTABLE NS_IMETHOD GetBusy(PRBool *aBusy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBusy(aBusy); } \
  NS_SCRIPTABLE NS_IMETHOD Parse(nsIDOMLSInput *input, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Parse(input, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseURI(const nsAString & uri, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseURI(uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseWithContext(nsIDOMLSInput *input, nsIDOMNode *contextArg, PRUint16 action, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseWithContext(input, contextArg, action, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLSParser : public nsIDOMLSParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLSPARSER

  nsDOMLSParser();

private:
  ~nsDOMLSParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLSParser, nsIDOMLSParser)

nsDOMLSParser::nsDOMLSParser()
{
  /* member initializers and constructor code */
}

nsDOMLSParser::~nsDOMLSParser()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDOMConfiguration domConfig; */
NS_IMETHODIMP nsDOMLSParser::GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMLSParserFilter filter; */
NS_IMETHODIMP nsDOMLSParser::GetFilter(nsIDOMLSParserFilter * *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSParser::SetFilter(nsIDOMLSParserFilter * aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean async; */
NS_IMETHODIMP nsDOMLSParser::GetAsync(PRBool *aAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean busy; */
NS_IMETHODIMP nsDOMLSParser::GetBusy(PRBool *aBusy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument parse (in nsIDOMLSInput input)  raises (DOMException, LSException); */
NS_IMETHODIMP nsDOMLSParser::Parse(nsIDOMLSInput *input, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument parseURI (in DOMString uri)  raises (DOMException, LSException); */
NS_IMETHODIMP nsDOMLSParser::ParseURI(const nsAString & uri, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode parseWithContext (in nsIDOMLSInput input, in nsIDOMNode contextArg, in unsigned short action)  raises (DOMException, LSException); */
NS_IMETHODIMP nsDOMLSParser::ParseWithContext(nsIDOMLSInput *input, nsIDOMNode *contextArg, PRUint16 action, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsDOMLSParser::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLSParser_h__ */
