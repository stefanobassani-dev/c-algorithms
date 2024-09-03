#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
} ListNode;

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

ListNode* getList(int* array, int dim) {
    if (dim == 0) return NULL;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode*));
    head->val = array[0];
    head->next = NULL;

    ListNode* prec = head;

    for (int i = 1; i < dim; i++) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode*));
        node->val = array[i];
        node->next = NULL;

        prec->next = node;
        prec = node;
    }

    return head;
}

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* next = head->next;
    head->next = swapPairs(head->next->next);
    next->next = head;

    return next;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};

    ListNode* res = swapPairs(getList(nums, 6));

    printList(res);
}
