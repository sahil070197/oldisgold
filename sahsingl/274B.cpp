#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> g[100001];
ll n;
ll w[100001];
ll ans = 0;
ll inc[100001], decr[100001];

void solve(ll cur, ll prev) {
	for(ll i=0;i<g[cur].size();i++) {
		ll v = g[cur][i];
		if(v!=prev) {
			solve(v, cur);
			inc[cur] = max(inc[cur], inc[v]);
			decr[cur] = max(decr[cur], decr[v]);
		} 
	}

	w[cur] += inc[cur] - decr[cur];
	if(w[cur] > 0) {
		//because positive value like 5 needs decrrement of 5 so decr[cur] = -5 => cev[cur] -= 5
		decr[cur] += w[cur];
	} else {
		//because negative value like -5 needs increment of 5 so inc[cur] -= -5 => inc[cur] += 5
		inc[cur] -= w[cur];
	}
}
int main() {
	cin>>n;
	for(ll i=0;i<n-1;i++) {
		ll u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(ll i=1;i<=n;i++) {
		cin>>w[i];
	}
	solve(1,-1);
	ans=inc[1] + decr[1];
	cout<<ans<<endl;
}
