#include <iostream>
using namespace std;

// Recursive function to calculate factorial
long long factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    int n;

    // Read the value of n
    cout << "Enter a number: ";
    cin >> n;

    // Display factorial
    cout << "Factorial of " << n << " = " << factorial(n) << endl;

    return 0;
}
