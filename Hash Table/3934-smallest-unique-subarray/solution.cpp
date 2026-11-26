    class Solution {
    public:
        bool check(vector<int>& nums,int len){
            unordered_map<long long,int>mp;
            int n=nums.size();
            long long power=1;
            long long hash=0;
            const long long MOD=1000000007;
            int l=0;
                for(int i=0;i<len;i++)
                {
                    hash=(hash*29+nums[i])%MOD;
                }
                for(int i=1;i<len;i++)
                    power=(power*29)%MOD;
                mp[hash]++;
                for(int l=1;l+len<=n;l++)
                {
                    // hash=hash-nums[l-1]*pow(31,len-1);
                    // hash=hash*31-nums[l+len-1];
                    //hash=((hash-nums[l-1]*power)*31+nums[l+len-1])%MOD;----> it produces negative hash 
                    hash=((hash-nums[l-1]*power)%MOD+MOD)%MOD;
                    hash=(hash*29+nums[l+len-1])%MOD;
                    mp[hash]++;
                }
                for(auto m:mp)
                {
                    if(m.second==1)
                    {
                        return true;
                    }
                }
            
            return false;
        }
        int smallestUniqueSubarray(vector<int>& nums) {
            int n=nums.size();
            int l=1,r=n,ans=n;
            while(l<=r)
            {
                int m=l+(r-l)/2;
                if(check(nums,m))
                {
                    ans=m;
                    r=m-1;
                }
                else l=m+1;
            }
            return ans;
        }
    };

    /*

    class Solution {
    public:
        int smallestUniqueSubarray(vector<int>& nums) {
            map<vector<int>,int>mp;
            int n=nums.size();
            vector<int>sub;
            for(int len=1;len<=n;len++)
            {
                sub.clear();
                mp.clear();
                int l=0,r=len;
                sub.assign(nums.begin()+l,nums.begin()+r);
                mp[sub]++;
                for(int l=1;l+len<=n;l++)
                {
                    r++;
                    sub.assign(nums.begin()+l,nums.begin()+r);
                    mp[sub]++;
                }
                for(auto m: mp)
                {
                    if(m.second==1)
                    {
                        return m.first.size();
                    }
                }
            }
            return 0;

        }
    };

    */
