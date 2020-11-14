#include <iostream>
#include "vector.h"

using syo::Vector;

static void exercise_3_1()
{
    using std::cout;
    using std::endl;

    cout << "Exercise_3_1:" << endl << endl;

    Vector<int> ivec;
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 10: \n";
    ivec.insertInOrder(10);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 3: \n";
    ivec.insertInOrder(3);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 7: \n";
    ivec.insertInOrder(7);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 1: \n";
    ivec.insertInOrder(1);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 5: \n";
    ivec.insertInOrder(5);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Insert 4: \n";
    ivec.insertInOrder(4);
    cout << "Array List: " << ivec << endl << endl;
}

static void exercise_3_2()
{
    using std::cout;
    using std::endl;

    cout << "Exercise_3_2:" << endl << endl;

    Vector<int> ivec = {1, -1, 3, 4, -3, 5, -6, -2, 9, -3};
    cout << "Original ArrayList: \n" << ivec << endl << endl;

    ivec.sortBySign();
    cout << "Called sort_by_sign(): \n" << ivec << endl << endl;

}

void exercise_3()
{
    exercise_3_1();
    exercise_3_2();
}
