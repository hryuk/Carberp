/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleProvider.idl
 */

#ifndef __gen_nsIAccessibleProvider_h__
#define __gen_nsIAccessibleProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleProvider */
#define NS_IACCESSIBLEPROVIDER_IID_STR "3f7f9194-c625-4a85-8148-6d92d34897fa"

#define NS_IACCESSIBLEPROVIDER_IID \
  {0x3f7f9194, 0xc625, 0x4a85, \
    { 0x81, 0x48, 0x6d, 0x92, 0xd3, 0x48, 0x97, 0xfa }}

/**
 * nsIAccessibleProvider interface is used to link element and accessible
   object. For that XBL binding of element should implement the interface.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEPROVIDER_IID)

  /**
   * Constants set of common use.
   */
/** Do not create an accessible for this object
   * This is useful if an ancestor binding already implements nsIAccessibleProvider,
   * but no accessible is desired for the inheriting binding
   */
  enum { NoAccessible = 0 };

  /** For elements that spawn a new document. For example now it is used by
    <xul:iframe>, <xul:browser> and <xul:editor>. */
  enum { OuterDoc = 1 };

  /**
   * Constants set is used by XUL controls.
   */
  enum { XULAlert = 4097 };

  enum { XULButton = 4098 };

  enum { XULCheckbox = 4099 };

  enum { XULColorPicker = 4100 };

  enum { XULColorPickerTile = 4101 };

  enum { XULCombobox = 4102 };

  enum { XULDropmarker = 4103 };

  enum { XULGroupbox = 4104 };

  enum { XULImage = 4105 };

  enum { XULLink = 4106 };

  enum { XULListbox = 4107 };

  enum { XULListCell = 4134 };

  enum { XULListHead = 4132 };

  enum { XULListHeader = 4133 };

  enum { XULListitem = 4108 };

  enum { XULMenubar = 4109 };

  enum { XULMenuitem = 4110 };

  enum { XULMenupopup = 4111 };

  enum { XULMenuSeparator = 4112 };

  enum { XULPane = 4113 };

  enum { XULProgressMeter = 4114 };

  enum { XULScale = 4115 };

  enum { XULStatusBar = 4116 };

  enum { XULRadioButton = 4117 };

  enum { XULRadioGroup = 4118 };

  /** The single tab in a dialog or tabbrowser/editor interface */
  enum { XULTab = 4119 };

  /** A combination of a tabs object and a tabpanels object */
  enum { XULTabBox = 4120 };

  /** The collection of tab objects, useable in the TabBox and independant of
   as well */
  enum { XULTabs = 4121 };

  enum { XULText = 4122 };

  enum { XULTextBox = 4123 };

  enum { XULThumb = 4124 };

  enum { XULTree = 4125 };

  enum { XULTreeColumns = 4126 };

  enum { XULTreeColumnItem = 4127 };

  enum { XULToolbar = 4128 };

  enum { XULToolbarSeparator = 4129 };

  enum { XULTooltip = 4130 };

  enum { XULToolbarButton = 4131 };

  /**
   * Constants set is used by XForms elements.
   */
/** Used for xforms elements that provide accessible object for itself as
   * well for anonymous content. This property are used for upload,
   * input[type="xsd:gDay"] and input[type="xsd:gMonth"] */
  enum { XFormsContainer = 8192 };

  /** Used for label element */
  enum { XFormsLabel = 8193 };

  /** Used for output element */
  enum { XFormsOuput = 8194 };

  /** Used for trigger and submit elements */
  enum { XFormsTrigger = 8195 };

  /** Used for input and textarea elements */
  enum { XFormsInput = 8196 };

  /** Used for input[xsd:boolean] element */
  enum { XFormsInputBoolean = 8197 };

  /** Used for input[xsd:date] element */
  enum { XFormsInputDate = 8198 };

  /** Used for secret element */
  enum { XFormsSecret = 8199 };

  /** Used for range element represented by slider */
  enum { XFormsSliderRange = 8200 };

  /** Used for select and select1 that are implemented using host document's
   * native widget. For example, a select1 in a xhtml document may be
   * represented by the native html control html:select */
  enum { XFormsSelect = 8201 };

  /** Used for xforms choices element */
  enum { XFormsChoices = 8208 };

  /** Used for xforms full select/select1 elements that may be represented by
   * group of checkboxes and radiogroup */
  enum { XFormsSelectFull = 8209 };

  /** Used for xforms item element that is used inside xforms select elements
   * represented by group of checkboxes */
  enum { XFormsItemCheckgroup = 8210 };

  /** Used for xforms item element that is used inside xforms select1 elements
   * represented by radio group */
  enum { XFormsItemRadiogroup = 8211 };

  /** Used for xforms select1 element that is represented by combobox */
  enum { XFormsSelectCombobox = 8212 };

  /** Used for xforms item element that is used inside xforms select1
   * elements represented by combobox */
  enum { XFormsItemCombobox = 8213 };

  /** Used for dropmarker widget that is used by xforms elements */
  enum { XFormsDropmarkerWidget = 8449 };

  /** Used for calendar widget that is used by xforms elements */
  enum { XFormsCalendarWidget = 8450 };

  /** Used for popup widget that is used by xforms minimal select1 elements */
  enum { XFormsComboboxPopupWidget = 8451 };

  /**
   * Return one of constants declared above.
   */
  /* readonly attribute long accessibleType; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleType(PRInt32 *aAccessibleType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleProvider, NS_IACCESSIBLEPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleType(PRInt32 *aAccessibleType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleType(PRInt32 *aAccessibleType) { return _to GetAccessibleType(aAccessibleType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleType(PRInt32 *aAccessibleType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleType(aAccessibleType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleProvider : public nsIAccessibleProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEPROVIDER

  nsAccessibleProvider();

private:
  ~nsAccessibleProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleProvider, nsIAccessibleProvider)

nsAccessibleProvider::nsAccessibleProvider()
{
  /* member initializers and constructor code */
}

nsAccessibleProvider::~nsAccessibleProvider()
{
  /* destructor code */
}

/* readonly attribute long accessibleType; */
NS_IMETHODIMP nsAccessibleProvider::GetAccessibleType(PRInt32 *aAccessibleType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleProvider_h__ */
