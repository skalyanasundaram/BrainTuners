#include <stdio.h>
#include <stdlib.h>

unsigned long long bicoeff(int n, int k) {
    int *n_a, *k_a, *nk_a, i, j;
    unsigned long long ret = 1;

    n_a = (int *) malloc(n * sizeof(int) + 1);
    k_a = (int *) malloc(k * sizeof(int) + 1);
    nk_a = (int *) malloc((n-k) * sizeof(int) + 1);

    for (i=0; i<n; i++)
        n_a[i] = i+1;
    for (i=0; i<k; i++)
        k_a[i] = i+1;
    for (i=0; i<(n-k); i++)
        nk_a[i] = i+1;

    for (i=0; i<n;  i++) {
        ret *= n_a[i];

        for (j=0; j<k; j++)
            if (k_a[j] != 0 && ret % k_a[j] == 0) {
                ret /= k_a[j];
                k_a[j] = 0;
            }
        for (j=0; j<n-k; j++)
            if (nk_a[j] != 0 && ret % nk_a[j] == 0) {
                ret /= nk_a[j];
                nk_a[j] = 0;
            }
    }
    return ret;

}
int main(int argc, char **argv) {
    int n = 20;

    printf("value %llu\n", bicoeff(10,8));
}
