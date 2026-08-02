class Solution {
public:
    double angleClock(int hour, int minutes) {
        //double a= abs((((hour%12)*30)+(minutes*0.5))-minutes*6);
        //return min(a,360-a);
        return min(abs((((hour%12)*30)+(minutes*0.5))-minutes*6),360-abs((((hour%12)*30)+(minutes*0.5))-minutes*6));
    }
};
/*double hour_angle = (hour % 12 ) * 30 + minutes * 0.5;
        double minute_angle = minutes * 6;
        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360 - diff);*/