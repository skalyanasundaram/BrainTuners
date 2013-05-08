#include <stdio.h>
#include <string.h>

void print(int num) {
    char digit [21][10] = { "", "one", "two", "three", "four", "five", "six", "seven",
                          "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
                          "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                          "nineteen"};
    char tens [11][10] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", 
                         "seventy", "eighty", "ninety"};
    char str[1000] = {0};
    int prev=0, div=1000;
    strcpy(str, "");
    
    while(div) {
        
        if ((num / div) % 10 > 0 || (div == 10 && (num%100) > 0)) { 

            if (prev) {
                strcat(str, "and");
                prev = 0;
            }
        
            switch(div) {
            case 1000:
                strcat(str, digit[(num / div) % 10]);     
                strcat(str, "thousand");
                prev = 1;
                break;
            case 100:
                strcat(str, digit[(num / div) % 10]);     
                strcat(str, "hundred");
                prev = 1;
                break;
            case 10:
                if ( (num%100) >= 10 && (num%100) <= 19)
                    strcat(str, digit[num%100]);
                else {
                    strcat(str, tens[(num%100)/10]);
                    strcat(str, digit[num%10]);
                }
                break;
            }
        }

        div /= 10;
    }
    printf("%d %s\n", num, str);

}
int main(int argc, char **argv) {

    long sum = 0;
    int count = 0;

    if (argc <= 1) {
        fprintf(stderr, "wrong number of arguments\n");
        return -1;
    }

    print(atoi(argv[1]));

    return 0;
}
