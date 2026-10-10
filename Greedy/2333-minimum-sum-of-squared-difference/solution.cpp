// class Solution {
// public:
//     bool ispos(int& x,vector<long long>& dif,int& k)
//     {
//         long long need=0;
//         int n=dif.size();
//         for(int i=0;i<n;i++)
//         {
//             need+=max(0,int(dif[i]-x));
//         }
//         return need<=k;
        
//     }
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         int n=nums1.size();
//         vector<long long>dif(n,0);
//         int mx=0;
//         for(int i=0;i<n;i++)
//         {
//             dif[i]=abs(nums1[i]-nums2[i]);
//             mx=max(mx,(int)dif[i]);
//         }
//         int k=k1+k2;
//         int l=0,h=mx,pos=INT_MAX;
//         while(l<=h)
//         {
//             int m=l+(h-l)/2;
//             if(ispos(m,dif,k))
//             {
//                 pos=min(pos,m);
//                 h=m-1;
//             }
//             else l=m+1;

//         }
//         long long temp=0,cnt=0;

//         for(int i=0;i<n;i++)
//         {
//             if(dif[i]>pos){
//                 temp+=dif[i]-pos;
//                 dif[i]=pos;
//                 cnt++;
//             }

//         }
//         int rem=k-temp;
//         sort(dif.begin(),dif.end());
//        int m=0,mi=0;
//        while(rem>0)
//        {
//         for(int i=n-1;i>=0;i--)
//         {
//             if(dif[i]==pos)
//             {
//                 dif[i]--;
//                 break;
//             }
//         }
//         rem--;
//        }
    
//        long long ans=0;
//         for(int i=0;i<n;i++)
//         {
//             dif[i]=dif[i]*dif[i];
//             ans+=dif[i];
//         }
//         return ans;



//     }
// };
class Solution {
public:
    bool ispos(int& x,vector<long long>& dif,int& k)
    {
        long long need=0;
        int n=dif.size();
        for(int i=0;i<n;i++)
        {
            need+=max(0LL,dif[i]-x);
        }
        return need<=k;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<long long>dif(n,0);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            dif[i]=abs(nums1[i]-nums2[i]);
            mx=max(mx,(int)dif[i]);
        }
        int k=k1+k2;
        long long total=0;
        for(int i=0;i<n;i++) total+=dif[i];
        if(k>=total) return 0;
        int l=0,h=mx,pos=INT_MAX;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(ispos(m,dif,k))
            {
                pos=min(pos,m);
                h=m-1;
            }
            else l=m+1;
        }
        long long temp=0;
        for(int i=0;i<n;i++)
        {
            if(dif[i]>pos)
            {
                temp+=dif[i]-pos;
                dif[i]=pos;
            }
        }
        long long rem=k-temp;
        sort(dif.begin(),dif.end());
        for(int i=n-1;i>=0&&rem>0;i--)
        {
            if(dif[i]==pos)
            {
                dif[i]--;
                rem--;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=dif[i]*dif[i];
        }
        return ans;
    }
};
