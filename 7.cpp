#include <stdio.h>

class Node {
public:
    int Data;
    Node *Next;
    Node *Back;
    Node(int data = 0) : Data(data), Next(NULL), Back(NULL) {}
};

class DoubleLinkedList {
private:
    Node *head;
    Node *tail;
public:
    DoubleLinkedList() : head(NULL), tail(NULL) {}

    void AddNode(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->Next = newNode;
            newNode->Back = tail;
            tail = newNode;
        }
    }

    void InsertNode(int data, int pos) {
        Node *newNode = new Node(data);
        if (pos == 1) {
            newNode->Next = head;
            if (head != NULL) {
                head->Back = newNode;
            }
            head = newNode;
            if (tail == NULL) {
                tail = newNode;
            }
            return;
        }

        Node *temp = head;
        int count = 1;
        while (temp != NULL && count < pos - 1) {
            temp = temp->Next;
            count++;
        }

        if (temp != NULL) {
            newNode->Next = temp->Next;
            newNode->Back = temp;
            if (temp->Next != NULL) {
                temp->Next->Back = newNode;
            }
            temp->Next = newNode;
            if (newNode->Next == NULL) {
                tail = newNode;
            }
        } else {
            printf("Position out of range\n");
        }
    }

    void DeleteNode(int pos) {
        if (head == NULL) {
            printf("List is empty\n");
            return;
        }

        Node *temp = head;
        if (pos == 1) {
            head = temp->Next;
            if (head != NULL) {
                head->Back = NULL;
            }
            delete temp;
            if (head == NULL) {
                tail = NULL;
            }
            return;
        }

        int count = 1;
        while (temp != NULL && count < pos) {
            temp = temp->Next;
            count++;
        }

        if (temp != NULL) {
            if (temp->Next != NULL) {
                temp->Next->Back = temp->Back;
            }
            if (temp->Back != NULL) {
                temp->Back->Next = temp->Next;
            }
            delete temp;
            if (head == NULL) {
                tail = NULL;
            }
        } else {
            printf("Position out of range\n");
        }
    }

    void ShowFront() {
        Node *temp = head;
        if (temp == NULL) {
            printf("List is empty\n");
            return;
        }
        while (temp != NULL) {
            printf("%d ", temp->Data);
            temp = temp->Next;
        }
        printf("\n");
    }

    void ShowBack() {
        Node *temp = tail;
        if (temp == NULL) {
            printf("List is empty\n");
            return;
        }
        while (temp != NULL) {
            printf("%d ", temp->Data);
            temp = temp->Back;
        }
        printf("\n");
    }
};

int main() {
    DoubleLinkedList A, B;
    int data, pos;

    // Add test case inputs
    printf("Add (data) : ");
    scanf("%d", &data);
    A.AddNode(data);

    printf("Add (data) : ");
    scanf("%d", &data);
    A.AddNode(data);

    A.ShowFront();

    printf("Insert (data pos) : ");
    scanf("%d %d", &data, &pos);
    A.InsertNode(data, pos);

    printf("Insert (data pos) : ");
    scanf("%d %d", &data, &pos);
    A.InsertNode(data, pos);

    A.ShowFront();

    printf("Delete (pos) : ");
    scanf("%d", &pos);
    A.DeleteNode(pos);

    printf("Delete (pos) : ");
    scanf("%d", &pos);
    A.DeleteNode(pos);

    A.ShowFront();

    printf("---\n");

    printf("Add (data) : ");
    scanf("%d", &data);
    B.AddNode(data);

    printf("Add (data) : ");
    scanf("%d", &data);
    B.AddNode(data);

    printf("Add (data) : ");
    scanf("%d", &data);
    B.AddNode(data);

    B.ShowBack();

    return 0;
}
