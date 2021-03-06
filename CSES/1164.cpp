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
	int n; cin >> n;
	vector<pii> v;
	multimap<tuple<int, int>, int> mult;
	loop(i, n) {
		int a, b; cin >> a >> b;
		mult.insert(mp(make_tuple(a, b), i));
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int room = 0;

	vi ans(n);

	for (auto& u : mult) {
		int a, b, c;
		tie(a, b) = u.first;

		if (pq.empty() || pq.top().first >= a) {
			c = ++room;
		}
		else {
			c = pq.top().second;
			pq.pop();
		}
		pq.push({ b, c });
		ans[u.second] = c;
	}
	cout << room << endl;
	for (auto& u : ans) cout << u << ' ';



}
