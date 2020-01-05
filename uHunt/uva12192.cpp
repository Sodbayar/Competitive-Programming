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


int grid[505][505];
int n, m;
int l, r;

bool isOK(int x, int y, int len) {
	if (x + len >= n || y + len >= m) return 0;
	return 1;
}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	while (cin >> n >> m, n + m) {
		loop(i, n) loop(j, m) cin >> grid[i][j];
		int Q; cin >> Q;
		while (Q--) {
			int maxNum = 0;
			cin >> l >> r;
			loop(i, n - maxNum + 1) {
				loop(j, m - maxNum + 1) {
					if (grid[i][j] >= l) {
						int len = maxNum;
						while (isOK(i, j, len) && grid[i + len][j + len] <= r) len++;
						maxNum = max(maxNum, len);
					}
				}
			}
			cout << maxNum << endl;
			if (Q == 0) cout << "-\n";
		}

	}
}
