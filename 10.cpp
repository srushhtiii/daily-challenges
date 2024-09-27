#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    
    for (string word : strs) {
       
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());

        
        anagramMap[sortedWord].push_back(word);
    }

 
    vector<vector<string>> result;
    for (auto& entry : anagramMap) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);

    cout << "Grouped anagrams: " << endl;
    for (const auto& group : groupedAnagrams) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
