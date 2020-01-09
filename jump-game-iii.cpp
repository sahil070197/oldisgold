class Solution {
public:
    set<int> g[50001];
    int vis[50001];
    void buildGraph(vector<int> &arr) {
        for(int i=0;i<arr.size();i++) {
            int fwd = i+arr[i];
            int bwd = i-arr[i];
            if(fwd < arr.size() && i!=fwd) {
                g[i].insert(fwd);
            }
            if(bwd >= 0 && i!=bwd) {
                g[i].insert(bwd);
            }
        } 
    }
    
    bool isZeroNodeReachable(vector<int> &arr, int cur) {
        queue<int> q;
        q.push(cur);
        vis[cur] =1;
        while(!q.empty()) {
            int x = q.front();
            vis[x] = 1;
            
            q.pop();
            if(!arr[x]) {
                return true;
            }
            
            for(set<int>::iterator it = g[x].begin();it!=g[x].end();it++) {
                int v = *it;
                if(!vis[v]) {
                    q.push(v);
                }
            }
        }
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        buildGraph(arr);
        return isZeroNodeReachable(arr, start);   
    }
};

/*
Easy solution
bool canReach(vector<int>& arr, int start) {
        if(start >=0 && start < arr.size() && s.insert(start).second) {
            return arr[start] == 0 || canReach(arr, start - arr[start]) || canReach(arr, start+arr[start]);
        }  
        return false;
    }
*/