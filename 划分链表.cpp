#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node* next;
};
 int n,pivot;
Node* input_list(void) {
    int val;
    Node* head = new Node();
    Node* cur = head;
    cin >> n >> pivot;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        if (i == 1)  {
            cur -> val = val;
            cur -> next = nullptr;
        }
        Node* newnode = new Node();
        newnode ->val = val;
        newnode -> next = nullptr;
        cur -> next = newnode; 
        cur = newnode;
    }
    return head;
}
Node* list_partition(Node *head,int privot) {
    if(!head)
        return head;
    Node* sh = nullptr;
    Node* st = nullptr;
    Node* eh = nullptr;
    Node* et = nullptr;
    Node* bh = nullptr;
    Node* bt = nullptr;
    
    Node* next = nullptr;

    while (head) {
        next = head ->next;
        if (head -> val < pivot) {
            if (sh == nullptr) {
                sh = head;
                st = head;
            }
            else {
                st -> next = head;
                st = head;
            }
        }
    }
}
int main() {
    Node* head = input_list();
    list_partition(head, pivot);
    return 0;
}
