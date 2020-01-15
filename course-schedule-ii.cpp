class Solution {
public:
    vector<int> g[100001];
    vector<int> ans;
    int vis[100001], timeStamp[100001], counter=0, noAnswer= 0;
    
    void buildGraph(vector<vector<int>> &edges) {
        for(int i=0;i<edges.size();i++) {
            int v = edges[i][0];
            int u = edges[i][1];
            g[u].push_back(v);
        }
    }
    void dfs(int start) {
        vis[start]=1;
        for(int i=0;i<g[start].size();i++) {
            int v = g[start][i];
            if(!noAnswer && vis[v] == 0) {
                dfs(v);
            }
            if(vis[v] == 1) {
                noAnswer=1;
                return;
            }
        }
        vis[start]=2;
        timeStamp[counter++] = start;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& edges) {
        buildGraph(edges);
        for(int i=0;i<numCourses;i++) {
            if(vis[i]==0) {
                dfs(i);
            }   
        }
        if(noAnswer) {
            return ans;
        }
        for(int i=counter-1;i>=0;i--) {
            ans.push_back(timeStamp[i]);
        }
        return ans;
    }
};