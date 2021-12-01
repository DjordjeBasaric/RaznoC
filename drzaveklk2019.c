#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#ifndef TYPE_H
#define TYPE_H

typedef struct data {
    char name[31];
    int numberOfDays;
    int *days;
} TData;

typedef struct node {
    TData *data;
    struct node *next;
} TNode;
#endif

TNode* readNode ( FILE *input ) {
    if (input == EOF){
        printf("PRAzno");
        exit(1);
    }
    TNode *head = NULL, *tail = head, *tmp;
    TData podaci;
    fscanf(input, "%[^|]", podaci.name);
    int p=0;
    fgetc(input);
    fscanf(input, "%d ",  &podaci.numberOfDays);
    podaci.days = (int*) calloc(podaci.numberOfDays,sizeof(podaci.days));
    for (int i=0; i<podaci.numberOfDays; i++){
        p++;
        fscanf(input, "%d", &podaci.days[i]);
    }
    if (p == 0){
        return 0;
    }
    tmp = malloc(sizeof(*tmp));
    if (!tmp) exit(1);
    tmp->data = &podaci;
    tmp->next = NULL;
    if (!head) head = tmp;
    else tail->next = tmp;
    tail = tmp;
    return head;
}

int main ( ) {
    FILE *input = fopen ( "evidencija.txt", "r" );
    if ( input == NULL) {
        return 0;
    }
    TNode *node = readNode ( input );
    if ( node != NULL) {
        printf ( "%s %d ", node->data->name, node->data->numberOfDays );
        for ( int i = 0; i < node->data->numberOfDays; ++i ) {
            printf ( "%d ", node->data->days[ i ] );
        }

    }
    fclose ( input );
    return 0;
}