class Solution {
public:
    map<string, vector<pair<string, double>>> g;
    void printGraph() {
        for(auto it=g.begin();it!=g.end();it++) {
            for(int j=0;j<(it->second).size();j++){
                cout<<it->first<<" "<<((it->second)[j].first)<<" "<<((it->second)[j].second)<<endl;
            }
        }
    }
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for(int i=0;i<equations.size();i++) {
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            g[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }   
    }
    int validate(string start, string end) {
        return g[start].size()==0 || g[end].size()==0;
    }
    double solve(string start, string end) {
        if(validate(start,end)) {
            return -1.0;
        }
        map<string, int> vis;
        queue<pair<string, double>> q;
        q.push({start,1});
        vis[start] = 1;
        while(!q.empty()) {
            pair<string, double> front = q.front();
            if(front.first == end) {
                return front.second;
            }
            q.pop();
            
            for(int i=0;i<g[front.first].size();i++) {
                pair<string, double> v = g[front.first][i];
                if(!vis[v.first]) {
                    vis[v.first]=1;
                    q.push({v.first, front.second*v.second});
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        buildGraph(equations, values);
        vector<double> ans;
        for(int i=0;i<queries.size();i++) {
            ans.push_back(solve(queries[i][0], queries[i][1]));
        }
        return ans;   
    }
};