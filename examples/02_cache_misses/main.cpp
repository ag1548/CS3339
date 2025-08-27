/*

$ # Fast version
$ make
reached the end
real 2.14
user 1.26
sys 0.87

$ perf stat -e cache-misses ./main

 Performance counter stats for './main':

        76,148,846      cache-misses

       2.180038023 seconds time elapsed

       1.266973000 seconds user
       0.911261000 seconds sys


$ # Slow version
$ make
reached the end
real 9.76
user 8.65
sys 1.10

$ perf stat -e cache-misses ./main

 Performance counter stats for './main':

     2,250,125,754      cache-misses

       9.434137673 seconds time elapsed

       8.206894000 seconds user
       1.216798000 seconds sys


$ # Only differ by memory access offset
$ make diff
diff main.s.fast main.s.slow
44c44
< 	movl	-36(%rbp), %eax
---
> 	movl	-32(%rbp), %eax
50c50
< 	movl	-32(%rbp), %edx
---
> 	movl	-36(%rbp), %edx

*/

#include <iostream>

#define SIZE 30000

int main() {

    int **my_array_of_arrays = new int*[SIZE];
    for (int i = 0; i < SIZE; ++i)
        my_array_of_arrays[i] = new int[SIZE];

    // Fast
    for (int y = 0; y < SIZE; ++y)
        for (int x = 0; x < SIZE; ++x)
            my_array_of_arrays[y][x] = 0;

    // Slow
    // for (int x = 0; x < SIZE; ++x)
    //     for (int y = 0; y < SIZE; ++y)
    //         my_array_of_arrays[y][x] = 0;

    for (int i = 0; i < SIZE; ++i)
        delete [] my_array_of_arrays[i];
    delete [] my_array_of_arrays;

    return 0;
}