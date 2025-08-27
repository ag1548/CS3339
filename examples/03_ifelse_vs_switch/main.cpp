/*

//////////////////////////////////////////////////////////////////////////////////////////////
// main.s.ifelse
//////////////////////////////////////////////////////////////////////////////////////////////

...

...

...

.L2:
	movl	-12(%rbp), %eax
	cmpl	$1, %eax
	jne	.L4
    ...
...
.L4:
	movl	-12(%rbp), %eax
	cmpl	$2, %eax
	jne	.L5
    ...
...
.L5:
	movl	-12(%rbp), %eax
	cmpl	$3, %eax
	jne	.L6
    ...
...
.L6:
	movl	-12(%rbp), %eax
	cmpl	$4, %eax
	jne	.L7
    ...
...

...

...

//////////////////////////////////////////////////////////////////////////////////////////////
// main.s.switch
//////////////////////////////////////////////////////////////////////////////////////////////

...

.L4:
	.long	.L13-.L4
	.long	.L12-.L4
	.long	.L11-.L4
	.long	.L10-.L4
	.long	.L9-.L4
	.long	.L8-.L4
	.long	.L7-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text

...

*/

#include <iostream>

int main() {

    int x;
    std::cout << "Enter x: ";
    std::cin >> x;

    // if (x == 0)      std::cout << "x is 0" << std::endl;
    // else if (x == 1) std::cout << "x is 1" << std::endl;
    // else if (x == 2) std::cout << "x is 2" << std::endl;
    // else if (x == 3) std::cout << "x is 3" << std::endl;
    // else if (x == 4) std::cout << "x is 4" << std::endl;
    // else if (x == 5) std::cout << "x is 5" << std::endl;
    // else if (x == 6) std::cout << "x is 6" << std::endl;
    // else if (x == 7) std::cout << "x is 7" << std::endl;
    // else if (x == 8) std::cout << "x is 8" << std::endl;
    // else if (x == 9) std::cout << "x is 9" << std::endl;

    switch(x) {
        case 0: std::cout << "x is 0" << std::endl; break;
        case 1: std::cout << "x is 1" << std::endl; break;
        case 2: std::cout << "x is 2" << std::endl; break;
        case 3: std::cout << "x is 3" << std::endl; break;
        case 4: std::cout << "x is 4" << std::endl; break;
        case 5: std::cout << "x is 5" << std::endl; break;
        case 6: std::cout << "x is 6" << std::endl; break;
        case 7: std::cout << "x is 7" << std::endl; break;
        case 8: std::cout << "x is 8" << std::endl; break;
        case 9: std::cout << "x is 9" << std::endl; break;
    }

    return 0;
}