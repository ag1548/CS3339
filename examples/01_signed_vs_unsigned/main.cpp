/*

$ make
x is greater than y
x: 11111111111111111111111111111111
y: 00000000000000000000000000000101

*/

#include <bitset>
#include <iostream>

int main() {

    int      x = -1;
    unsigned y =  5;

    if (x < y) std::cout << "x is less than y"    << std::endl;
    else       std::cout << "x is greater than y" << std::endl;

    std::cout << "x: " << std::bitset<32>(x) << std::endl;
    std::cout << "y: " << std::bitset<32>(y) << std::endl;

    return 0;
}