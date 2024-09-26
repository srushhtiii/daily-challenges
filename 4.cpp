#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();

    
    for (int i = m - 1, j = 0; i >= 0 && j < n;) {
        if (arr1[i] > arr2[j]) {
            
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        } else {
            break; 
        }
    }

    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main() {
    int m, n;
    
    
    cout << "Enter size of the first sorted array (arr1): ";
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter elements of the first sorted array:\n";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }
    
    
    cout << "Enter size of the second sorted array (arr2): ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter elements of the second sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    
    mergeSortedArrays(arr1, arr2);

    
    cout << "Merged arr1: ";
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\nMerged arr2: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
