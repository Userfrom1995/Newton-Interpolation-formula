#include<iostream>
using namespace std;

// Function to calculate u for a given value of x
float u_cal(float u, int n) {
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}

// Function to calculate factorial of given number n
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    cout << "Enter the number of data points: " << endl;
    int n ;
    cin >> n;
    float x[n] ;
    float y[n][n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of x" << i + 1 << ": " << endl;
        cin >> x[i];
       
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of y" << i + 1 << ": " << endl;
        cin >> y[i][0];
    }
    // Value to interpolate at
    cout << "Enter the value of x for which you want to find y: " << endl;
    float value ;
    cin >> value;

    

    // Constructing forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }

    // Displaying forward difference table
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << y[i][j] << "\t";
        cout << endl;
    }

    
    // Initializing result
    float sum = y[0][0];

    // 'p' is used for difference of y and x[0]
    float u = (value - x[0]) / (x[1] - x[0]);

    // Implementing the formula
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[0][i]) / fact(i);
    }

    cout << "\n Value at " << value << " is " << sum << endl;
    return 0;
}
