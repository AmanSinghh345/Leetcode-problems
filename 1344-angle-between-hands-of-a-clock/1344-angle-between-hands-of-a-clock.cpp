class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle=minutes*6;
        double hrsAngle=(hour%12)*30 + (minutes/2.0);
        double firstAngle=abs(minAngle-hrsAngle);
        double secondAngle=360-firstAngle;
        return min(firstAngle,secondAngle);
    }
};