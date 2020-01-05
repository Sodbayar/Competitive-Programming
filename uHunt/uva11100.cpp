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



int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	vector<int> vec;
	int n;
	bool flag = 0;
	while (cin >> n, n) {
		vec.clear();
		loop(i, n) {
			int in; cin >> in;
			vec.pb(in);
		}

		sort(vec.begin(), vec.end());

		int maxCnt = 0;
		int prev = vec[0];
		int cnt = 0;
		for (auto u : vec) {
			if (u == prev) {
				cnt++;
				maxCnt = max(maxCnt, cnt);
			}
			else {
				cnt = 1;
				prev = u;
			}
		}
		if (flag) cout << endl;
		flag = 1;

		cout << maxCnt << endl;
		for (int st = 0; st < maxCnt; st++) {
			for (int i = st; i < n; i += maxCnt) {
				cout << vec[i];
				if (i + maxCnt < n) cout << ' ';
			}
			cout << endl;
		}
	}
}
