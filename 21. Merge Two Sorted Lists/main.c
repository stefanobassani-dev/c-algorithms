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

ListNode* mergeSortedLists(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    ListNode* currentHead;

    if (head1 -> val < head2 -> val) {
        currentHead = head1;
        head1 = head1 -> next;
    } else {
        currentHead = head2;
        head2 = head2 -> next;
    }

    currentHead -> next = mergeSortedLists(head1, head2);

    return currentHead;
}

int main() {
    int list1[] = {1, 2, 4};
    int list2[] = {1, 3, 4};

    ListNode* res = mergeSortedLists(getList(list1, 3), getList(list2, 3));

    printList(res);
}