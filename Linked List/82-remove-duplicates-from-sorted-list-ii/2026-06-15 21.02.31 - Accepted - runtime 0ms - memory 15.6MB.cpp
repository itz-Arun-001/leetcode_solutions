/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>mp;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            mp[temp->val]++;
            temp=temp->next;

        }
        temp=head;
        ListNode* dummy=new ListNode(0);
        ListNode* t=dummy;
        for(auto p:mp)
        {
                if(p.second==1)
                {
                    dummy->next=new ListNode(p.first);
                    dummy=dummy->next;
                }
                //temp=temp->next;
        }
      //  delete dummy;
        delete temp;
        return t->next;

    }
};
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
void operator delete[](void* ptr) {}*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        while (curr != nullptr) {
            if (curr->next!= nullptr && curr->val == curr->next->val) {
                int x = curr->val;
                while (curr != nullptr && x == curr->val) {
                    curr = curr->next;
                }
            
            prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};