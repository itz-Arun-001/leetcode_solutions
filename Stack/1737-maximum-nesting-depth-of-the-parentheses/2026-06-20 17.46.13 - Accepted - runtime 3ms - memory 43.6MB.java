class Solution {
    public int maxDepth(String s) {
         int x=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
                {
            if(s.charAt(i)=='('){ x++;
            ans=Math.max(ans,x);}


            else if(s.charAt(i)==')')  x--;
            else   continue;
        }
        System.gc();
        return ans;
        
    }
}