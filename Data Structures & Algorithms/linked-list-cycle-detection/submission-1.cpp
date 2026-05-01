/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        auto seen = std::unordered_set<ListNode*>();
        auto it = head;
        while (it != nullptr) {
            if (seen.contains(it)) {
                return true;
            }
            seen.insert(it);
            it = it->next;
        }
        return false;
    }
};
