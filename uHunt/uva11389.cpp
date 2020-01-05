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

int mrn[101];
int evn[101];

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n, d, r;
	while (1) {
		cin >> n >> d >> r;
		if (n == 0 && d == 0 && r == 0) break;
		loop(i, n) cin >> mrn[i];
		loop(i, n) cin >> evn[i];

		sort(mrn, mrn + n);
		sort(evn, evn + n, greater<int>());

		int cost = 0;

		loop(i, n) {
			int diff = d - (mrn[i] + evn[i]);
			if (diff < 0) cost += abs(diff) * r;
		}
		cout << cost << endl;
	}
}
