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
            printf("GRESKA\n");
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
        printf("GRESKA\n");
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
                printf("GRESKA\n");
                exit(1);
            }
            else { return lines; }
        }

        lines = realloc(lines, (i + 2) * (sizeof(char*)));
        if (lines == NULL) {
            perror(NULL);
            exit(0);
        }

        lines[i] = p;
        i++;
        lines[i] = NULL;
    }

}

int main() {
    char *p = NULL, valuta;
    char **exchgValues;
    char *a, *msg, *currencyCode;
    char c, bl;
    int tacka, v, i = 0, j = 0, pom1 = 0, pom2 = 0, pom3, pocetak_broja, pocetak_valute, kraj_broja;
    int konacna, x, y;
    int stepen;
    char string;
    double broj = 0, broj_valute, KONACNIBROJ;
    int pocetak_vrednosti_valute, tacka_valute, kraj_vrednosti_valute;
    int *indeksi = 0;
    int brojac = 0;
    int brojacIn = 0;
    int m;
    msg = readLine();
    if (*msg=='\0'){
        printf("GRESKA\n");
        exit(0);
    }
    currencyCode = readLine();
    exchgValues = readLines();


    //i = 0;

    x = 0;
    while (exchgValues[x] != NULL) {
        i = 0;
        while (msg[i] != '\0') {
            if (msg[i] == exchgValues[x][0]) {
                pom1 = i;
                if (msg[i + 1] == exchgValues[x][1]) {
                    if (msg[i + 2] == exchgValues[x][2]) {



                        pocetak_valute = pom1;

                        while (msg[pom1 - 2] != ' ') {
                            if (msg[pom1 - 2] == '.') {
                                tacka = pom1 - 2;
                            }
                            pom1--;
                        }

                        pocetak_broja = pom1 - 1;
                        kraj_broja = pocetak_valute - 2;

                        while (brojac<pocetak_broja){
                            printf("%c",msg[brojac]);
                            brojac++;
                        }

                        stepen = 1;
                        broj = 0;
                        for (v = tacka - 1; v >= pocetak_broja; v--) {

                            broj += (msg[v] - 48) * stepen;

                            stepen *= 10;
                        }
                        stepen = 1/10;
                        for (v = tacka + 1; v <= kraj_broja; v++) {
                            broj += (msg[v] - 48) * stepen;
                            stepen /= 10;
                        }

                        pocetak_vrednosti_valute = 4;
                        v = pocetak_vrednosti_valute;
                        while (exchgValues[x][v] != NULL) {
                            if (exchgValues[x][v] == '.') {
                                tacka_valute = v;
                            }
                            v++;

                        }
                        kraj_vrednosti_valute = v - 1;

                        stepen = 1;
                        broj_valute = 0;

                        for (v = tacka_valute - 1; v >= pocetak_vrednosti_valute; v--) {

                            broj_valute += ((exchgValues[x][v]) - 48) * stepen;

                            stepen *= 10;
                        }
                        double stepen1;
                        stepen1 = 0.1;

                        for (v = tacka_valute + 1; v <= kraj_vrednosti_valute; v++) {

                            broj_valute += ((exchgValues[x][v]) - 48) * stepen1;

                            stepen1 /= 10;
                        }


                        KONACNIBROJ = broj_valute * broj;



                        printf("%.2lf %s", KONACNIBROJ, currencyCode);
                        brojac = pocetak_valute+3;


                    }

                }
            }

            i++;
        }
        x++;
    }
    while(msg[brojac] != '\0'){
        printf("%c", msg[brojac]);
        brojac++;
    }
    putchar('\n');


    int t= 0;

    while (exchgValues[t] != NULL){
        free(exchgValues[t]);
        t++;
    }
    free(exchgValues);
    free(msg);
    free(currencyCode);
    return 0;




#include<stdio.h>
#include<string.h>

    int main()
    {
        char *s1 = "hello";
        char *s2 = "world";

        printf("Address of string pointed by s1 = %u\n", s1);
        printf("Address of string pointed by s2 = %u\n\n", s2);

        printf("Is s1 == s2 ? %u\n", s1 == s2);
        printf("Is s1 > s2 ? %u\n", s1 > s2);
        printf("Is s1 < s2 ? %u\n", s1 < s2);

        // signal to operating system program ran fine
        return 0;
    }
}