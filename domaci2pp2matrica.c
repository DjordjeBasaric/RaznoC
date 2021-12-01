#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int i, n, j, m, x, y, k, b, z;
    char **p;
    //printf("Uneist dimenzije m, n");
    scanf("%d %d\n", &m, &n);

    if (m > 0 && n > 0 && m == n) {


        p = malloc(m * sizeof(char *));
        if (p==NULL){
            printf("MEM_GRESKA");
        }
        for (i = 0; i < m; i++) {
            p[i] = malloc(n * sizeof(char));
            if (p[i]==NULL){
                printf("MEM_GRESKA");
            }
            //printf("Unesite elemente %d-te vrste:", i);
            for (j = 0; j < n; j++) {
                scanf("%c ", &p[i][j]);
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n - 1; j++) {
                printf("%c ", p[i][j]);
            }
            printf("%c\n", p[i][j]);
            //putchar('\n');
        }

        printf("HORIZONTALNO\n");
        for (i = 0; i < m; i++) {
            for (x = 0; x < n-2 ; x++) {
                for (y = n; y >= 0; y--) {
                    if ((p[i][x] == p[i][y]) && isalpha(p[i][x]) && isalpha(p[i][y])){
                        if (x != 0 && y != n-1){
                            if (!isalpha(p[i][x - 1]) && !(isalpha(p[i][y + 1]))) {
    //                            if (x == y && (!isalpha(p[i][x - 1]) && !(isalpha(p[i][x + 1]))) && isalpha(p[i][x])) {
    //                                printf("%c\n", p[i][x]);
    //                                break;
    //                            }

                                k = y - x + 1;// duzina reci

                                for (b = 0; b < k / 2; b++) { // b je brojac
                                    if (p[i][b + x] != p[i][y - b]) {
                                        break;
                                    }
                                }
                                if (b == k / 2) {
                                    for (b = 0; b < k-1; b++) {
                                        printf("%c", p[i][b + x]);

                                    }
                                    printf("%c\n", p[i][b + x]);
                                    //putchar('\n');
                                    break;
                                }break;

                            }
                        }

                        if (x!= 0 && y == n-1){
                            if (!(isalpha(p[i][x-1]))) {

                                k = y - x + 1;
                                for (b = 0; b < k / 2; b++) {
                                    if (p[i][x+b] != p[i][y-b]) {
                                        break;
                                    }

                                }
                                if (b == k / 2) {
                                    for (b = 0; b < k-1; b++){
                                        printf("%c", p[i][b + x]);
                                    }
                                    printf("%c\n", p[i][b + x]);
                                    //putchar('\n');
                                    break;
                                }
                            }
                        }

                        if ( x== 0 && y != n-1){
                            if (!(isalpha(p[i][y+1]))) {

                                k = y - x + 1;
                                for (b = 0; b < k / 2; b++) {
                                    if (p[i][x+b] != p[i][y-b]) {
                                        break;
                                    }

                                }
                                if (b == k / 2) {
                                    for (b = 0; b < k-1; b++){
                                        printf("%c", p[i][b + x]);
                                    }
                                    printf("%c\n", p[i][b + x]);
                                    //putchar('\n');
                                    break;
                                }
                            }
                        }
                        if ( x== 0 && y == n-1){

                            k = y - x + 1;
                            for (b = 0; b < k / 2; b++) {
                                if (p[i][x+b] != p[i][y-b]) {
                                    break;
                                }

                            }
                            if (b == k / 2) {
                                for (b = 0; b < k-1; b++){
                                    printf("%c", p[i][b + x]);
                                }
                                printf("%c\n", p[i][b + x]);
                                //putchar('\n');
                                break;
                            }
                        }
                    }
                }
            }
        }

        printf("VERTIKALNO\n");
        for (j = 0; j < m; j++) {
            for (x = 0; x < n; x++) {
                for (y = n - 1; y >= 0; y--) {

                    if (p[x][j] == p[y][j]) {
                        if (x == 0 && y == n-1){
                            if ((isalpha(p[x][j])) && (isalpha(p[y][j]))) {
                                k = y - x + 1;
                                for (b = 0; b < k / 2; b++) {
                                    if (p[x + b][j] != p[y - b][j]) {
                                        break;
                                    }

                                }
                                if (b == k / 2) {
                                    for (b = 0; b < k; b++) {
                                        printf("%c", p[b + x][j]);
                                    }
                                    putchar('\n');
                                }
                            }
                            break;
                        }
                        if (x != 0 && y != n-1){
                            if (!(isalpha(p[x-1][j])) && !(isalpha(p[y+1][j]))) {
                                if ((isalpha(p[x][j])) && (isalpha(p[y][j]))) {
                                    k = y - x + 1;
                                    for (b = 0; b < k / 2; b++) {
                                        if (p[x + b][j] != p[y - b][j]) {
                                            break;
                                        }

                                    }
                                    if (b == k / 2) {
                                        for (b = 0; b < k; b++) {
                                            printf("%c", p[b + x][j]);
                                        }
                                        putchar('\n');
                                    }
                                }
                            }
                            break;
                        }
                        if (x == 0 && y != n-1) {
                            if (!(isalpha(p[y + 1][j]))) {
                                if ((isalpha(p[x][j])) && (isalpha(p[y][j]))) {
                                    k = y - x + 1;
                                    for (b = 0; b < k / 2; b++) {
                                        if (p[x + b][j] != p[y - b][j]) {
                                            break;
                                        }

                                    }
                                    if (b == k / 2) {
                                        for (b = 0; b < k; b++) {
                                            printf("%c", p[b + x][j]);
                                        }
                                        putchar('\n');
                                    }
                                }
                            }
                            break;
                        }
                        if (x != 0 && y == n-1){
                            if (!(isalpha(p[x-1][j]))) {
                                if ((isalpha(p[x][j])) && (isalpha(p[y][j]))) {
                                    k = y - x + 1;
                                    for (b = 0; b < k / 2; b++) {
                                        if (p[x + b][j] != p[y - b][j]) {
                                            break;
                                        }

                                    }
                                    if (b == k / 2) {
                                        for (b = 0; b < k; b++){
                                            printf("%c", p[b + x][j]);
                                        }
                                        putchar('\n');
                                    }
                                }
                            }
                            break;
                        }
                        if (x != 0 && y == n-1) {
                            if (!(isalpha(p[x - 1][j]))) {
                                if ((isalpha(p[x][j])) && (isalpha(p[y][j]))) {
                                    k = y - x + 1;
                                    for (b = 0; b < k / 2; b++) {
                                        if (p[x + b][j] != p[y - b][j]) {
                                            break;
                                        }

                                    }
                                    if (b == k / 2) {
                                        for (b = 0; b < k; b++) {
                                            printf("%c", p[b + x][j]);
                                        }
                                        putchar('\n');
                                    }

                                }

                            }

                        }
                        break;
                    }
                }
            }

        }

        printf("DIJAGONALNO\n");
        // GLAVNAA DIJAGONALAAA
        for (i = 0; i<n; i++){
            for (z = n-1; z>=0; z--){
                if (p[i][i] == p[z][z]){
                    if ((p[i][i] == p[z][z]) && isalpha(p[i][i]) && isalpha(p[z][z])){
//                        if (x == y && (!isalpha(p[i - 1][i - 1]) && !(isalpha(p[z + 1][z + 1]))) && isalpha(p[i][x])) {
//                            printf("%c\n", p[i][x]);
//                            break;
//                        }


                        if ((i == 0) && (z == n-1)){
                            k = z - i + 1;
                            for (b = 0; b < k / 2; b++) {
                                if (p[i + b][i + b] != p[z - b][z - b]) {
                                    break;
                                }

                            }
                            if (b == k / 2) {
                                for (b = 0; b < k; b++) {
                                    printf("%c", p[b + i][b + i]);
                                }
                                putchar('\n');
                            }
                            break;
                        }




                        if ((i == 0)&&(z!=n-1)){
                            if (!(isalpha(p[z + 1][z + 1]))){
                                k = z - i + 1;
                                for (b = 0; b < k / 2; b++) {
                                    if (p[i + b][i + b] != p[z - b][z - b]) {
                                        break;
                                    }

                                }
                                if (b == k / 2) {
                                    for (b = 0; b < k; b++) {
                                        printf("%c", p[b + i][b + i]);
                                    }
                                    putchar('\n');
                                }
                            }
                            break;
                        }




                        if ((i != 0)&& (z == n-1)) {
                            if (!(isalpha(p[i - 1][i - 1]))) {
                                k = z - i + 1;
                                for (b = 0; b < k / 2; b++) {
                                    if (p[i + b][i + b] != p[z - b][z - b]) {
                                        break;
                                    }

                                }
                                if (b == k / 2) {
                                    for (b = 0; b < k; b++) {
                                        printf("%c", p[b + i][b + i]);
                                    }
                                    putchar('\n');
                                }
                            }
                            break;
                        }





                        if ((i != 0) && (z != n -1 )){
                            if (!(isalpha(p[i - 1][i - 1])) && !(isalpha(p[z + 1][z + 1]))) {
                                k = z - i + 1;
                                for (b = 0; b < k / 2; b++) {
                                    if (p[i + b][i + b] != p[z - b][z - b]) {
                                        break;
                                    }

                                }
                                if (b == k / 2) {
                                    for (b = 0; b < k; b++) {
                                        printf("%c", p[b + i][b + i]);
                                    }
                                    putchar('\n');
                                }
                                break;
                            }
                        }

                    }

                }
            }
        }
        // SPOREDNAA DIJAGONALAAAA
        ;
        for (i=0; i<n; i++){
            for (z = 0; z<n; z++){
                if ((p[(n-1-i)][i] == p[z][n-1-z]) && isalpha(p[n-1-i][i]) && isalpha(p[z][n-1-z])){
                    if (i == 0 && z==0){

                        k = n-i-z;
                        for (b = 0; b < k / 2; b++) {
                            if (p[n-1-i-b][i+b] != p[z+b][n-1-z-b]) {
                                break;
                            }

                        }
                        if (b == k / 2) {
                            for (b = 0; b < k; b++) {
                                printf("%c", p[n-1-i-b][i+b]);
                            }
                            putchar('\n');
                        }
                        break;
                    }
                    if (i != 0 && z == 0){
                        if (!isalpha(p[n-1-i+1][i-1])) {
                            k = n-i-z;
                            for (b = 0; b < k / 2; b++) {
                                if (p[n-1-i-b][i+b] != p[z+b][n-1-z-b]) {
                                    break;
                                }

                            }
                            if (b == k / 2) {
                                for (b = 0; b < k; b++) {
                                    printf("%c", p[n-1-i-b][i+b]);
                                }
                                putchar('\n');
                            }
                            break;
                        }
                    }
                    if (i == 0 && z != 0){
                        if (!isalpha(p[z-1][n-1-z+1])){
                            k = n-i-z;
                            for (b = 0; b < k / 2; b++) {
                                if (p[n-1-i-b][i+b] != p[z+b][n-1-z-b]) {
                                    break;
                                }

                            }
                            if (b == k / 2) {
                                for (b = 0; b < k; b++) {
                                    printf("%c", p[n-1-i-b][i+b]);
                                }
                                putchar('\n');
                            }
                            break;
                        }
                    }
                    if (i != 0 && z != 0){
                        if (!isalpha(p[n-1-i+1][i-1]) && !isalpha(p[z-1][n-1-z+1])){
                            k = n-i-z;
                            for (b = 0; b < k / 2; b++) {
                                if (p[n-1-i-b][i+b] != p[z+b][n-1-z-b]) {
                                    break;
                                }

                            }
                            if (b == k / 2) {
                                for (b = 0; b < k; b++) {
                                    printf("%c", p[n-1-i-b][i+b]);
                                }
                                putchar('\n');
                            }
                            break;

                        }
                    }
                }
            }
        }
        for (i=0;i<n;i++) free(p[i]); free(p);
        return 0;
    }


    return 0;
}


