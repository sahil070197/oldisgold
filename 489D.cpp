#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[3001];
void input() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
	}
}
void getFixedDistantNodes(int start, int distance, int parent, vector<int> &ans) {
	if(distance == 0) {
		ans.push_back(start);
		return;
	}
	for(int i=0;i<g[start].size();i++) {
		int v = g[start][i];
		if(v!=parent) {
			getFixedDistantNodes(v, distance-1, start, ans);
		}
	}
}
vector<int> getFixedDistantNodes(int start, int distance) {
	vector<int> ans;
	getFixedDistantNodes(start, distance, -1, ans);
	return ans;
}
map<int, int> getNodeToFrequencyMap(vector<int> &nodes) {
	map<int, int> nodeToFrequencyMap;
	for(int i=0;i<nodes.size();i++) {
		nodeToFrequencyMap[nodes[i]]++;
	}
	return nodeToFrequencyMap;
}
int getRhombiCount(map<int, int> &nodeToFrequencyMap) {
	int ans = 0;
	for(it = nodeToFrequencyMap.v.begin(), it != v.end(); it++) {
		int freq = it->second;	
		ans+= (freq * (freq-1))/2;
	}
	return ans;
}
void solve() {
	//for each node get 2 distant nodes
	int ans = 0;
	for(int i=1;i<=n;i++) {
		vector<int> twoDistantNodes = getFixedDistantNodes(i, 2);
		map<int, int> nodeToFrequencyMap = getNodeToFrequencyMap(twoDistantNodes);
		ans+=getRhombiCount(nodeToFrequencyMap);
	}
	return ans;
}
void output(int ans) {
	cout<<ans<<endl;
}
int main() {
	input();
	int ans = solve();
	output(ans);
}