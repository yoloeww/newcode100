/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here
        ListNode* tail = nullptr;
        ListNode* cur = head;
        ListNode* smallpre = nullptr;
        ListNode* small = nullptr;

        while (cur) {
            small = cur;
            smallpre = getSmallNode(cur);
            if (smallpre) {
                small = smallpre -> next;
            }
            cur = cur == small ? cur -> next : cur;
            if (tail == nullptr)
                head = small;
            else 
                tail -> next = small;
        }
        return head;
    }
    ListNode* getSmallNode(ListNode* head) {
        ListNode* smallpre = nullptr;
        ListNode* small = head;
        ListNode* pre = head;
        ListNode* cur = head -> next;
        while (cur) {
            if (cur -> val < small -> val) {
                smallpre = pre;
                small = cur;
            }
            pre = cur;
            cur = cur -> next;
        }
        return smallpre;
    }
};
