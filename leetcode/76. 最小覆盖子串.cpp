class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        for (char c : t) need[c]++;
        int l = 0, r = 0, start = 0, len = INT_MAX, count = t.size();
        
        while (r < s.size()) {
            if (need[s[r++]]-- > 0) --count;
            while (count == 0) {
                if (r - l < len) {
                    len = r - l;
                    start = l;
                }
                if (++need[s[l++]] > 0) ++count;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
