class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(i, s);
    }
private:
    string helper(int &i, const string &s) {
        string ret;
        int k = 0;
        while (i < s.length()) {
            char c = s[i];
            if (isdigit(c)) {
                k = k * 10 + c - '0';
            } else if (c == '[') {
                i++;
                string t = helper(i, s);
                while (k-- > 0) ret += t;
                k = 0;
            } else if (c == ']') {
                return ret;
            } else {
                ret += c;
            }

            i++;
        }

        return ret;
    }
};