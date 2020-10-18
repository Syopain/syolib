#include <iostream>
#include "algorithm.h"
#include "stack.h"

using std::cin;
using std::cout;
using std::endl;

static void exercise_6_1()
{
    cout << "Exercise_6_1:" << endl << endl;

    std::string expr;
    cout << "Input expression: ";
    getline(cin, expr);
    cout << endl;
    cout << "Reverse Polish notation: " << syo::toSuffix(expr) << endl << endl;
    cout << "Result: " << syo::calculate(expr) << endl << endl;
}

static void exercise_6_2()
{
    cout << "Exercise_6_2:" << endl << endl;
    syo::Stack<int> order_stack;
    cout << "Order stack: " << endl << endl;
    cout << "After push {10, 4, 5, 4, 7, 2}: ";
    for (auto i : {10, 4, 5, 4, 7, 2}) {
        order_stack.push(i);
    }
    cout << order_stack << endl << endl;

    cout << "After remove All 4: ";
    order_stack.removeAll(4);
    cout << order_stack << endl << endl;

    syo::Stack<int, syo::ForwardList<int>> link_stack;
    cout << "Link stack: " << endl << endl;
    cout << "After push {10, 4, 5, 4, 7, 2}: ";
    for (auto i : {10, 4, 5, 4, 7, 2}) {
        link_stack.push(i);
    }
    cout << link_stack << endl << endl;

    cout << "After remove All 4: ";
    link_stack.removeAll(4);
    cout << link_stack << endl << endl;
}

void exercise_6()
{
    exercise_6_1();
    exercise_6_2();
}
