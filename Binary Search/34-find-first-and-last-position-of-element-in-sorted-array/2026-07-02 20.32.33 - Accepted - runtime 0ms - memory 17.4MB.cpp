/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n= nums.size();
        int low=0;
        int high=n-1;
        int first=-1,end=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else    high=mid-1;

        }
        low=0;high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                end=mid;
                low=mid+1;
            }
             else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else    high=mid-1;

        }
        return {first,end};
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        ans.push_back((lower_bound(nums.begin(), nums.end(), target)) - nums.begin());
        ans.push_back((upper_bound(nums.begin(), nums.end(), target) - nums.begin()) -1);

        return ans;
    }
};

*/
int lb(vector<int>& a,int x)
{
    int low=0;
    int ans=a.size();
    int high=a.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return ans;
}
int ub(vector<int>& a,int x)
{
    int low=0;
    int ans=a.size();
    int high=a.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lb(nums,target);
        if(l==nums.size()||nums[l]!=target)
        {
            return {-1,-1};
        }
        else 
             return {l,ub(nums,target)-1};
    }
};
