#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

// TODO: Insert a new node with value `data` at the end of the list.
// Return the (possibly updated) head of the list.
Node* insertAtEnd(Node* head, int data) {
    Node *p = malloc(sizeof(Node));
    if (p == NULL) {
        return head;
    }
    Node *q = head;
    if (head != NULL) {
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
        p->data = data;
        p->next = NULL;
    }
    else {
        head = p;
        p->data = data;
        p->next = NULL;
    }
    return head;
}

// TODO: Delete the first node whose value equals `key`.
// Return the (possibly updated) head of the list.
Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        return head;
    }
    if (head->data == key) {
        if (head->next == NULL) {
            head = NULL;
            return head;
        }
        else {
            head = head->next;
            return head;
        }
    }
    else {
        Node* p = head;
        Node* q= NULL;
        for (int i = 0; 1; i++) {
            if (p->next != NULL) {
                if (p->next->data == key) {
                    q = p;
                    p = p->next;
                    break;
                }
                q = p;
                p = p->next;
            }
            else {
                return head;
            }
        }
        if (p->next == NULL) {
            q->next = NULL;
            free(p);
            return head;
        }
        else {
            q->next = p->next;
            free(p);
            return head;
        }
    }
}

// TODO: Print the list as "val1 val2 val3 NULL"
// Print just "NULL" if the list is empty.
void printList(Node* head) {
    Node* p = head;
    if (p == NULL) {
        printf("NULL\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p= p->next;
    }
    printf("NULL\n");
    return;
}

int main(void) {
  int q;
  scanf("%d", &q);

  Node* head = NULL;
  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
      int data;
      scanf("%d", &data);
      head = insertAtEnd(head, data);
    } else if (type == 2) {
      int key;
      scanf("%d", &key);
      head = deleteNode(head, key);
    } else if (type == 3) {
      printList(head);
    }
  }

  return 0;
}
