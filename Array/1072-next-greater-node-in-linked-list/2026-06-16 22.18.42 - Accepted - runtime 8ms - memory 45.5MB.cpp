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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i];
            /*          if(st.empty())
                      {

                          st.push(arr[i]);
                           arr[i]=0;
                      }
                      else{
                          while(!st.empty())
                          {
                              while(!st.empty()&&st.top()<=arr[i])
                              {
                                  st.pop();
                              }
                              if(!st.empty())
                              {
                                  st.push(arr[i]);
                                  arr[i]=st.top();

                              }
                              else{
                                  arr[i]==0;
                              }

                          }
                      }
          */
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (!st.empty()) {
                arr[i] = st.top();
            } else {
                arr[i] = 0;
            }

            st.push(curr); // Push original value
        }
        return arr;
    }
};