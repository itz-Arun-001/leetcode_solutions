class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a= abs((((hour%12)*30)+(minutes*0.5))-minutes*6);
        return min(a,360-a);
        
    }
};