#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
char* readLine();
char** readLines();


char* readLine() {
    char* line = NULL, c;
    int i = 0;
    // ucitavanje karaktera

    while (1) {

        c = getchar();
        if (c == '\n') {
            break;
        }

        line = realloc(line, ((i + 1) * sizeof(char)));
        if (!line) {
            printf("GRESKA");
            perror(NULL);
            exit(0);
        }
        line[i++] = c;
        if (c == '\n') {
            break;
        }
    }
    // dodavanje terminalnog znaka
    line = realloc(line, (i) * sizeof(char));
    if (line == NULL) {
        printf("GRESKA");
        perror(NULL);
        exit(0);
    }

    line[i] = '\0';
    return line;
}


char** readLines() {
    char** lines = 0;
    char* p;
    int i = 0;
    while (1) {
        p = readLine();
        if (*p == '\0') {
            if (i == 0) {
                printf("GRESKA");
                exit(1);
            }
            else { return lines; }
        }

        lines = realloc(lines, (i + 2) * (sizeof(char*)));
        if (*lines == '\0') {
            perror(NULL);
            exit(0);
        }

        lines[i] = p;
        i++;
        lines[i] = NULL;
    }

}


int main() {
    char* p = NULL, valuta;
    char** exchgValues;
    char* a, * msg, * currencyCode;
    char c, bl;
    int tacka, v, i = 0, j = 0, pom1 = 0, pom2 = 0, pom3, pocetak_broja, pocetak_valute, kraj_broja;
    int konacna, x, y;
    int stepen;
    char string;
    double broj = 0;
    msg = readLine();
    currencyCode = readLine();
    exchgValues = readLines();

    printf("%s\n", msg);
    printf("%s\n", currencyCode);

    while (exchgValues[i] != '\0') {
        j = 0;
        while (exchgValues[i][j]) {
            printf("%c", exchgValues[i][j]);
            j++;
        }
        putchar('\n');
        i++;
    }
    //i = 0;

    x = 0;
    while (exchgValues[x] != NULL) {
        i = 0;
        while (msg[i] != NULL) {
            if (msg[i] == exchgValues[x][0]) {
                pom1 = i;
                if (msg[i + 1] == exchgValues[x][1]) {
                    if (msg[i + 2] == exchgValues[x][2]) {

                        printf("pocetak valute: %d\n", pom1);

                        pocetak_valute = pom1;
                        //printf("NASAO SAM ---%c---\n", exchgValues[0][pom1 - 1]);
                        while (msg[pom1 - 2] != ' ') {
                            if (msg[pom1 - 2] == '.') {
                                tacka = pom1 - 2;
                            }
                            pom1--;
                        }

                        printf("valuta: %c%c%c\n", exchgValues[x][0], exchgValues[x][1], exchgValues[x][2]);
                        pocetak_broja = pom1 - 1;
                        kraj_broja = pocetak_valute - 2;


                        printf("pocetak broja: %d\n", pocetak_broja);
                        printf("kraj broja: %d\n", kraj_broja);
                        printf("tacka: %d\n", tacka);
                        stepen = 1;
                        for (v = tacka - 1; v >= pocetak_broja; v--) {
                            broj += msg[v] * stepen;
                            printf("%d", broj);
                            stepen *= 10;
                        }
                        printf("%lf", broj);
                    }

                }
            }
            //x++;
            i++;
        }
        x++;

    }





    // char provera[] = "0123456789" ;
    //p = strpbrk(exchgValues, provera);
    //a = strstr(exchgValues, "EUR");
    //if (a != NULL) {
    //  printf("%c", a);

    //}

    //    putchar('\n');
    //    printf("%s\n", exchgValues);
    //
    //    printf("%s", valuta);
    free(exchgValues);
    // free(valuta);
    // system("pause");
    return 0;
}