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
	while(curr){
		Node*n = new Node(curr->val);
		// insert this node just after cur
		Node* temp = curr->next;
		curr ->next = n;
		n->next = temp;

		curr = temp;
	}

	curr = head;
	while(curr){
		Node* copyNode = curr->next;
		Node* nxt = copyNode->next;
		copyNode->random = curr->random ->next;
		copyNode->next = copyNode->next->next;
		curr = nxt;
	}

	return head->next;

}