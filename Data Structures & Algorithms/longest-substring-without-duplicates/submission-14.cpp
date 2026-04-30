class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto seen = std::unordered_map<char, int>();
        auto longest = 0;
        auto l = 0;

        for (int r = 0; r < s.length(); r++) {
            if (seen.contains(s[r]) && seen.at(s[r]) >= l) {
                l = seen.at(s[r]) + 1;
            }
            seen[s[r]] = r;
            longest = std::max(longest, r - l + 1);
        }
        return longest;
    }
};