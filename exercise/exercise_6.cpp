#include <iostream>
#include "algorithm.h"

using std::cin;
using std::cout;
using std::endl;

static void exercise_6_1()
{
    std::string expr;
    cout << "Input expression: ";
    getline(cin, expr);
    cout << "Reverse Polish notation: " << toSuffix(expr) << endl;
    cout << "Result: " << calculate(expr) << endl;
}

void exercise_6()
{
    exercise_6_1();
}
