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
        if(!head || !head->next) {
            return;
        }

        ListNode* mid = findMid(head);
        ListNode* reversed = reverse(mid);
        merge(head, reversed);
    }

private:
    ListNode* findMid(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void merge(ListNode* l1, ListNode* l2) {
        while(l2) {
            ListNode* next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next;
        }
    }
};
