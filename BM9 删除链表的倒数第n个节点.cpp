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
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        if(head == nullptr || n < 1) {
            return head;
        }
        ListNode* cur = head;
        while(cur != nullptr) {
            n --;
            cur = cur -> next;
        }
        // 三种情况
        // 等于0（就是头）小于0 大于0（不存在）
        if (n == 0) 
            head = head -> next;
        if (n < 0) {
            cur = head;
            while(++n != 0) {
                cur = cur -> next;
            }
            cur -> next = cur -> next -> next;
        }
        return head;
    }
};
