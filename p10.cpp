#include <bits/stdc++.h>
using namespace std;
struct minCost{
	int n, left, cost;
	bool operator<(const minCost other) const{
		return cost > other.cost;
	}
};
int main(int argc, char const *argv[])
{
	int n, m, temp1, temp2, temp3, T, c, s, e;
	while(cin >> n >> m){
		int cost[n];
		int w[n][n];
		vector<int> v[n];
		for(int i = 0; i < n; i++){
			cin >> cost[i];
		}
		for(int i = 0; i < m; i++){
			cin >> temp1 >> temp2 >> temp3;
			v[temp1].push_back(temp2);
			w[temp1][temp2] = temp3;
		}
		cin >> T;
		while(T--){
			cin >> c >> s >> e;
			int dp[n][c];
			memset(dp, 2e9, n * c);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < c; j++)
					dp[i][j] == 2e9;
			}
			
			bool isVisit[n];
			for(int i = 0; i < n; i++) isVisit[i] = false;
			
			priority_queue<minCost> pq;
			isVisit[s] = true;
			pq.push(minCost{s, 0, 0});
			while(!pq.empty()){
				minCost top = pq.top(); pq.pop();
				for(auto i : v[top.n]){
					int capacity = c;
					while(c - w[top.n][i] >= 0){
						pq.push(minCost{i, capacity - w[top.n][i], capacity * cost[top.n]});
						capacity--;
					}
				}
				if(dp[top.n][top.left] < top.cost) dp[top.n][top.left] = top.cost;
				if(top.n == e) break;
			}
			printf("%d\n", dp[e][0]);

		}
	}
	return 0;
}