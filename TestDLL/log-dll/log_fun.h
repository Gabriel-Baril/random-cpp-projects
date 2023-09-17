#pragma once

#ifdef LOGDLL_EXPORTS
#define LOGDLL_API __declspec(dllexport)
#else
#define LOGDLL_API __declspec(dllimport)
#endif

LOGDLL_API void log(const char* message);