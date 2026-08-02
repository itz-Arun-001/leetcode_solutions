class Solution {
public:
    int trap(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
         int ans=0,lowmax=0,highmax=0;
        while(low<high)
        {
            if(height[low]<height[high]){
            if(height[low]>=lowmax)
                lowmax=height[low];
            else   
                ans+=(lowmax-height[low]);
            low++;
            }
            else
            {
                if(height[high]>=highmax)
                    highmax=height[high];
                else
                    ans+=(highmax-height[high]);
                high--;
            }

        }
        return ans;

        
    }
};