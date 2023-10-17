// HackRank interview Question
// PHONE NUMBER

#include <bits/stdc++.h>
using namespace std;

string convertToDigits(const string& input) {
    unordered_map<string, string> digitMapping = {
        {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"},
        {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"},
        {"eight", "8"}, {"nine", "9"}
    };

    vector<string> words;
    string currentWord;

    for (char c : input) {
        if (c == ' ') {
            words.push_back(currentWord);
            currentWord = "";
        } else {
            currentWord += c;
        }
    }
    words.push_back(currentWord);

    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i] == "double") {
            result += digitMapping[words[i + 1]] + digitMapping[words[i + 1]];
            i += 1;  
        } else if (words[i] == "triple") {
            result += digitMapping[words[i + 1]] + digitMapping[words[i + 1]] + digitMapping[words[i + 1]];
            i += 1;  
        } else {
            result += digitMapping[words[i]];
        }
    }

    return result;
}

int main() {
    cout << convertToDigits("two one nine six eight one six four six zero") << endl;  
    cout << convertToDigits("five one zero two four eight zero double three two") << endl;  
    cout << convertToDigits("five one zero six triple eight nine six four") << endl;  
    cout << convertToDigits("five eight double two double two four eight five six") << endl;  
    cout << convertToDigits(" double two  double two  double two  double two  double two ")<<endl;
    cout << convertToDigits(" triple two  triple two  triple two  triple two  triple two ")<<endl;

  
    return 0;
}
