class Solution {
public:
    int dayOfYear(string date, vector<int>&currMonthDay){
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3));
        if(month == 1) return day;
        return currMonthDay[month-2]+day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int>currMonthDay(12,0);
        currMonthDay[0]=31;
        for(int i=1;i<12;i++){
            currMonthDay[i]=currMonthDay[i-1]+daysInMonth[i];
        }
        int arriveAliceDay = dayOfYear(arriveAlice,currMonthDay);
        int leaveAliceDay = dayOfYear(leaveAlice,currMonthDay);
        int arriveBobDay = dayOfYear(arriveBob,currMonthDay);
        int leaveBobDay = dayOfYear(leaveBob,currMonthDay);

        int overlapDays = min(leaveAliceDay,leaveBobDay)-max(arriveAliceDay,arriveBobDay)+1;

        return max(0,overlapDays);
    }
};