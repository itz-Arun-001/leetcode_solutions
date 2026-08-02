class Solution {
public:int max(int a,int b)
        {
            return (a>b)?a:b;
        }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        int x=0;
        int n=arr1.size();
        int m=arr2.size();
        unordered_set<string>s;
        
        for(int i=0;i<n;i++)
        {
            string a=to_string(arr1[i]);
            string temp="";
            for(char ch : a)
            {
                temp+=ch;
                s.insert(temp);
            }
        }
        for(int i=0;i<m;i++)
        {
            string a=to_string(arr2[i]);
            string temp="";
            for(char ch : a)
            {
                temp+=ch;
                if(s.count(temp))
                {
                    ans=max(ans,temp.size());
                }
            }
        }
        return ans;
        

        
    }
};