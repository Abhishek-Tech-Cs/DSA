class Solution {
public:
    vector<int>months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDays(string date){
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
        int total = day;
        for(int i = 0; i < month - 1; i++)
            total += months[i];

        return total;
    } 
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string st = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);
        if(st > end) return 0;

        return countDays(end) - countDays(st) + 1;
    }
};