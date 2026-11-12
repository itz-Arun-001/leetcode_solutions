class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        int n=arr1.size();
        int m=arr2.size();
        bool f;
        int low,high;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<n;i++)
        {
            f=true;
            low=0;
            high=m-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(abs(arr1[i]-arr2[mid])<=d)
                {
                    f=false;
                    break;
                }
                if(arr1[i]>arr2[mid]) low=mid+1;
                else high=mid-1;
            }
            if(f)cnt++;
        }
        return cnt;
    }
};
            


/*class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        int n=arr1.size();
        int m=arr2.size();
        bool f;
        for(int i=0;i<n;i++)
        {
            f=true;
            for(int j=0;j<m;j++)
            {
                if(abs(arr1[i]-arr2[j])<=d) {
                    f=false;
                    break;
                }
            }
            if(f) cnt++;
        }   
        return cnt;

    }
};*/
