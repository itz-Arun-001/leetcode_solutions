class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int temp=nums[0];
        if(nums.size()==1) return ++nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]+1)
             { 
               break;
             }

            else{
                 temp+=nums[i];
            }

        }
        unordered_set<int> elements(nums.begin(), nums.end());
        while(elements.count(temp))
        {
            temp++;
        }
        return temp;
        
    }
};
