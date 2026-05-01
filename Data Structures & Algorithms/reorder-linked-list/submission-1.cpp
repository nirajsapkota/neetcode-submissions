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
    void reorderList(ListNode* head) {
        while (head) {
            auto old_next = head->next;
            auto new_next = get_new_next(head);

            if (old_next == new_next) {
                head->next = new_next;
                break;
            }
            
            head->next = new_next;
            new_next->next = old_next;
            head = old_next;
        }
    }

    ListNode* get_new_next(ListNode* head) {
        ListNode* prev = nullptr;
        while (head->next) {
            prev = head;
            head = head->next;
        }
        if (prev) {
            prev->next = nullptr;
        }
        return head;
    }
};
