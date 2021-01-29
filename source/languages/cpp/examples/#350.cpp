#if DOCTEST_CLANG
    #ifdef __has_warning
        #define DOCTEST_CLANG_HAS_WARNING(x) __has_warning(x)
    #endif // __has_warning
    #ifdef __has_feature
        #define DOCTEST_CLANG_HAS_FEATURE(x) __has_feature(x)
    #endif // __has_feature
    #define DOCTEST_PRAGMA_TO_STR(x) _Pragma(#x)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_PUSH _Pragma("clang diagnostic push")
    #define DOCTEST_MSVC_SUPPRESS_WARNING_PUSH
    #define DOCTEST_GCC_SUPPRESS_WARNING_PUSH
    #define DOCTEST_CLANG_SUPPRESS_WARNING(w) DOCTEST_PRAGMA_TO_STR(clang diagnostic ignored w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING(w)
    #define DOCTEST_GCC_SUPPRESS_WARNING(w)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_POP _Pragma("clang diagnostic pop")
    #define DOCTEST_MSVC_SUPPRESS_WARNING_POP
    #define DOCTEST_GCC_SUPPRESS_WARNING_POP
    #define DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH(w)                                                \
        DOCTEST_CLANG_SUPPRESS_WARNING_PUSH DOCTEST_CLANG_SUPPRESS_WARNING(w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(w)
    #define DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH(w)
#elif DOCTEST_GCC
    #define DOCTEST_PRAGMA_TO_STR(x) _Pragma(#x)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_PUSH
    #define DOCTEST_MSVC_SUPPRESS_WARNING_PUSH
    #if DOCTEST_GCC >= DOCTEST_COMPILER(4, 7, 0)
        #define DOCTEST_GCC_SUPPRESS_WARNING_PUSH _Pragma("GCC diagnostic push")
    #else // GCC 4.7+
        #define DOCTEST_GCC_SUPPRESS_WARNING_PUSH
    #endif // GCC 4.7+
    #define DOCTEST_CLANG_SUPPRESS_WARNING(w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING(w)
    #define DOCTEST_GCC_SUPPRESS_WARNING(w) DOCTEST_PRAGMA_TO_STR(GCC diagnostic ignored w)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_POP
    #define DOCTEST_MSVC_SUPPRESS_WARNING_POP
    #if DOCTEST_GCC >= DOCTEST_COMPILER(4, 7, 0)
        #define DOCTEST_GCC_SUPPRESS_WARNING_POP _Pragma("GCC diagnostic pop")
    #else // GCC 4.7+
        #define DOCTEST_GCC_SUPPRESS_WARNING_POP
    #endif // GCC 4.7+
    #define DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH(w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(w)
    #define DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH(w)                                                  \
        DOCTEST_GCC_SUPPRESS_WARNING_PUSH DOCTEST_GCC_SUPPRESS_WARNING(w)
#elif DOCTEST_MSVC
    #define DOCTEST_PRAGMA_TO_STR(x)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_PUSH
    #define DOCTEST_MSVC_SUPPRESS_WARNING_PUSH __pragma(warning(push))
    #define DOCTEST_GCC_SUPPRESS_WARNING_PUSH
    #define DOCTEST_CLANG_SUPPRESS_WARNING(w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING(w) __pragma(warning(disable : w))
    #define DOCTEST_GCC_SUPPRESS_WARNING(w)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_POP
    #define DOCTEST_MSVC_SUPPRESS_WARNING_POP __pragma(warning(pop))
    #define DOCTEST_GCC_SUPPRESS_WARNING_POP
    #define DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH(w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(w)                                                 \
        DOCTEST_MSVC_SUPPRESS_WARNING_PUSH DOCTEST_MSVC_SUPPRESS_WARNING(w)
    #define DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH(w)
#else
    #define DOCTEST_PRAGMA_TO_STR(x)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_PUSH
    #define DOCTEST_MSVC_SUPPRESS_WARNING_PUSH 
    #define DOCTEST_GCC_SUPPRESS_WARNING_PUSH
    #define DOCTEST_CLANG_SUPPRESS_WARNING(w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING(w) 
    #define DOCTEST_GCC_SUPPRESS_WARNING(w)
    #define DOCTEST_CLANG_SUPPRESS_WARNING_POP
    #define DOCTEST_MSVC_SUPPRESS_WARNING_POP 
    #define DOCTEST_GCC_SUPPRESS_WARNING_POP
    #define DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH(w)
    #define DOCTEST_MSVC_SUPPRESS_WARNING_WITH_PUSH(w)
    #define DOCTEST_GCC_SUPPRESS_WARNING_WITH_PUSH(w)
#endif // different compilers - warning suppression macros
