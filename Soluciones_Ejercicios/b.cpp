#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 - 7;
int n,k;
vector<int> h, dp;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	h = vector<int>(n );
	dp = vector<int>(n + 1);
	for(auto &it : h) cin >> it;
	for(int i=1 ; i<=n ; i++){
		dp[i] = INF;
		for(int j = 1 ; j <= k ; j++){
			if( i - j >= 0){
				dp[i] = min(dp[i],dp[i - j] + abs(h[i] - h[i - j]));
			}
		}
	}
	cout << dp[n - 1] <<"\n";
	

	return 0;
}

