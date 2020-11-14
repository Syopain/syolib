#include <iostream>
#include <string>
#include "binary_tree.h"

using std::cout;
using std::endl;

static void exercise_11_1()
{
    cout << "Exercise_11_1:" << endl << endl;

    syo::BinaryTree<char> tree('A');
    auto B = tree.setLeft('B');
    B.setLeft('D');
    B.setRight('E').setLeft('G');
    auto C = tree.setRight('C');
    auto F = C.setRight('F');
    F.setLeft('H');
    F.setRight('I');

    cout << "print the tree: " << endl;
    tree.printVertical();
    tree.printIndex();
}

static void exercise_11_2()
{
    cout << "Exercise_11_2:" << endl << endl;

    syo::BinaryTree<char> tree('A');
    auto B = tree.setLeft('B');
    B.setLeft('D');
    B.setRight('E').setLeft('G');
    auto C = tree.setRight('C');
    auto F = C.setRight('F');
    F.setLeft('H');
    F.setRight('I');

    tree.printHorizontal();
}

static void exercise_11_3()
{
    cout << "Exercise_11_3:" << endl << endl;

    syo::BinaryTree<char> tree('A');
    auto B = tree.setLeft('B');
    B.setLeft('D');
    B.setRight('E').setLeft('G');
    auto C = tree.setRight('C');
    auto F = C.setRight('F');
    F.setLeft('H');
    F.setRight('I');

    tree.printWireframe();
}

void exercise_11()
{
    exercise_11_1();
    exercise_11_2();
    exercise_11_3();
}
