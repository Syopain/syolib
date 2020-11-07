#include <iostream>
#include "binary_tree.h"

using std::cout;
using std::endl;


static void exercise_10_1()
{
    cout << "Exercise_10_1:" << endl << endl;

    syo::BinaryTree<char> tree('A');
    auto B = tree.setLeft('B');
    B.setLeft('D');
    B.setRight('E').setLeft('G');
    auto C = tree.setRight('C');
    auto F = C.setRight('F');
    F.setLeft('H');
    F.setRight('I');

    cout << "Print the tree:" << endl;
    tree.print();
    cout << endl;
    cout << "ProOrderTraversal:  ";
    tree.preOrderTraversal([](char c){ cout << c << ' '; });
    cout << endl << endl;
    cout << "InOrderTraversak:   ";
    tree.inOrderTraversal([](char c){ cout << c << ' '; });
    cout << endl << endl;
    cout << "PostOrderTraversal: ";
    tree.postOrderTraversal([](char c){ cout << c << ' '; });
    cout << endl << endl;
}

static void exercise_10_2()
{
    cout << "Exercise_10_2:" << endl << endl;

    syo::BinaryTree<char> tree('A');
    auto B = tree.setLeft('B');
    B.setLeft('D');
    B.setRight('E').setLeft('G');
    auto C = tree.setRight('C');
    auto F = C.setRight('F');
    F.setLeft('H');
    F.setRight('I');

    cout << "Print the tree:" << endl;
    tree.print();
    cout << endl;

    auto nodeNum = tree.nodeNum();
    cout << "The tree has " << nodeNum << (nodeNum >= 2 ? " nodes" : " node") << endl;
    auto height = tree.height();
    cout << "The height of the tree is " << height << endl << endl;
}

void exercise_10()
{
    exercise_10_1();
    exercise_10_2();
}
