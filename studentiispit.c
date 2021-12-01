#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char id[10];
    char name[31];
    char mod[3];
    char group[3];
    float pts, p1, p2,p3,p4;
    int z, grade;
}Student;

typedef struct elem{
    Student s;
    struct elem *next;
} Elem;

Elem* create_list(){
    Elem *head = NULL, *tail = head, *tmp;
    Student s;
    FILE *file= fopen("ispit.csv", "r");
    if (!file) exit(1);
    char *format = "%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f,%d\n"; //uglaste zagrade znace da citam sve karaktere iz jednog skupa, kapica predstavlja negaciju(ne citam sve karaktere nego sve karaktere koji nisu u skupu)
    while (fscanf(file, format, s.id, s.name, s.mod, s.group, &s.p1, &s.p2, &s.p3, &s.p4, &s.z) == 9){//povratna vrednost je broj uspesno ocitanih info
        float p = s.p1 + s.p2 + s.p3 + s.p4;
        s.pts = (p > 45 ? 45 : p<0 ? 0 : p) + s.z;
        s.grade = s.pts /10;
        if (s.grade < 5) s.grade = 5;
        else if (s.pts > s.grade*10) s.grade++;

        tmp = malloc(sizeof(*tmp));
        if (!tmp) exit(1);
        tmp->s = s;
        tmp->next = NULL;
        if (!head) head = tmp;
        else tail->next = tmp;
        tail = tmp;



    }


    fclose(file);
    return head;
}
void write_and_free(Elem* head){
    Elem* old;
    FILE *file = fopen("ocene.txt", "w");
    if (!file) exit(1);
    while (head){
        fprintf(file,"%s, %s, %s, %s, %.2f, %d\n", head->s.mod, head->s.group, head->s.id, head->s.name, head->s.pts, head->s.grade);
        old = head;
        head = head->next;
        free(old);
    }
    fclose(file);
}
int cmp(Student s1, Student s2){
    int m = strcmp(s1.mod, s2.mod);
    if (m) return m;
    else {
        int g = strcmp(s1.group, s2.group);
        if (g) return g;
        else return strcmp(s1.id,s2.id);

    }
}
void sort(Elem *head){
    for(Elem *p = head; p; p = p->next )
        for(Elem *d = p->next; d; d = d->next){
            if (cmp(p->s, d->s) > 0){
                Student tmp = p->s;
                p->s = d->s;
                d->s = tmp;
            }
        }
}

int main() {
    Elem *head = create_list();
    sort(head);
    write_and_free(head);
    return 0;
}
