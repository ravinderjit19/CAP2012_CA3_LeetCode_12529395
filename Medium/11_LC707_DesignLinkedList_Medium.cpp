// LeetCode 707 - Design Linked List
struct Node {
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
    Node* head;

public:
    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* temp = head;

        while(index > 0 && temp != nullptr) {
            temp = temp->next;
            index--;
        }

        return temp == nullptr ? -1 : temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if(index < 0) return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if(temp == nullptr) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || head == nullptr) return;

        if(index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if(temp == nullptr || temp->next == nullptr) return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};
