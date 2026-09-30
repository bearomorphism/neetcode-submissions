class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> g(26);
        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            const string &a = words[i - 1], &b = words[i];
            int len = min(a.length(), b.length());
            while (j < len && a[j] == b[j]) j++;
            if (j < len) {
                g[b[j] - 'a'].push_back(a[j] - 'a');
            } else if (j == b.length() && j < a.length()) {
                return "";
            }
        }

        string ans;
        vector<int> state(26);
        for (const string &s : words) {
            for (char c : s) {
                state[c - 'a'] = 1;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (!dfs(i, g, state, ans)) {
                return ""; // cycle
            }
        }

        return ans;
    }
private:
    bool dfs(int idx, const vector<vector<int>> &g, vector<int> &state, string &ans) {
        if (state[idx] == 0) return true;
        if (state[idx] == 2) return false;
        state[idx] = 2;
        for (int x : g[idx]) {
            if (!dfs(x, g, state, ans)) return false;
        }
        state[idx] = 0;
        ans += 'a' + idx;
        return true;
    }
};
