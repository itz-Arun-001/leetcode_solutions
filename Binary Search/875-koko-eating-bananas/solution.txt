/*class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     int high=*max_element(piles.begin(),piles.end());
     int low=1;
     int k=high;
     int n=piles.size();

     while(low<=high)
     {
        int mid=(high+low)/2;
        long long taken =0;
        for(int i=0;i<n;i++)
        {
            taken+=(piles[i]+mid-1)/mid;

        }
        if(taken<=h)
        {
            k=mid;
            high=mid-1;
        }
        else    low=mid+1;
     }
     return k;
    }
};*/
class Solution {
public:
    long long findtime(vector<int>& arr, int val) {
        long long tt = 0;
        for (int i = 0; i < arr.size(); i++) {
            tt += ceil((double)arr[i] / val);
        }
        return tt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long tt = findtime(piles, mid);
            if (tt <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};