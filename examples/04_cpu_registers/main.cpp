#include <iostream>

int main() {

    int x;
    int y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    const int z = x + y;

    std::cout << z << std::endl;

	return 0;
}

