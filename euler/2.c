#include <stdio.h>

int main(int argc, char **argv) {
    
    long a = 1, b = 2, tot = 2;

    for(; a=a+b, a<4000000; a=a+b, b=a-b, a=a-b)
        if(a%2 == 0)
            tot += a;
    printf("+ of fibo of %%2 is %ld\n", tot);
    return 0;
}
