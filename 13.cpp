#include <iostream>
#include <string>
using namespace std;


string expandAroundCenter(const string& s, int left, int right) {
    
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    string longest = "";
    
    
    for (int i = 0; i < s.length(); i++) {
        
        string palindrome1 = expandAroundCenter(s, i, i);
        
        string palindrome2 = expandAroundCenter(s, i, i + 1);
        
        
        if (palindrome1.length() > longest.length()) {
            longest = palindrome1;
        }
        if (palindrome2.length() > longest.length()) {
            longest = palindrome2;
        }
    }
    
    return longest;
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}
