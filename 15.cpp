#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap; 
    int left = 0, maxLength = 0;

   
    for (int right = 0; right < s.length(); ++right) {
        char currentChar = s[right];

       
        if (charIndexMap.find(currentChar) != charIndexMap.end()) {
            left = max(left, charIndexMap[currentChar] + 1);
        }

        
        charIndexMap[currentChar] = right;

        
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
