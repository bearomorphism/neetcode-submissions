class Solution {
public:
    bool isAnagram(string s, string t) {
        return cnt(s) == cnt(t);
    }
private:
    array<int, 26> cnt(const string &s) {
        array<int, 26> ret{};
        for (char c : s) {
            ret[c - 'a']++;
        }
        return ret;
    }
};
