#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int vrednost;
    int potez;
    int* putanja;
    int distanca;
}Node;

int** createGraph(int n) {
    int** p;
    int i;

    p = calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        p[i] = calloc(n, sizeof(int));
    }
    return p;
}

int** addNodeinGraph(int** p, int n) {
    int i;
    putchar('\n');
    p = realloc(p, sizeof(int*) * (n + 1));
    for (i = 0; i < n; i++) {
        p[i] = realloc(p[i], sizeof(int) * (n + 1));
    }
    p[i] = malloc((n + 1) * sizeof(int));
    for (i = 0; i < n + 1; i++) {
        p[i][n] = 0;
        p[n][i] = 0;
    }

    return p;
}
int** addEdgeinGraph(int i, int j, int** p) {
    p[i][j] = 1;
    return p;
}

int** removeVertexinGraph(int** p, int v, int n) {
    int i, j;
    for (j = v; j < n - 1; j++) {

        for (i = 0; i < n; i++) {
            p[i][j] = p[i][j + 1];
        }
        for (i = 0; i < n; i++) {
            p[i] = realloc(p[i], (n - 1) * sizeof(int));

        }
        free(p[v]);
        for (i = 0; i < n; i++) {
            p[j][i] = p[j + 1][i];
        }
        p = realloc(p, (n - 1) * sizeof(int*));
    }
    return p;
}


int** removeEdgeinGraph(int i, int j, int** p) {
    p[i][j] = 0;
    return p;
}
void printGraph(int** p, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        putchar('\n');
    }
}
void freeGraph(int** p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
}
// FLOYD
int** minMoves(int** p, int n, int ki, int kj) {

    p[0][1] = 1;
    p[1][3] = 1;
    p[1][5] = 1;
    p[2][0] = 1;
    p[2][3] = 1;
    p[3][4] = 1;
    p[4][2] = 1;
    p[5][4] = 1;

    int i, j, k;
    int** f;
    int** t;
    f = createGraph(n);
    t = createGraph(n);


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                f[i][j] = 0;
            }
            else {
                f[i][j] = 1;
            }
            if ((i != j) && (p[i][j] == 0)) {
                f[i][j] = 9;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i == j) || (f[i][j] == 9)) {
                t[i][j] = -1;
            }
            if ((i != j) && (f[i][j] < 9)) {
                t[i][j] = i;
            }

        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (f[i][k] + f[k][j] < f[i][j]) {
                    t[i][j] = t[k][j];
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }
    printf("Najmanji broj poteza je: %d\n", f[ki][kj]);
    int pomkj;
    pomkj = kj;
    printf("Putanja od starta do cilja je: ");
    printf("%d->", ki);
    for (j = 0; j < f[ki][pomkj] - 1; j++) {
        kj = pomkj;
        for (i = 0; i < f[ki][pomkj] - 2 - j; i++) {
            kj = t[ki][kj];
        }
        printf("%d->", t[ki][kj]);
    }
    printf("%d\n", pomkj);


    // printGraph(t, n);
    // printGraph(f, n);
    return t;
}

//void onePath(int** p) {
//    printf("one");
//}
//void allPaths(int** p) {
//    printf("all");
//
//}

void allPaths(int** p, int n, int start, int finish) {
    p[0][1] = 1;
    p[1][0] = 1;
    p[1][2] = 1;
    p[1][5] = 1;
    p[2][1] = 1;
    p[2][3] = 1;
    p[2][5] = 1;
    p[3][2] = 1;
    p[3][2] = 1;
    p[3][4] = 1;
    p[3][6] = 1;
    p[4][3] = 1;
    p[4][5] = 1;
    p[4][6] = 1;
    p[5][1] = 1;
    p[5][2] = 1;
    p[5][4] = 1;
    p[6][3] = 1;
    p[6][4] = 1;

    int* d;
    int md;
    int i;
    d = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        d[i] = 10000000;
    }

    Node** q;
    Node* start1;
    q = malloc(n * sizeof(Node*));
    Node** konput;
    Node** t;
    konput = malloc(n * sizeof(Node*));
    t = konput;

    start1 = malloc(n* sizeof(Node));
    start1->vrednost = start;
    start1->putanja = malloc(2 * n * (sizeof(int)));
    start1->putanja[0] = start;
    start1->distanca = 0;
    *q = start1;
    *(q + 1) = NULL;
    md = 1000000;
    d[start] = 0;
    while (*q != NULL) {
        Node* s;

        s = *q;
        q++;
        if (s->vrednost == finish) {
            md = s->distanca;
            *t = s;

            *(t+1) = NULL;
        }
        if (s->distanca > md) {
            continue;
        }
        else {
            for (i = 0; i < n; i++) {
                if ((p[s->vrednost][i] == 1) && (d[i] >= s->distanca + 1)) {
                    Node* x;
                    x = malloc(sizeof(Node));
                    x->vrednost = i;

                    x->distanca = s->distanca + 1;
                    x->putanja[s->distanca+1] = s->putanja[s->distanca+1] + i;
                    d[i] = s->distanca + 1;
                    *q = x;
                    *(q+1) = NULL;
                }
            }
        }


    }
    t = konput;

    while (t != NULL) {
        Node* s = *t;
        t++;
        for (i = 0; i < md; i++) {
            printf("%d", s->putanja[i]);
        }
    }


}

int main() {
    int n = 4, x, y, vertex;
    int** matrix = 0;
    int opcija;

    while (1) {
        printf("Unesite broj opcije\n");
        printf("1. Kreirati graf\n");
        printf("2. Dodaj cvor\n");
        printf("3. Ukloni cvor\n");
        printf("4. Dodaj granu\n");
        printf("5. Izbrisi granu\n");
        printf("6. Ispis grafa\n");
        printf("7. Brisanje grafa\n");
        printf("8. ULAZ U DRUGI ZADATAK\n");
        printf("0. Izlaz\n");
        scanf_s("%d", &opcija);

        if (opcija == 1) {
            printf("Unestie broj cvorova: \n");
            scanf_s("%d", &n);
            matrix = createGraph(n);

        }
        if (opcija == 2) {
            matrix = addNodeinGraph(matrix, n);
            n = n + 1;
        }
        if (opcija == 3) {
            printf("Unesite index cvora koji se uklanja: ");
            scanf_s("%d", &vertex);
            if (vertex > n) {
                printf("Cvor ne postoji");
                break;
            }
            matrix = removeVertexinGraph(matrix, vertex, n);
            n = n - 1;
        }
        if (opcija == 4) {
            printf("Unesite koordinate cvora (i, j)\n");
            printf("Unesite i: ");
            scanf_s("%d", &x);
            printf("\nUnesite j: ");
            scanf_s("%d", &y);
            addEdgeinGraph(x, y, matrix);

        }
        if (opcija == 5) {
            printf("Unesite koordinate cvora (i, j)");
            printf("Unesite i:");
            scanf_s("%d", &x);
            printf("\nUnesite j: ");
            scanf_s("%d", &y);
            removeEdgeinGraph(x, y, matrix);
        }
        if (opcija == 6) {
            printGraph(matrix, n);
        }
        if (opcija == 7) {
            freeGraph(matrix, n);
        }
        if (opcija == 8) {
            int opcija2, koordi, koordj;
            while (1) {
                printf("\nDRUGI ZADATAK\n");
                printf("1. Najmanji broj poteza\n");
                printf("2. Ispsati sve najkrace puteve\n");
                printf("0. Izlaz iz programa\n");
                printf("Unesi opciju: ");
                scanf_s("%d", &opcija2);
                switch (opcija2) {
                    case 1:

                        printf("Unesite startni cvor: ");
                        scanf_s("%d", &koordi);

                        printf("Unesite ciljni cvor: ");
                        scanf_s("%d", &koordj);

                        minMoves(matrix, n, koordi, koordj);

                        break;

                    case 2:
                        printf("Unesite startni cvor: ");
                        scanf_s("%d", &koordi);

                        printf("Unesite ciljni cvor: ");
                        scanf_s("%d", &koordj);
                        allPaths(matrix, n, koordi, koordj);
                        break;
                    default:
                        exit(0);

                }

            }

        }
        if (opcija == 0) {
            exit(0);
        }
    }

}
