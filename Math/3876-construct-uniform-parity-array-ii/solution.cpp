/*class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool odd=false;
        bool even=false;
        int oc=0,ec=0;
        int n=nums1.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==1) {
                oc++;
                continue;
            }
            for(int j=1;j<nums1[i];j++)
            {
                if(st.count(j))
                {
                    if((nums1[i]-j)%2==1)
                    {
                        oc++ ;
                        continue;
                    }
                }

            }
            st.insert(nums1[i]);


        }
        odd=(oc==n);
        for(int i=0;i<n;i++)
        {
            if(nums1[i]%2==0) {
                ec++;
                continue;
            }
            for(int j=1;j<nums1[i];j++)
            {
                if(st.count(j))
                {
                    if((nums1[i]-j)%2==0)
                    {
                        ec++ ;
                        continue;
                    }
                }

            }
            st.insert(nums1[i]);


        }
        even=(ec==n);
        return (even||odd);
    }
};*/
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2 == 1)
                mnOdd = min(mnOdd, x);
        }

        if (mnOdd == INT_MAX)
            return true;

        for (int x : nums1) {
            if (x % 2 == 0 && x < mnOdd)
                return false;
        }

        return true;
    }
};
