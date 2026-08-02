class Solution {
public:
    int minimumPushes(string word) {
      int n=word.size();
      if(n<8)   return n;
      int cnt=0;
      int a=0;
      while(cnt<n)
      {
        if(cnt<8) a++;
        else if(cnt<16) a+=2;
        else if(cnt<24) a+=3;
        else a+=4;
        cnt++;
      }
      return a;
      
    }
};