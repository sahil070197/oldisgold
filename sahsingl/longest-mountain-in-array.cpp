class Solution {
public:
    int getIncreasingLength(vector<int> &ar, int start) {
        int len = 1;
        while(start < ar.size()-1 && ar[start+1] > ar[start]) {
            len++;
            start++;
        }
        return len;
    }
    
    int getDecreasingLength(vector<int> &ar, int start) {
        int len = 1;
        while(start < ar.size() -1 && ar[start + 1] < ar[start]) {
            len++;
            start++;
        }
        return len;
    }
    
    bool validate(int len, int &cur) {
        if(len >=2) {
            cur+=len-1;
            return true;
        } else {
            cur++;
            return false;
        }
    }
    int longestMountain(vector<int>& ar) {
        int cur = 0;
        int ans = 0;
        int size = ar.size();
        while(cur < size) {
            int inc = getIncreasingLength(ar, cur);
            if(!validate(inc, cur)) {
                continue;
            }
            
            int dec = getDecreasingLength(ar, cur);
            if(!validate(dec, cur)) {
                continue;
            }
            ans = max(ans, inc + dec - 1);
        }
        return ans;
    }
};