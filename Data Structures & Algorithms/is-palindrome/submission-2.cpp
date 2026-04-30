class Solution {
public:
    bool isPalindrome(string s) {
        auto left = 0;
        auto right = s.length() - 1;
        while (left < right) {
            if (std::isspace(s[left]) || !std::isalnum(s[left])) {
                left++;
                continue;
            }
            if (std::isspace(s[right]) || !std::isalnum(s[right])) {
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
};
