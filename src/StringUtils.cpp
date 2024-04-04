#include "XW/StringUtils.h"

std::string StringUtils::Format(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int size = vsnprintf(nullptr, 0, format, args);
    va_end(args);

    char* buffer = new char[size + 1];

    va_start(args, format);
    vsnprintf(buffer, size + 1, format, args);
    va_end(args);

    std::string result(buffer);

    delete[] buffer;

    return result;
}