#ifndef UUID_AC36409666B843BE8900B7C226369163
#define UUID_AC36409666B843BE8900B7C226369163

#define PP_TOSTRING2(x) #x
#define PP_TOSTRING(x) PP_TOSTRING2(x)

#define PP_COMPILER_MESSAGE(msg)  __pragma(message("COMPILE-TIME MESSAGE: [" msg "]:(" __FILE__ ":" PP_TOSTRING(__LINE__) ":'"__FUNCTION__"')"))



#ifndef NDEBUG
# define ENABLE_DPRINTF
#endif


#ifdef ENABLE_DPRINTF

void LogOutput(const wchar_t * message, ...);

# define PP_DPRINTF LogOutput

#else
# define PP_DPRINTF __noop
#endif


#define PP_RETURNIF1(expression)                                  \
        { if (expression) {                                       \
            PP_DPRINTF(                                           \
            L"RETURNIF1:fun='%S'reason='%S'src='%S':%d",          \
              __FUNCTION__,                                       \
              PP_TOSTRING(expression),                            \
              __FILE__,                                           \
              __LINE__);                                          \
            return;                                               \
        }};

#define PP_RETURNIF2(expression, return_exp)                        \
        { if (expression) {                                         \
            PP_DPRINTF(                                             \
            L"RETURNIF2:fun='%S'reason='%S'result='%S'src='%S':%d", \
              __FUNCTION__,                                         \
              PP_TOSTRING(expression),                              \
              PP_TOSTRING(return_exp),                              \
              __FILE__,                                             \
              __LINE__);                                            \
            return (return_exp);                                    \
        }};


#endif