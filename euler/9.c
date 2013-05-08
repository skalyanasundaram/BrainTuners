#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    unsigned int a = 1, b = 1, c = 1;

    for (a=1; a<=998; a++)
        for(b=1; b<=998; b++)
            for(c=1; c<=998; c++)
                if (a+b+c == 1000)
                    if(pow(a,2) + pow(b,2) == pow(c,2))
                        printf("a=%d, b=%d, c=%d, abcd=%ld\n",a,b,c, a*b*c);

    return 0;
}
