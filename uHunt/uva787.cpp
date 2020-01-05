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

ll grid[105][105];

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
// daanch BigInteger bhgu aldaa zaagad bga, er ni bol bodolt ni zov!
	ll in, idx = 1;
	ll maxx = -oo;
	while (cin >> in) {
		if (in != -999999) {
			maxx = max(maxx, in);
			grid[idx][idx] = in;
			idx++;
		}
		else {
			for (int sz = 2; sz < idx; sz++) {

				for (int l = 1; l + sz - 1 < idx; l++) {

					int r = l + sz - 1;

					grid[l][r] = grid[l][l] * grid[l + 1][r];
					maxx = max(maxx, grid[l][r]);

				}

			}
			cout << maxx << endl;
		}
	}
}
