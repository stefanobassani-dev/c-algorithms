#include <stdbool.h>
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

bool isPalindrome(ListNode** head, ListNode* tail) {
    if (tail == NULL) {
        return true;
    }
    bool res = isPalindrome(head, tail -> next) && ((*head) -> val == tail -> val);

    *head = (*head)->next;

    return res;
}
bool checkIsPalindrome(ListNode* head) {
    ListNode* t = head;
    ListNode* mover = head;

    return isPalindrome(&t, mover);
}

int main() {
    int palindrome[] = {1, 2, 2, 1};
    int not_palindrome[] = {1, 2, 3};

    bool res1 = checkIsPalindrome(getList(palindrome, 4));
    bool res2 = checkIsPalindrome(getList(not_palindrome, 3));

    printf("First list: %d\nSecond list: %d", res1, res2);

}