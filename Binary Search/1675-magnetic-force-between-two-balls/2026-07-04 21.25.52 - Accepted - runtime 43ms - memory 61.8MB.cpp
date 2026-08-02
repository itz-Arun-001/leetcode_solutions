class Solution {
public: bool ispossible(vector<int>& nums,int count,int dist){
    //sort(nums.begin(),nums.end());
    int ball=1;
    int lastpos=nums[0];
    for (int i=1;i<nums.size();i++)
        {
            if(nums[i]-lastpos>=dist){
                ball++;
                lastpos=nums[i];
            }
            else continue;
        }
    return ball>=count;
    
}
    int maxDistance(vector<int>& position, int m) { 
        sort(position.begin(),position.end());
        int low=0;
        int high=position.back()-position.front();
        int ans=INT_MIN;
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(ispossible(position,m,mid)){
                    ans=max(ans,mid);
                    low=mid+1;
                }
                else high=mid-1;
            }
        return ans;
    }
};