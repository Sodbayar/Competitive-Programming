#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
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

using iii = tuple<int, int, int>;
using vi = vector<int>;
using viii = vector<iii>;

int main() {
	int n, x; cin >> n >> x;
	vi v(n);
	loop(i, n) cin >> v[i];
	viii vec;

	loop(i, n) {
		for (int j = i + 1; j < n; j++) {
			vec.emplace_back(v[i] + v[j], i + 1, j + 1);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < (int)vec.size() - 1; i++) {
		int sum = get<0>(vec[i]);
		if (sum > x / 2) break;
		auto it = lower_bound(&vec[i + 1], &vec[vec.size() - 1], make_tuple(x - sum, 0, 0));
		while (sum + get<0>(*it) == x) {
			int a, b, c, x, j, q;
			tie(a, b, c) = vec[i];
			tie(x, j, q) = *it;
			if (b == j || b == q || c == j || c == q) {
				it++;
				continue;
			}
			printf("%d %d %d %d\n", b, c, j, q);
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}
