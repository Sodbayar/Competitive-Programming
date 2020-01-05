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

int f, r;
double fteeth[111];
double rteeth[111];

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	while (cin >> f, f) {
		cin >> r;
		loop(i, f) cin >> fteeth[i];
		loop(i, r) cin >> rteeth[i];
		vector<double> vec;

		loop(i, r) {
			loop(j, f) {

				double q = rteeth[i] / fteeth[j];
				vec.pb(q);

			}
		}

		sort(vec.begin(), vec.end());
		double ans = -oo;
		for (int i = 1; i < vec.size(); i++) {
			ans = max(ans, vec[i] / vec[i - 1]);
		}
		printf("%.2lf\n", ans);
	}
}
