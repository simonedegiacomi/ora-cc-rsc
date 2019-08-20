#include "NEPODefs.h"

template<typename T, typename U>
void assertNepo(bool test, std::string text, T left, std::string op, U right) {
    if (!test) {
        std::string testStatement = ToString(left) + " " + op + " " + ToString(right);
        printf("Assertion failed: %s %s\n", text.c_str(), testStatement.c_str());
    }
}
