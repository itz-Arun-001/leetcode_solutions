class Solution {
    public String minWindow(String s, String t) {
        int m=s.length();
        int n=t.length();
        int[] freq=new int[128];
        int unique=0;
        for(int i=0;i<n;i++)
        {
            if(freq[(int)t.charAt(i)]==0)
                unique++;
            freq[(int)t.charAt(i)]++;

        }
        int[] ans=new int[128];
        int aunique=0;
        int l=0;
        int minlen = Integer.MAX_VALUE;
        int st = 0;
        for(int i=0;i<m;i++)
        {
            char a=s.charAt(i);
            ans[a]++;
            if(freq[(int)a]>0&&freq[(int)a]==ans[(int)a])
            {
                aunique++;
            }
            while(aunique==unique)
            { 
                if(i-l+1<minlen)
                {
                    minlen=i-l+1;
                    st=l;
                }
                char b=s.charAt(l);
                ans[b]--;
                if(freq[b]>0&&ans[b]<freq[b])
                {
                    aunique--;
                }
              
                l++;
            }

        }
        return minlen==Integer.MAX_VALUE?"":s.substring(st,st+minlen);
    }
}
