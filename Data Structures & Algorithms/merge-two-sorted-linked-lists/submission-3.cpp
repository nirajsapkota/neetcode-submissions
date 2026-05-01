/**
 * Definition for singly-linlist2ed list.
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
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* it = nullptr;

        while (list1 != nullptr && list2 != nullptr) {
            if (head == nullptr) {
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
        
        while (list1 != nullptr) {
            it->next = list1;
            it = list1;
            list1 = list1->next;
        }
        while (list2 != nullptr) {
            it->next = list2;
            it = list2;
            list2 = list2->next;
        }

        it->next = nullptr;
        return head;
    }
};
