// partitionList.cpp

ListNode* partition(ListNode* head, int x) {
    ListNode* left_head = nullptr, *left_tail = nullptr, *right_head = nullptr, *right_tail = nullptr;

    ListNode*curr = head;

    while(curr){

        if(curr->val < x){
            // it should be the part of left list

            if(left_head == nullptr){
                left_head = left_tail = curr;
            }else{
                left_tail->next = curr;
                left_tail = curr;
            }


        }else{
            // right list
            if(right_head == nullptr){
                right_head = right_tail = curr;
            }else{
                right_tail->next = curr;
                right_tail = curr;
            }
        }

        curr = curr->next;
    }
    if(left_head == nullptr){
        return right_head;
    }

    if(right_head == nullptr){
        return left_head;1
    }

    //
    right_tail->next = nullptr;

    left_tail->next = right_head;

    return left_head;

}