#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;

    for(int i = 0; i < s.length(); i++) {
        // Check if current symbol is smaller than next one (e.g., I before V or X)
        if(i + 1 < s.length() && roman[s[i]] < roman[s[i+1]]) {
            result -= roman[s[i]];
        } else {
            result += roman[s[i]];
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter Roman numeral: ";
    cin >> s;
    cout << "Integer value: " << romanToInt(s) << endl;
    return 0;
}
