class Solution {
public:
int ans=0;
void help(int &n,int idx,vector<int>& temp,vector<int>&freq)
{
    //if(idx==n-1)
    if(temp.size()==n)
    {
        ans++;
        return ;

    }
    //if(idx>=n) return;
    int a=temp.size()+1;
    for(int i=1;i<=n;i++)
    {
        if((freq[i]==0)&&(i%a==0||a%i==0))
        {
            temp.push_back(i);
            freq[i]=1;
            help(n,i+1,temp,freq);
            temp.pop_back();
            freq[i]=0;
        }

    }
}
    int countArrangement(int n) {
        vector<int>freq(n+1,0);
        vector<int>temp;
        help(n,0,temp,freq);
        return ans;
    }
};
