#include "bits/stdc++.h"
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define repi(itr,ds) for(auto itr = ds.begin(); itr != ds.end(); ++itr)
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

// Union-Find木
class UnionFind {
public:
	vector<int> par, rank;
 
	void init(int n) {
		par = vector<int>(n);
		rank = vector<int>(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}
 
	// 木の根を求める
	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}
 
	// xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
 
		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rank[x] == rank[y])rank[x]++;
		}
	}
 
	// xとyが同じ集合に属するか否か
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

// ノード数nのグラフについてクラスカル法で最小全域木のコストを求める
// gは各辺のコストと(始点,終点)を要素とする優先度付きキュー
// gはコストが小さい順に取り出す
ll Kruscal(priority_queue<pair<int,P>, vector<pair<int,P> >, greater<pair<int,P> > > g, int n){
	UnionFind uf;	// 連結関係を記録
	uf.init(n);		// Union-Find木を初期化
	ll ans = 0;
	
	// 全域木にはn-1本の辺があるので、n-1回辺を選ぶ
	rep(i,n-1){
		pair<int,P> e;
		// ループを作らない辺が選べるまで探す
		while(true){
			e = g.top();	// 最もコストが小さい辺を選ぶ
			g.pop();		// 選んだ辺を取り除く
			if(!uf.same(e.second.first, e.second.second)){
				// 選んだ辺によってループができないなら、採用
				break;
			}
		}
		ans += e.first;	// 採用した辺のコストを加算
		// 連結関係を更新
		uf.unite(e.second.first, e.second.second);
	}
	return ans;
}
 
int main() {
	priority_queue<pair<int,P>, vector<pair<int,P> >, greater<pair<int,P> > > G;
	int N, M;
	
	cin >> N >> M;
	
	// 交易所を都市Nとして、
	// 全ての都市に対して、
	// そこと交易所を結ぶ道を舗装するコストをc_iとする
	rep(i, N){
		int c;
		cin >> c;
		G.push(mp(c, mp(i, N)));
	}
	
	// 各道の舗装コストを記録
	rep(i, M){
		int a,b,r;
		cin >> a >> b >> r;
		a--;
		b--;
		G.push(mp(r, mp(a, b)));
	}
	
	// 最小全域木のコストを出力
	cout << Kruscal(G, N + 1) << endl;
	
	return 0;
}
