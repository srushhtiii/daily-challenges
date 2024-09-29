#include <iostream>
using namespace std;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int lcm(int N, int M) {
    return (N * M) / gcd(N, M); // LCM formula
}

int main() {
    int N = 4, M = 6;
    cout << "LCM of " << N << " and " << M << " is: " << lcm(N, M) << endl;
    return 0;
}
