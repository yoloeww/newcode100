/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == nullptr)
			return pHead;
		ListNode *pre = nullptr;
		ListNode *cur = pHead;
		ListNode *temp;
		while (cur) {
			temp = cur -> next;
			cur -> next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;

    }
};
