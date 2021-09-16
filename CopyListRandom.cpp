// CopyListRandom.cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

Node* copyRandomList(Node* head) {

	Node* curr = head;
	while (curr) {
		Node*n = new Node(curr->val);
		// insert this node just after cur
		Node* temp = curr->next;
		curr ->next = n;
		n->next = temp;

		curr = temp;
	}

	curr = head;
	while (curr) {
		Node* copyNode = curr->next;
		Node* nxt = copyNode->next;
		copyNode->random = curr->random ->next;
		copyNode->next = copyNode->next->next;
		curr = nxt;
	}

	return head->next;

}

// Approach 2ḍ
Node* copyRandomList(Node* head) {

	if(head == nullptr)
		return head;
	
	// iteration 1 -:   create new nodes and insert just after curr nodes
	Node*curr = head;

	while(curr){
		Node* n = new Node(curr->val);

		// inserst just after curr node
		Node*nxt = curr->next;
		curr->next = n;
		n->next = nxt;
		
		// for next iteration
		curr = nxt;
	}

	// iteration 2 adjust the random pointers
	curr = head;
	while(curr){
		Node* curr_copy = curr->next;
		Node*nxt = curr_copy->next;

		if(curr->random)
			curr_copy->random = curr->random ->next;

		// for next iteration
		curr = nxt;
	}

	// iteration 3 readjust next pointer 
	// to separate the list
	Node*newHead = nullptr;

	curr = head;
	while(curr){
		Node* curr_copy = curr->next;
		Node*nxt = curr_copy->next;

		if(curr == head)
			newHead = curr_copy;

		if(nxt)
			curr_copy->next = nxt->next;
		curr->next = nxt;

		curr = nxt;
	}
return newHead;
}