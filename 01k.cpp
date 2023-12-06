#include <iostream>
using namespace std;

int knapsack(int w, int n, int p[], int wt[]) {
    int V[n + 1][w + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (wt[i - 1] > j) {
                V[i][j] = V[i - 1][j];
            } else {
                V[i][j] = max(p[i - 1] + V[i - 1][j - wt[i - 1]], V[i - 1][j]);
            }
        }
    }

    return V[n][w];
}

int main() {
    int n;

    cout << "Enter the number of items: ";
    cin >> n;

    int weight[100];
    int profit[100];

    cout << "Enter profit of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter the weight of items:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int w;
    cout << "Enter the capacity : ";
    cin >> w;

    int max = knapsack(w, n, profit, weight);
    cout << "Maximum value: " << max << endl;

    return 0;
}
