#include <stdio.h>
#include <stdlib.h>
long reversenumber (long in) {
    
    long out = 0;

    for (; in>0; in = in/10)
        out = (out * 10) + (in % 10);

    return out;
}

int isPolyndrome(long in) {
    long out = reversenumber(in);
    return (in == out)? 1:0;
}

int main(int argc, char ** argv) {
    
    long a = 999, b = 999, max = 0;

    for (; a>=100; a--) {
        for (b = 999; b>=100; b--) {
            if (isPolyndrome(a*b) == 1) {
                if (a*b > max)
                    max = a*b;
            }
        }
    }
    printf("max polyndrom is %ld \n", max);
    return 0;
}
