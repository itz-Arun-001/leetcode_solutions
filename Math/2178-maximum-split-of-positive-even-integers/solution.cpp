/*class Solution {
public:
    vector<long long>ans;
    void help(long long& t,long long &curr,vector<long long>& temp,long long i)
    {
        if(curr==t)
        {
            if(temp.size()>ans.size()) ans=temp;
            return;
        }
        if(curr>t) return;

        for(i+=2;i<t;i+=2)
        {
            curr+=i;
            temp.push_back(i);
            help(t,curr,temp,i);
            temp.pop_back();
            curr-=i;
          }
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0)
            return {};
        long long c=0,i=0;
        vector<long long> temp;
        help(finalSum,c,temp,i);
        return ans;
    }
};*/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum%2!=0)
            return {};
        vector<long long>ans;
        long long curr=2;
        while(finalSum>=curr) {
            ans.push_back(curr);
            finalSum-=curr;
            curr+=2;
        }
        if(finalSum>0) {
           ans.back()+=finalSum;
        }
        return ans;
    }
};
