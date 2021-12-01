#include <stdio.h>
//PLAINDROM
int main(void) {
    char p[5];
    int b, i,j,temp_i,temp_j;

    for (i=0;i<5;i++)
        scanf("%c", &p[i])  ;
    for (i = 0; i<5; i++){
        for (j = 5; j>0; i--){
            if (p[i] == p[j]){
                temp_i = i;
                temp_j = j;
                while (p[temp_i] == p[temp_j]){
                    temp_j--;
                    temp_i++;
                }
                if (p[temp_i] == p[temp_j]){
                    for (b = i; b<j; b++)
                        printf("%c", p[b]);}
            }


        }
    }

    for (i=0;i<5;i++)
        printf("%c", p[i]) ;
    return 0;
}