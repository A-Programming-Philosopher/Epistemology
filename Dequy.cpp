#include<bits/stdc++.h>
using namespace std;
int S(int n){
	if (n == 1||n==2) return 1;
	else return S(n-1) + S(n-2);
}
int main(){
	int n;
	cin >> n;
	cout << S(n);
	return 0;
}
