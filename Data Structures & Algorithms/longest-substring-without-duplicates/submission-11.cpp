class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto seen = std::unordered_map<char, int>();
        auto longest = 0;
        auto l = 0;

        for (int r = 0; r < s.length(); r++) {
            auto ch = s[r];
            if (seen.contains(ch) && seen.at(ch) >= l) {
                l = seen.at(ch) + 1;
                seen.erase(ch);
                seen.insert({ ch, r });
            }
            seen[ch] = r;
            longest = std::max(longest, r - l + 1);
        }
        return longest;
    }
};