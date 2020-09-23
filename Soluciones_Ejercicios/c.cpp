#include<iostream>
#include<vector>

using namespace std;
const int MAXN = 1e5;
const int INF = 1e9 - 7;
typedef long long ll;
ll dp[MAXN + 2][4];
int n;
vector<ll> a,b,c;

ll happy(ll N, ll K){
	if(N == 0) return 0;
	if(dp[N][K] != -1) return dp[N][K];
	if(K == 3) return dp[N][K] = max(happy(N-1, 2) + b[N], happy(N-1, 1) + a[N]);
	if(K == 2) return dp[N][K] = max(happy(N-1, 1) + a[N], happy(N-1, 3) + c[N]);
	if(K == 1) return dp[N][K] = max(happy(N-1, 2) + b[N], happy(N-1, 3) + c[N]);
	if(K == 0) return dp[N][K] = max(happy(N-1, 1) + a[N], max(happy(N-1, 2) + b[N],happy(N-1, 3) + c[N]));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	a = vector<ll>(n + 1);
	b = vector<ll>(n + 1);
	c = vector<ll>(n + 1);

	for(int i=0 ; i<=n ; i++)
		for(int j=0 ; j<=3 ; j++)
			dp[i][j] = -1;
	a[0] = INF;
	b[0] = INF;
	c[0] = INF;
	for(int i=1 ; i<=n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	cout << happy(n, 0) <<"\n";
		
	return 0;
}
