#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 101
int main() {
    int t, i, j, n, p, temp;

    double x[MAX], y[MAX], r[MAX], min, x1[MAX], y1[MAX], r1[MAX];

    // BROJ KRUGOVA

    scanf("%d", &n);




    // UCITAVANJE NIZOVA

    for (i = 0; i < n; i++) {
        scanf(" (%lf,%lf,%lf)", &x[i], &y[i], &r[i]);
    }

    // ISTPIS NIZOVA
    for (i = 0; i < n; i++) {
        printf("(%.2lf, %.2lf, %.2lf)\n", x[i], y[i], r[i]);
    }




    // OBRADA DA Li SE SEKU

    t = -1;
    for (i = 0; i < n; i++) {
        p = i;
        for (j = i + 1; j < n; j++) {

            if ((r[i] + r[j]) < sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2))) {
                p++;
            }

        }

        if (p + 1 == j) {

            t++;

            x1[t] = x[i];
            y1[t] = y[i];
            r1[t] = r[i];

            printf("(%.2lf, %.2lf, %.2lf)\n", x1[t], y1[t], r1[t]);
        }

    }



    // NAJBLIZA KORD POCETKU

    temp = 0;
    min = abs( sqrt( pow(x1[0],2) + pow(y1[0],2) ) - r1[0] );

    for (i = 1; i < t; i++) {
        if (abs( sqrt( pow(x1[i],2) + pow(y1[i],2) )-r1[i] ) < min) {

            min = abs( sqrt( pow(x1[i],2) + pow(y1[i],2) )-r1[i] );
            temp = i;

        }
    }

    printf("(%.2lf, %.2lf, %.2lf)\n", x1[temp], y1[temp], r1[temp]);


    return 0;
}


