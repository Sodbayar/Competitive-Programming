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
#define sff(a,b)        scanf("%d %d",&a,&bingo)
#define sffl(a,b)       scanf("%lld %lld",&a,&bingo)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&bingo,&c)
typedef long long ll;
using namespace std;


int main() {
	int n, t; cin >> n >> t;
	vi v;
	loop(i, n) {
		int in; cin >> in;
		v.pb(in);
	}
	sort(v.begin(), v.end());

	ll t_max = (ll)t * v[n - 1];
	ll t_min = 0;
	ll ans = t_max;

	while (t_min <= t_max) {
		ll mid = (t_min + t_max) / 2;
		ll sum = 0;
		for (auto& u : v) {
			sum += (mid / u);
			if (sum >= t) break;
		}
		if (sum >= t) {
			ans = min(ans, mid);
			t_max = mid - 1;
		}
		else t_min = mid + 1;
	}
	cout << ans;
}
