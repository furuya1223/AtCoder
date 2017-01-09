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
	double a, b;
	int N;
	cin >> a >> b >> N;
	rep(i, N) {
		double c, d;
		cin >> c >> d;
		if (min(a, b) <= min(c, d) && max(a, b) <= max(c, d)) {
			cout << "YES" << endl;
		}
		else if (min(a, b) > min(c, d) || a*a + b*b > c*c + d*d) {
			cout << "NO" << endl;
		}
		else {
			if (a < b)swap(a, b);
			double th1 = 2 * atan2(b, a);
			double th2 = acos(c / sqrt(a*a + b*b));
			double th3 = acos(d / sqrt(a*a + b*b));
			if (PI / 2 - th2 - th3 > th1) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
 
	return 0;
}