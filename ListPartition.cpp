// ListPartition.cpp

ListNode* partition(ListNode* head, int x) {

    ListNode* left_head = nullptr, left_tail = nullptr, right_head = nullptr, right_tail = nullptr;

    ListNode*curr = head;

    while(curr){

        if(curr->val < x){
            //left part add 
            if(left_head==nullptr){
                left_head = curr;
                left_tail = curr;
            }else{
                left_tail->next = curr;
                left_tail = curr;
            }

        }else{
            // add to the right part 
            if(right_head==nullptr){
                right_head = curr;
                right_tail = curr;
            }else{
                right_tail->next = curr;
                right_tail = curr;
            }
        }


        curr = curr->next;
    }

    if(right_head==nullptr){
        return left_head;
    }

    if(left_head ==nullptr){
        return right_head;
    }

    left_tail->next = right_head;
    right_tail->next = nullptr;

    return left_head;
}

10,-3,-14,7,6,5,-4,-1
-1,40,-50,7,6,5,-4,-1
1,-5,3,4,-2