#include <stdio.h>
#include <stdlib.h>
int** readAcquaintances(int* n) {
    int i, k,m;

    int** p = 0;
    int** q = 0;
    i = 0;

    scanf_s("%d\n", n);
    while (1) {
        p = realloc(p, (i + 1) * sizeof(int));
        p[i] = malloc(2 * sizeof(int));
        q = realloc(q, (i + 1) * sizeof(int));
        q[i] = calloc(2, sizeof(int));
        scanf_s("%d", &p[i][0]);
        if (p[i][0] == -1) {
            p[i][0] = 0;
            p[i][1] = 0;
            break;

        }
        scanf_s(" %d\n", &p[i][1]);
        if (p[i][1] == -1) {
            break;
        }

        i++;


    }
    for (m = i; m >= 0; m--) {
        for (k = 0; k < n; k++) {
            if (p[m][0] == k) {
                q[k][0]++;
            }
        }
    }
    for (m = i; m >= 0; m--) {
        for (k = 0; k < n; k++) {
            if (p[m][1] == k) {
                q[k][1]++;
            }
        }
    }
    return q;
}

int main() {
    int n;
    int** m = readAcquaintances(&n);
    printf("%d\n", n);
    for (int i = 0; i < (n + 1); ++i) {
        printf("%d %d\n", m[i][0], m[i][1]);
    }
    //freeSpace(m, n);
    return 0;
}