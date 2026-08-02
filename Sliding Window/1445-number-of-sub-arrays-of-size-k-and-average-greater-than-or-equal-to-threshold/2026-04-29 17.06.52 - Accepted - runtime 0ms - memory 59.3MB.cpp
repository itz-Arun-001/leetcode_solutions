class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int key) {
        int n=arr.size();
        int c=0;
        double avg=INT_MIN;
        double sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
       // avg=sum/k;
        if(sum/k>=key)
        {
            c++;
        }
        for(int i=k;i<n;i++)
        {
            sum+=arr[i];
            sum-=arr[i-k];
            if(sum/k>=key)
                c++;
            
           }
           return c;

        
    }
};