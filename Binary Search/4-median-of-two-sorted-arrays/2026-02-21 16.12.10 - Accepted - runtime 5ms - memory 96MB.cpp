class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector <int> merged;
        for(int i=0;i<m;i++)
        {
            merged.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++)
        {
            merged.push_back(nums2[i]);
        }
        sort(merged.begin(),merged.end());
        int a=merged.size();
        if(a%2==1)
        {
            return merged.at(a/2);
        }
        else
        {
            return (float)((merged.at(a/2 -1)+merged.at(a/2))/2.000);
        }
            }
};