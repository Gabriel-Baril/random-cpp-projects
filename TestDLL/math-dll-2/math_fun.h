#pragma once

#ifdef MATHDLL2_EXPORTS
#define MATHDLL2_API __declspec(dllexport)
#else
#define MATHDLL2_API __declspec(dllimport)
#endif

MATHDLL2_API int add(int a, int b);
MATHDLL2_API int sub(int a, int b);
MATHDLL2_API void inc();
MATHDLL2_API int get_inc();