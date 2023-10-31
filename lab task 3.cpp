#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

int main() {
    int arr[10];
    
    
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int minDiff = INT_MAX;
    int num1, num2;

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            int currentDiff = abs(arr[i] + arr[j]);

            if (currentDiff < minDiff) {
                minDiff = currentDiff;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    cout << "The two elements with the sum nearest to zero are: " << num1 << " and " << num2 << endl;

    return 0;
}
