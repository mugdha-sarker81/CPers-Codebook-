
#include <bits/stdc++.h>
using namespace std;

// ==================== IMPLEMENTATION ====================

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// ==================== BASIC OPERATIONS ====================

                                            // Create linked list from vector
ListNode* createList(vector<int> a) {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int x : a) {
        ListNode* node = new ListNode(x);

        if (head == NULL) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

                                            // Print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

                                            // Count nodes
int length(ListNode* head) {
    int cnt = 0;

    while (head != NULL) {
        cnt++;
        head = head->next;
    }

    return cnt;
}

                                            // Search value, return 0-based index
int searchList(ListNode* head, int target) {
    int pos = 0;

    while (head != NULL) {
        if (head->val == target) return pos;

        head = head->next;
        pos++;
    }

    return -1;
}

                                            // Insert at beginning
ListNode* insertFront(ListNode* head, int value) {
    ListNode* node = new ListNode(value);
    node->next = head;

    return node;
}

                                            // Insert at end
ListNode* insertBack(ListNode* head, int value) {
    ListNode* node = new ListNode(value);

    if (head == NULL) return node;

    ListNode* cur = head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = node;

    return head;
}

                                            // Insert at 0-based position
ListNode* insertAt(ListNode* head, int pos, int value) {
    if (pos <= 0) return insertFront(head, value);

    ListNode* cur = head;

    for (int i = 0; i < pos - 1 && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur == NULL) return head;

    ListNode* node = new ListNode(value);
    node->next = cur->next;
    cur->next = node;

    return head;
}

                                            // Delete first occurrence of value
ListNode* deleteValue(ListNode* head, int value) {
    if (head == NULL) return NULL;

    if (head->val == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    ListNode* cur = head;

    while (cur->next != NULL && cur->next->val != value) {
        cur = cur->next;
    }

    if (cur->next != NULL) {
        ListNode* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }

    return head;
}

                                                // Reverse linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;

    while (cur != NULL) {
        ListNode* nextNode = cur->next;

        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }

    return prev;
}

                                                // Find middle node
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

                                                // Detect cycle
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

                                                // Delete entire linked list
                                                // Call only if there is no cycle
void deleteList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;

        delete temp;
    }
}

/*
    QUICK USAGE:

    vector<int> a = {10, 20, 30, 40};

    ListNode* head = createList(a);

    printList(head);

    head = insertFront(head, 5);
    head = insertBack(head, 50);
    head = insertAt(head, 2, 15);

    head = deleteValue(head, 20);

    head = reverseList(head);

    cout << length(head) << endl;
    cout << searchList(head, 30) << endl;

    deleteList(head);
*/
