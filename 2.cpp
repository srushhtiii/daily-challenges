#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    
    
    for (int i = m - 1, j = 0; i >= 0 && j < n; i--, j++) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        } else {
            break;
        }
    }
    
   
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main() {
    vector<int> arr1 = {10, 20, 30};
    vector<int> arr2 = {5, 15, 25, 35};
    
    mergeSortedArrays(arr1, arr2);
    
   
    cout << "arr1: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
