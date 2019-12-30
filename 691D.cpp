#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000001];
int ar[1000001], vis[1000001], ans[1000001];
int n, m;
void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>ar[i];
	}
	for(int i=0;i<m;i++) {
		int u, v;
		cin>>u>>v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

vector<int> getConnectedComponent(int start) {
	queue<int> q;
	vector<int> ans;
	q.push(start);
	vis[start] = 1;
	ans.push_back(start);
	while(!q.empty()) {
		int fr = q.front();
		q.pop();
		for(int i=0;i<g[fr].size();i++) {
			int v = g[fr][i];
			if(!vis[v]) {
				vis[v] = 1;
				q.push(v);
				ans.push_back(v);
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

vector<int> valuesOfConnectedComponent(vector<int> &connectedComponent) {
	vector<int> values;
	for(int i=0;i<connectedComponent.size();i++) {
		values.push_back(ar[connectedComponent[i]]);
	}
	sort(values.rbegin(), values.rend());
	return values;
}

void buildAns(vector<int> &connectedComponent, vector<int> &valuesOfConnectedCom) {
	for(int i=0;i<connectedComponent.size();i++) {
		ans[connectedComponent[i]] = valuesOfConnectedCom[i];
	}
}
void solve() {
	for(int i=0;i<n;i++) {
		if(!vis[i]) {
			vector<int> connectedComponent = getConnectedComponent(i);
			vector<int> valuesOfConnectedCom = valuesOfConnectedComponent(connectedComponent);
			buildAns(connectedComponent, valuesOfConnectedCom);
		}
	}
}

void output() {
	for(int i=0;i<n;i++) {
		cout<<ans[i]<<" ";
	}
}
int main() {
	
	input();
	solve();
	output();
}