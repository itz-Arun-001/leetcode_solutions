class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* temp = head;
        int k = 0;

        while (temp) {
            if (k == index)
                return temp->val;

            temp = temp->next;
            k++;
        }

        return -1;
    }

    void addAtHead(int val) {
        Node* newHead = new Node(val);

        if (head) {
            newHead->next = head;
            head->prev = newHead;
        }

        head = newHead;
    }

    void addAtTail(int val) {
        Node* newTail = new Node(val);

        if (!head) {
            head = newTail;
            return;
        }

        Node* temp = head;

        while (temp->next)
            temp = temp->next;

        temp->next = newTail;
        newTail->prev = temp;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        int k = 0;

        while (temp && k < index - 1) {
            temp = temp->next;
            k++;
        }

        if (!temp)
            return;

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (!head)
            return;

        if (index == 0) {
            Node* del = head;
            head = head->next;

            if (head)
                head->prev = nullptr;

            delete del;
            return;
        }

        Node* temp = head;
        int k = 0;

        while (temp && k < index) {
            temp = temp->next;
            k++;
        }

        if (!temp)
            return;

        if (temp->prev)
            temp->prev->next = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */