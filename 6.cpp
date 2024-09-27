#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<pair<int, int>> findZeroSumSubarrays(const vector<int>& arr) {
    
    unordered_map<int, vector<int>> prefixSumMap;
    vector<pair<int, int>> result;

    int sum = 0;

    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        
        if (sum == 0) {
            result.push_back({0, i});
        }

        
        if (prefixSumMap.find(sum) != prefixSumMap.end()) {
            for (int start : prefixSumMap[sum]) {
                result.push_back({start + 1, i});
            }
        }

       
        prefixSumMap[sum].push_back(i);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

  
    vector<pair<int, int>> result = findZeroSumSubarrays(arr);

    
    cout << "Subarrays with zero sum: " << endl;
    for (const auto& p : result) {
        cout << "Subarray found from index " << p.first << " to " << p.second << endl;
    }

    return 0;
}
