class Solution {
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
            taken+=ceil((double)piles[i] / mid);

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
};