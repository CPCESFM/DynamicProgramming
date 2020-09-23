#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
typedef long long ll;
ll memo[MAXN][3];


int n;
int a[MAXN][3];
ll dp(int index, int equipo){
	if( index > n ) return 0;
	if(memo[index][equipo] != -1){
		return memo[index][equipo];
	}
	ll choice1 = a[index][equipo] + dp(index+1,(equipo+1)%2);
	ll choice2 = dp(index + 1, equipo);
	return memo[index][equipo] = max(choice1,choice2);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i=0; i<n ; i++){
		cin >> a[i][0];
		memo[i][0] = -1;
	}
	for(int i=0; i<n ; i++){
		cin >> a[i][1];
		memo[i][1] = -1;
	}
	ll ch1 = dp(0,0);
	ll ch2 = dp(0,1);
	cout << max(ch1,ch2) << "\n";
	return 0;
}
