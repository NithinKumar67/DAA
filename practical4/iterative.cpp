#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    // Read the value of n
    cout << "Enter a number: ";
    cin >> n;

    // Calculate factorial iteratively
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    // Display the result
    cout << "Factorial of " << n << " = " << fact << endl;

    return 0;
}
