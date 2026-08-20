#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int capacity = 8;

    int profit[] = {1, 2, 5, 6};
    int weight[] = {2, 3, 4, 5};

    int dp[n + 1][capacity + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            // No items or capacity 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            // Current item can fit
            else if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }

            // Current item cannot fit
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][capacity] << endl;

    return 0;
}