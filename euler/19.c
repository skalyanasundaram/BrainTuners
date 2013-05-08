#include <stdio.h>

int main(int argc, char **argv) {
    
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, ptr, count = 0;

    ptr = 7;
    for (i=1900; i<=2000; i++) {
        days[2] = 28;
        if (i % 4 == 0)
            if (i%100 == 0 && i%400 != 0 )
                days[2] = 28;
            else
                days[2] = 29;

        for (j=1; j<=12;) {
            
            if (ptr > 28) {
                ptr -= days[j];
                j++;
            }

            if (ptr == 1 && i > 1900) {
                printf("year %d month %d\n", i, j);
                count ++;
            }
                
            ptr += 7;
        }
    }

    printf("sum %d\n", count);
    return 0;
}
