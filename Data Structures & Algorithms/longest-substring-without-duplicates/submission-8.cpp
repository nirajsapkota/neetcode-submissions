class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto characters = std::unordered_map<char, int>();
        auto l = 0;
        auto longest = 0;

        for (int r = 0; r < s.length(); r++) {
            auto character = s[r];
            if (characters.contains(character) && characters.at(character) >= l) {
                l = characters.at(character) + 1;
                characters.erase(character);
                characters.insert({ character, r });
            } else {
                characters[character] = r;
            }
            longest = std::max(longest, r - l + 1);
        }
        return longest;
    }
};