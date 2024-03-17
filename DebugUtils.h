#include "Enum.h"
#include <string>
#include <iostream>

#if defined(_WIN32)
    #include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
    #include <cstdio>
#endif

#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H
class DebugUtils {
    public:
        static void PrintOutput(
            enum OutputLevel output_level,
            enum OutputType output_type,
            std::string message
        );

        static void SetConsoleTitle(std::string title);

        static std::string SetConsoleOutputColor(std::string message, enum OutputType output_type);
};
#endif