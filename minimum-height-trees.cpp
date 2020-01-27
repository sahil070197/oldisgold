class Solution {
public:
    vector<int> g[100001];
    int parent[100001],dist[100001];
    int nodes;
    
    void buildGraph(vector<vector<int>> edges) {
        for(int i=0;i<edges.size();i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    void dfs(int cur, int prev, int d) {
        parent[cur] = prev;
        dist[cur] = d;
        for(int i=0;i<g[cur].size();i++) {
            if(g[cur][i]!=prev) {
                dfs(g[cur][i], cur, d+1);
            }
        }
    }
    
    int getMaxDistantNode() {
        int d = 0, node = 0;
        for(int i=0;i<nodes;i++) {
            if(dist[i] > d) {
                node = i;
                d = dist[i];
            }
        }
        return node;
    }
    vector<int> getPath(int start, int end) {
        vector<int> path;
        path.push_back(start);
        while(start!=end) {
            start = parent[start];
            path.push_back(start);
        }
        return path;
    }
    vector<int> solve() {
        dfs(0, -1, 0);
        int first = getMaxDistantNode();
        dfs(first, -1, 0);
        int second = getMaxDistantNode();
        vector<int> path = getPath(second, first);
        int pathLen = path.size();
        vector<int> ans;
        ans.push_back(path[(pathLen)/2]);
        if(pathLen%2==0) {
            ans.push_back(path[(pathLen-1)/2]);
        } 
        return ans;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        buildGraph(edges);
        nodes = n;
        return solve();
    }
};