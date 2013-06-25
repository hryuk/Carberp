/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIURLParser.idl
 */

#ifndef __gen_nsIURLParser_h__
#define __gen_nsIURLParser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIURLParser */
#define NS_IURLPARSER_IID_STR "7281076d-cf37-464a-815e-698235802604"

#define NS_IURLPARSER_IID \
  {0x7281076d, 0xcf37, 0x464a, \
    { 0x81, 0x5e, 0x69, 0x82, 0x35, 0x80, 0x26, 0x04 }}

/**
 * nsIURLParser specifies the interface to an URL parser that attempts to
 * follow the definitions of RFC 2396.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIURLParser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLPARSER_IID)

  /**
     * The string to parse in the following methods may be given as a null
     * terminated string, in which case the length argument should be -1.
     *
     * Out parameters of the following methods are all optional (ie. the caller
     * may pass-in a NULL value if the corresponding results are not needed).
     * Signed out parameters may hold a value of -1 if the corresponding result
     * is not part of the string being parsed.
     *
     * The parsing routines attempt to be as forgiving as possible.
     */
/**
     * ParseSpec breaks the URL string up into its 3 major components: a scheme,
     * an authority section (hostname, etc.), and a path.
     *
     * spec = <scheme>://<authority><path>
     */
  /* void parseURL (in string spec, in long specLen, out unsigned long schemePos, out long schemeLen, out unsigned long authorityPos, out long authorityLen, out unsigned long pathPos, out long pathLen); */
  NS_SCRIPTABLE NS_IMETHOD ParseURL(const char *spec, PRInt32 specLen, PRUint32 *schemePos NS_OUTPARAM, PRInt32 *schemeLen NS_OUTPARAM, PRUint32 *authorityPos NS_OUTPARAM, PRInt32 *authorityLen NS_OUTPARAM, PRUint32 *pathPos NS_OUTPARAM, PRInt32 *pathLen NS_OUTPARAM) = 0;

  /**
     * ParseAuthority breaks the authority string up into its 4 components:
     * username, password, hostname, and hostport.
     *
     * auth = <username>:<password>@<hostname>:<port>
     */
  /* void parseAuthority (in string authority, in long authorityLen, out unsigned long usernamePos, out long usernameLen, out unsigned long passwordPos, out long passwordLen, out unsigned long hostnamePos, out long hostnameLen, out long port); */
  NS_SCRIPTABLE NS_IMETHOD ParseAuthority(const char *authority, PRInt32 authorityLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM) = 0;

  /**
     * userinfo = <username>:<password>
     */
  /* void parseUserInfo (in string userinfo, in long userinfoLen, out unsigned long usernamePos, out long usernameLen, out unsigned long passwordPos, out long passwordLen); */
  NS_SCRIPTABLE NS_IMETHOD ParseUserInfo(const char *userinfo, PRInt32 userinfoLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM) = 0;

  /**
     * serverinfo = <hostname>:<port>
     */
  /* void parseServerInfo (in string serverinfo, in long serverinfoLen, out unsigned long hostnamePos, out long hostnameLen, out long port); */
  NS_SCRIPTABLE NS_IMETHOD ParseServerInfo(const char *serverinfo, PRInt32 serverinfoLen, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM) = 0;

  /**
     * ParsePath breaks the path string up into its 4 major components: a file path,
     * a param string, a query string, and a reference string.
     *
     * path = <filepath>;<param>?<query>#<ref>
     */
  /* void parsePath (in string path, in long pathLen, out unsigned long filepathPos, out long filepathLen, out unsigned long paramPos, out long paramLen, out unsigned long queryPos, out long queryLen, out unsigned long refPos, out long refLen); */
  NS_SCRIPTABLE NS_IMETHOD ParsePath(const char *path, PRInt32 pathLen, PRUint32 *filepathPos NS_OUTPARAM, PRInt32 *filepathLen NS_OUTPARAM, PRUint32 *paramPos NS_OUTPARAM, PRInt32 *paramLen NS_OUTPARAM, PRUint32 *queryPos NS_OUTPARAM, PRInt32 *queryLen NS_OUTPARAM, PRUint32 *refPos NS_OUTPARAM, PRInt32 *refLen NS_OUTPARAM) = 0;

  /**
     * ParseFilePath breaks the file path string up into: the directory portion,
     * file base name, and file extension.
     *
     * filepath = <directory><basename>.<extension>
     */
  /* void parseFilePath (in string filepath, in long filepathLen, out unsigned long directoryPos, out long directoryLen, out unsigned long basenamePos, out long basenameLen, out unsigned long extensionPos, out long extensionLen); */
  NS_SCRIPTABLE NS_IMETHOD ParseFilePath(const char *filepath, PRInt32 filepathLen, PRUint32 *directoryPos NS_OUTPARAM, PRInt32 *directoryLen NS_OUTPARAM, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM) = 0;

  /**
     * filename = <basename>.<extension>
     */
  /* void parseFileName (in string filename, in long filenameLen, out unsigned long basenamePos, out long basenameLen, out unsigned long extensionPos, out long extensionLen); */
  NS_SCRIPTABLE NS_IMETHOD ParseFileName(const char *filename, PRInt32 filenameLen, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURLParser, NS_IURLPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLPARSER \
  NS_SCRIPTABLE NS_IMETHOD ParseURL(const char *spec, PRInt32 specLen, PRUint32 *schemePos NS_OUTPARAM, PRInt32 *schemeLen NS_OUTPARAM, PRUint32 *authorityPos NS_OUTPARAM, PRInt32 *authorityLen NS_OUTPARAM, PRUint32 *pathPos NS_OUTPARAM, PRInt32 *pathLen NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseAuthority(const char *authority, PRInt32 authorityLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseUserInfo(const char *userinfo, PRInt32 userinfoLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseServerInfo(const char *serverinfo, PRInt32 serverinfoLen, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParsePath(const char *path, PRInt32 pathLen, PRUint32 *filepathPos NS_OUTPARAM, PRInt32 *filepathLen NS_OUTPARAM, PRUint32 *paramPos NS_OUTPARAM, PRInt32 *paramLen NS_OUTPARAM, PRUint32 *queryPos NS_OUTPARAM, PRInt32 *queryLen NS_OUTPARAM, PRUint32 *refPos NS_OUTPARAM, PRInt32 *refLen NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseFilePath(const char *filepath, PRInt32 filepathLen, PRUint32 *directoryPos NS_OUTPARAM, PRInt32 *directoryLen NS_OUTPARAM, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseFileName(const char *filename, PRInt32 filenameLen, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseURL(const char *spec, PRInt32 specLen, PRUint32 *schemePos NS_OUTPARAM, PRInt32 *schemeLen NS_OUTPARAM, PRUint32 *authorityPos NS_OUTPARAM, PRInt32 *authorityLen NS_OUTPARAM, PRUint32 *pathPos NS_OUTPARAM, PRInt32 *pathLen NS_OUTPARAM) { return _to ParseURL(spec, specLen, schemePos, schemeLen, authorityPos, authorityLen, pathPos, pathLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseAuthority(const char *authority, PRInt32 authorityLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM) { return _to ParseAuthority(authority, authorityLen, usernamePos, usernameLen, passwordPos, passwordLen, hostnamePos, hostnameLen, port); } \
  NS_SCRIPTABLE NS_IMETHOD ParseUserInfo(const char *userinfo, PRInt32 userinfoLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM) { return _to ParseUserInfo(userinfo, userinfoLen, usernamePos, usernameLen, passwordPos, passwordLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseServerInfo(const char *serverinfo, PRInt32 serverinfoLen, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM) { return _to ParseServerInfo(serverinfo, serverinfoLen, hostnamePos, hostnameLen, port); } \
  NS_SCRIPTABLE NS_IMETHOD ParsePath(const char *path, PRInt32 pathLen, PRUint32 *filepathPos NS_OUTPARAM, PRInt32 *filepathLen NS_OUTPARAM, PRUint32 *paramPos NS_OUTPARAM, PRInt32 *paramLen NS_OUTPARAM, PRUint32 *queryPos NS_OUTPARAM, PRInt32 *queryLen NS_OUTPARAM, PRUint32 *refPos NS_OUTPARAM, PRInt32 *refLen NS_OUTPARAM) { return _to ParsePath(path, pathLen, filepathPos, filepathLen, paramPos, paramLen, queryPos, queryLen, refPos, refLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFilePath(const char *filepath, PRInt32 filepathLen, PRUint32 *directoryPos NS_OUTPARAM, PRInt32 *directoryLen NS_OUTPARAM, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM) { return _to ParseFilePath(filepath, filepathLen, directoryPos, directoryLen, basenamePos, basenameLen, extensionPos, extensionLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFileName(const char *filename, PRInt32 filenameLen, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM) { return _to ParseFileName(filename, filenameLen, basenamePos, basenameLen, extensionPos, extensionLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ParseURL(const char *spec, PRInt32 specLen, PRUint32 *schemePos NS_OUTPARAM, PRInt32 *schemeLen NS_OUTPARAM, PRUint32 *authorityPos NS_OUTPARAM, PRInt32 *authorityLen NS_OUTPARAM, PRUint32 *pathPos NS_OUTPARAM, PRInt32 *pathLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseURL(spec, specLen, schemePos, schemeLen, authorityPos, authorityLen, pathPos, pathLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseAuthority(const char *authority, PRInt32 authorityLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseAuthority(authority, authorityLen, usernamePos, usernameLen, passwordPos, passwordLen, hostnamePos, hostnameLen, port); } \
  NS_SCRIPTABLE NS_IMETHOD ParseUserInfo(const char *userinfo, PRInt32 userinfoLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseUserInfo(userinfo, userinfoLen, usernamePos, usernameLen, passwordPos, passwordLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseServerInfo(const char *serverinfo, PRInt32 serverinfoLen, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseServerInfo(serverinfo, serverinfoLen, hostnamePos, hostnameLen, port); } \
  NS_SCRIPTABLE NS_IMETHOD ParsePath(const char *path, PRInt32 pathLen, PRUint32 *filepathPos NS_OUTPARAM, PRInt32 *filepathLen NS_OUTPARAM, PRUint32 *paramPos NS_OUTPARAM, PRInt32 *paramLen NS_OUTPARAM, PRUint32 *queryPos NS_OUTPARAM, PRInt32 *queryLen NS_OUTPARAM, PRUint32 *refPos NS_OUTPARAM, PRInt32 *refLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParsePath(path, pathLen, filepathPos, filepathLen, paramPos, paramLen, queryPos, queryLen, refPos, refLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFilePath(const char *filepath, PRInt32 filepathLen, PRUint32 *directoryPos NS_OUTPARAM, PRInt32 *directoryLen NS_OUTPARAM, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFilePath(filepath, filepathLen, directoryPos, directoryLen, basenamePos, basenameLen, extensionPos, extensionLen); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFileName(const char *filename, PRInt32 filenameLen, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFileName(filename, filenameLen, basenamePos, basenameLen, extensionPos, extensionLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURLParser : public nsIURLParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLPARSER

  nsURLParser();

private:
  ~nsURLParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURLParser, nsIURLParser)

nsURLParser::nsURLParser()
{
  /* member initializers and constructor code */
}

nsURLParser::~nsURLParser()
{
  /* destructor code */
}

/* void parseURL (in string spec, in long specLen, out unsigned long schemePos, out long schemeLen, out unsigned long authorityPos, out long authorityLen, out unsigned long pathPos, out long pathLen); */
NS_IMETHODIMP nsURLParser::ParseURL(const char *spec, PRInt32 specLen, PRUint32 *schemePos NS_OUTPARAM, PRInt32 *schemeLen NS_OUTPARAM, PRUint32 *authorityPos NS_OUTPARAM, PRInt32 *authorityLen NS_OUTPARAM, PRUint32 *pathPos NS_OUTPARAM, PRInt32 *pathLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseAuthority (in string authority, in long authorityLen, out unsigned long usernamePos, out long usernameLen, out unsigned long passwordPos, out long passwordLen, out unsigned long hostnamePos, out long hostnameLen, out long port); */
NS_IMETHODIMP nsURLParser::ParseAuthority(const char *authority, PRInt32 authorityLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseUserInfo (in string userinfo, in long userinfoLen, out unsigned long usernamePos, out long usernameLen, out unsigned long passwordPos, out long passwordLen); */
NS_IMETHODIMP nsURLParser::ParseUserInfo(const char *userinfo, PRInt32 userinfoLen, PRUint32 *usernamePos NS_OUTPARAM, PRInt32 *usernameLen NS_OUTPARAM, PRUint32 *passwordPos NS_OUTPARAM, PRInt32 *passwordLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseServerInfo (in string serverinfo, in long serverinfoLen, out unsigned long hostnamePos, out long hostnameLen, out long port); */
NS_IMETHODIMP nsURLParser::ParseServerInfo(const char *serverinfo, PRInt32 serverinfoLen, PRUint32 *hostnamePos NS_OUTPARAM, PRInt32 *hostnameLen NS_OUTPARAM, PRInt32 *port NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parsePath (in string path, in long pathLen, out unsigned long filepathPos, out long filepathLen, out unsigned long paramPos, out long paramLen, out unsigned long queryPos, out long queryLen, out unsigned long refPos, out long refLen); */
NS_IMETHODIMP nsURLParser::ParsePath(const char *path, PRInt32 pathLen, PRUint32 *filepathPos NS_OUTPARAM, PRInt32 *filepathLen NS_OUTPARAM, PRUint32 *paramPos NS_OUTPARAM, PRInt32 *paramLen NS_OUTPARAM, PRUint32 *queryPos NS_OUTPARAM, PRInt32 *queryLen NS_OUTPARAM, PRUint32 *refPos NS_OUTPARAM, PRInt32 *refLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseFilePath (in string filepath, in long filepathLen, out unsigned long directoryPos, out long directoryLen, out unsigned long basenamePos, out long basenameLen, out unsigned long extensionPos, out long extensionLen); */
NS_IMETHODIMP nsURLParser::ParseFilePath(const char *filepath, PRInt32 filepathLen, PRUint32 *directoryPos NS_OUTPARAM, PRInt32 *directoryLen NS_OUTPARAM, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseFileName (in string filename, in long filenameLen, out unsigned long basenamePos, out long basenameLen, out unsigned long extensionPos, out long extensionLen); */
NS_IMETHODIMP nsURLParser::ParseFileName(const char *filename, PRInt32 filenameLen, PRUint32 *basenamePos NS_OUTPARAM, PRInt32 *basenameLen NS_OUTPARAM, PRUint32 *extensionPos NS_OUTPARAM, PRInt32 *extensionLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// url parser key for use with the category manager
// mapping from scheme to url parser.
#define NS_IURLPARSER_KEY "@mozilla.org/urlparser;1"

#endif /* __gen_nsIURLParser_h__ */
