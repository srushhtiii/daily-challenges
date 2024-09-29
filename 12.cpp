#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s) {
    
    unordered_map<char, char> matchingParen = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    

    stack<char> st;

    for (char c : s) {
        
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
       
        else {
            
            if (st.empty() || st.top() != matchingParen[c]) {
                return false;
            }
            
            st.pop();
        }
    }

    
    return st.empty();
}

int main() {
    string s = "[{()}]";
    if (isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
