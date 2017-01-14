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
	int W, N, K;
	cin >> W >> N >> K;
	vector<int> a(N), b(N);
	rep(i, N) {
		cin >> a[i] >> b[i];
	}
	int dp[50][51][10001];
	memset(dp, 0, sizeof(dp));
 
	dp[0][1][a[0]] = b[0];
 
	repl(i, 1, N) {
		repl(j, 1, K + 1) {
			rep(k, W + 1) {
				if(k - a[i] >= 0) dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][k - a[i]] + b[i]);
				else dp[i][j][k] = dp[i - 1][j][k];
			}
		}
	}
	int ans = 0;
	rep(j, K + 1) {
		rep(k, W + 1) {
			ans = max(ans, dp[N - 1][j][k]);
		}
	}
 
	cout << ans << endl;
 
	return 0;
}
