#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    vector<int> dp(amount + 1, amount + 1);
    vector<int> used(amount + 1, -1);

    dp[0] = 0;

    // DP
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
                used[i] = coin;
            }
        }
    }

    // No solution
    if (dp[amount] == amount + 1) {
        cout << "No solution" << endl;
        return 0;
    }

    // Print result
    cout << "Minimum number of coins = " << dp[amount] << endl;

    cout << "Coins used = ";

    int x = amount;
    while (x > 0) {
        cout << used[x] << " ";
        x -= used[x];
    }

    cout << endl;

    return 0;
}