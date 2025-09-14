#include <iostream>

using namespace std;

void squared(int x, int *&result_location)
{
    int result = x * x;
    result_location = &result;

    cout << "1: ";
    cout << (unsigned long)result_location << ": ";
    cout << *result_location << endl;
}

void squared_other(int x, int *&result_location)
{
    int result;

    cout << "3: ";
    cout << (unsigned long)&result << ": ";
    cout << result << endl;

    result = x * x;

    result_location = &result;
}

int main()
{
    int *result;

    squared(4, result);

    cout << "2: ";
    cout << (unsigned long)result << ": ";
    cout << *result << endl;

    squared_other(3, result);

    cout << "4: ";
    cout << (unsigned long)result << ": ";
    cout << *result << endl;

    return 0;
}
