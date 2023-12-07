#include <bits/stdc++.h>
using namespace std;

int main() {
    string sen = "I am doing well";
    string word = "doingu";
    bool flag = false;

    for (int i = 0; i <= sen.size() - word.size(); i++) {
        if (sen[i] == word[0]) {
            flag = true;
            for (int j = 1; j < word.size(); j++) {
                if (word[j] != sen[i + j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "found";
                break;  // Added to stop checking further positions once found
            }
        }
    }

    if (!flag) cout << "Not Found";

    return 0;
}
