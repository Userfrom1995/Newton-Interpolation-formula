#include<iostream>
#include<cmath>

using namespace std;

// Function to calculate u mentioned in the formula
float u_cal(float u, int n) {
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
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

    // Constructing the backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    // Value to interpolate at
    cout << "Enter the value of x for which you want to find y: " << endl;
    float value ;
    cin >> value;

    // Displaying the backward difference table
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j <= i; j++)
            cout << y[i][j] << "\t";
        cout << "\n";
    }

    


    // Initializing u and sum
    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / (x[1] - x[0]);

    // Adding remaining terms
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) / fact(i);
    }

    cout << "\n Value at " << value << " is " << sum << endl;
    return 0;
}
