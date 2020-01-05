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

int n, k;
int grid[10][10];
int tmp[10][10];
bool travelled[10][10];
vector<pii> vec;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int ans = -oo;


void solve(int x, int y, int k, int count) {
	ans = max(ans, count);


	travelled[x][y] = 1;
	loop(i, 4) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx < 0 || yy < 0 || xx >= n || yy >= n || travelled[xx][yy]) continue;

		if (grid[xx][yy] < grid[x][y]) solve(xx, yy, k, count + 1);
		else {
			if (grid[xx][yy] - k < grid[x][y]) {
				int ctr = grid[xx][yy];
				int tmpK = k;
				while (tmpK-- && grid[xx][yy] >= grid[x][y]) {
					grid[xx][yy]--;
				}
				solve(xx, yy, 0, count + 1);
				grid[xx][yy] = ctr;
			}
		}


	}
	travelled[x][y] = 0;


}


int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	int tt; cin >> tt;
	forl(t, 1, tt) {
		ans = -oo;
		vec.clear();
		memset(travelled, 0, sizeof travelled);
		cin >> n >> k;

		int maxx = -oo;
		loop(i, n) {
			loop(j, n) {
				cin >> grid[i][j];
				maxx = max(maxx, grid[i][j]);
			}
		}
		loop(i, n) {
			loop(j, n) {
				tmp[i][j] = grid[i][j];
				if (grid[i][j] == maxx) vec.pb({i, j});
			}
		}

		for (auto u : vec) {
			solve(u.first, u.second, k, 1);
		}
		cout << "#" << t << ' ' << ans << endl;


	}
}
