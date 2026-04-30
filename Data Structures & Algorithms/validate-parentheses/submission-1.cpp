class Solution {
public:
    bool isValid(string s) {
        auto parentheses = std::stack<char>();

        for (auto const& c : s) {
            if (isOpeningParentheses(c)) {
                parentheses.push(c);
            } else {
                if (parentheses.empty()) {
                    return false;
                }
                auto top = parentheses.top();
                parentheses.pop();
                if (top != getOpenBasedOnClosed(c)) {
                    return false;
                }
            }
        }

        if (!parentheses.empty()) {
            return false;
        }

        return true;
    }

    bool isOpeningParentheses(char const& c) {
        return c == '(' || c == '{' || c == '[';
    } 

    char getOpenBasedOnClosed(char const& c) {
        if (c == ')') {
            return '(';
        }
        if (c == '}') {
            return '{';
        }
        return '[';
    }
};
