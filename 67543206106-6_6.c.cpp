#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
    struct Node *Back;
};
typedef struct Node N;

void AddNode(N **, int Data);
void InsertNode(N **, int Data, int position);
void DeleteNode(N **, int position);
void SwapNode(N **, int position1, int position2);
void ShowFront(N **);
void ShowBack(N **);

int main() {
    N *start = NULL;
    int data = 0, pos1 = 0, pos2 = 0;

    printf("Add (data) : "); scanf("%d", &data); AddNode(&start, data);
    printf("Add (data) : "); scanf("%d", &data); AddNode(&start, data);
    printf("Add (data) : "); scanf("%d", &data); AddNode(&start, data);
    ShowFront(&start);
    ShowBack(&start);

    printf("Insert (data pos) : "); scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    printf("Insert (data pos) : "); scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    printf("Insert (data pos) : "); scanf("%d %d", &data, &pos1); InsertNode(&start, data, pos1);
    ShowFront(&start);

    printf("Delete (pos) : "); scanf("%d", &pos1); DeleteNode(&start, pos1);
    printf("Delete (pos) : "); scanf("%d", &pos1); DeleteNode(&start, pos1);
    ShowFront(&start);

    printf("Swap (pos1 pos2) : "); scanf("%d %d", &pos1, &pos2); SwapNode(&start, pos1, pos2);
    ShowFront(&start);
    return 0;
}

void AddNode(N **Walk, int Data) {
    N *newNode = (N *)malloc(sizeof(N));
    newNode->Data = Data;
    newNode->Next = NULL;
    newNode->Back = NULL;
    
    if (*Walk == NULL) {
        *Walk = newNode;
    } else {
        N *temp = *Walk;
        while (temp->Next != NULL)
            temp = temp->Next;
        temp->Next = newNode;
        newNode->Back = temp;
    }
}

void ShowFront(N **Walk) {
    N *temp = *Walk;
    printf("Show Front : ");
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("\n");
}

void ShowBack(N **Walk) {
    N *temp = *Walk;
    if (temp == NULL) return;
    while (temp->Next != NULL)
        temp = temp->Next;
    printf("Show Back : ");
    while (temp != NULL) {
        printf("%d ", temp->Data);
        temp = temp->Back;
    }
    printf("\n");
}

void InsertNode(N **Walk, int Data, int position) {
    N *newNode = (N *)malloc(sizeof(N));
    newNode->Data = Data;
    
    if (position == 1) {
        newNode->Next = *Walk;
        if (*Walk != NULL)
            (*Walk)->Back = newNode;
        *Walk = newNode;
        return;
    }
    
    N *temp = *Walk;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->Next;
    
    if (temp == NULL) {
        free(newNode);
        return;
    }
    
    newNode->Next = temp->Next;
    if (temp->Next != NULL)
        temp->Next->Back = newNode;
    temp->Next = newNode;
    newNode->Back = temp;
}

void DeleteNode(N **Walk, int position) {
    if (*Walk == NULL)
        return;
    
    N *temp = *Walk;
    if (position == 1) {
        *Walk = temp->Next;
        if (*Walk != NULL)
            (*Walk)->Back = NULL;
        free(temp);
        return;
    }
    
    for (int i = 1; temp != NULL && i < position; i++)
        temp = temp->Next;
    
    if (temp == NULL)
        return;
    
    if (temp->Next != NULL)
        temp->Next->Back = temp->Back;
    if (temp->Back != NULL)
        temp->Back->Next = temp->Next;
    
    free(temp);
}

void SwapNode(N **Walk, int position1, int position2) {
    if (position1 == position2)
        return;
    
    N *node1 = *Walk, *node2 = *Walk;
    for (int i = 1; node1 != NULL && i < position1; i++)
        node1 = node1->Next;
    for (int i = 1; node2 != NULL && i < position2; i++)
        node2 = node2->Next;
    
    if (node1 == NULL || node2 == NULL)
        return;
    
    int temp = node1->Data;
    node1->Data = node2->Data;
    node2->Data = temp;
}
