#include<stdio.h>
#include<stdlib.h>

unsigned long long primecache[1000];
int primecount;

int apowerbmoduloc(unsigned long long a, unsigned long long b, unsigned long long c) {
    
    unsigned long long x = 1, y = a;
    while(b>0) {
        if (b%2 == 1)
            x = (x*y) % c;

        y = (y*y) % c;
        b /= 2;
    }

    return x%c;
}


int isprime(unsigned long long num) {
    int i=0;
    unsigned long long a;

    //to avoid fermet liars
    for(i=0; i<20 ; i++) {
        a = rand() % (num-1) + 1;
        if(apowerbmoduloc(a, num-1, num) != 1)
            return 0;
    }

    return 1;
}

unsigned long long getnextprime(unsigned long long num){
    for (num++;;num++)
        if (isprime(num) == 1)
            return num;
}

int getfactofnum(unsigned long long num) {
    unsigned int count = 1, primeptr = 0, i=0;
    unsigned int divisiorcount[1000] = {0};

    if (num == 1)
        return 1;
    else if (isprime(num) == 1)
        return 2;
    else {
        
        while(isprime(num) != 1) {
            for (primeptr=0, i=0; primeptr<1000; primeptr++, i++) {
                if(num % primecache[primeptr] == 0) {
                    num /= primecache[primeptr];
                    divisiorcount[primeptr] ++;
                    break;
                }
            }
        }
        
        for(i=0; i<1000; i++) {

            // 55/5 brings 11 in which 11 is not included anywhere. so count for it
            if(num != 0 && primecache[i] == num) {
                divisiorcount[i]++;
                num = 0;
            }
            if(divisiorcount[i] > 0) {
                //                printf ("%d\t", primecache[i]);
                count *= (divisiorcount[i] + 1);
            }
        }
        
        // it was not part of any of the above prime, so
        // a^b * b^c * newprime^1 = (b+1) * (c+1) * (1+1)
        if (num != 0)
            count *= 2;

        return count;
    }

}

int main(int argc, char **argv) {

    unsigned long long seqtri = 0, current = 1;
    unsigned int start = 0, count = 0;
    
    primecount = 1;
    primecache[0] = 2;

    //build a prime cache to use it for factoring the numbers
    for(start=1; start<1000; start++) {
        primecache[start] = getnextprime(primecache[start-1]);
        //        printf("%d %ld\n",start, primecache[start]);
    }
    
    for (count=0, current=1; count<500; current++) {
        seqtri += current;
        count = getfactofnum(seqtri);
        printf("%d %llu\n", count, seqtri);
    }
    return 0;
}

