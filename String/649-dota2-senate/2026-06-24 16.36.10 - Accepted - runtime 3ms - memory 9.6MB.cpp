/*class Solution {
public:
    string predictPartyVictory(string senate) {
        int d,r=0;
        for(auto c:senate)
        {
            if(c=='R') r++;
            else  d++;
        }
        return(r>d)?"Radiant":"Dire";
        
    }
};*/




class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char>q;
        int ban=0;
        for(char c:senate)
        {
            q.push(c);
        }
        while(q.size()>abs(ban))
        {
            if(q.front()=='D'&&ban<0)
            {
                ban++;
                q.pop();
            }
            else if(q.front()=='R'&&ban>0)
            {
                ban--;
                q.pop();
            }
            else{
                if(q.front()=='R')
                {
                    ban--;
                    q.push(q.front());
                    q.pop();

                }

                else{
                    ban++;
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        return ban>0?"Dire":"Radiant";
    }
};