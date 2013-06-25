/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsITimelineService.idl
 */

#ifndef __gen_nsITimelineService_h__
#define __gen_nsITimelineService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef MOZ_TIMELINE

/* starting interface:    nsITimelineService */
#define NS_ITIMELINESERVICE_IID_STR "93276790-3daf-11d5-b67d-000064657374"

#define NS_ITIMELINESERVICE_IID \
  {0x93276790, 0x3daf, 0x11d5, \
    { 0xb6, 0x7d, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

/**
 * nsITimelineService is used to construct a timeline of program
 * execution.  The timeline is output to a file, either stderr or the
 * value of the environment variable NS_TIMELINE_LOG_FILE.  On the
 * Mac, the timeline is output to the file named "timeline.txt".  The
 * reason it's different on the Mac is that the Mac environment
 * initialization code happens after timeline initialization code.
 * 
 * If NS_TIMELINE_INIT_TIME is set in the environment, that will be
 * used as the time of startup; otherwise the current time when mark()
 * is first called will be used.
 * 
 * mark() is used to put marks on the timeline.
 * 
 * indent() and outdent() are used to format the timeline a bit to
 * show nesting.  This doesn't produce perfect results in the face of
 * asychrony and multiple threads.
 * 
 * enter() and leave() are convenience functions that add marks to the
 * timeline and do indentation.
 * 
 * startTimer() and stopTimer() control named stop watches.  If
 * startTimer() is called more than once, an equal number of
 * stopTimer() calls are needed to actually stop the timer.  This
 * makes these timers slightly useful in a threaded environment.
 * 
 * markTimer() puts a mark on the timeline containing the total for
 * the named timer.
 * 
 * Don't use nsITimelineService in C++ code; use the NS_TIMELINE
 * macros instead.  nsITimelineService exists so that JavaScript code
 * can mark the timeline.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsITimelineService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMELINESERVICE_IID)

  /**
     * mark()
     * Print "<elapsed time>: <text>\n" in the timeline log file.
     */
  /* void mark (in string text); */
  NS_SCRIPTABLE NS_IMETHOD Mark(const char *text) = 0;

  /**
     * causes subsequent marks to be indented for a more readable
     * report.
     */
  /* void indent (); */
  NS_SCRIPTABLE NS_IMETHOD Indent(void) = 0;

  /**
     * Causes subsequent marks to be outdented.
     */
  /* void outdent (); */
  NS_SCRIPTABLE NS_IMETHOD Outdent(void) = 0;

  /**
     * enter/leave bracket code with "<text>..." and "...<text>" as
     * well as indentation.
     */
  /* void enter (in string text); */
  NS_SCRIPTABLE NS_IMETHOD Enter(const char *text) = 0;

  /* void leave (in string text); */
  NS_SCRIPTABLE NS_IMETHOD Leave(const char *text) = 0;

  /* void startTimer (in string timerName); */
  NS_SCRIPTABLE NS_IMETHOD StartTimer(const char *timerName) = 0;

  /* void stopTimer (in string timerName); */
  NS_SCRIPTABLE NS_IMETHOD StopTimer(const char *timerName) = 0;

  /* void markTimer (in string timerName); */
  NS_SCRIPTABLE NS_IMETHOD MarkTimer(const char *timerName) = 0;

  /* void resetTimer (in string timerName); */
  NS_SCRIPTABLE NS_IMETHOD ResetTimer(const char *timerName) = 0;

  /* void markTimerWithComment (in string timerName, in string comment); */
  NS_SCRIPTABLE NS_IMETHOD MarkTimerWithComment(const char *timerName, const char *comment) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimelineService, NS_ITIMELINESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMELINESERVICE \
  NS_SCRIPTABLE NS_IMETHOD Mark(const char *text); \
  NS_SCRIPTABLE NS_IMETHOD Indent(void); \
  NS_SCRIPTABLE NS_IMETHOD Outdent(void); \
  NS_SCRIPTABLE NS_IMETHOD Enter(const char *text); \
  NS_SCRIPTABLE NS_IMETHOD Leave(const char *text); \
  NS_SCRIPTABLE NS_IMETHOD StartTimer(const char *timerName); \
  NS_SCRIPTABLE NS_IMETHOD StopTimer(const char *timerName); \
  NS_SCRIPTABLE NS_IMETHOD MarkTimer(const char *timerName); \
  NS_SCRIPTABLE NS_IMETHOD ResetTimer(const char *timerName); \
  NS_SCRIPTABLE NS_IMETHOD MarkTimerWithComment(const char *timerName, const char *comment); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMELINESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Mark(const char *text) { return _to Mark(text); } \
  NS_SCRIPTABLE NS_IMETHOD Indent(void) { return _to Indent(); } \
  NS_SCRIPTABLE NS_IMETHOD Outdent(void) { return _to Outdent(); } \
  NS_SCRIPTABLE NS_IMETHOD Enter(const char *text) { return _to Enter(text); } \
  NS_SCRIPTABLE NS_IMETHOD Leave(const char *text) { return _to Leave(text); } \
  NS_SCRIPTABLE NS_IMETHOD StartTimer(const char *timerName) { return _to StartTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD StopTimer(const char *timerName) { return _to StopTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD MarkTimer(const char *timerName) { return _to MarkTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD ResetTimer(const char *timerName) { return _to ResetTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD MarkTimerWithComment(const char *timerName, const char *comment) { return _to MarkTimerWithComment(timerName, comment); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMELINESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Mark(const char *text) { return !_to ? NS_ERROR_NULL_POINTER : _to->Mark(text); } \
  NS_SCRIPTABLE NS_IMETHOD Indent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Indent(); } \
  NS_SCRIPTABLE NS_IMETHOD Outdent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Outdent(); } \
  NS_SCRIPTABLE NS_IMETHOD Enter(const char *text) { return !_to ? NS_ERROR_NULL_POINTER : _to->Enter(text); } \
  NS_SCRIPTABLE NS_IMETHOD Leave(const char *text) { return !_to ? NS_ERROR_NULL_POINTER : _to->Leave(text); } \
  NS_SCRIPTABLE NS_IMETHOD StartTimer(const char *timerName) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD StopTimer(const char *timerName) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD MarkTimer(const char *timerName) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD ResetTimer(const char *timerName) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetTimer(timerName); } \
  NS_SCRIPTABLE NS_IMETHOD MarkTimerWithComment(const char *timerName, const char *comment) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkTimerWithComment(timerName, comment); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimelineService : public nsITimelineService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMELINESERVICE

  nsTimelineService();

private:
  ~nsTimelineService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTimelineService, nsITimelineService)

nsTimelineService::nsTimelineService()
{
  /* member initializers and constructor code */
}

nsTimelineService::~nsTimelineService()
{
  /* destructor code */
}

/* void mark (in string text); */
NS_IMETHODIMP nsTimelineService::Mark(const char *text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void indent (); */
NS_IMETHODIMP nsTimelineService::Indent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void outdent (); */
NS_IMETHODIMP nsTimelineService::Outdent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enter (in string text); */
NS_IMETHODIMP nsTimelineService::Enter(const char *text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void leave (in string text); */
NS_IMETHODIMP nsTimelineService::Leave(const char *text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startTimer (in string timerName); */
NS_IMETHODIMP nsTimelineService::StartTimer(const char *timerName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopTimer (in string timerName); */
NS_IMETHODIMP nsTimelineService::StopTimer(const char *timerName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markTimer (in string timerName); */
NS_IMETHODIMP nsTimelineService::MarkTimer(const char *timerName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetTimer (in string timerName); */
NS_IMETHODIMP nsTimelineService::ResetTimer(const char *timerName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markTimerWithComment (in string timerName, in string comment); */
NS_IMETHODIMP nsTimelineService::MarkTimerWithComment(const char *timerName, const char *comment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#endif /* MOZ_TIMELINE */
#ifdef MOZ_TIMELINE
/*
 * These are equivalent to the corresponding nsITimelineService
 * methods, and can be called before XPCOM is initialized.
 */
extern "C" NS_COM nsresult NS_TimelineMark(const char *text, ...);
extern "C" NS_COM nsresult NS_TimelineForceMark(const char *text, ...);
extern "C" NS_COM nsresult NS_TimelineStartTimer(const char *timerName);
extern "C" NS_COM nsresult NS_TimelineStopTimer(const char *timerName);
extern "C" NS_COM nsresult NS_TimelineResetTimer(const char *timerName);
extern "C" NS_COM nsresult NS_TimelineMarkTimer(const char *timerName, const char *str=nsnull);
extern "C" NS_COM nsresult NS_TimelineIndent();
extern "C" NS_COM nsresult NS_TimelineOutdent();
extern "C" NS_COM nsresult NS_TimelineEnter(const char *text);
extern "C" NS_COM nsresult NS_TimelineLeave(const char *text);
/*
 * Use these macros for the above calls so we can easily compile them
 * out.
 */
#define NS_TIMELINE_MARK(text) NS_TimelineMark(text)
#define NS_TIMELINE_MARKV(args) NS_TimelineMark args
#define NS_TIMELINE_INDENT() NS_TimelineIndent()
#define NS_TIMELINE_OUTDENT() NS_TimelineOutdent()
#define NS_TIMELINE_ENTER(text) NS_TimelineEnter(text)
#define NS_TIMELINE_LEAVE(text) NS_TimelineLeave(text)
#define NS_TIMELINE_START_TIMER(timerName) NS_TimelineStartTimer(timerName)
#define NS_TIMELINE_STOP_TIMER(timerName) NS_TimelineStopTimer(timerName)
#define NS_TIMELINE_MARK_TIMER(timerName) NS_TimelineMarkTimer(timerName)
#define NS_TIMELINE_RESET_TIMER(timerName) NS_TimelineResetTimer(timerName)
#define NS_TIMELINE_MARK_TIMER1(timerName, str) NS_TimelineMarkTimer(timerName, str)
/*
 * Helper class to time functions. Use only static strings.
 */
class nsFunctionTimer {
public:
    const char *mTimer;
    PRBool mMark;
    const char *mMarkStr;
    nsFunctionTimer(const char *timer, PRBool mark = PR_TRUE, const char *markStr = nsnull)
        : mTimer(timer), mMark(mark), mMarkStr(markStr)
    {
        NS_TIMELINE_START_TIMER(mTimer);
    }
    ~nsFunctionTimer()
    {
        NS_TIMELINE_STOP_TIMER(mTimer);
        if (mMark)
            if (mMarkStr)
                NS_TIMELINE_MARK_TIMER1(mTimer, mMarkStr);
            else
                NS_TIMELINE_MARK_TIMER(mTimer);
    }
};
/*
 * NS_TIMELINE_MARK_ macros for various data types.  Each of these
 * macros replaces "%s" in its "text" argument with a string
 * representation of its last argument.
 * 
 * Please feel free to add more NS_TIMELINE_MARK_ macros for
 * various data types so that code using NS_TIMELINE is uncluttered.
 * Don't forget the empty versions in the #else section below for
 * non-timeline builds.
 */
#define NS_TIMELINE_MARK_URI(text, uri) \
    { \
        nsCAutoString spec; \
        if (uri) { \
            uri->GetSpec(spec); \
        } \
        if (!spec.IsEmpty()) { \
            NS_TimelineMark(text, spec.get()); \
        } else { \
            NS_TimelineMark(text, "??"); \
        } \
    }
#define NS_TIMELINE_MARK_CHANNEL(text, channel) \
    { \
        nsCOMPtr<nsIURI> uri; \
        if (channel) { \
            channel->GetURI(getter_AddRefs(uri)); \
        } \
        NS_TIMELINE_MARK_URI(text, uri); \
    }
#define NS_TIMELINE_MARK_LOADER(text, loader) \
    { \
        nsCOMPtr<nsIRequest> request; \
        loader->GetRequest(getter_AddRefs(request)); \
        nsCOMPtr<nsIChannel> channel(do_QueryInterface(request)); \
        NS_TIMELINE_MARK_CHANNEL(text, channel); \
    }
#define NS_TIMELINE_MARK_FUNCTION(timer) nsFunctionTimer functionTimer(timer)
#define NS_TIMELINE_MARK_FUNCTION1(timer, str) nsFunctionTimer functionTimer(timer, PR_TRUE, str)
#define NS_TIMELINE_TIME_FUNCTION(timer) nsFunctionTimer functionTimer(timer, PR_FALSE) /* no mark, only time */
#else /* !defined(MOZ_TIMELINE) */
#define NS_TIMELINE_MARK(text)
#define NS_TIMELINE_MARKV(args)
#define NS_TIMELINE_INDENT()
#define NS_TIMELINE_OUTDENT()
#define NS_TIMELINE_START_TIMER(timerName)
#define NS_TIMELINE_STOP_TIMER(timerName)
#define NS_TIMELINE_MARK_TIMER(timerName)
#define NS_TIMELINE_RESET_TIMER(timerName)
#define NS_TIMELINE_MARK_TIMER1(timerName, str)
#define NS_TIMELINE_ENTER(text)
#define NS_TIMELINE_LEAVE(text)
#define NS_TIMELINE_MARK_URI(text, uri)
#define NS_TIMELINE_MARK_FUNCTION(timer)
#define NS_TIMELINE_TIME_FUNCTION(timer)
#define NS_TIMELINE_MARK_CHANNEL(text, channel)
#define NS_TIMELINE_MARK_LOADER(text, loader);
#endif /* defined(MOZ_TIMELINE) */ 

#endif /* __gen_nsITimelineService_h__ */
