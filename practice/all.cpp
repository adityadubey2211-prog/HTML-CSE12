#include <bits/stdc++.h>
using namespace std;

/////////////////////// DOUBLY LINKED LIST ///////////////////////

class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void dllInsertHead(DLLNode* &head, int val) {
    DLLNode* newNode = new DLLNode(val);

    if (!head) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void dllInsertTail(DLLNode* &head, int val) {
    DLLNode* newNode = new DLLNode(val);

    if (!head) {
        head = newNode;
        return;
    }

    DLLNode* temp = head;
    while (temp->next) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void dllInsertPos(DLLNode* &head, int pos, int val) {
    if (pos == 1) {
        dllInsertHead(head, val);
        return;
    }

    DLLNode* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next) {
        temp = temp->next;
        count++;
    }

    DLLNode* newNode = new DLLNode(val);

    newNode->next = temp->next;
    if (temp->next)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
}

void dllDeleteHead(DLLNode* &head) {
    if (!head) return;

    DLLNode* temp = head;
    head = head->next;

    if (head) head->prev = NULL;

    delete temp;
}

void dllDeleteTail(DLLNode* &head) {
    if (!head) return;

    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }

    DLLNode* temp = head;
    while (temp->next) temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
}

void dllDeletePos(DLLNode* &head, int pos) {
    if (pos == 1) {
        dllDeleteHead(head);
        return;
    }

    DLLNode* temp = head;
    int count = 1;

    while (count < pos && temp) {
        temp = temp->next;
        count++;
    }

    if (!temp) return;

    if (temp->next)
        temp->next->prev = temp->prev;

    if (temp->prev)
        temp->prev->next = temp->next;

    delete temp;
}

void printDLL(DLLNode* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

/////////////////////// CIRCULAR LINKED LIST ///////////////////////

class CLLNode {
public:
    int data;
    CLLNode* next;

    CLLNode(int val) {
        data = val;
        next = NULL;
    }
};

void cllInsertHead(CLLNode* &head, int val) {
    CLLNode* newNode = new CLLNode(val);

    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    CLLNode* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void cllInsertTail(CLLNode* &head, int val) {
    CLLNode* newNode = new CLLNode(val);

    if (!head) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    CLLNode* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void cllInsertPos(CLLNode* &head, int pos, int val) {
    if (pos == 1) {
        cllInsertHead(head, val);
        return;
    }

    CLLNode* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    CLLNode* newNode = new CLLNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void cllDeleteHead(CLLNode* &head) {
    if (!head) return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    CLLNode* temp = head;
    CLLNode* last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    delete temp;
}

void cllDeleteTail(CLLNode* &head) {
    if (!head) return;

    if (head->next == head) {
        delete head;
        head = NULL;
        return;
    }

    CLLNode* temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    CLLNode* del = temp->next;
    temp->next = head;

    delete del;
}

void cllDeletePos(CLLNode* &head, int pos) {
    if (pos == 1) {
        cllDeleteHead(head);
        return;
    }

    CLLNode* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    CLLNode* del = temp->next;
    temp->next = del->next;

    delete del;
}

void printCLL(CLLNode* head) {
    if (!head) return;

    CLLNode* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int main() {

    DLLNode* dllHead = NULL;
    CLLNode* cllHead = NULL;

    // DLL Testing
    dllInsertHead(dllHead, 10);
    dllInsertTail(dllHead, 20);
    dllInsertPos(dllHead, 2, 15);
    printDLL(dllHead);

    dllDeleteHead(dllHead);
    dllDeleteTail(dllHead);
    printDLL(dllHead);

    cout << "\n";

    // CLL Testing
    cllInsertHead(cllHead, 10);
    cllInsertTail(cllHead, 20);
    cllInsertPos(cllHead, 2, 15);
    printCLL(cllHead);

    cllDeleteHead(cllHead);
    cllDeleteTail(cllHead);
    printCLL(cllHead);

    return 0;
}