/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/stylesheets/nsIDOMNSDocumentStyle.idl
 */

#ifndef __gen_nsIDOMNSDocumentStyle_h__
#define __gen_nsIDOMNSDocumentStyle_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMDocumentStyle_h__
#include "nsIDOMDocumentStyle.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSDocumentStyle */
#define NS_IDOMNSDOCUMENTSTYLE_IID_STR "26311d10-7e24-4c7b-bb3d-17aad86f4d88"

#define NS_IDOMNSDOCUMENTSTYLE_IID \
  {0x26311d10, 0x7e24, 0x4c7b, \
    { 0xbb, 0x3d, 0x17, 0xaa, 0xd8, 0x6f, 0x4d, 0x88 }}

/**
 * The nsIDOMNSDocumentStyle interface is an extension to the
 * nsIDOMDocumentStyle interface.  This interface exposes more ways to interact
 * with style sheets in the Document Object Model.  This interface is currently
 * very much experimental.
 *
 * NOTE: This interface represents the additions to nsIDOMDocumentStyle defined
 * by <http://whatwg.org/specs/web-apps/current-work/#alternate-style-sheets>.
 * The comments here describe our implementation; if those comments don't match
 * that spec, file bugs.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSDocumentStyle : public nsIDOMDocumentStyle {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSDOCUMENTSTYLE_IID)

  /**
   * This attribute must return the preferred style sheet set as set by the
   * author. It is determined from the order of style sheet declarations and
   * the Default-Style HTTP headers, as eventually defined elsewhere in the Web
   * Apps 1.0 specification. If there is no preferred style sheet set, this
   * attribute must return the empty string. The case of this attribute must
   * exactly match the case given by the author where the preferred style sheet
   * is specified or implied. This attribute must never return null.
   */
  /* readonly attribute DOMString preferredStyleSheetSet; */
  NS_SCRIPTABLE NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet) = 0;

  /**
   * This attribute indicates which style sheet set is in use. This attribute
   * is live; changing the disabled attribute on style sheets directly will
   * change the value of this attribute.
   *
   * If all the sheets that are enabled and have a title have the same title
   * (by case-sensitive comparisons) then the value of this attribute must be
   * exactly equal to the title of the first enabled style sheet with a title
   * in the styleSheets list. Otherwise, if style sheets from different sets
   * are enabled, then the return value must be null (there is no way to
   * determine what the currently selected style sheet set is in those
   * conditions). Otherwise, either all style sheets that have a title are
   * disabled, or there are no alternate style sheets, and
   * selectedStyleSheetSet must return the empty string.
   *
   * Setting this attribute to the null value must have no effect.
   *
   * Setting this attribute to a non-null value must call
   * enableStyleSheetsForSet() with that value as the function's argument, and
   * set lastStyleSheetSet to that value.
   *
   * From the DOM's perspective, all views have the same
   * selectedStyleSheetSet. If a UA supports multiple views with different
   * selected alternate style sheets, then this attribute (and the StyleSheet
   * interface's disabled attribute) must return and set the value for the
   * default view.
   */
  /* attribute DOMString selectedStyleSheetSet; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet) = 0;

  /* readonly attribute DOMString lastStyleSheetSet; */
  NS_SCRIPTABLE NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet) = 0;

  /**
   * This must return the live list of the currently available style sheet
   * sets. This list is constructed by enumerating all the style sheets for
   * this document available to the implementation, in the order they are
   * listed in the styleSheets attribute, adding the title of each style sheet
   * with a title to the list, avoiding duplicates by dropping titles that
   * match (case-sensitively) titles that have already been added to the
   * list.
   */
  /* readonly attribute nsIDOMDOMStringList styleSheetSets; */
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheetSets(nsIDOMDOMStringList * *aStyleSheetSets) = 0;

  /**
   * Calling this method must change the disabled attribute on each StyleSheet
   * object with a title attribute with a length greater than 0 in the
   * styleSheets attribute, so that all those whose title matches the name
   * argument are enabled, and all others are disabled. Title matches must be
   * case-sensitive. Calling this method with the empty string disables all
   * alternate and preferred style sheets (but does not change the state of
   * persistent style sheets, that is those with no title attribute).
   *
   * Calling this method with a null value must have no effect.
   *
   * Style sheets that do not have a title are never affected by this
   * method. This method does not change the values of the lastStyleSheetSet or
   * preferredStyleSheetSet attributes.
   */
  /* void enableStyleSheetsForSet (in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheetsForSet(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSDocumentStyle, NS_IDOMNSDOCUMENTSTYLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSDOCUMENTSTYLE \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet); \
  NS_SCRIPTABLE NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet); \
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheetSets(nsIDOMDOMStringList * *aStyleSheetSets); \
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheetsForSet(const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSDOCUMENTSTYLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet) { return _to GetPreferredStyleSheetSet(aPreferredStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet) { return _to GetSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet) { return _to SetSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet) { return _to GetLastStyleSheetSet(aLastStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheetSets(nsIDOMDOMStringList * *aStyleSheetSets) { return _to GetStyleSheetSets(aStyleSheetSets); } \
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheetsForSet(const nsAString & name) { return _to EnableStyleSheetsForSet(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSDOCUMENTSTYLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredStyleSheetSet(aPreferredStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastStyleSheetSet(aLastStyleSheetSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetStyleSheetSets(nsIDOMDOMStringList * *aStyleSheetSets) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleSheetSets(aStyleSheetSets); } \
  NS_SCRIPTABLE NS_IMETHOD EnableStyleSheetsForSet(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableStyleSheetsForSet(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSDocumentStyle : public nsIDOMNSDocumentStyle
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSDOCUMENTSTYLE

  nsDOMNSDocumentStyle();

private:
  ~nsDOMNSDocumentStyle();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSDocumentStyle, nsIDOMNSDocumentStyle)

nsDOMNSDocumentStyle::nsDOMNSDocumentStyle()
{
  /* member initializers and constructor code */
}

nsDOMNSDocumentStyle::~nsDOMNSDocumentStyle()
{
  /* destructor code */
}

/* readonly attribute DOMString preferredStyleSheetSet; */
NS_IMETHODIMP nsDOMNSDocumentStyle::GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString selectedStyleSheetSet; */
NS_IMETHODIMP nsDOMNSDocumentStyle::GetSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDocumentStyle::SetSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastStyleSheetSet; */
NS_IMETHODIMP nsDOMNSDocumentStyle::GetLastStyleSheetSet(nsAString & aLastStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList styleSheetSets; */
NS_IMETHODIMP nsDOMNSDocumentStyle::GetStyleSheetSets(nsIDOMDOMStringList * *aStyleSheetSets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableStyleSheetsForSet (in DOMString name); */
NS_IMETHODIMP nsDOMNSDocumentStyle::EnableStyleSheetsForSet(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSDocumentStyle_h__ */
