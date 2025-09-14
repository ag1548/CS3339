#include <iostream>

int main() {

    int x;
    int y;
    int z;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    std::cout << "Enter z: ";
    std::cin >> z;

    const int w = y * x + z;

    std::cout << w << std::endl;

	return 0;
}

