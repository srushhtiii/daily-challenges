#include <iostream>
#include <vector>
using namespace std;


string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    
    string prefix = strs[0];

    
    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        
        prefix = prefix.substr(0, j);

        
        if (prefix.empty()) return "";
    }

    return prefix;
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

    string result = longestCommonPrefix(strs);
    cout << "Longest common prefix: \"" << result << "\"" << endl;

    return 0;
}
