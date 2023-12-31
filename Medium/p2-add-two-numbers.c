#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Adds elements to the end of the given list
 */
struct ListNode *append(struct ListNode *head, int val) {
    struct ListNode *temp = malloc(sizeof(struct ListNode));
    struct ListNode *ptr;

    if (temp) {
        temp->val = val;
        temp->next = NULL;
        if (head) {
            ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        } else {
            head = temp;
        }
    }

    return head;
}

/**
 * Prints the values within the given list
 */
void printList(struct ListNode *head) {
    struct ListNode *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * Adds the two numbers and returns the sum as a linked list.
 *
 * The two given non-empty lists represents two non-negative integers (digits stored in reverse order, one digit per node).
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *output = NULL;
    int change = 0;

    while (l1 != NULL || l2 != NULL) {
        int n1 = (l1 != NULL) ? l1->val : 0;
        int n2 = (l2 != NULL) ? l2->val : 0;

        output = append(output, (n1 + n2 + change) % 10);
        change = (n1 + n2 + change) / 10;

        l1 = (l1 != NULL) ? l1->next : NULL;
        l2 = (l2 != NULL) ? l2->next : NULL;
    }

    if (change == 1) {
        output = append(output, change);
    }

    return output;
}

int main() {
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    struct ListNode *output = NULL;

    // here I added custom numbers, it can be changed to receive number from command line, file etc.
    head1 = append(head1, 3);
    head1 = append(head1, 7);
    head2 = append(head2, 9);
    head2 = append(head2, 2);

    output = addTwoNumbers(head1, head2);

    printList(head1);
    printList(head2);
    printList(output);

    return 0;
}