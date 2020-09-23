#include <iostream>
#include <vector>

using namespace std;
int n;
const int INF = 1e7;
vector<int> h;
vector<int> dp;

int main(){
	cin >> n;
	h = vector<int>(n);
	dp = vector<int>(n + 1);
	for(auto &it: h) cin >> it;
	for(int i=1; i<=n ; i++){
		int x = dp[i - 1] + abs(h[i] - h[i - 1]);
		int y = i - 2 >= 0 ? dp[i - 2] + abs(h[i] - h[i - 2]) : INF;
		dp[i] = min(x,y);
	}
	cout << dp[n-1] << "\n";

	return 0;
}
