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
        auto mp = std::unordered_set<ListNode*>();
        auto it = head;
        while (it != nullptr) {
            if (mp.contains(it)) {
                return true;
            }
            mp.insert(it);
            it = it->next;
        }
        return false;
    }
};
