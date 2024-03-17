#include <cstdarg> 
#include <cstdio>
#include <string>


#ifndef STRINGUTILS_H
#define STRINGUTILS_H
class StringUtils {
    public:
        static std::string Format(const char* format, ...);
};
#endif