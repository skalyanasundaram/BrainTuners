#include <stdio.h>


/*
  This is to verify proof 
  By Hand: 2520 can be divided in to;

  col: vol
  1  : 1
  2  : 2
  3  : 3
  4  : 2 (2*2, there is a 2 already)
  5  : 5
  6  : - (3*2, both already exists)
  7  : 7
  8  : 2 (2*2*2, two 2 already exists)
  9  : 3
 10  : -
 11  : 11
 12  : -
 13  : 13
 14  : -
 15  : - 
 16  : 2 (2*2*2*2, )
 17  : 17
 18  : - 
 19  : 19
 20  : -


232792560

*/
int main(int argc, char **argv) {
    long num = 2520;
    int i = 1;

    for (; num <= 232792560; num++ ) {
        printf ("%ld\t", num);
        for(i=1; i<=20; i++)
            if (num % i != 0)
                break;

        if (i == 20)
            printf ("Small evenly % by 1-20 is %ld\n", num);
    }
   
    return 0;
}
