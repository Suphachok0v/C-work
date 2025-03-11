#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    float gpa;
    struct studentNode *next;
};
typedef struct studentNode Node;

void saveNode(Node *child);
void GoNext(Node **now);

int main() {
    Node *start, *now;
    
    start = (Node *)malloc(sizeof(Node));
    saveNode(start);

    start->next = (Node *)malloc(sizeof(Node));
    saveNode(start->next);

    start->next->next = (Node *)malloc(sizeof(Node));
    saveNode(start->next->next);
    
    start->next->next->next = NULL;

    now = start;
    GoNext(&now);
    GoNext(&now);
    GoNext(&now);
    
    // Free memory
    while (start != NULL) {
        Node *temp = start;
        start = start->next;
        free(temp);
    }
    
    return 0;
}

void saveNode(Node *child) {
    printf("Enter (Name Age GPA) : ");
    scanf("%s %d %f", child->name, &child->age, &child->gpa);
    child->next = NULL;
}

void GoNext(Node **now) {
    if (*now != NULL) {
        printf("[%s, %d, %.1f]\n", (*now)->name, (*now)->age, (*now)->gpa);
        *now = (*now)->next;
    }
}
