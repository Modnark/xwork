#include "DebugUtils.h"

void DebugUtils::PrintOutput(
    enum OutputLevel output_level,
    enum OutputType output_type,
    std::string message
)
{
    switch(output_level) {
        case Console:
            printf(SetConsoleOutputColor(message, output_type).c_str());
            break;
        case ScreenSpace:
            printf("\e[0;33mOutputLevel.ScreenSpace Not Implemented\n");
            break;
        case ConsoleScreenSpace:
            printf(SetConsoleOutputColor(message, output_type).c_str());
            break;
    }
}

void DebugUtils::SetConsoleTitle(std::string title) {
    #if defined(_WIN32)
        SetConsoleTitleA(title.c_str());
    #elif defined(__linux__) || defined(__APPLE__)
        std::cout << "\033]0;" << title << "\007";
    #endif    
}

std::string DebugUtils::SetConsoleOutputColor(std::string message, enum OutputType output_type) {
    std::string ansi_color = "";
    switch(output_type) {
        case General: break;
        case Info: ansi_color = "\e[0;34m"; break;
        case Warn: ansi_color = "\e[0;33m"; break;
        case Error: ansi_color = "\e[0;31m"; break;
    }
    return ansi_color + message + "\e[0m";
}