/*class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        int c1 = 0, c0 = 0;
        for (int i : stud) {
            if (i == 1) {
                c1++;

            } else
                c0++;
        }
        for (int i : sand) {
             if (i==1&&c1 == 0||i==0 && c0 == 0) {
                break;
            }
            if (c1 > 0 && i == 1) {
                c1--;
            } else if (c0 > 0 && i == 0) {
                c0--;
            }
           
        }
        return c1+c0;
    }
};

*/
class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        stack<int>st;
        queue<int>q;
        for(int  i:stud)
        {
            q.push(i);
        }
        for(int i=sand.size()-1;i>=0;i--)
        {
            st.push(sand[i]);
        }
        int cnt=0;
        while(!q.empty())
        {
            int x=q.front();
            if(q.front()!=st.top())
            {

                cnt++;
                q.push(x);
                q.pop();
                if(cnt==q.size())
                {
                    break;
                }
            }
            else{
                cnt=0;
                q.pop();
                st.pop();
            }
        }
        return cnt;
    }
};