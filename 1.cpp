#include <stdio.h>
#include <stdlib.h>  

void GetMatrix(int *value, int *row, int *col);
void PrintMatrix(int *value, int row, int col);

int main() {
    int m, n;
    
    scanf("%d %d", &m, &n);
    
    int *data = (int *)malloc(m * n * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    GetMatrix(data, &m, &n);
    
    PrintMatrix(data, m, n);
    
    free(data);

    return 0;
}

void GetMatrix(int *value, int *row, int *col) {
    for (int i = 0; i < (*row); i++) {
        for (int j = 0; j < (*col); j++) {
            scanf("%d", (value + i * (*col) + j));
        }
    }
}

void PrintMatrix(int *value, int row, int col) {
    printf("Matrix (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", *(value + i * col + j));
        }
        printf("\n");
    }
}
