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
	int n, m, k;
	cin >> n >> m >> k;
	vi app, desired;
	loop(i, n) {
		int in; cin >> in;
		app.pb(in);
	}
	loop(i, m) {
		int in; cin >> in;
		desired.pb(in);
	}

	sort(app.begin(), app.end());
	sort(desired.begin(), desired.end());
	vector<bool> vis(desired.size(), 0);
	int ans = 0;
	int i = 0, j = 0;

	while (i < n && j < m) {

		if (app[i] + k < desired[j]) {
			i++;
		}
		else if (app[i] - k > desired[j]) {
			j++;
		}
		else {
			i++, j++; ans++;
		}

	}

	cout << ans << endl;
}
