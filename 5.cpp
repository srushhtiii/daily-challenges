#include <iostream>
#include <vector>
using namespace std;


vector<int> findLeaders(const vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders; 
    
   
    int maxFromRight = arr[n - 1];
    leaders.push_back(maxFromRight);

    
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            leaders.push_back(maxFromRight);
        }
    }

    
    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main() {
    int n;

   
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> arr(n);

    
    cout << "Enter elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    vector<int> leaders = findLeaders(arr);

    
    cout << "Leaders: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}
