
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct node {
    char* data;

    struct node* next;
} Node;
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

Node* formList() {
    int cena;
    char* p;
    int i = 0;
    char* line;
    int duzina = 0;
    Node* head = NULL;
    Node* last = NULL;
    while (1){
        line = readLine();
        if (line[0] == '\0'){
            break;
        }
        Node* node = calloc(1, sizeof(Node));
        node->data = line;
        node->next = NULL;

        if (last == NULL){
            head = node;
        }
        else {
            last->next = node;
        }
        last = node;

    }
    return head;
}
void printList(Node* head){
    char* y;
    char** x;
    for (Node* current = head; current != NULL; current = current->next){
        y = current->data;

        printf("%s\n", y);
    }
}
Node* removeNodes(Node* head, char* linija){
    for (Node *current = head, *previous = NULL; current != NULL;){
        if (current->data == linija){
            Node* old = current;
            current = current->next;
            free(old);

            if (previous == NULL) {
                head = current;
            }
            else {
                previous->next = current;
            }

        }
        else {
            previous = current;
            current = current->next;
        }
    }
    return head;
}
Node* formPackage(Node* head, char* paket12) {
    int paket=atoi(paket12);
    int ostalo = 0;
    Node* head2 = NULL;
    Node* last2 = NULL;
    int brojac = 0, i=0, p = 0;
    char* linija ;

    ostalo = paket;
    for (Node *current = head; current != NULL; current = current->next) {
        p = 0;
        linija = current->data;
        while((linija[p]!= ' ') && (linija[p]!='-')){
            p++;
        }
        linija[p] = '-';
        int stepen = 1;
        int broj = 0;

        for (i=p-1; i>=0; i--) {

            broj += (linija[i]-48)*stepen;

            stepen *= 10;
        }
        if (broj > paket){
            head = removeNodes(head, linija);
            break;
        }
        if (ostalo - broj >= 0){
            ostalo = ostalo - broj;


            Node* ceopaket = calloc(1, sizeof(Node));


            ceopaket->data = linija;
            ceopaket->next = NULL;


            if (last2 == NULL){
                head2 = ceopaket;
            }
            else {
                last2->next = ceopaket;
            }
            last2 = ceopaket;
            head = removeNodes(head, linija);
        }

    }
    if (head2 == NULL){
        return 0;
    }
    if (head2 != NULL){
        printList(head2);
    }

    if (paket-ostalo > 0){
        printf("%d", paket - ostalo);
    }
    putchar('\n');

    return head;
}



int main() {
    char *linija;
    char *paket123;
    paket123 = readLine();
    Node *head;
    Node *head2;
    head = formList();
    while (head != NULL) {
        head = formPackage(head, paket123);

    }




}
