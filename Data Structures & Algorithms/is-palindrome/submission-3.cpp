class Solution {
public:
    bool isPalindrome(string s) {
        auto left = 0;
        auto right = s.length() - 1;
        while (left < right) {
            if (shouldSkipChar(s[left])) {
                left++;
                continue;
            }
            if (shouldSkipChar(s[right])) {
                right--;
                continue;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    auto shouldSkipChar(char &c) -> bool {
        return std::isspace(c) || !std::isalnum(c);
    }
};
