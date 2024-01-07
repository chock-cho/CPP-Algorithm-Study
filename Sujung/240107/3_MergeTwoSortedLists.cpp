class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0); // 새로운 연결리스트 생성(공백 노드)
        ListNode *ptr = head;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            }
            else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }

        if(list1 != NULL) ptr->next = list1;
        else if(list2 != NULL) ptr->next = list2;
        return head->next;
    }
};
