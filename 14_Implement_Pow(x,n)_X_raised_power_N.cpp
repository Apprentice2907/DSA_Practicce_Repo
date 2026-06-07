// Simple appraoch using function
// Time complexity: O(logN) space:O(1)


#include <bits/stdc++.h>
using namespace std;

double pow(double x, int n){
    return pow(x, n);
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    cout << pow(x, n);
    return 0;
}







// appraoch without function
// Time complexity: O(logN) space:O(1)

#include <bits/stdc++.h>
using namespace std;

double power(double x, long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n % 2 == 0) {
        return power(x * x, n / 2);
    }
    return x * power(x, n - 1);
}

double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
        return 1.0 / power(x, -N);
    }
    return power(x, N);
}

int main() {
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n);
    return 0;
}