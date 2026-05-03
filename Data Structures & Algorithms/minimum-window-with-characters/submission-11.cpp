class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        if (s.size() == t.size() && is_subset(count_char_frequencies(s), count_char_frequencies(t))) return s;
        if (t.size() == 1 && s.contains(t[0])) return t;

        auto res = std::string("");
        auto min_window_size = num_unique_chars(t);
        auto t_frequencies = count_char_frequencies(t);
        for (int l = 0; l < s.length() - 1; l++) {
            auto r = min_window_size;
            while ((l + r) <= s.length()) {
                auto substr = s.substr(l, r);
                if (res != "" && substr.length() >= res.length()) { r++; continue; }
                auto substr_frequencies = count_char_frequencies(substr);
                auto is_valid = is_subset(substr_frequencies, t_frequencies);
                auto is_better = (res == "" || substr.length() < res.length());
                if (is_valid && is_better) {
                    res = substr;
                }
                r++;
            }
        }

        return res;
    }

    auto num_unique_chars(
        std::string const& str
    ) -> int {
        auto st = std::unordered_set<char>(str.begin(), str.end());
        return st.size();
    }

    auto count_char_frequencies(
        std::string const& str
    ) -> std::unordered_map<char, int> {
        auto mp = std::unordered_map<char, int>();
        for (auto const& ch : str) mp[ch]++;
        return mp;   
    }

    auto is_subset(
        std::unordered_map<char, int> const& superset, 
        std::unordered_map<char, int> const& subset
    ) -> bool {
        for (auto const &[k, v] : subset) {
            auto it = superset.find(k);
            if (it == superset.end()) return false;
            if (it->second < v) return false;
        }
        return true;
    }
};
