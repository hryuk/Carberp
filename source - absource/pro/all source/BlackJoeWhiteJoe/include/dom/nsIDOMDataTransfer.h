/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMDataTransfer.idl
 */

#ifndef __gen_nsIDOMDataTransfer_h__
#define __gen_nsIDOMDataTransfer_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMDataTransfer */
#define NS_IDOMDATATRANSFER_IID_STR "b5947dd0-8e86-4b9c-aa65-c86303efcf94"

#define NS_IDOMDATATRANSFER_IID \
  {0xb5947dd0, 0x8e86, 0x4b9c, \
    { 0xaa, 0x65, 0xc8, 0x63, 0x03, 0xef, 0xcf, 0x94 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDataTransfer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATATRANSFER_IID)

  /**
   * The actual effect that will be used, and should always be one of the
   * possible values of effectAllowed.
   *
   * For dragstart, drag and dragleave events, the dropEffect is initialized
   * to none. Any value assigned to the dropEffect will be set, but the value
   * isn't used for anything.
   *
   * For the dragenter and dragover events, the dropEffect will be initialized
   * based on what action the user is requesting. How this is determined is
   * platform specific, but typically the user can press modifier keys to
   * adjust which action is desired. Within an event handler for the dragenter
   * and dragover events, the dropEffect should be modified if the action the
   * user is requesting is not the one that is desired.
   *
   * For the drop and dragend events, the dropEffect will be initialized to
   * the action that was desired, which will be the value that the dropEffect
   * had after the last dragenter or dragover event.
   *
   * Possible values:
   *  copy - a copy of the source item is made at the new location
   *  move - an item is moved to a new location
   *  link - a link is established to the source at the new location
   *  none - the item may not be dropped
   *
   * Assigning any other value has no effect and retains the old value.
   */
  /* attribute DOMString dropEffect; */
  NS_SCRIPTABLE NS_IMETHOD GetDropEffect(nsAString & aDropEffect) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDropEffect(const nsAString & aDropEffect) = 0;

  /* attribute DOMString effectAllowed; */
  NS_SCRIPTABLE NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed) = 0;

  /**
   * Holds a list of the format types of the data that is stored for the first
   * item, in the same order the data was added. An empty list will be
   * returned if no data was added.
   */
  /* readonly attribute nsIDOMDOMStringList types; */
  NS_SCRIPTABLE NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes) = 0;

  /**
   * Remove the data associated with a given format. If format is empty or not
   * specified, the data associated with all formats is removed. If data for
   * the specified format does not exist, or the data transfer contains no
   * data, this method will have no effect.
   */
  /* void clearData ([optional] in DOMString format); */
  NS_SCRIPTABLE NS_IMETHOD ClearData(const nsAString & format) = 0;

  /**
   * Set the data for a given format. If data for the format does not exist,
   * it is added at the end, such that the last item in the types list will be
   * the new format. If data for the format already exists, the existing data
   * is replaced in the same position. That is, the order of the types list is
   * not changed.
   *
   * @throws NS_ERROR_NULL_POINTER if the data is null
   */
  /* void setData (in DOMString format, in DOMString data); */
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & format, const nsAString & data) = 0;

  /**
   * Retrieves the data for a given format, or an empty string if data for
   * that format does not exist or the data transfer contains no data.
   */
  /* DOMString getData (in DOMString format); */
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & format, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Set the image to be used for dragging if a custom one is desired. Most of
   * the time, this would not be set, as a default image is created from the
   * node that was dragged.
   *
   * If the node is an HTML img element, an HTML canvas element or a XUL image
   * element, the image data is used. Otherwise, image should be a visible
   * node and the drag image will be created from this. If image is null, any
   * custom drag image is cleared and the default is used instead.
   *
   * The coordinates specify the offset into the image where the mouse cursor
   * should be. To center the image for instance, use values that are half the
   * width and height.
   *
   * @param image a node to use 
   * @param x the horizontal offset
   * @param y the vertical offset
   * @throws NO_MODIFICATION_ALLOWED_ERR if the item cannot be modified
   */
  /* void setDragImage (in nsIDOMElement image, in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD SetDragImage(nsIDOMElement *image, PRInt32 x, PRInt32 y) = 0;

  /* void addElement (in nsIDOMElement element); */
  NS_SCRIPTABLE NS_IMETHOD AddElement(nsIDOMElement *element) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataTransfer, NS_IDOMDATATRANSFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATATRANSFER \
  NS_SCRIPTABLE NS_IMETHOD GetDropEffect(nsAString & aDropEffect); \
  NS_SCRIPTABLE NS_IMETHOD SetDropEffect(const nsAString & aDropEffect); \
  NS_SCRIPTABLE NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed); \
  NS_SCRIPTABLE NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed); \
  NS_SCRIPTABLE NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes); \
  NS_SCRIPTABLE NS_IMETHOD ClearData(const nsAString & format); \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & format, const nsAString & data); \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & format, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetDragImage(nsIDOMElement *image, PRInt32 x, PRInt32 y); \
  NS_SCRIPTABLE NS_IMETHOD AddElement(nsIDOMElement *element); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATATRANSFER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDropEffect(nsAString & aDropEffect) { return _to GetDropEffect(aDropEffect); } \
  NS_SCRIPTABLE NS_IMETHOD SetDropEffect(const nsAString & aDropEffect) { return _to SetDropEffect(aDropEffect); } \
  NS_SCRIPTABLE NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed) { return _to GetEffectAllowed(aEffectAllowed); } \
  NS_SCRIPTABLE NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed) { return _to SetEffectAllowed(aEffectAllowed); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes) { return _to GetTypes(aTypes); } \
  NS_SCRIPTABLE NS_IMETHOD ClearData(const nsAString & format) { return _to ClearData(format); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & format, const nsAString & data) { return _to SetData(format, data); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & format, nsAString & _retval NS_OUTPARAM) { return _to GetData(format, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDragImage(nsIDOMElement *image, PRInt32 x, PRInt32 y) { return _to SetDragImage(image, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD AddElement(nsIDOMElement *element) { return _to AddElement(element); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATATRANSFER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDropEffect(nsAString & aDropEffect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDropEffect(aDropEffect); } \
  NS_SCRIPTABLE NS_IMETHOD SetDropEffect(const nsAString & aDropEffect) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDropEffect(aDropEffect); } \
  NS_SCRIPTABLE NS_IMETHOD GetEffectAllowed(nsAString & aEffectAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffectAllowed(aEffectAllowed); } \
  NS_SCRIPTABLE NS_IMETHOD SetEffectAllowed(const nsAString & aEffectAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEffectAllowed(aEffectAllowed); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypes(nsIDOMDOMStringList * *aTypes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypes(aTypes); } \
  NS_SCRIPTABLE NS_IMETHOD ClearData(const nsAString & format) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearData(format); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & format, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(format, data); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & format, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(format, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDragImage(nsIDOMElement *image, PRInt32 x, PRInt32 y) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDragImage(image, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD AddElement(nsIDOMElement *element) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddElement(element); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataTransfer : public nsIDOMDataTransfer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATATRANSFER

  nsDOMDataTransfer();

private:
  ~nsDOMDataTransfer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDataTransfer, nsIDOMDataTransfer)

nsDOMDataTransfer::nsDOMDataTransfer()
{
  /* member initializers and constructor code */
}

nsDOMDataTransfer::~nsDOMDataTransfer()
{
  /* destructor code */
}

/* attribute DOMString dropEffect; */
NS_IMETHODIMP nsDOMDataTransfer::GetDropEffect(nsAString & aDropEffect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataTransfer::SetDropEffect(const nsAString & aDropEffect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString effectAllowed; */
NS_IMETHODIMP nsDOMDataTransfer::GetEffectAllowed(nsAString & aEffectAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataTransfer::SetEffectAllowed(const nsAString & aEffectAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringList types; */
NS_IMETHODIMP nsDOMDataTransfer::GetTypes(nsIDOMDOMStringList * *aTypes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearData ([optional] in DOMString format); */
NS_IMETHODIMP nsDOMDataTransfer::ClearData(const nsAString & format)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setData (in DOMString format, in DOMString data); */
NS_IMETHODIMP nsDOMDataTransfer::SetData(const nsAString & format, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getData (in DOMString format); */
NS_IMETHODIMP nsDOMDataTransfer::GetData(const nsAString & format, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDragImage (in nsIDOMElement image, in long x, in long y); */
NS_IMETHODIMP nsDOMDataTransfer::SetDragImage(nsIDOMElement *image, PRInt32 x, PRInt32 y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addElement (in nsIDOMElement element); */
NS_IMETHODIMP nsDOMDataTransfer::AddElement(nsIDOMElement *element)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMNSDataTransfer */
#define NS_IDOMNSDATATRANSFER_IID_STR "53c854fc-33f9-4647-b045-46d7ab06a6f1"

#define NS_IDOMNSDATATRANSFER_IID \
  {0x53c854fc, 0x33f9, 0x4647, \
    { 0xb0, 0x45, 0x46, 0xd7, 0xab, 0x06, 0xa6, 0xf1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSDataTransfer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSDATATRANSFER_IID)

  /* [noscript] attribute unsigned long dropEffectInt; */
  NS_IMETHOD GetDropEffectInt(PRUint32 *aDropEffectInt) = 0;
  NS_IMETHOD SetDropEffectInt(PRUint32 aDropEffectInt) = 0;

  /* [noscript] attribute unsigned long effectAllowedInt; */
  NS_IMETHOD GetEffectAllowedInt(PRUint32 *aEffectAllowedInt) = 0;
  NS_IMETHOD SetEffectAllowedInt(PRUint32 aEffectAllowedInt) = 0;

  /**
   * Creates a copy of the data transfer object, for the given event type and
   * user cancelled flag.
   */
  /* [noscript] nsIDOMDataTransfer clone (in PRUint32 aEventType, in PRBool aUserCancelled); */
  NS_IMETHOD Clone(PRUint32 aEventType, PRBool aUserCancelled, nsIDOMDataTransfer **_retval NS_OUTPARAM) = 0;

  /**
   * The number of items being dragged.
   */
  /* readonly attribute unsigned long mozItemCount; */
  NS_SCRIPTABLE NS_IMETHOD GetMozItemCount(PRUint32 *aMozItemCount) = 0;

  /**
   * Holds a list of the format types of the data that is stored for an item
   * at the specified index. If the index is not in the range from 0 to
   * itemCount - 1, an empty string list is returned.
   */
  /* nsIDOMDOMStringList mozTypesAt (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD MozTypesAt(PRUint32 index, nsIDOMDOMStringList **_retval NS_OUTPARAM) = 0;

  /**
   * Remove the data associated with the given format for an item at the
   * specified index. The index is in the range from zero to itemCount - 1.
   *
   * If the last format for the item is removed, the entire item is removed,
   * reducing the itemCount by one.
   *
   * If format is empty, then the data associated with all formats is removed.
   * If the format is not found, then this method has no effect.
   *
   * @param format the format to remove
   * @throws NS_ERROR_DOM_INDEX_SIZE_ERR if index is greater or equal than itemCount
   * @throws NO_MODIFICATION_ALLOWED_ERR if the item cannot be modified
   */
  /* void mozClearDataAt (in DOMString format, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD MozClearDataAt(const nsAString & format, PRUint32 index) = 0;

  /* void mozSetDataAt (in DOMString format, in nsIVariant data, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, PRUint32 index) = 0;

  /**
   * Retrieve the data associated with the given format for an item at the
   * specified index, or null if it does not exist. The index should be in the
   * range from zero to itemCount - 1.
   *
   * @param format the format of the data to look up
   * @returns the data of the given format, or null if it doesn't exist.
   * @throws NS_ERROR_DOM_INDEX_SIZE_ERR if index is greater or equal than itemCount
   */
  /* nsIVariant mozGetDataAt (in DOMString format, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD MozGetDataAt(const nsAString & format, PRUint32 index, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Will be true when the user has cancelled the drag (typically by pressing
   * Escape) and when the drag has been cancelled unexpectedly.  This will be
   * false otherwise, including when the drop has been rejected by its target.
   * This property is only relevant for the dragend event.
   */
  /* readonly attribute boolean mozUserCancelled; */
  NS_SCRIPTABLE NS_IMETHOD GetMozUserCancelled(PRBool *aMozUserCancelled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSDataTransfer, NS_IDOMNSDATATRANSFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSDATATRANSFER \
  NS_IMETHOD GetDropEffectInt(PRUint32 *aDropEffectInt); \
  NS_IMETHOD SetDropEffectInt(PRUint32 aDropEffectInt); \
  NS_IMETHOD GetEffectAllowedInt(PRUint32 *aEffectAllowedInt); \
  NS_IMETHOD SetEffectAllowedInt(PRUint32 aEffectAllowedInt); \
  NS_IMETHOD Clone(PRUint32 aEventType, PRBool aUserCancelled, nsIDOMDataTransfer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMozItemCount(PRUint32 *aMozItemCount); \
  NS_SCRIPTABLE NS_IMETHOD MozTypesAt(PRUint32 index, nsIDOMDOMStringList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MozClearDataAt(const nsAString & format, PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD MozGetDataAt(const nsAString & format, PRUint32 index, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMozUserCancelled(PRBool *aMozUserCancelled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSDATATRANSFER(_to) \
  NS_IMETHOD GetDropEffectInt(PRUint32 *aDropEffectInt) { return _to GetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD SetDropEffectInt(PRUint32 aDropEffectInt) { return _to SetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD GetEffectAllowedInt(PRUint32 *aEffectAllowedInt) { return _to GetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD SetEffectAllowedInt(PRUint32 aEffectAllowedInt) { return _to SetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD Clone(PRUint32 aEventType, PRBool aUserCancelled, nsIDOMDataTransfer **_retval NS_OUTPARAM) { return _to Clone(aEventType, aUserCancelled, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozItemCount(PRUint32 *aMozItemCount) { return _to GetMozItemCount(aMozItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD MozTypesAt(PRUint32 index, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return _to MozTypesAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozClearDataAt(const nsAString & format, PRUint32 index) { return _to MozClearDataAt(format, index); } \
  NS_SCRIPTABLE NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, PRUint32 index) { return _to MozSetDataAt(format, data, index); } \
  NS_SCRIPTABLE NS_IMETHOD MozGetDataAt(const nsAString & format, PRUint32 index, nsIVariant **_retval NS_OUTPARAM) { return _to MozGetDataAt(format, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozUserCancelled(PRBool *aMozUserCancelled) { return _to GetMozUserCancelled(aMozUserCancelled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSDATATRANSFER(_to) \
  NS_IMETHOD GetDropEffectInt(PRUint32 *aDropEffectInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD SetDropEffectInt(PRUint32 aDropEffectInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDropEffectInt(aDropEffectInt); } \
  NS_IMETHOD GetEffectAllowedInt(PRUint32 *aEffectAllowedInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD SetEffectAllowedInt(PRUint32 aEffectAllowedInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEffectAllowedInt(aEffectAllowedInt); } \
  NS_IMETHOD Clone(PRUint32 aEventType, PRBool aUserCancelled, nsIDOMDataTransfer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(aEventType, aUserCancelled, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozItemCount(PRUint32 *aMozItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozItemCount(aMozItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD MozTypesAt(PRUint32 index, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozTypesAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozClearDataAt(const nsAString & format, PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozClearDataAt(format, index); } \
  NS_SCRIPTABLE NS_IMETHOD MozSetDataAt(const nsAString & format, nsIVariant *data, PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetDataAt(format, data, index); } \
  NS_SCRIPTABLE NS_IMETHOD MozGetDataAt(const nsAString & format, PRUint32 index, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetDataAt(format, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozUserCancelled(PRBool *aMozUserCancelled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozUserCancelled(aMozUserCancelled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSDataTransfer : public nsIDOMNSDataTransfer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSDATATRANSFER

  nsDOMNSDataTransfer();

private:
  ~nsDOMNSDataTransfer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSDataTransfer, nsIDOMNSDataTransfer)

nsDOMNSDataTransfer::nsDOMNSDataTransfer()
{
  /* member initializers and constructor code */
}

nsDOMNSDataTransfer::~nsDOMNSDataTransfer()
{
  /* destructor code */
}

/* [noscript] attribute unsigned long dropEffectInt; */
NS_IMETHODIMP nsDOMNSDataTransfer::GetDropEffectInt(PRUint32 *aDropEffectInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDataTransfer::SetDropEffectInt(PRUint32 aDropEffectInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute unsigned long effectAllowedInt; */
NS_IMETHODIMP nsDOMNSDataTransfer::GetEffectAllowedInt(PRUint32 *aEffectAllowedInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDataTransfer::SetEffectAllowedInt(PRUint32 aEffectAllowedInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMDataTransfer clone (in PRUint32 aEventType, in PRBool aUserCancelled); */
NS_IMETHODIMP nsDOMNSDataTransfer::Clone(PRUint32 aEventType, PRBool aUserCancelled, nsIDOMDataTransfer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozItemCount; */
NS_IMETHODIMP nsDOMNSDataTransfer::GetMozItemCount(PRUint32 *aMozItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMStringList mozTypesAt (in unsigned long index); */
NS_IMETHODIMP nsDOMNSDataTransfer::MozTypesAt(PRUint32 index, nsIDOMDOMStringList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozClearDataAt (in DOMString format, in unsigned long index); */
NS_IMETHODIMP nsDOMNSDataTransfer::MozClearDataAt(const nsAString & format, PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozSetDataAt (in DOMString format, in nsIVariant data, in unsigned long index); */
NS_IMETHODIMP nsDOMNSDataTransfer::MozSetDataAt(const nsAString & format, nsIVariant *data, PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant mozGetDataAt (in DOMString format, in unsigned long index); */
NS_IMETHODIMP nsDOMNSDataTransfer::MozGetDataAt(const nsAString & format, PRUint32 index, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozUserCancelled; */
NS_IMETHODIMP nsDOMNSDataTransfer::GetMozUserCancelled(PRBool *aMozUserCancelled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMNSDataTransfer_MOZILLA_1_9_1 */
#define NS_IDOMNSDATATRANSFER_MOZILLA_1_9_1_IID_STR "a3d50078-13cf-4bef-b673-c3f25a41b9ca"

#define NS_IDOMNSDATATRANSFER_MOZILLA_1_9_1_IID \
  {0xa3d50078, 0x13cf, 0x4bef, \
    { 0xb6, 0x73, 0xc3, 0xf2, 0x5a, 0x41, 0xb9, 0xca }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSDataTransfer_MOZILLA_1_9_1 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSDATATRANSFER_MOZILLA_1_9_1_IID)

  /**
   * Sets the drag cursor state. Primarily used to control the cursor during
   * tab drags, but could be expanded to other uses. XXX Currently implemented
   * on Win32 only.
   *
   * Possible values:
   *  auto - use default system behavior.
   *  default - set the cursor to an arrow during the drag operation.
   *
   * Values other than 'default' are indentical to setting mozCursor to
   * 'auto'.
   */
  /* attribute DOMString mozCursor; */
  NS_SCRIPTABLE NS_IMETHOD GetMozCursor(nsAString & aMozCursor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMozCursor(const nsAString & aMozCursor) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSDataTransfer_MOZILLA_1_9_1, NS_IDOMNSDATATRANSFER_MOZILLA_1_9_1_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSDATATRANSFER_MOZILLA_1_9_1 \
  NS_SCRIPTABLE NS_IMETHOD GetMozCursor(nsAString & aMozCursor); \
  NS_SCRIPTABLE NS_IMETHOD SetMozCursor(const nsAString & aMozCursor); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSDATATRANSFER_MOZILLA_1_9_1(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozCursor(nsAString & aMozCursor) { return _to GetMozCursor(aMozCursor); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozCursor(const nsAString & aMozCursor) { return _to SetMozCursor(aMozCursor); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSDATATRANSFER_MOZILLA_1_9_1(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozCursor(nsAString & aMozCursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozCursor(aMozCursor); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozCursor(const nsAString & aMozCursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozCursor(aMozCursor); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSDataTransfer_MOZILLA_1_9_1 : public nsIDOMNSDataTransfer_MOZILLA_1_9_1
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSDATATRANSFER_MOZILLA_1_9_1

  nsDOMNSDataTransfer_MOZILLA_1_9_1();

private:
  ~nsDOMNSDataTransfer_MOZILLA_1_9_1();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSDataTransfer_MOZILLA_1_9_1, nsIDOMNSDataTransfer_MOZILLA_1_9_1)

nsDOMNSDataTransfer_MOZILLA_1_9_1::nsDOMNSDataTransfer_MOZILLA_1_9_1()
{
  /* member initializers and constructor code */
}

nsDOMNSDataTransfer_MOZILLA_1_9_1::~nsDOMNSDataTransfer_MOZILLA_1_9_1()
{
  /* destructor code */
}

/* attribute DOMString mozCursor; */
NS_IMETHODIMP nsDOMNSDataTransfer_MOZILLA_1_9_1::GetMozCursor(nsAString & aMozCursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDataTransfer_MOZILLA_1_9_1::SetMozCursor(const nsAString & aMozCursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataTransfer_h__ */
