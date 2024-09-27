#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


string reverseWords(string s) {

    int start = 0, end = s.length() - 1;
    
   
    while (start <= end && s[start] == ' ') {
        start++;
    }
    
    while (end >= start && s[end] == ' ') {
        end--;
    }
    

    stringstream ss(s.substr(start, end - start + 1));
    vector<string> words;
    string word;

 
    while (ss >> word) {
        words.push_back(word);
    }

   
    reverse(words.begin(), words.end());

    
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    
    string reversed = reverseWords(s);

    
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
