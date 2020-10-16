#include <iostream>
#include "forward_list.h"

using syo::ForwardList;
using std::cout;
using std::endl;

static void exercise_4_1()
{
    cout << "Exercise_4_1:" << endl << endl;

    ForwardList<int> lst = {9, 3, 5, 4, 8, 5, 2, 5, 6};
    cout << "Array List: " << lst << endl << endl;

    cout << "List Length: " << lst.length() << endl << endl;

    for (auto item : {5, 12, 15}) {
        if (lst.index_of(item) >= 0)
            cout << "The first " << item << " appears in: " << lst.index_of(item)  << endl << endl;
        else
            cout << "The first " << item << " appears in: Not found!"  << endl << endl;
    }

    cout << "Index 4: " << lst[4] << endl << endl;
}

static void exercise_4_2()
{
    cout << "Exercise_4_2:" << endl << endl;

    ForwardList<int> lst = {9, 3, 5, 4, 8, 5, 2, 5, 6};

    cout << "Before Reverse" << endl << endl;
    cout << "Array List: " << lst << endl << endl;

    lst.reverse();

    cout << "After Reverse" << endl << endl;
    cout << "Array List: " << lst << endl << endl;

}

void exercise_4()
{
    exercise_4_1();
    exercise_4_2();
}
