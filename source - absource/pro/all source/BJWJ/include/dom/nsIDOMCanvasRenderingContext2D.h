/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/canvas/nsIDOMCanvasRenderingContext2D.idl
 */

#ifndef __gen_nsIDOMCanvasRenderingContext2D_h__
#define __gen_nsIDOMCanvasRenderingContext2D_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMHTMLElement; /* forward declaration */

class nsIDOMHTMLImageElement; /* forward declaration */

class nsIDOMHTMLCanvasElement; /* forward declaration */


/* starting interface:    nsIDOMCanvasGradient */
#define NS_IDOMCANVASGRADIENT_IID_STR "bbb20a59-524e-4662-981e-5e142814b20c"

#define NS_IDOMCANVASGRADIENT_IID \
  {0xbbb20a59, 0x524e, 0x4662, \
    { 0x98, 0x1e, 0x5e, 0x14, 0x28, 0x14, 0xb2, 0x0c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCanvasGradient : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCANVASGRADIENT_IID)

  /* void addColorStop (in float offset, in DOMString color); */
  NS_SCRIPTABLE NS_IMETHOD AddColorStop(float offset, const nsAString & color) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCanvasGradient, NS_IDOMCANVASGRADIENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCANVASGRADIENT \
  NS_SCRIPTABLE NS_IMETHOD AddColorStop(float offset, const nsAString & color); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCANVASGRADIENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddColorStop(float offset, const nsAString & color) { return _to AddColorStop(offset, color); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCANVASGRADIENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddColorStop(float offset, const nsAString & color) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddColorStop(offset, color); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCanvasGradient : public nsIDOMCanvasGradient
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCANVASGRADIENT

  nsDOMCanvasGradient();

private:
  ~nsDOMCanvasGradient();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCanvasGradient, nsIDOMCanvasGradient)

nsDOMCanvasGradient::nsDOMCanvasGradient()
{
  /* member initializers and constructor code */
}

nsDOMCanvasGradient::~nsDOMCanvasGradient()
{
  /* destructor code */
}

/* void addColorStop (in float offset, in DOMString color); */
NS_IMETHODIMP nsDOMCanvasGradient::AddColorStop(float offset, const nsAString & color)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMCanvasPattern */
#define NS_IDOMCANVASPATTERN_IID_STR "21dea65c-5c08-4eb1-ac82-81fe95be77b8"

#define NS_IDOMCANVASPATTERN_IID \
  {0x21dea65c, 0x5c08, 0x4eb1, \
    { 0xac, 0x82, 0x81, 0xfe, 0x95, 0xbe, 0x77, 0xb8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCanvasPattern : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCANVASPATTERN_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCanvasPattern, NS_IDOMCANVASPATTERN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCANVASPATTERN \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCANVASPATTERN(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCANVASPATTERN(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCanvasPattern : public nsIDOMCanvasPattern
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCANVASPATTERN

  nsDOMCanvasPattern();

private:
  ~nsDOMCanvasPattern();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCanvasPattern, nsIDOMCanvasPattern)

nsDOMCanvasPattern::nsDOMCanvasPattern()
{
  /* member initializers and constructor code */
}

nsDOMCanvasPattern::~nsDOMCanvasPattern()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMTextMetrics */
#define NS_IDOMTEXTMETRICS_IID_STR "2d01715c-ec7d-424a-ab85-e0fd70c8665c"

#define NS_IDOMTEXTMETRICS_IID \
  {0x2d01715c, 0xec7d, 0x424a, \
    { 0xab, 0x85, 0xe0, 0xfd, 0x70, 0xc8, 0x66, 0x5c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMTextMetrics : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTEXTMETRICS_IID)

  /* readonly attribute float width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTextMetrics, NS_IDOMTEXTMETRICS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTEXTMETRICS \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTEXTMETRICS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) { return _to GetWidth(aWidth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTEXTMETRICS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(float *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTextMetrics : public nsIDOMTextMetrics
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTEXTMETRICS

  nsDOMTextMetrics();

private:
  ~nsDOMTextMetrics();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTextMetrics, nsIDOMTextMetrics)

nsDOMTextMetrics::nsDOMTextMetrics()
{
  /* member initializers and constructor code */
}

nsDOMTextMetrics::~nsDOMTextMetrics()
{
  /* destructor code */
}

/* readonly attribute float width; */
NS_IMETHODIMP nsDOMTextMetrics::GetWidth(float *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMCanvasRenderingContext2D */
#define NS_IDOMCANVASRENDERINGCONTEXT2D_IID_STR "66e6d87c-759c-43a7-b3d3-3348180b35df"

#define NS_IDOMCANVASRENDERINGCONTEXT2D_IID \
  {0x66e6d87c, 0x759c, 0x43a7, \
    { 0xb3, 0xd3, 0x33, 0x48, 0x18, 0x0b, 0x35, 0xdf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCanvasRenderingContext2D : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCANVASRENDERINGCONTEXT2D_IID)

  /* readonly attribute nsIDOMHTMLCanvasElement canvas; */
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement * *aCanvas) = 0;

  /* void save (); */
  NS_SCRIPTABLE NS_IMETHOD Save(void) = 0;

  /* void restore (); */
  NS_SCRIPTABLE NS_IMETHOD Restore(void) = 0;

  /* void scale (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD Scale(float x, float y) = 0;

  /* void rotate (in float angle); */
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle) = 0;

  /* void translate (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y) = 0;

  /* void transform (in float m11, in float m12, in float m21, in float m22, in float dx, in float dy); */
  NS_SCRIPTABLE NS_IMETHOD Transform(float m11, float m12, float m21, float m22, float dx, float dy) = 0;

  /* void setTransform (in float m11, in float m12, in float m21, in float m22, in float dx, in float dy); */
  NS_SCRIPTABLE NS_IMETHOD SetTransform(float m11, float m12, float m21, float m22, float dx, float dy) = 0;

  /* attribute float globalAlpha; */
  NS_SCRIPTABLE NS_IMETHOD GetGlobalAlpha(float *aGlobalAlpha) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGlobalAlpha(float aGlobalAlpha) = 0;

  /* attribute DOMString globalCompositeOperation; */
  NS_SCRIPTABLE NS_IMETHOD GetGlobalCompositeOperation(nsAString & aGlobalCompositeOperation) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGlobalCompositeOperation(const nsAString & aGlobalCompositeOperation) = 0;

  /* attribute nsIVariant strokeStyle; */
  NS_SCRIPTABLE NS_IMETHOD GetStrokeStyle(nsIVariant * *aStrokeStyle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStrokeStyle(nsIVariant * aStrokeStyle) = 0;

  /* attribute nsIVariant fillStyle; */
  NS_SCRIPTABLE NS_IMETHOD GetFillStyle(nsIVariant * *aFillStyle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFillStyle(nsIVariant * aFillStyle) = 0;

  /* nsIDOMCanvasGradient createLinearGradient (in float x0, in float y0, in float x1, in float y1); */
  NS_SCRIPTABLE NS_IMETHOD CreateLinearGradient(float x0, float y0, float x1, float y1, nsIDOMCanvasGradient **_retval NS_OUTPARAM) = 0;

  /* nsIDOMCanvasGradient createRadialGradient (in float x0, in float y0, in float r0, in float x1, in float y1, in float r1); */
  NS_SCRIPTABLE NS_IMETHOD CreateRadialGradient(float x0, float y0, float r0, float x1, float y1, float r1, nsIDOMCanvasGradient **_retval NS_OUTPARAM) = 0;

  /* nsIDOMCanvasPattern createPattern (in nsIDOMHTMLElement image, in DOMString repetition); */
  NS_SCRIPTABLE NS_IMETHOD CreatePattern(nsIDOMHTMLElement *image, const nsAString & repetition, nsIDOMCanvasPattern **_retval NS_OUTPARAM) = 0;

  /* attribute float lineWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetLineWidth(float *aLineWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLineWidth(float aLineWidth) = 0;

  /* attribute DOMString lineCap; */
  NS_SCRIPTABLE NS_IMETHOD GetLineCap(nsAString & aLineCap) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLineCap(const nsAString & aLineCap) = 0;

  /* attribute DOMString lineJoin; */
  NS_SCRIPTABLE NS_IMETHOD GetLineJoin(nsAString & aLineJoin) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLineJoin(const nsAString & aLineJoin) = 0;

  /* attribute float miterLimit; */
  NS_SCRIPTABLE NS_IMETHOD GetMiterLimit(float *aMiterLimit) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMiterLimit(float aMiterLimit) = 0;

  /* attribute float shadowOffsetX; */
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetX(float *aShadowOffsetX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetX(float aShadowOffsetX) = 0;

  /* attribute float shadowOffsetY; */
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetY(float *aShadowOffsetY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetY(float aShadowOffsetY) = 0;

  /* attribute float shadowBlur; */
  NS_SCRIPTABLE NS_IMETHOD GetShadowBlur(float *aShadowBlur) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShadowBlur(float aShadowBlur) = 0;

  /* attribute DOMString shadowColor; */
  NS_SCRIPTABLE NS_IMETHOD GetShadowColor(nsAString & aShadowColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShadowColor(const nsAString & aShadowColor) = 0;

  /* void clearRect (in float x, in float y, in float w, in float h); */
  NS_SCRIPTABLE NS_IMETHOD ClearRect(float x, float y, float w, float h) = 0;

  /* void fillRect (in float x, in float y, in float w, in float h); */
  NS_SCRIPTABLE NS_IMETHOD FillRect(float x, float y, float w, float h) = 0;

  /* void strokeRect (in float x, in float y, in float w, in float h); */
  NS_SCRIPTABLE NS_IMETHOD StrokeRect(float x, float y, float w, float h) = 0;

  /* void beginPath (); */
  NS_SCRIPTABLE NS_IMETHOD BeginPath(void) = 0;

  /* void closePath (); */
  NS_SCRIPTABLE NS_IMETHOD ClosePath(void) = 0;

  /* void moveTo (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD MoveTo(float x, float y) = 0;

  /* void lineTo (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD LineTo(float x, float y) = 0;

  /* void quadraticCurveTo (in float cpx, in float cpy, in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD QuadraticCurveTo(float cpx, float cpy, float x, float y) = 0;

  /* void bezierCurveTo (in float cp1x, in float cp1y, in float cp2x, in float cp2y, in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD BezierCurveTo(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) = 0;

  /* void arcTo (in float x1, in float y1, in float x2, in float y2, in float radius); */
  NS_SCRIPTABLE NS_IMETHOD ArcTo(float x1, float y1, float x2, float y2, float radius) = 0;

  /* void arc (in float x, in float y, in float r, in float startAngle, in float endAngle, in boolean clockwise); */
  NS_SCRIPTABLE NS_IMETHOD Arc(float x, float y, float r, float startAngle, float endAngle, PRBool clockwise) = 0;

  /* void rect (in float x, in float y, in float w, in float h); */
  NS_SCRIPTABLE NS_IMETHOD Rect(float x, float y, float w, float h) = 0;

  /* void fill (); */
  NS_SCRIPTABLE NS_IMETHOD Fill(void) = 0;

  /* void stroke (); */
  NS_SCRIPTABLE NS_IMETHOD Stroke(void) = 0;

  /* void clip (); */
  NS_SCRIPTABLE NS_IMETHOD Clip(void) = 0;

  /* attribute DOMString font; */
  NS_SCRIPTABLE NS_IMETHOD GetFont(nsAString & aFont) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFont(const nsAString & aFont) = 0;

  /* attribute DOMString textAlign; */
  NS_SCRIPTABLE NS_IMETHOD GetTextAlign(nsAString & aTextAlign) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTextAlign(const nsAString & aTextAlign) = 0;

  /* attribute DOMString textBaseline; */
  NS_SCRIPTABLE NS_IMETHOD GetTextBaseline(nsAString & aTextBaseline) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTextBaseline(const nsAString & aTextBaseline) = 0;

  /* void fillText (in DOMString text, in float x, in float y, [optional] in float maxWidth); */
  NS_SCRIPTABLE NS_IMETHOD FillText(const nsAString & text, float x, float y, float maxWidth) = 0;

  /* void strokeText (in DOMString text, in float x, in float y, [optional] in float maxWidth); */
  NS_SCRIPTABLE NS_IMETHOD StrokeText(const nsAString & text, float x, float y, float maxWidth) = 0;

  /* nsIDOMTextMetrics measureText (in DOMString text); */
  NS_SCRIPTABLE NS_IMETHOD MeasureText(const nsAString & text, nsIDOMTextMetrics **_retval NS_OUTPARAM) = 0;

  /* attribute DOMString mozTextStyle; */
  NS_SCRIPTABLE NS_IMETHOD GetMozTextStyle(nsAString & aMozTextStyle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMozTextStyle(const nsAString & aMozTextStyle) = 0;

  /* void mozDrawText (in DOMString textToDraw); */
  NS_SCRIPTABLE NS_IMETHOD MozDrawText(const nsAString & textToDraw) = 0;

  /* float mozMeasureText (in DOMString textToMeasure); */
  NS_SCRIPTABLE NS_IMETHOD MozMeasureText(const nsAString & textToMeasure, float *_retval NS_OUTPARAM) = 0;

  /* void mozPathText (in DOMString textToPath); */
  NS_SCRIPTABLE NS_IMETHOD MozPathText(const nsAString & textToPath) = 0;

  /* void mozTextAlongPath (in DOMString textToDraw, in boolean stroke); */
  NS_SCRIPTABLE NS_IMETHOD MozTextAlongPath(const nsAString & textToDraw, PRBool stroke) = 0;

  /* void drawImage (); */
  NS_SCRIPTABLE NS_IMETHOD DrawImage(void) = 0;

  /* boolean isPointInPath (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD IsPointInPath(float x, float y, PRBool *_retval NS_OUTPARAM) = 0;

  /* void getImageData (); */
  NS_SCRIPTABLE NS_IMETHOD GetImageData(void) = 0;

  /* void putImageData (); */
  NS_SCRIPTABLE NS_IMETHOD PutImageData(void) = 0;

  /* void createImageData (); */
  NS_SCRIPTABLE NS_IMETHOD CreateImageData(void) = 0;

  enum { DRAWWINDOW_DRAW_CARET = 1U };

  enum { DRAWWINDOW_DO_NOT_FLUSH = 2U };

  /**
   * Renders a region of a window into the canvas.  The contents of
   * the window's viewport are rendered, ignoring viewport clipping
   * and scrolling.
   *
   * @param x
   * @param y
   * @param w
   * @param h specify the area of the window to render, in CSS
   * pixels.
   *
   * @param backgroundColor the canvas is filled with this color
   * before we render the window into it. This color may be
   * transparent/translucent. It is given as a CSS color string
   * (e.g., rgb() or rgba()).
   *
   * @param flags Uused to better control the drawWindow call.
   * Flags can be ORed together.
   *
   * Of course, the rendering obeys the current scale, transform and
   * globalAlpha values.
   *
   * Hints:
   * -- If 'rgba(0,0,0,0)' is used for the background color, the
   * drawing will be transparent wherever the window is transparent.
   * -- Top-level browsed documents are usually not transparent
   * because the user's background-color preference is applied,
   * but IFRAMEs are transparent if the page doesn't set a background.
   * -- If an opaque color is used for the background color, rendering
   * will be faster because we won't have to compute the window's
   * transparency.
   *
   * This API cannot currently be used by Web content. It is chrome
   * only.
   */
  /* void drawWindow (in nsIDOMWindow window, in long x, in long y, in long w, in long h, in DOMString bgColor, [optional] in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD DrawWindow(nsIDOMWindow *window, PRInt32 x, PRInt32 y, PRInt32 w, PRInt32 h, const nsAString & bgColor, PRUint32 flags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCanvasRenderingContext2D, NS_IDOMCANVASRENDERINGCONTEXT2D_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCANVASRENDERINGCONTEXT2D \
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement * *aCanvas); \
  NS_SCRIPTABLE NS_IMETHOD Save(void); \
  NS_SCRIPTABLE NS_IMETHOD Restore(void); \
  NS_SCRIPTABLE NS_IMETHOD Scale(float x, float y); \
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle); \
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y); \
  NS_SCRIPTABLE NS_IMETHOD Transform(float m11, float m12, float m21, float m22, float dx, float dy); \
  NS_SCRIPTABLE NS_IMETHOD SetTransform(float m11, float m12, float m21, float m22, float dx, float dy); \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalAlpha(float *aGlobalAlpha); \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalAlpha(float aGlobalAlpha); \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalCompositeOperation(nsAString & aGlobalCompositeOperation); \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalCompositeOperation(const nsAString & aGlobalCompositeOperation); \
  NS_SCRIPTABLE NS_IMETHOD GetStrokeStyle(nsIVariant * *aStrokeStyle); \
  NS_SCRIPTABLE NS_IMETHOD SetStrokeStyle(nsIVariant * aStrokeStyle); \
  NS_SCRIPTABLE NS_IMETHOD GetFillStyle(nsIVariant * *aFillStyle); \
  NS_SCRIPTABLE NS_IMETHOD SetFillStyle(nsIVariant * aFillStyle); \
  NS_SCRIPTABLE NS_IMETHOD CreateLinearGradient(float x0, float y0, float x1, float y1, nsIDOMCanvasGradient **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateRadialGradient(float x0, float y0, float r0, float x1, float y1, float r1, nsIDOMCanvasGradient **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreatePattern(nsIDOMHTMLElement *image, const nsAString & repetition, nsIDOMCanvasPattern **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLineWidth(float *aLineWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetLineWidth(float aLineWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetLineCap(nsAString & aLineCap); \
  NS_SCRIPTABLE NS_IMETHOD SetLineCap(const nsAString & aLineCap); \
  NS_SCRIPTABLE NS_IMETHOD GetLineJoin(nsAString & aLineJoin); \
  NS_SCRIPTABLE NS_IMETHOD SetLineJoin(const nsAString & aLineJoin); \
  NS_SCRIPTABLE NS_IMETHOD GetMiterLimit(float *aMiterLimit); \
  NS_SCRIPTABLE NS_IMETHOD SetMiterLimit(float aMiterLimit); \
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetX(float *aShadowOffsetX); \
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetX(float aShadowOffsetX); \
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetY(float *aShadowOffsetY); \
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetY(float aShadowOffsetY); \
  NS_SCRIPTABLE NS_IMETHOD GetShadowBlur(float *aShadowBlur); \
  NS_SCRIPTABLE NS_IMETHOD SetShadowBlur(float aShadowBlur); \
  NS_SCRIPTABLE NS_IMETHOD GetShadowColor(nsAString & aShadowColor); \
  NS_SCRIPTABLE NS_IMETHOD SetShadowColor(const nsAString & aShadowColor); \
  NS_SCRIPTABLE NS_IMETHOD ClearRect(float x, float y, float w, float h); \
  NS_SCRIPTABLE NS_IMETHOD FillRect(float x, float y, float w, float h); \
  NS_SCRIPTABLE NS_IMETHOD StrokeRect(float x, float y, float w, float h); \
  NS_SCRIPTABLE NS_IMETHOD BeginPath(void); \
  NS_SCRIPTABLE NS_IMETHOD ClosePath(void); \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(float x, float y); \
  NS_SCRIPTABLE NS_IMETHOD LineTo(float x, float y); \
  NS_SCRIPTABLE NS_IMETHOD QuadraticCurveTo(float cpx, float cpy, float x, float y); \
  NS_SCRIPTABLE NS_IMETHOD BezierCurveTo(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y); \
  NS_SCRIPTABLE NS_IMETHOD ArcTo(float x1, float y1, float x2, float y2, float radius); \
  NS_SCRIPTABLE NS_IMETHOD Arc(float x, float y, float r, float startAngle, float endAngle, PRBool clockwise); \
  NS_SCRIPTABLE NS_IMETHOD Rect(float x, float y, float w, float h); \
  NS_SCRIPTABLE NS_IMETHOD Fill(void); \
  NS_SCRIPTABLE NS_IMETHOD Stroke(void); \
  NS_SCRIPTABLE NS_IMETHOD Clip(void); \
  NS_SCRIPTABLE NS_IMETHOD GetFont(nsAString & aFont); \
  NS_SCRIPTABLE NS_IMETHOD SetFont(const nsAString & aFont); \
  NS_SCRIPTABLE NS_IMETHOD GetTextAlign(nsAString & aTextAlign); \
  NS_SCRIPTABLE NS_IMETHOD SetTextAlign(const nsAString & aTextAlign); \
  NS_SCRIPTABLE NS_IMETHOD GetTextBaseline(nsAString & aTextBaseline); \
  NS_SCRIPTABLE NS_IMETHOD SetTextBaseline(const nsAString & aTextBaseline); \
  NS_SCRIPTABLE NS_IMETHOD FillText(const nsAString & text, float x, float y, float maxWidth); \
  NS_SCRIPTABLE NS_IMETHOD StrokeText(const nsAString & text, float x, float y, float maxWidth); \
  NS_SCRIPTABLE NS_IMETHOD MeasureText(const nsAString & text, nsIDOMTextMetrics **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMozTextStyle(nsAString & aMozTextStyle); \
  NS_SCRIPTABLE NS_IMETHOD SetMozTextStyle(const nsAString & aMozTextStyle); \
  NS_SCRIPTABLE NS_IMETHOD MozDrawText(const nsAString & textToDraw); \
  NS_SCRIPTABLE NS_IMETHOD MozMeasureText(const nsAString & textToMeasure, float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MozPathText(const nsAString & textToPath); \
  NS_SCRIPTABLE NS_IMETHOD MozTextAlongPath(const nsAString & textToDraw, PRBool stroke); \
  NS_SCRIPTABLE NS_IMETHOD DrawImage(void); \
  NS_SCRIPTABLE NS_IMETHOD IsPointInPath(float x, float y, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetImageData(void); \
  NS_SCRIPTABLE NS_IMETHOD PutImageData(void); \
  NS_SCRIPTABLE NS_IMETHOD CreateImageData(void); \
  NS_SCRIPTABLE NS_IMETHOD DrawWindow(nsIDOMWindow *window, PRInt32 x, PRInt32 y, PRInt32 w, PRInt32 h, const nsAString & bgColor, PRUint32 flags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCANVASRENDERINGCONTEXT2D(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement * *aCanvas) { return _to GetCanvas(aCanvas); } \
  NS_SCRIPTABLE NS_IMETHOD Save(void) { return _to Save(); } \
  NS_SCRIPTABLE NS_IMETHOD Restore(void) { return _to Restore(); } \
  NS_SCRIPTABLE NS_IMETHOD Scale(float x, float y) { return _to Scale(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle) { return _to Rotate(angle); } \
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y) { return _to Translate(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Transform(float m11, float m12, float m21, float m22, float dx, float dy) { return _to Transform(m11, m12, m21, m22, dx, dy); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransform(float m11, float m12, float m21, float m22, float dx, float dy) { return _to SetTransform(m11, m12, m21, m22, dx, dy); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalAlpha(float *aGlobalAlpha) { return _to GetGlobalAlpha(aGlobalAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalAlpha(float aGlobalAlpha) { return _to SetGlobalAlpha(aGlobalAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalCompositeOperation(nsAString & aGlobalCompositeOperation) { return _to GetGlobalCompositeOperation(aGlobalCompositeOperation); } \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalCompositeOperation(const nsAString & aGlobalCompositeOperation) { return _to SetGlobalCompositeOperation(aGlobalCompositeOperation); } \
  NS_SCRIPTABLE NS_IMETHOD GetStrokeStyle(nsIVariant * *aStrokeStyle) { return _to GetStrokeStyle(aStrokeStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetStrokeStyle(nsIVariant * aStrokeStyle) { return _to SetStrokeStyle(aStrokeStyle); } \
  NS_SCRIPTABLE NS_IMETHOD GetFillStyle(nsIVariant * *aFillStyle) { return _to GetFillStyle(aFillStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetFillStyle(nsIVariant * aFillStyle) { return _to SetFillStyle(aFillStyle); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLinearGradient(float x0, float y0, float x1, float y1, nsIDOMCanvasGradient **_retval NS_OUTPARAM) { return _to CreateLinearGradient(x0, y0, x1, y1, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateRadialGradient(float x0, float y0, float r0, float x1, float y1, float r1, nsIDOMCanvasGradient **_retval NS_OUTPARAM) { return _to CreateRadialGradient(x0, y0, r0, x1, y1, r1, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreatePattern(nsIDOMHTMLElement *image, const nsAString & repetition, nsIDOMCanvasPattern **_retval NS_OUTPARAM) { return _to CreatePattern(image, repetition, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineWidth(float *aLineWidth) { return _to GetLineWidth(aLineWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetLineWidth(float aLineWidth) { return _to SetLineWidth(aLineWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineCap(nsAString & aLineCap) { return _to GetLineCap(aLineCap); } \
  NS_SCRIPTABLE NS_IMETHOD SetLineCap(const nsAString & aLineCap) { return _to SetLineCap(aLineCap); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineJoin(nsAString & aLineJoin) { return _to GetLineJoin(aLineJoin); } \
  NS_SCRIPTABLE NS_IMETHOD SetLineJoin(const nsAString & aLineJoin) { return _to SetLineJoin(aLineJoin); } \
  NS_SCRIPTABLE NS_IMETHOD GetMiterLimit(float *aMiterLimit) { return _to GetMiterLimit(aMiterLimit); } \
  NS_SCRIPTABLE NS_IMETHOD SetMiterLimit(float aMiterLimit) { return _to SetMiterLimit(aMiterLimit); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetX(float *aShadowOffsetX) { return _to GetShadowOffsetX(aShadowOffsetX); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetX(float aShadowOffsetX) { return _to SetShadowOffsetX(aShadowOffsetX); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetY(float *aShadowOffsetY) { return _to GetShadowOffsetY(aShadowOffsetY); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetY(float aShadowOffsetY) { return _to SetShadowOffsetY(aShadowOffsetY); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowBlur(float *aShadowBlur) { return _to GetShadowBlur(aShadowBlur); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowBlur(float aShadowBlur) { return _to SetShadowBlur(aShadowBlur); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowColor(nsAString & aShadowColor) { return _to GetShadowColor(aShadowColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowColor(const nsAString & aShadowColor) { return _to SetShadowColor(aShadowColor); } \
  NS_SCRIPTABLE NS_IMETHOD ClearRect(float x, float y, float w, float h) { return _to ClearRect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD FillRect(float x, float y, float w, float h) { return _to FillRect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD StrokeRect(float x, float y, float w, float h) { return _to StrokeRect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD BeginPath(void) { return _to BeginPath(); } \
  NS_SCRIPTABLE NS_IMETHOD ClosePath(void) { return _to ClosePath(); } \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(float x, float y) { return _to MoveTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD LineTo(float x, float y) { return _to LineTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD QuadraticCurveTo(float cpx, float cpy, float x, float y) { return _to QuadraticCurveTo(cpx, cpy, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD BezierCurveTo(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) { return _to BezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD ArcTo(float x1, float y1, float x2, float y2, float radius) { return _to ArcTo(x1, y1, x2, y2, radius); } \
  NS_SCRIPTABLE NS_IMETHOD Arc(float x, float y, float r, float startAngle, float endAngle, PRBool clockwise) { return _to Arc(x, y, r, startAngle, endAngle, clockwise); } \
  NS_SCRIPTABLE NS_IMETHOD Rect(float x, float y, float w, float h) { return _to Rect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD Fill(void) { return _to Fill(); } \
  NS_SCRIPTABLE NS_IMETHOD Stroke(void) { return _to Stroke(); } \
  NS_SCRIPTABLE NS_IMETHOD Clip(void) { return _to Clip(); } \
  NS_SCRIPTABLE NS_IMETHOD GetFont(nsAString & aFont) { return _to GetFont(aFont); } \
  NS_SCRIPTABLE NS_IMETHOD SetFont(const nsAString & aFont) { return _to SetFont(aFont); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextAlign(nsAString & aTextAlign) { return _to GetTextAlign(aTextAlign); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextAlign(const nsAString & aTextAlign) { return _to SetTextAlign(aTextAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextBaseline(nsAString & aTextBaseline) { return _to GetTextBaseline(aTextBaseline); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextBaseline(const nsAString & aTextBaseline) { return _to SetTextBaseline(aTextBaseline); } \
  NS_SCRIPTABLE NS_IMETHOD FillText(const nsAString & text, float x, float y, float maxWidth) { return _to FillText(text, x, y, maxWidth); } \
  NS_SCRIPTABLE NS_IMETHOD StrokeText(const nsAString & text, float x, float y, float maxWidth) { return _to StrokeText(text, x, y, maxWidth); } \
  NS_SCRIPTABLE NS_IMETHOD MeasureText(const nsAString & text, nsIDOMTextMetrics **_retval NS_OUTPARAM) { return _to MeasureText(text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozTextStyle(nsAString & aMozTextStyle) { return _to GetMozTextStyle(aMozTextStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozTextStyle(const nsAString & aMozTextStyle) { return _to SetMozTextStyle(aMozTextStyle); } \
  NS_SCRIPTABLE NS_IMETHOD MozDrawText(const nsAString & textToDraw) { return _to MozDrawText(textToDraw); } \
  NS_SCRIPTABLE NS_IMETHOD MozMeasureText(const nsAString & textToMeasure, float *_retval NS_OUTPARAM) { return _to MozMeasureText(textToMeasure, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozPathText(const nsAString & textToPath) { return _to MozPathText(textToPath); } \
  NS_SCRIPTABLE NS_IMETHOD MozTextAlongPath(const nsAString & textToDraw, PRBool stroke) { return _to MozTextAlongPath(textToDraw, stroke); } \
  NS_SCRIPTABLE NS_IMETHOD DrawImage(void) { return _to DrawImage(); } \
  NS_SCRIPTABLE NS_IMETHOD IsPointInPath(float x, float y, PRBool *_retval NS_OUTPARAM) { return _to IsPointInPath(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageData(void) { return _to GetImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD PutImageData(void) { return _to PutImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD CreateImageData(void) { return _to CreateImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD DrawWindow(nsIDOMWindow *window, PRInt32 x, PRInt32 y, PRInt32 w, PRInt32 h, const nsAString & bgColor, PRUint32 flags) { return _to DrawWindow(window, x, y, w, h, bgColor, flags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCANVASRENDERINGCONTEXT2D(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCanvas(nsIDOMHTMLCanvasElement * *aCanvas) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanvas(aCanvas); } \
  NS_SCRIPTABLE NS_IMETHOD Save(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Save(); } \
  NS_SCRIPTABLE NS_IMETHOD Restore(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Restore(); } \
  NS_SCRIPTABLE NS_IMETHOD Scale(float x, float y) { return !_to ? NS_ERROR_NULL_POINTER : _to->Scale(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rotate(angle); } \
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y) { return !_to ? NS_ERROR_NULL_POINTER : _to->Translate(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD Transform(float m11, float m12, float m21, float m22, float dx, float dy) { return !_to ? NS_ERROR_NULL_POINTER : _to->Transform(m11, m12, m21, m22, dx, dy); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransform(float m11, float m12, float m21, float m22, float dx, float dy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransform(m11, m12, m21, m22, dx, dy); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalAlpha(float *aGlobalAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalAlpha(aGlobalAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalAlpha(float aGlobalAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGlobalAlpha(aGlobalAlpha); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalCompositeOperation(nsAString & aGlobalCompositeOperation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalCompositeOperation(aGlobalCompositeOperation); } \
  NS_SCRIPTABLE NS_IMETHOD SetGlobalCompositeOperation(const nsAString & aGlobalCompositeOperation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGlobalCompositeOperation(aGlobalCompositeOperation); } \
  NS_SCRIPTABLE NS_IMETHOD GetStrokeStyle(nsIVariant * *aStrokeStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStrokeStyle(aStrokeStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetStrokeStyle(nsIVariant * aStrokeStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStrokeStyle(aStrokeStyle); } \
  NS_SCRIPTABLE NS_IMETHOD GetFillStyle(nsIVariant * *aFillStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFillStyle(aFillStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetFillStyle(nsIVariant * aFillStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFillStyle(aFillStyle); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLinearGradient(float x0, float y0, float x1, float y1, nsIDOMCanvasGradient **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLinearGradient(x0, y0, x1, y1, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateRadialGradient(float x0, float y0, float r0, float x1, float y1, float r1, nsIDOMCanvasGradient **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateRadialGradient(x0, y0, r0, x1, y1, r1, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreatePattern(nsIDOMHTMLElement *image, const nsAString & repetition, nsIDOMCanvasPattern **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreatePattern(image, repetition, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineWidth(float *aLineWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineWidth(aLineWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetLineWidth(float aLineWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLineWidth(aLineWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineCap(nsAString & aLineCap) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineCap(aLineCap); } \
  NS_SCRIPTABLE NS_IMETHOD SetLineCap(const nsAString & aLineCap) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLineCap(aLineCap); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineJoin(nsAString & aLineJoin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineJoin(aLineJoin); } \
  NS_SCRIPTABLE NS_IMETHOD SetLineJoin(const nsAString & aLineJoin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLineJoin(aLineJoin); } \
  NS_SCRIPTABLE NS_IMETHOD GetMiterLimit(float *aMiterLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMiterLimit(aMiterLimit); } \
  NS_SCRIPTABLE NS_IMETHOD SetMiterLimit(float aMiterLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMiterLimit(aMiterLimit); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetX(float *aShadowOffsetX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShadowOffsetX(aShadowOffsetX); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetX(float aShadowOffsetX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShadowOffsetX(aShadowOffsetX); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowOffsetY(float *aShadowOffsetY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShadowOffsetY(aShadowOffsetY); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowOffsetY(float aShadowOffsetY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShadowOffsetY(aShadowOffsetY); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowBlur(float *aShadowBlur) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShadowBlur(aShadowBlur); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowBlur(float aShadowBlur) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShadowBlur(aShadowBlur); } \
  NS_SCRIPTABLE NS_IMETHOD GetShadowColor(nsAString & aShadowColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShadowColor(aShadowColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetShadowColor(const nsAString & aShadowColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShadowColor(aShadowColor); } \
  NS_SCRIPTABLE NS_IMETHOD ClearRect(float x, float y, float w, float h) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearRect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD FillRect(float x, float y, float w, float h) { return !_to ? NS_ERROR_NULL_POINTER : _to->FillRect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD StrokeRect(float x, float y, float w, float h) { return !_to ? NS_ERROR_NULL_POINTER : _to->StrokeRect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD BeginPath(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginPath(); } \
  NS_SCRIPTABLE NS_IMETHOD ClosePath(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClosePath(); } \
  NS_SCRIPTABLE NS_IMETHOD MoveTo(float x, float y) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD LineTo(float x, float y) { return !_to ? NS_ERROR_NULL_POINTER : _to->LineTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD QuadraticCurveTo(float cpx, float cpy, float x, float y) { return !_to ? NS_ERROR_NULL_POINTER : _to->QuadraticCurveTo(cpx, cpy, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD BezierCurveTo(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) { return !_to ? NS_ERROR_NULL_POINTER : _to->BezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD ArcTo(float x1, float y1, float x2, float y2, float radius) { return !_to ? NS_ERROR_NULL_POINTER : _to->ArcTo(x1, y1, x2, y2, radius); } \
  NS_SCRIPTABLE NS_IMETHOD Arc(float x, float y, float r, float startAngle, float endAngle, PRBool clockwise) { return !_to ? NS_ERROR_NULL_POINTER : _to->Arc(x, y, r, startAngle, endAngle, clockwise); } \
  NS_SCRIPTABLE NS_IMETHOD Rect(float x, float y, float w, float h) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rect(x, y, w, h); } \
  NS_SCRIPTABLE NS_IMETHOD Fill(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Fill(); } \
  NS_SCRIPTABLE NS_IMETHOD Stroke(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stroke(); } \
  NS_SCRIPTABLE NS_IMETHOD Clip(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clip(); } \
  NS_SCRIPTABLE NS_IMETHOD GetFont(nsAString & aFont) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFont(aFont); } \
  NS_SCRIPTABLE NS_IMETHOD SetFont(const nsAString & aFont) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFont(aFont); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextAlign(nsAString & aTextAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextAlign(aTextAlign); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextAlign(const nsAString & aTextAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextAlign(aTextAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextBaseline(nsAString & aTextBaseline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextBaseline(aTextBaseline); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextBaseline(const nsAString & aTextBaseline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextBaseline(aTextBaseline); } \
  NS_SCRIPTABLE NS_IMETHOD FillText(const nsAString & text, float x, float y, float maxWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->FillText(text, x, y, maxWidth); } \
  NS_SCRIPTABLE NS_IMETHOD StrokeText(const nsAString & text, float x, float y, float maxWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->StrokeText(text, x, y, maxWidth); } \
  NS_SCRIPTABLE NS_IMETHOD MeasureText(const nsAString & text, nsIDOMTextMetrics **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MeasureText(text, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozTextStyle(nsAString & aMozTextStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozTextStyle(aMozTextStyle); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozTextStyle(const nsAString & aMozTextStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozTextStyle(aMozTextStyle); } \
  NS_SCRIPTABLE NS_IMETHOD MozDrawText(const nsAString & textToDraw) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozDrawText(textToDraw); } \
  NS_SCRIPTABLE NS_IMETHOD MozMeasureText(const nsAString & textToMeasure, float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozMeasureText(textToMeasure, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozPathText(const nsAString & textToPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozPathText(textToPath); } \
  NS_SCRIPTABLE NS_IMETHOD MozTextAlongPath(const nsAString & textToDraw, PRBool stroke) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozTextAlongPath(textToDraw, stroke); } \
  NS_SCRIPTABLE NS_IMETHOD DrawImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawImage(); } \
  NS_SCRIPTABLE NS_IMETHOD IsPointInPath(float x, float y, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPointInPath(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD PutImageData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD CreateImageData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD DrawWindow(nsIDOMWindow *window, PRInt32 x, PRInt32 y, PRInt32 w, PRInt32 h, const nsAString & bgColor, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawWindow(window, x, y, w, h, bgColor, flags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCanvasRenderingContext2D : public nsIDOMCanvasRenderingContext2D
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCANVASRENDERINGCONTEXT2D

  nsDOMCanvasRenderingContext2D();

private:
  ~nsDOMCanvasRenderingContext2D();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCanvasRenderingContext2D, nsIDOMCanvasRenderingContext2D)

nsDOMCanvasRenderingContext2D::nsDOMCanvasRenderingContext2D()
{
  /* member initializers and constructor code */
}

nsDOMCanvasRenderingContext2D::~nsDOMCanvasRenderingContext2D()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLCanvasElement canvas; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetCanvas(nsIDOMHTMLCanvasElement * *aCanvas)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void save (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Save()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restore (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Restore()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scale (in float x, in float y); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Scale(float x, float y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rotate (in float angle); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Rotate(float angle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void translate (in float x, in float y); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Translate(float x, float y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void transform (in float m11, in float m12, in float m21, in float m22, in float dx, in float dy); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Transform(float m11, float m12, float m21, float m22, float dx, float dy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTransform (in float m11, in float m12, in float m21, in float m22, in float dx, in float dy); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetTransform(float m11, float m12, float m21, float m22, float dx, float dy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float globalAlpha; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetGlobalAlpha(float *aGlobalAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetGlobalAlpha(float aGlobalAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString globalCompositeOperation; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetGlobalCompositeOperation(nsAString & aGlobalCompositeOperation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetGlobalCompositeOperation(const nsAString & aGlobalCompositeOperation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant strokeStyle; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetStrokeStyle(nsIVariant * *aStrokeStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetStrokeStyle(nsIVariant * aStrokeStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant fillStyle; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetFillStyle(nsIVariant * *aFillStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetFillStyle(nsIVariant * aFillStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCanvasGradient createLinearGradient (in float x0, in float y0, in float x1, in float y1); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::CreateLinearGradient(float x0, float y0, float x1, float y1, nsIDOMCanvasGradient **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCanvasGradient createRadialGradient (in float x0, in float y0, in float r0, in float x1, in float y1, in float r1); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::CreateRadialGradient(float x0, float y0, float r0, float x1, float y1, float r1, nsIDOMCanvasGradient **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCanvasPattern createPattern (in nsIDOMHTMLElement image, in DOMString repetition); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::CreatePattern(nsIDOMHTMLElement *image, const nsAString & repetition, nsIDOMCanvasPattern **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float lineWidth; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetLineWidth(float *aLineWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetLineWidth(float aLineWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString lineCap; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetLineCap(nsAString & aLineCap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetLineCap(const nsAString & aLineCap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString lineJoin; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetLineJoin(nsAString & aLineJoin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetLineJoin(const nsAString & aLineJoin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float miterLimit; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetMiterLimit(float *aMiterLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetMiterLimit(float aMiterLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float shadowOffsetX; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetShadowOffsetX(float *aShadowOffsetX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetShadowOffsetX(float aShadowOffsetX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float shadowOffsetY; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetShadowOffsetY(float *aShadowOffsetY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetShadowOffsetY(float aShadowOffsetY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float shadowBlur; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetShadowBlur(float *aShadowBlur)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetShadowBlur(float aShadowBlur)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString shadowColor; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetShadowColor(nsAString & aShadowColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetShadowColor(const nsAString & aShadowColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearRect (in float x, in float y, in float w, in float h); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::ClearRect(float x, float y, float w, float h)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fillRect (in float x, in float y, in float w, in float h); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::FillRect(float x, float y, float w, float h)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void strokeRect (in float x, in float y, in float w, in float h); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::StrokeRect(float x, float y, float w, float h)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginPath (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::BeginPath()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closePath (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::ClosePath()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveTo (in float x, in float y); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::MoveTo(float x, float y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lineTo (in float x, in float y); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::LineTo(float x, float y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void quadraticCurveTo (in float cpx, in float cpy, in float x, in float y); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::QuadraticCurveTo(float cpx, float cpy, float x, float y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bezierCurveTo (in float cp1x, in float cp1y, in float cp2x, in float cp2y, in float x, in float y); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::BezierCurveTo(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void arcTo (in float x1, in float y1, in float x2, in float y2, in float radius); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::ArcTo(float x1, float y1, float x2, float y2, float radius)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void arc (in float x, in float y, in float r, in float startAngle, in float endAngle, in boolean clockwise); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Arc(float x, float y, float r, float startAngle, float endAngle, PRBool clockwise)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rect (in float x, in float y, in float w, in float h); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Rect(float x, float y, float w, float h)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fill (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Fill()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stroke (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Stroke()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clip (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::Clip()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString font; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetFont(nsAString & aFont)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetFont(const nsAString & aFont)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString textAlign; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetTextAlign(nsAString & aTextAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetTextAlign(const nsAString & aTextAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString textBaseline; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetTextBaseline(nsAString & aTextBaseline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetTextBaseline(const nsAString & aTextBaseline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fillText (in DOMString text, in float x, in float y, [optional] in float maxWidth); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::FillText(const nsAString & text, float x, float y, float maxWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void strokeText (in DOMString text, in float x, in float y, [optional] in float maxWidth); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::StrokeText(const nsAString & text, float x, float y, float maxWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMTextMetrics measureText (in DOMString text); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::MeasureText(const nsAString & text, nsIDOMTextMetrics **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString mozTextStyle; */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetMozTextStyle(nsAString & aMozTextStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::SetMozTextStyle(const nsAString & aMozTextStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozDrawText (in DOMString textToDraw); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::MozDrawText(const nsAString & textToDraw)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float mozMeasureText (in DOMString textToMeasure); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::MozMeasureText(const nsAString & textToMeasure, float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozPathText (in DOMString textToPath); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::MozPathText(const nsAString & textToPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozTextAlongPath (in DOMString textToDraw, in boolean stroke); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::MozTextAlongPath(const nsAString & textToDraw, PRBool stroke)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void drawImage (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::DrawImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPointInPath (in float x, in float y); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::IsPointInPath(float x, float y, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getImageData (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::GetImageData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putImageData (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::PutImageData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createImageData (); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::CreateImageData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void drawWindow (in nsIDOMWindow window, in long x, in long y, in long w, in long h, in DOMString bgColor, [optional] in unsigned long flags); */
NS_IMETHODIMP nsDOMCanvasRenderingContext2D::DrawWindow(nsIDOMWindow *window, PRInt32 x, PRInt32 y, PRInt32 w, PRInt32 h, const nsAString & bgColor, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCanvasRenderingContext2D_h__ */
