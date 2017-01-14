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
	vector<vector<bool>> know(N);
	rep(i, N) {
		know[i] = vector<bool>(N);
		fill(begin(know[i]), end(know[i]), false);
	}
	rep(i, M) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		know[x][y] = know[y][x] = true;
	}
	int ans = 0;
	rep(i, 1 << N) {
		int n = i, cnt = 0;
		vector<int> m;
		while (n > 0) {
			if (n % 2 == 1) {
				m.push_back(cnt);
			}
			n >>= 1;
			cnt++;
		}
		bool flag = true;
		rep(j, m.size()) {
			repl(k, j + 1, m.size()) {
				if (!know[m[j]][m[k]]) {
					flag = false;
					break;
 
				}
			}
			if (!flag)break;
		}
		if (flag) {
			ans = max(ans, (int)m.size());
		}
	}
	cout << ans << endl;
 
	return 0;
}
