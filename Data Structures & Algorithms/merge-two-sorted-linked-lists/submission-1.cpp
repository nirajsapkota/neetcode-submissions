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
            if (head == nullptr) {
                head = j;
                i = head;
            } else {
                i->next = j;
                i = j;
            }
            j = j->next;
        }
        while (k != nullptr) {
            if (head == nullptr) {
                head = k;
                i = head;
            } else {
                i->next = k;
                i = k;
            }
            k = k->next;
        }

        if (i != nullptr) {
            i->next = nullptr;
        }
        return head;
    }
};
