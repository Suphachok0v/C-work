#include <stdio.h>
#include <stdlib.h>

struct student {
    char Name[20];
    int Age;
} typedef SS;

SS (*GetStudent(int *N))[4];
void PrintStudent(SS *, int N);

int main() {
    SS (*children)[4];
    int group;
    children = GetStudent(&group);
    PrintStudent(*children, group);
    free(children);
    return 0;
}

SS (*GetStudent(int *N))[4] {
    printf("Enter Group : ");
    scanf("%d", N);

    SS (*students)[4] = (SS(*)[4])malloc((*N) * 4 * sizeof(SS));
    if (!students) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < *N; i++) {
        printf("Class %d :\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("[%d/4] Enter Student Info (Name Age) : ", j + 1);
            scanf("%s %d", students[i][j].Name, &students[i][j].Age);
        }
    }
    return students;
}
void PrintStudent(SS *students, int N) {
    for (int i = 0; i < N; i++) {
        printf("Class%d\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%s %d\n", students[i * 4 + j].Name, students[i * 4 + j].Age);
        }
    }
}
