#include <stdio.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x, int currentWeight, int currentValue);

int main() {
    int n = 5, wx = 11, vx, i;
    
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter wx : ");
    scanf("%d", &wx);
    
    int *w = new int[n];
    int *v = new int[n];
    for (i = 0; i < n; i++) {
        printf("weight for item %d : ", i);
        scanf("%d", &w[i]);
    }
    for (i = 0; i < n; i++) {
        printf("value for item %d : ", i);
        scanf("%d", &v[i]);
    }
    
    int *x = new int[n];
    vx = KnapsackBT(w, v, n, wx, 0, x, 0, 0);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);
    printf("\nValue = %d", vx);
    return 0;
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x, int currentWeight, int currentValue) {
    if (i == n) {
        return currentValue;
    }

    int excludeValue = KnapsackBT(w, v, n, wx, i + 1, x, currentWeight, currentValue);

    int includeValue = 0;
    if (currentWeight + w[i] <= wx) {
        x[i] = 1;
        includeValue = KnapsackBT(w, v, n, wx, i + 1, x, currentWeight + w[i], currentValue + v[i]);
        x[i] = 0;
    }

    if (includeValue > excludeValue) {
        return includeValue;
    } else {
        return excludeValue;
    }
}
