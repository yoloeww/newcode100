
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(pHead == nullptr || pHead -> next == nullptr || pHead -> next -> next == nullptr)
            return nullptr;
        ListNode* slow = pHead -> next;
        ListNode* fast = pHead -> next -> next;
        while (fast != slow) {
            if(fast -> next == nullptr || fast -> next -> next == nullptr)
                return nullptr;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        fast = pHead;
        while (fast != slow) {
                fast = fast -> next;
                slow = slow -> next;
        }
        return slow;
    }
};
