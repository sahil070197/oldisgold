class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();
        deque<int> r, d;
        for(int i=0;i<len;i++) {
            if(senate[i] == 'R') {
                r.push_back(i);
            } else {
                d.push_back(i);
            }
        }
        if(d.empty()) {
            return "Radiant";
        }
        if(r.empty()) {
            return "Dire";
        }
        string lastVote="";
        while(!r.empty() && !d.empty()) {
            if(r.front() < d.front()) {
                d.pop_front();
                lastVote = "Radiant";
                if(d.empty()) {
                    return "Radiant";
                }
                r.push_back(len+r.front());
                r.pop_front();
                
            } else {
                r.pop_front();
                lastVote = "Dire";
                if(r.empty()) {
                    return "Dire";
                }
                d.push_back(len+d.front());
                d.pop_front();
            }
        }
            
            
        return lastVote;
    }
};