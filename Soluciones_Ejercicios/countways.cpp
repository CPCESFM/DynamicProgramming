#include <bits/stdc++.h>

using namespace std;
int peticion,maximo;
long long dp[30002][6];

int main(){
	vector<int> coins{1,5,10,25,50};
	int n = 5;
	queue<int> q;

	while(cin >> peticion){
		maximo = max(peticion, maximo);
		q.push(peticion);
	}

	for(int i=0; i < 5; i++) dp[0][i] = 1;
	for(int i= 1; i<= maximo; i++){
		for(int j = n - 1; j >= 0; j--){
			if( i - coins[j] >= 0) dp[i][j] += dp[i - coins[j]][j];
			dp[i][j] += dp[i][j + 1];
		}
	}
	
	while(!q.empty()){
		if(dp[q.front()][0] == 1){
			printf("There is only 1 way to produce %d cents change.\n",q.front());
			q.pop();
		}else{
			printf("There are %lld ways to produce %d cents change.\n",dp[q.front()][0],q.front());
			q.pop();
		}
	}

	return 0;
}
