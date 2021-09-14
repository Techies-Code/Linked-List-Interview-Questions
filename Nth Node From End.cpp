// Nth Node From End.cpp

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


ListNode* removeNthFromEnd(ListNode* head, int n) {
    	
    ListNode* ptr2=head,*ptr1=head;

    // Move ptr2 n steps ahead
    while(ptr2 && n--){
    	ptr2 = ptr2->next;
    }

    if(ptr2==nullptr){
    	Node*temp = head;
    	head = head->next;
    	delete temp;
    	return head;
    }

    // move both pointer
    while(ptr2->next!=nullptr){
    	ptr1 = ptr1->next;
    	ptr2 = ptr2->next;
    }

    // 3 delete node
    ListNode* temp = ptr1->next;
    ptr1->next = temp->next;
    delete temp;

    return head;
}
