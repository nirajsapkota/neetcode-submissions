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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto sz = length(head);

        // Deleting the head, or only element in the linked list
        if (n == sz) {
            auto next = head->next;
            delete head;
            return next;
        }
        

        // Deleting from the end of the linked list
        if (n == 1) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
            delete curr;
            return head;
        }

        // Deleting from the middle of the linked list
        auto delete_index = sz - n;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < delete_index; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }

    auto length(ListNode* head) -> int {
        auto res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
};
