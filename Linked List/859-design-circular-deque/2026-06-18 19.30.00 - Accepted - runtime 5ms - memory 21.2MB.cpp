//BUMP ALLOCATOR OR global arena allocator
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int v) {
        val = v;
        next = prev = nullptr;
    }
    Node(int v, Node* n, Node* p) {
        val = v;
        next = n;
        prev = p;
    }
};

class MyCircularDeque {

public:
    Node* front;
    Node* last;
    int maxsize;
    int dqsize;
    MyCircularDeque(int k) {
        front = nullptr;
        last = nullptr;
        maxsize = k;
        dqsize = 0;
    }

    bool insertFront(int value) {
        if (front == nullptr) {
            front = new Node(value);
            dqsize++;
            last = front;
            front->next = last;
            last->prev = front;
            return true;
        }

        else if (maxsize > dqsize) {
            dqsize++;
            Node* newnode = new Node(value, front, nullptr);
            front->prev = newnode;
            front = newnode;
            // Node* temp=temp;
            // while(temp->next){
            //  temp=temp->next;

            //}
            front->prev = last;
            last->next = front;
            return true;
        } else {
            return false;
        }
    }

    bool insertLast(int value) {
        if (front == nullptr) {
            front = new Node(value);
            dqsize++;
            last = front;
            front->next = last;
            last->prev = front;
            return true;
        }

        else if (maxsize > dqsize) {
            dqsize++;
            /* Node* temp=data;
             while(temp->next)
             {
                 temp=temp->next;
             }*/
            Node* newnode = new Node(value, front, last);
            last->next = newnode;
            last = newnode;
            front->prev = last;
            last->next = front;
            return true;
        } else {
            return false;
        }
    }

    bool deleteFront() {
        if (front == nullptr)
            return false;
        if (dqsize == 1) {
            delete front;
            front = nullptr;
            last = nullptr;
            dqsize--;
            return true;
        }

        Node* f1 = front;
        front = front->next;
        front->prev = last;
        last->next = front;
        f1->next = nullptr;
        f1->prev = nullptr;
        dqsize--;
        delete f1;
        return true;
    }

    bool deleteLast() {
        if (front == nullptr)
            return false;
        if (dqsize == 1) {
            delete last;
            front = nullptr;
            last = nullptr;
            dqsize--;
            return true;
        }

        Node* f1 = last;
        last = last->prev;
        front->prev = last;
        last->next = front;
        f1->next = nullptr;
        f1->prev = nullptr;
        dqsize--;
        delete f1;
        return true;
    }

    int getFront() {
        if (front == nullptr) {
            return -1;
        }
        return front->val;
    }

    int getRear() {
        if (last == nullptr) {
            return -1;
        }
        return last->val;
    }

    bool isEmpty() { return (dqsize == 0) ? true : false; }

    bool isFull() { return (dqsize == maxsize) ? true : false; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */