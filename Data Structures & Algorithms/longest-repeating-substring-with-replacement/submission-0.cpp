class Solution {
public:
    int characterReplacement(string s, int k) {
        auto longest = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                auto substr = s.substr(i, j + 1);
                auto mp = get_frequencies(substr);
                auto most_frequent = get_most_frequent(mp);
                auto replacements_required = substr.length() - most_frequent;
                if (replacements_required <= k) {
                    longest = std::max(longest, int(substr.size()));
                }
            }
        }
        return longest;
    }

    std::unordered_map<char, int> get_frequencies(string s) {
        auto res = std::unordered_map<char, int>();
        for (auto const &c : s) {
            res[c]++;
        }
        return res;
    }

    int get_most_frequent(std::unordered_map<char, int> const& mp) {
        auto max = 0;
        for (auto const&[k,v] : mp) {
            max = std::max(max, v);
        }
        return max;
    }

    void print_map(unordered_map<char, int> const& mp) {
        for (auto &[k,v] : mp) {
            std::cout << "key: " << k << ", value: " << v << std::endl;
        }
    }
};
