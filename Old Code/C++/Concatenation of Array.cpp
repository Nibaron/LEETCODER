class Solution {
public:
    string findLatestTime(string s) {
            if (s[0] == '?') {
            s[0] = (s[1] == '1') ? '1' : '0';
        }
        if (s[1] == '?') {
            s[1] = (s[0] == '0') ? '9' : '1';
        }
        if (s[3] == '?') {
            s[3] = '5'; // Minutes tens digit can be '5'
        }
        if (s[4] == '?') {
            s[4] = '9'; // Minutes ones digit can be '9'
        }


        return s;
    }
};