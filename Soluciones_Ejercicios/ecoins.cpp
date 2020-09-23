#include <bits/stdc++.h>

using namespace std;

#define eps 1e-5;
#define INF 1e9;

int TC, monedas , dinero;

struct coin{
	int pr;
	int seg;
};

coin e[42];
int memo[302][302][42];

bool es_igual(double a, double b){
	return abs(a-b) < eps;
}

long double e_mod(int a, int b){
	return sqrt(a*a+b*b);
}

int DP(int fi , int se, int index ){
	if(index >= monedas){
		return 1e9;
	}
	int check = e_mod(fi,se);
	if(check > dinero){
		return 1e9;
	}
	if(es_igual(e_mod(fi,se),dinero)){
		return 0;
	}
	if(memo[fi][se][index]!=0){
		return memo[fi][se][index];
	}
	int choice1 = 1+DP(fi+e[index].pr,se+e[index].seg,index);	    int choice2 = DP(fi,se,index+1);
	return memo[fi][se][index]=min(choice1,choice2);
}
int respon;
void leer(){
	cin >> TC;
	while(TC--){
		cin >> monedas >> dinero;
		for(int i=0 ; i<monedas;i++){
			cin >> e[i].pr >> e[i].seg;	
		}
		 respon = DP(0,0,0);
		if( respon >= 1e9){
			cout << "not possible\n";
		}else{
			cout << respon<<"\n";
		}
		memset(memo,0,sizeof(memo));
	}

}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	leer();
	return 0;
}
