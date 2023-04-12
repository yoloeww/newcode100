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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if(head == nullptr || head -> next == nullptr) 
            return true;
        ListNode* n1 = head;
        ListNode* n2 = head;
            
        while (n2 -> next && n2 -> next -> next) {
                n1 = n1 -> next;
                n2 = n2 -> next -> next;
        }

        n2 = n1 -> next; // 第一个反转节点
        n1 -> next = nullptr;
        ListNode* n3 = nullptr;

        while (n2) {
            n3 = n2 -> next;
            n2 -> next = n1;
            n1 = n2;
            n2 = n3;
        }
        n3 = n1;
        n2 = head;
        bool res = true;
        while(n1 && n2) {
            if(n1 -> val != n2 -> val) {
                res = false;
                break;
            }
                n1 = n1 -> next;
                n2 = n2 -> next;
        }
        n1 = n3 -> next;
        n3 -> next = nullptr;
        while (n1) {
                n2 = n1 -> next;
                n1 -> next = n3;
                n3 = n1;
                n1 = n2;
        }
         return res;
    }
};
