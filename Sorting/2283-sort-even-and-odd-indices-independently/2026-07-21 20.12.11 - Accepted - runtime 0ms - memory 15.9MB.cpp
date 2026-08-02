/*class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        for(int i=0;i<nums.size();i+=2)
        {
            int min=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]<nums[min])
                    min=j;
            }
            swap(nums[i],nums[min]);
        }
        for(int i=1;i<nums.size();i+=2)
        {
            int max=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]>nums[max])
                    max=j;
            }
            swap(nums[i],nums[max]);
        }
        return nums;
      
        
    }
};*/


class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
                nums[i]=even[b++];
            else  nums[i]=odd[a++];

        }
        return nums;
    }
};