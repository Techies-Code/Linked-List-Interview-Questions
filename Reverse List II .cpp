// Reverse List II .cpp

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


ListNode* reverseBetween(ListNode* head, int left, int right) {

	if(left == right || head == nullptr )
		return head;

	// Go to the left NOde
	ListNode* curr =head,*prev = nullptr;
	int cnt = 1;
	while(curr){
		if(cnt == left)
			break;
		prev = curr;
		curr = curr->next;
		cnt++;
	}

	ListNode* beforeStart = prev;
	ListNode* StartNode = curr;
	// prev -> prev wali node
	// curr -> left wali node
	while(curr){
		Node*nxt = curr->next;
		curr->next = prev;

		prev = curr;
		curr = nxt;

		if(cnt == right)
			break;
		cnt++;

	}

	if(beforeStart == nullptr){
		StartNode->next = curr;
		return prev;
	}

	beforeStart->next = prev;
	StartNode->next = curr;

	return head;

}
