#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MaxN = 1e5;
const int MaxM = 1e5;

vector<vector<int>> lista(MaxN);
vector<int> memo(MaxN, -1);
vector<int> bu(MaxN, -1);
int dp(int nodo){
	if(lista[nodo].empty()) return 0;
	if(memo[nodo] != -1) return memo[nodo];
	int maxE = INT_MIN;
	for(auto x: lista[nodo]){
		maxE = max(1 + dp(x), maxE);
	}
	return memo[nodo] = maxE;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, u, v;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		u--,v--;
		lista[u].push_back(v);
	}
	int maxE;
	for(int i=0; i<n; i++){
		if(memo[i] == -1){
			dp(i);
		}
	}
	int maxE = INT_MIN;
	for(int j=0; j<n; j++){
		maxE = max(maxE, memo[j]);
	}
	cout << maxE <<"\n";
	
	return 0;
}
