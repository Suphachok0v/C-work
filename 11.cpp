#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

//----| Greedy Algorithm : Shortest Path (Dijkstra's Algorithm)
void SetWeight(int *Town, int n, int i, int j, int Weight) {
    Town[i * n + j] = Weight;
}

void InitializeGraph(int *g, int n, int value) {
    for (int i = 0; i < n * n; i++) {
        g[i] = value;
    }
}

void PrintGraph(int *g, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", g[i * n + j]);
        }
        printf("\n");
    }
}

int *Dijkstra(int *L, int n) {
    int *dist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[0] = 0; // Start from town 0

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && L[u * n + v] != -1 && dist[u] != INT_MAX && dist[u] + L[u * n + v] < dist[v]) {
                dist[v] = dist[u] + L[u * n + v];
            }
        }
    }

    free(visited);
    return dist;
}

void PrintArrayAndMax(int *arr, int size) {
    int max = 0;
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
        if (arr[i] > max) max = arr[i];
    }
    printf("\nTotal Range = %d\n", max);
}

//----| Greedy Algorithm : Knapsack Problem
int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    double *ratio = (double *)malloc(n * sizeof(double));
    int *x = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        ratio[i] = (double)v[i] / w[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                double tempR = ratio[i]; ratio[i] = ratio[j]; ratio[j] = tempR;
                int tempW = w[i]; w[i] = w[j]; w[j] = tempW;
                int tempV = v[i]; v[i] = v[j]; v[j] = tempV;
            }
        }
    }

    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + w[i] <= wx) {
            x[i] = 1;
            currentWeight += w[i];
        }
    }

    free(ratio);
    return x;
}

int main() {
    printf("Greedy Algorithm : Shortest Path\n");
    int n, i, j, km;
    
    printf("Enter town : ");
    scanf("%d", &n);

    int *g = (int *)malloc(n * n * sizeof(int));
    InitializeGraph(g, n, -1);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter km [%d, %d] : ", i, j);
            scanf("%d", &km);
            SetWeight(g, n, i, j, km);
        }
    }

    PrintGraph(g, n);

    int *d = Dijkstra(g, n);
    PrintArrayAndMax(d, n - 1);

    free(g);
    free(d);

    printf("\nGreedy Algorithm : Knapsack Problem\n");
    int wx;

    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter wx : ");
    scanf("%d", &wx);

    int *w = (int *)malloc(n * sizeof(int));
    int *v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        printf("weight for item %d : ", i);
        scanf("%d", &w[i]);
    }
    for (i = 0; i < n; i++) {
        printf("value for item %d : ", i);
        scanf("%d", &v[i]);
    }

    int *x = KnapsackGreedy(w, v, n, wx);

    int ans = 0;
    for (i = 0; i < n; i++) printf("%d ", x[i]);
    printf("\n");
    for (i = 0; i < n; i++) if (x[i] == 1) ans += v[i];
    printf("Value = %d\n", ans);

    free(w);
    free(v);
    free(x);

    return 0;
}
