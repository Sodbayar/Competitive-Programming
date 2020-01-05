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
#include <iomanip>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define oo (int)1e9 + 42
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
	int tt; cin >> tt;
	forl (t, 1, tt) {
		int n; cin >> n;
		int sum = 0;
		int st = 1, en = -1, tmpst = 1;
		int maxx = 0;

		forl(i, 2, n) {
			int x; cin >> x;
			sum += x;
			if (sum < 0) sum = 0, tmpst = i;
			if (sum >= maxx) {
				if (sum > maxx || (en - st < i - tmpst)) {
					maxx = sum;
					en = i;
					st = tmpst;
				}
			}
		}
		if (maxx <= 0) {
			printf("Route %d has no nice parts\n", t);
		}
		else {
			printf("The nicest part of route %d is between stops %d and %d\n", t, st, en);
		}

	}

}
