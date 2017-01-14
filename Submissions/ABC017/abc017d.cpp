#include "bits/stdc++.h"
using namespace std;
 
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define replrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) replrev(i,0,n)
#define repi(itr,ds) for(auto itr = ds.begin(); itr != ds.end(); ++itr)
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
#define PI 3.1415926536
typedef long long ll;
typedef pair<int, int> P;
 
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> f(N);
	rep(i, N) {
		cin >> f[i];
		f[i]--;
	}
	vector<int> next(N);
	vector<int> recent(M);
	fill(begin(next), end(next), N);
	fill(begin(recent), end(recent), -1);
	rep(i, N) {
		if (recent[f[i]] != -1) {
			next[recent[f[i]]] = i;
		}
		recent[f[i]] = i;
	}
	reprev(i, N - 1) {
		next[i] = min(next[i], next[i + 1]);
	}
 
	vector<int> num(N + 1);
	vector<int> numsum(N + 1);
	num[N] = 1;
 
	reprev(i, N) {
		if (next[i] + 1 < N + 1) num[i] = num[i + 1] - num[next[i] + 1] + MOD;
		else num[i] = num[i + 1];
		num[i] %= MOD;
		if(i != 0) num[i] += num[i + 1];
		num[i] %= MOD;
	}
 
	cout << num[0] << endl;
 
	return 0;
}
