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
	string in; cin >> in;

	int q; cin >> q;
	vector < vector<int >> vec;
	vec.resize(256);

	loop(i, in.size())
		vec[in[i]].pb(i);

	while (q--) {
		string ss; cin >> ss;
		int idx = -1, fi = -1;
		bool flag = 1;
		loop(i, ss.size()) {
			vector<int>::iterator upper;
			upper = upper_bound(vec[ss[i]].begin(), vec[ss[i]].end(), idx);
			if (upper == vec[ss[i]].end()) {
				flag = 0;
				break;
			}
			int pos = upper - vec[ss[i]].begin();
			idx = vec[ss[i]][pos];
			if (i == 0) fi = idx;
		}
		if (flag) {
			printf("Matched %d %d\n", fi, idx);
		}
		else cout << "Not matched\n";
	}

}
