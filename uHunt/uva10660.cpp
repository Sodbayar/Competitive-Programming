#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cctype>
#include <bitset>
#include <stack>
#include <iterator>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define oo (int)1e9
#define ii pair<int, int>
#define forl(i, k, p) for (int i = k; i <= p; i++)
#define loop(i, p) for (int i = 0; i < p; i++)
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&bingo)
#define sffl(a,b)       scanf("%lld %lld",&a,&bingo)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&bingo,&c)
using namespace std;

struct ppl {
	int x;
	int y;
	int popul;
};

vector<ppl> area;
vector<pii> allArea;
int ans = oo;
vector<int> ansIdx;

void solve(int pos, vector<int>& v) {
	if (v.size() == 5) {
		int sum = 0;
		for (auto u : area) {

			int tmp = oo;

			for (auto idx : v) {
				tmp = min(tmp, abs(allArea[idx].first - u.x) + abs(allArea[idx].second - u.y));
			}
			sum += tmp * u.popul;
		}
		if (sum < ans) {
			ans = sum;
			ansIdx = v;
		}

		return;
	}

	if (pos >= 25) return;

	v.pb(pos);
	solve(pos + 1, v);
	v.pop_back();
	solve(pos + 1, v);

}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	loop(i, 5) loop(j, 5) allArea.pb({i, j});

	int tt; cin >> tt;
	while (tt--) {
		ans = oo;
		ansIdx.clear();
		area.clear();
		int n; cin >> n;
		loop(i, n) {
			ppl p;
			cin >> p.x >> p.y >> p.popul;
			area.pb(p);
		}
		vector<int> tmp;
		solve(0, tmp);
		loop(i, 5) {
			if (i) cout << ' ';
			cout << ansIdx[i];
		}
		cout << endl;
	}

}
