#ifndef NEPOMATH
#define NEPOMATH

#include <math.h>

// AbstractCppVisitor generates code that uses the PI constant instead of M_PI
#define PI M_PI

#define GOLDEN_RATIO 1.61803398875


bool IsWhole(double d);

bool IsPrime(double d);

#endif
