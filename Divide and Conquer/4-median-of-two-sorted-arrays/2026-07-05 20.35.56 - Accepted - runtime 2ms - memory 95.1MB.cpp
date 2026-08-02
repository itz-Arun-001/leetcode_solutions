/*class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged;
        for (int i = 0; i < m; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < n; i++) {
            merged.push_back(nums2[i]);
        }
        sort(merged.begin(), merged.end());
        int a = merged.size();
        if (a % 2 == 1) {
            return merged.at(a / 2);
        } else {
            return (float)((merged.at(a / 2 - 1) + merged.at(a / 2)) / 2.000);
        }
    }
};*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n2<n1) return findMedianSortedArrays(nums2,nums1);
        int n=n1+n2;
        int left=(n1+n2+1)/2;
        int low=0;
        int high=nums1.size();
        while(low<=high)
        {
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(l1<=r2&&l2<=r1)
            {
                if(n%2==1) return max(l1,l2);
                else return (double)(max(l1,l2)+min(r1,r2))/2.00;
            }
            if(l1>r2) high=mid1-1;
            if(l2>r1) low=mid1+1;
        }
        return 0;
    }
};