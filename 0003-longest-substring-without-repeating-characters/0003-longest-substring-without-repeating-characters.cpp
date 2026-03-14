class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> cnt(128, 0);  // Sneaky ASCII spy
        for (int l = 0, r = 0; r < s.size(); ++r) {
            ++cnt[s[r]];
            while (cnt[s[r]] > 1) --cnt[s[l++]];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
