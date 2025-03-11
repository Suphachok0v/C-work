#include <stdio.h>

int *KnapsackKP(int *w, int *v, int n, int wx);

int main() {
    int wx = 11, ans = 0, n, i;
    n = 5;
    
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
    
    int *x = KnapsackKP(w, v, n, wx);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);
    for (int i = 0; i < n; i++) if (x[i] == 1) ans += v[i];
    printf("\nValue = %d", ans);
    return 0;
}

int *KnapsackKP(int *w, int *v, int n, int wx) {
    static int x[100];
    int dp[100][100] = {0};

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i-1] <= j) {
                dp[i][j] = (v[i-1] + dp[i-1][j - w[i-1]] > dp[i-1][j]) ? v[i-1] + dp[i-1][j - w[i-1]] : dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int res = dp[n][wx];
    int remainingWeight = wx;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i-1][remainingWeight]) {
            x[i-1] = 1;
            res -= v[i-1];
            remainingWeight -= w[i-1];
        } else {
            x[i-1] = 0;
        }
    }

    return x;
}
