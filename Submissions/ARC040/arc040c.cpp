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
	int N;
	cin >> N;
	vector<vector<char>> f(N);
	rep(i, N) {
		f[i] = vector<char>(N);
		string str;
		cin >> str;
		rep(j, N) {
			f[i][j] = str[j];
		}
	}
	int ans = 0;
	rep(i, N) {
		reprev(j, N) {
			if (f[i][j] == '.') {
				ans++;
				replrev(k, 0, j + 1) {
					f[i][k] = 'o';
				}
				if (i != N - 1) {
					repl(k, j, N) {
						f[i + 1][k] = 'o';
					}
				}
			}
		}
	}
	cout << ans << endl;
 
	return 0;
}
