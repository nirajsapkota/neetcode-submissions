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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        } else if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* it = nullptr;
        while (list1 && list2) {
            if (!head) {
                if (list1->val <= list2->val) {
                    head = list1;
                    it = head;
                    list1 = list1->next;
                } else {
                    head = list2;
                    it = head;
                    list2 = list2->next;
                }
            } else {
                if (list1->val <= list2->val) {
                    it->next = list1;
                    it = list1;
                    list1 = list1->next;
                } else {
                    it->next = list2;
                    it = list2;
                    list2 = list2->next;
                }
            }
        }
        if (list1) {
            it->next = list1;
        } else if (list2) {
            it->next = list2;
        } else {
            it->next = nullptr;
        }
        return head;
    }
};
