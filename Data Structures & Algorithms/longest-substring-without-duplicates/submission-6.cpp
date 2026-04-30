class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;

        auto characters = std::unordered_map<char, int>();
        characters.insert({ s[0], 0 });
        auto left = 0;
        auto longest = 1;

        for (int i = 1; i < s.length(); i++) {
            auto character = s[i];
            if (characters.contains(character) && characters.at(character) >= left) {
                left = characters.at(character) + 1;
                characters.erase(character);
                characters.insert({ character, i });
            } else {
                characters[character] = i;
            }
            longest = std::max(longest, i - left + 1);
        }
        return longest;
    }
};