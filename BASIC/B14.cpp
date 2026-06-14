#include <iostream>
using namespace std;

int main() {
    long long n;
    bool isPrime = true;

    cout << "Enter a number: ";
    cin >> n;

    if (n <= 1) isPrime = false;
    else if (n <= 3) isPrime = true;
    else if (n % 2 == 0 || n % 3 == 0) isPrime = false;
    else {
        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime)
        cout << "Prime";
    else
        cout << "Not Prime";

    return 0;
}
