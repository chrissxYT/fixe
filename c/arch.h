#if \
defined(__amd64__) \
|| defined(__amd64) \
|| defined(__x86_64__) \
|| defined(__x86_64) \
|| defined(_M_X64) \
|| defined(_M_AMD64)
#define X86 1
#define X64 1
#elif \
defined(i386) \
|| defined(__i386) \
|| defined(__i386__) \
|| defined(__IA32__) \
|| defined(_M_IX86) \
|| defined(__X86__) \
|| defined(_X86_) \
|| defined(__THW_INTEL__) \
|| defined(__I86__) \
|| defined(__INTEL__) \
|| defined(__386)
#define X86 1
#define X64 0
#else
#define X86 0
#define X64 0
#endif
