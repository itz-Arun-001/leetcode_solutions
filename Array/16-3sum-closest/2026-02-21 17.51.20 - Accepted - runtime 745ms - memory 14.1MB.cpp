class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int bsum=nums[0]+nums[1]+nums[2];
        int bdif=abs(target-bsum);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    int temp=nums[i]+nums[j]+nums[k];

                    if(temp==target)
                        return temp;
        
                    int q=abs(temp-target);               
                    
                        if(q<bdif)
                        {
                            bdif=q;
                            bsum=temp;
                        }
                
                }

            }
        }
        return bsum;
        
    }
};