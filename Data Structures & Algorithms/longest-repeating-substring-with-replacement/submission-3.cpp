class Solution {
public:
    int characterReplacement(string s, int k) {
        auto longest = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                auto substr = s.substr(i, j + 1);
                if (replacements_required(substr) <= k) {
                    longest = std::max(longest, int(substr.size()));
                }
            }
        }
        return longest;
    }

    auto replacements_required(std::string const& s) -> int {
        return s.length() - most_frequent(s);
    }

    auto most_frequent(std::string const& s) -> int {
        auto max = 0;
        for (auto const& [k,v] : frequencies(s)) {
            max = std::max(max, v);
        }
        return max;
    }

    auto frequencies(std::string const& s) -> std::unordered_map<char, int> {
        auto mp = std::unordered_map<char, int>();
        for (auto const &ch : s) {
            mp[ch]++;
        }
        return mp;
    }
};
