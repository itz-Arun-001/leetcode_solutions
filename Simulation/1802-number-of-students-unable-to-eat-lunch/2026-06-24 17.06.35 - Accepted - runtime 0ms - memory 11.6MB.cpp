class Solution {
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