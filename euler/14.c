#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char **argv) {
    unsigned long long num=1000000, big = 0, chain = 0;
    unsigned long long tmp = 1, chaintmp = 0;

    struct timeval tv;
    struct timezone tz;
    time_t now, latter;

    gettimeofday(&tv, &tz);
    now = tv.tv_sec;

    for(num--; num>1; num--) {
        tmp = num;

        chaintmp = 0;
        while(tmp != 1) {
            if (tmp % 2 == 0) tmp /= 2;
            else tmp = (tmp * 3) + 1;
            chaintmp ++;
        }

        //printf("%llu --> %llu\n", num, chaintmp);

        if (chaintmp > chain) {
            chain = chaintmp;
            big = num;

            printf("New big chain %llu of size %llu\n", big, chain);
        }
    }

    gettimeofday(&tv, &tz);
    latter = tv.tv_sec;

    printf("Biggest chain is %llu of size %llu\n", big, chain);

    printf("time before %s\ntime after  %s", ctime(&now), ctime(&latter));
    return 0;
}
