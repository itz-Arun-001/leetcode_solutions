class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=1;
        int prefix=0;
        int n=arr.size();
        int ans=0;
        const int MOD=1000000007;
        for(int i=0;i<n;i++)
        {
            prefix+=arr[i]%MOD;
            if(prefix%2==0)
            {
                ans=(ans+odd)%MOD;
                even++;
            }
            else{
                ans=(ans+even)%MOD;
                odd ++;

            }
        }
        return ans;
    }
};
