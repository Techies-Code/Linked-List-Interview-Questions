// Reverse Nodes in k-Group .cpp


ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr)
        return head;

    /// reveres first k elements
    int cnt = 0;
    Node* curr = head , *prev = nullptr;

    while (curr && cnt < k) {
        Node*nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;

        cnt++;
        if (cnt == k) {
            break;
        }
    }

    if (cnt < k) {
        // undo the changes
        // re reverse the list
        curr = prev;
        prev = nullptr;
        while (curr) {
            Node*nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }
        return prev;
    }


    Node*ans = reverseKGroup(curr, k);
    head->next = ans;
    return prev;
}