#include <stdio.h>

#include <stdlib.h>

#define TYPE_H



typedef struct {

    char name[31];

    int team_id;

    unsigned time;

    char country_code[4];

} runner_t;



typedef struct runner_node {

    runner_t *runner;

    struct runner_node *next;

} runner_node_t;

runner_node_t* read_node(FILE *input) {
    runner_node_t *head=NULL, *tail=head, *tmp;
    runner_t trkac;
    fopen(input, "r");
    if (!input) exit(1);
    while(fscanf(input,"%s|%d %d %s", trkac.name,&trkac.team_id, &trkac.time,trkac.country_code)==4){
        tmp = malloc(sizeof(*tmp));
        tmp->runner = &trkac;
        tmp->next = NULL;
        if(!head) head=tmp;
        else tail->next=tmp;
        tail = tmp;

    }
    return head;
}
void write_and_free(runner_node_t  *head){
    runner_node_t * old;
    FILE *input = fopen("trkaci.txt", "w");
    if (!input) exit(1);
    while (head){
        fprintf(input,"%s|%d %d %s", head->runner->name,head->runner->team_id, head->runner->time,head->runner->country_code);
        old = head;
        head = head->next;
        free(old);
    }
    fclose(input);
}

int main(){
    runner_node_t *head;
    head = read_node("trkaci.txt");
    write_and_free(head);
}