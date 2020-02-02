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
	vi v;
	loop(i, n) {
		int in; cin >> in;
		v.pb(in);
	}

	set<int> st;

	int i = 0, j = 1;
	st.insert(v[0]);
	int sz = 1;
	int ans = 1;

	while (j < n) {
		st.insert(v[j]);
		if (st.size() != sz) {
			j++;
		}
		else {
			while (i < j && v[i] != v[j]) {
				st.erase(v[i]);
				i++;
			}
			st.erase(v[i]);
			i++;
		}

		ans = max(ans, (int)st.size());

		sz = st.size();
	}
	cout << ans << endl;
}
