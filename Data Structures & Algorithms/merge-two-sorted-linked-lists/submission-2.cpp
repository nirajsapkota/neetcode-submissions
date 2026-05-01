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
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* i = head;
        ListNode* j = list1;
        ListNode* k = list2;
        
        while (j != nullptr && k != nullptr) {
            if (head == nullptr) {
                if (j->val <= k->val) {
                    head = j;
                    i = head;
                    j = j->next;
                } else {
                    head = k;
                    i = head;
                    k = k->next;
                }
            } else {
                if (j->val <= k->val) {
                    i->next = j;
                    i = j;
                    j = j->next;
                } else {
                    i->next = k;
                    i = k;
                    k = k->next;
                }
            }
        }
        
        while (j != nullptr) {
            i->next = j;
            i = j;
            j = j->next;
        }
        while (k != nullptr) {
            i->next = k;
            i = k;
            k = k->next;
        }

        i->next = nullptr;
        return head;
    }
};
