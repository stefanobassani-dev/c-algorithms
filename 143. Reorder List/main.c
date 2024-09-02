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

ListNode* reorder(ListNode* head, ListNode* currentNode) {
    if (currentNode == NULL) return head;

    ListNode* nextList = reorder(head, currentNode->next);

    if (nextList == NULL) return NULL;
    else if (nextList == currentNode || nextList->next == currentNode) {
        // when I reach the half of the list
        currentNode->next = NULL;
        return NULL;
    } else {
        ListNode* next = nextList->next;
        nextList->next = currentNode;
        currentNode->next = next;
        return next;
    }
}

void reorderList(ListNode* head) {
    reorder(head, head);
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    ListNode* list = getList(nums, 5);

    reorderList(list);

    printList(list);

    free(list);
}
