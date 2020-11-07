#include <iostream>
#include "vector.h"

void exercise_2()
{
    using std::cout;
    using std::endl;
    using syo::Vector;

    cout << "Exercise_2:" << endl << endl;

    Vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Original ArrayList: \n";

    cout << "Array List: " << ivec << endl << endl;;

    cout << "Insert 3 elements at index 4: \n";
    ivec.insert(4, 3, 15);
    cout << "Array List: " << ivec << endl << endl;

    cout << "Remove 2 elements at index 3: \n";
    ivec.remove(3, 2);
    cout << "Array List: " << ivec << endl << endl;
}
