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

    Node(int v, Node* n, Node* p) {
        val = v;
        next = n;
        prev = p;
    }
};

class MyLinkedList {
public:
    Node* obj;

    MyLinkedList() {
        obj = nullptr;
    }

    int get(int index) {
        int k = 0;
        Node* obj1 = obj;

        while (obj1 != nullptr) {
            if (k == index)
                return obj1->val;

            k++;
            obj1 = obj1->next;
        }

        return -1;
    }

    void addAtHead(int val) {
        if (obj == nullptr) {
            obj = new Node(val);
            return;
        }

        Node* newhead = new Node(val);
        newhead->next = obj;
        obj->prev = newhead;
        obj = newhead;
    }

    void addAtTail(int val) {
        if (obj == nullptr) {
            obj = new Node(val);
            return;
        }

        Node* temp = obj;

        while (temp->next != nullptr)
            temp = temp->next;

        Node* newtail = new Node(val);
        newtail->prev = temp;
        temp->next = newtail;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        int k = 0;
        Node* obj1 = obj;

        while (obj1 != nullptr) {
            if (k == index - 1)
                break;

            obj1 = obj1->next;
            k++;
        }

        if (obj1 == nullptr)
            return;

        Node* next = obj1->next;
        Node* newlist = new Node(val, obj1->next, obj1);

        obj1->next = newlist;

        if (next != nullptr)
            next->prev = newlist;
    }

    void deleteAtIndex(int index) {
        if (obj == nullptr)
            return;

        if (index == 0) {
            Node* del = obj;
            obj = obj->next;

            if (obj)
                obj->prev = nullptr;

            delete del;
            return;
        }

        int k = 0;
        Node* obj1 = obj;

        while (obj1 != nullptr) {
            if (k == index - 1)
                break;

            obj1 = obj1->next;
            k++;
        }

        if (obj1 == nullptr || obj1->next == nullptr)
            return;

        Node* del = obj1->next;
        Node* temp = del->next;

        obj1->next = temp;

        if (temp != nullptr)
            temp->prev = obj1;

        delete del;
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