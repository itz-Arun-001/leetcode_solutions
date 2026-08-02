class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        else
        {
            int j=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[j]!=nums[i])
                {
                    nums[++j]=nums[i];
                }
            }
            return j+1;
        }

    }
};


/*

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0; 
        if (nums.empty()) {
            return 0;
        }
        
        else {
            stack<int> st;

            for (int i = 0; i < nums.size(); i++) {
                if (st.empty()||st.top() != nums[i]) {
                    st.push(nums[i]);
                    s++;
                }
                //else if(st.empty()) {st.push(nums[i]);
                //s++;}
            }
            for(int i=s-1;i>=0;i--)
            {
                nums[i]=st.top();
                st.pop();

            }
        }
        return s;
    }
};*/