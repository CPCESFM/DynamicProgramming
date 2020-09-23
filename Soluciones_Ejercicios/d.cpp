#include<iostream>
#include<vector>
#include<string.h>
#include<limits.h>

using namespace std;

int n, S;
const int MAXN = 1e9 + 2;
const long long INF = LONG_MAX;
vector<long long> w,v;
long long dp[MAXN][102];
long long memo[MAXN][102];


long long ganacia(int S, int k){
	if(S < 0) return -INF;
	if(S == 0) return 0;
	if(k >= n) return 0;
	if(memo[S][k] != -1) return memo[S][k];

	return memo[S][k] = max(ganacia(S - w[k], k + 1) + v[k], ganacia(S, k + 1));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> S;
	memset(memo, -1, sizeof(memo));
	w = vector<long long>(n);
	v = vector<long long>(n);
	for(int i=0 ; i<n ; i++){
		cin >> w[i] >> v[i];
	}

	for(int s= 1 ; s<=S ; s++){
		for(int k = n - 1; k >=0 ; k--){
			long long x = -INF;
			if(s - w[k] >= 0) x = dp[s - w[k]][k + 1] + v[k];
			long long y = 0;
			if( k < n) y = dp[s][k + 1];
			dp[s][k] = max(x,y);
		}
	}
	cout << dp[S][0] <<"\n";
//	cout << ganacia(S,0) <<"\n";
	return 0;
}
