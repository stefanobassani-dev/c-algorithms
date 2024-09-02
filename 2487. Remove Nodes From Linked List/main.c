#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

void printList(ListNode *head) {
    while (head != NULL) {
        printf("%d ", head -> val);
        head = head -> next;
    }
}
ListNode* getList(int* array, int dim) {
    if (dim == 0) return NULL;
    ListNode *head = (ListNode*) malloc(sizeof(ListNode*));
    head -> val = array[0];
    head -> next = NULL;

    ListNode* prec = head;

    for (int i = 1; i < dim; i++) {
        ListNode *node = (ListNode*) malloc(sizeof(ListNode*));
        node -> val = array[i];
        node -> next = NULL;

        prec -> next = node;
        prec = node;
    }

    return head;

}

ListNode* removeNodesWithGreaterValuesOnRightSide(ListNode* head) {
    if (head == NULL) return NULL;

    head->next = removeNodesWithGreaterValuesOnRightSide(head->next);

    return head->next != NULL && head->next->val > head->val ?
        head->next : head;
}

int main() {
    int nums[] = {5, 2, 13, 3, 8 };

    ListNode* res = removeNodesWithGreaterValuesOnRightSide(getList(nums, 5));

    printList(res);

  return 0;
}
