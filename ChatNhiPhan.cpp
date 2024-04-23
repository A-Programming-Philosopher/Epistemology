#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int a[], int n, int t, ll time){
	ll dem =0;
	for(int  i = 0; i <n; i++){
		dem += time / a[i];
	}
	return dem >= t;
}
int main(){
	int n, t;
	cin >> n >> t;
	int a[n];
	for(int &x : a) cin >> x;
	ll left = 0, right = 1ll * (*min_element(a, a + n)) *t;
	ll ans = -1;
	while(left <= right){
		ll mid = (left + right) / 2;
		// check mid
		if(check(a, n, t, mid)){
			ans = mid;
			right = mid-1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << ans << endl;
}