#ifndef NEPOSTRINGS
#define NEPOSTRINGS

#include <list>
#include "NEPOColors.h"


std::string ToString(std::string str);

std::string ToString(const char *str);

std::string ToString(bool b);

std::string ToString(double d);

std::string removeTrailingZeros(std::string str);

std::string ToString(int n);

// used for the times
std::string ToString(unsigned long long n);

std::string ToString(Color color);

template<typename T>
std::string ToString(std::list<T> values);

#endif