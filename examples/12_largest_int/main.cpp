#include <iostream>

int main() {

    using std::cout;
    using std::endl;

    cout << 147483647 << endl;
    cout << sizeof(147483647) << endl;

    cout << 9992147483647 << endl;
    cout << sizeof(9992147483647) << endl;

    cout << 999999999999999999999999999999999999999 << endl;
    cout << sizeof(999999999999999999999999999999999999999) << endl;

    return 0;
}
