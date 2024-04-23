#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, c[100][100], X[100], ans = INT_MAX,cmin=INT_MAX;
int visited[100];

void Try(int i, int dis){
	for(int j =1; j <= n; j++){// cac thanh pho
		if(!visited[j]){
			X[i]=j;
			visited[j]=1;
			dis += c[X[i-1]][X[i]];
			if(i == n){
				ans = min(ans,dis+c[X[n]][i]);
			}
			else if(dis+(n-i+1)*cmin < ans) {// nhanh can
				Try(i+1, dis);
			}
			visited[j]=0;
			dis -= c[X[i-1]][X[i]];
		}
	}
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c[i][j];
			if(c[i][j]) cmin = min(cmin,c[i][j]);//tim chi phi nho nhat
		}
	}
	memset(a + 1, a+n+1, 0);
	X[1] = 1;
	visited[1] = 1;
	Try(2,0);
	cout << ans << endl;
}