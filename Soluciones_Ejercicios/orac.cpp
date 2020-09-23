#include<bits/stdc++.h>

using namespace std;
int n,t,DP[100002];
int a[100002];

void solve(){
	cin >> n;
	for(int i=1 ; i<=n ;  i++){
		DP[i]=1;
		cin >> a[i];
	}
	for(int i=1 ; i<=n ; i++){
		for(int j=i*2 ; j<=n ; j+=i){
			if(a[i] < a[j]){
				DP[j] = max(DP[j],1+DP[i]);
			}
		}
	}
	int ans=1;
	for(int i=1 ; i<=n ;i++){
		ans = max(ans,DP[i]);
	}
	cout << ans <<"\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		solve();

	}

	return 0;
}
