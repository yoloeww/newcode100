/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <list>
class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        stack<int> s1;
        stack<int> s2;
        while (head1 != nullptr) {
            s1.push(head1 -> val);
            head1 = head1 -> next;
        }
        while (head2 != nullptr) {
            s2.push(head2 -> val);
            head2 = head2 -> next;
        }
        int ca = 0;
        int n1 = 0;
        int n2 = 0;
        int n = 0;
        ListNode* cur = nullptr;
        ListNode* pre = nullptr;
        while(!s1.empty() || !s2.empty()){
            n1 = s1.empty() ? 0 : s1.top();
            if (!s1.empty()) s1.pop();
            
            n2 = s2.empty() ? 0 : s2.top();
            if (!s2.empty()) s2.pop();
            n = n1 + n2 + ca;
            pre = cur;
            cur = new ListNode(n % 10);
            cur -> next = pre;
            ca = n / 10;
        }
        if (ca == 1) {
            pre = cur;
            cur = new ListNode(1);
            cur -> next = pre;
        }
        return cur;
    }
};
