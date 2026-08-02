/*class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
            if(st.empty()){
                st.push(i);
            }
            if(nums[st.top()]<nums[i])
            {
                nums[st.top()]=nums[i];
                st.pop();
                st.push(i);
            }
            else{
                nums[st.top()]=-1;
                st.push(i);
            }
        }
        return nums;
    }
};*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> ans(nums.size(), -1);
        stack<int> st;
        for (int i = 0; i < 2 * nums.size(); i++) {
            int k = i % nums.size();
            while (!st.empty() && nums[st.top()] < nums[k]) {
                ans[st.top()] = nums[k];
                st.pop();
            }
            if (i < nums.size()) {
                st.push(i);
            }
        }
        return ans;
    }
};