#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct time {

    int hours, minutes;

} Time;



#define MAX_LENGTH 20

typedef struct patient {

    char forename[MAX_LENGTH + 1], surname[MAX_LENGTH + 1];

    int severity;

    Time sanitationTime;

} Patient;



typedef struct node {

    Patient patient;

    struct node *next;

} Node;



Node* readPatients ( ) {
    Node *head = NULL, *tail = head, *tmp;
    Patient pacijent;
    int brojac=0;
    FILE *file = fopen("pacijenti.txt", "r");
    if (!file) exit(1);
    while(fscanf(file, "%s %s %d %d:%d", pacijent.forename, pacijent.surname, &pacijent.severity, &pacijent.sanitationTime.hours, &pacijent.sanitationTime.minutes)==5){
        brojac++;
        tmp = malloc(sizeof(*tmp));
        if (!tmp) exit(1);
        tmp->patient = pacijent;
        tmp->next = NULL;
        if (!head) head = tmp;
        else tail->next = tmp;
        tail = tmp;
    }
    fclose(file);
    return head;
}

void sortPatients ( Node *head ) {
    int max;
    max = head->patient.severity;
    Node *tmp;
    int i=0;
    tmp = head;
    while(tmp){
        if (tmp->patient.severity > max){
            max = tmp->patient.severity;

        }

        tmp= tmp->next;
    }
    while(i>0){

    }

}

void ispisliste(Node* head){
    Node *old;
    int i=0;
    FILE *file = fopen("izlaz.txt", "w");
    while(head){
        fprintf(file, "N%d = { %s %s %d %d:%d }\n", i, head->patient.forename, head->patient.surname, head->patient.severity, head->patient.sanitationTime.hours, head->patient.sanitationTime.minutes);
        i++;
        old = head;
        head = head->next;
        free(old);
    }

    fclose(file);

}



void main(){
    Node *head;
    head = readPatients();
    ispisliste(head);
}