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
#define oo (int)1e9 + 7
#define ii pair<int, int>
#define forl(i, k, p) for (int i = k; i <= p; i++)
#define loop(i, p) for (int i = 0; i < p; i++)
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
typedef long long ll;
using namespace std;


int main() {
	int n, x; cin >> n >> x;
	vector<pii> v;
	loop(i, n) {
		int in; cin >> in;
		v.pb({ in, i + 1 });
	}
	sort(v.begin(), v.end());


	loop(i, n - 2) {

		for (int j = i + 1; j < n - 1; j++) {

			int target = x - (v[i].first + v[j].first);

			auto it = lower_bound(v.begin() + j + 1, v.end(), mp(target, 0));
			if (it != v.end()) {
				if (target == v[it - v.begin()].first) {
					cout << v[i].second << ' ' << v[j].second << ' ' << v[it - v.begin()].second << endl;
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}
