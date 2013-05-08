#include <stdio.h>

#define GET(x,y) ((x) >= 0 && (y) >= 0 && (x) <=19 && (y) <= 19)?grid[(x)][(y)]:0
#define RIGHT(x,y) ((GET(x,y)) * (GET(x, (y+1))) * (GET(x, (y+2))) * (GET(x, (y+3))))
#define LEFT(x,y) ((GET(x,y)) * (GET(x, (y-1))) * (GET(x, (y-2))) * (GET(x, (y-3))))
#define UP(x,y) ((GET(x,y)) * (GET((x-1), y)) * (GET((x-2), y)) * (GET((x-3), y)))
#define DOWN(x,y) ((GET(x,y)) * (GET((x+1), y)) * (GET((x+2), y)) * (GET((x+3), y)))

#define UPRIGHT(x,y) ((GET(x,y)) * (GET((x-1), (y+1))) * (GET((x-2), (y+2))) * (GET((x-3), (y+3))))
#define UPLEFT(x,y) ((GET(x,y)) * (GET((x-1), (y-1))) * (GET((x-2), (y-2))) * (GET((x-3), (y-3))))
#define DOWNRIGHT(x,y) ((GET(x,y)) * (GET((x+1), (y+1))) * (GET((x+2), (y+2))) * (GET((x+3), (y+3))))
#define DOWNLEFT(x,y) ((GET(x,y)) * (GET((x+1), (y-1))) * (GET((x+2), (y-2))) * (GET((x+3), (y-3))))

#define FINDMAXONRADIOUS(x,y) { unsigned long long tmp = 0; \
    if((tmp = LEFT(x,y)) > max) max=tmp; \
    if((tmp = RIGHT(x,y)) > max) max=tmp; \
    if((tmp = UP(x,y)) > max) max=tmp; \
    if((tmp = DOWN(x,y)) > max) max=tmp; \
    if((tmp = UPRIGHT(x,y)) > max) max=tmp; \
    if((tmp = UPLEFT(x,y)) > max) max=tmp; \
    if((tmp = DOWNRIGHT(x,y)) > max) max=tmp; \
    if((tmp = DOWNLEFT(x,y)) > max) max=tmp; \
}

int main(int argc, char **argv) {

    int grid[20][20];
    FILE *fp = NULL;
    int i = 0, j = 0;
    unsigned long long max = 0;

    if (argc != 2)
        return -1;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        return -1;

    for (i=0; i<20; i++)
        for (j=0; j<20; j++)
            fscanf(fp, "%d ", &grid[i][j]);

    for (i=0; i<20; i++)
        for (j=0; j<20; j++)
            FINDMAXONRADIOUS(i,j);
                
    printf("%ld\n", max);
    return 0;

}
