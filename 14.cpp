#include <iostream>
#include <vector>

using namespace std;

int countSubstringsWithKDistinct(string s, int k) {
    int n = s.length();
    vector<int> count(26, 0); 
    int start = 0, end = 0, distinctChars = 0, result = 0;

    while (end < n) {
        if (count[s[end] - 'a'] == 0) {
            distinctChars++;
        }
        count[s[end] - 'a']++;
        end++;

        while (distinctChars > k) {
            count[s[start] - 'a']--;
            if (count[s[start] - 'a'] == 0) {
                distinctChars--;
            }
            start++;
        }

        if (distinctChars == k) {
            result += end - start;
        }
    }

    return result;
}

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = countSubstringsWithKDistinct(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;

    return 0;
}