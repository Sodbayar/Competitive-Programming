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

int n, m;
int r, c, l;
int arr[55][55];
bool grid[55][55];
vector<vector<pii>> dir;

void pre() {

	vector<pii> trash;
	dir.pb(trash);

	trash.clear();
	trash.push_back({ 1, 0 });
	trash.push_back({ -1, 0 });
	trash.push_back({ 0, 1 });
	trash.push_back({ 0, -1 });
	dir.pb(trash);

	trash.clear();
	trash.push_back({ 1, 0 });
	trash.push_back({ -1, 0 });
	dir.push_back(trash);

	trash.clear();
	trash.push_back({ 0, 1 });
	trash.push_back({ 0, -1 });
	dir.pb(trash);


	trash.clear();
	trash.push_back({ -1, 0 });
	trash.push_back({ 0, 1 });
	dir.pb(trash);


	trash.clear();
	trash.push_back({ 1, 0 });
	trash.push_back({ 0, 1 });
	dir.pb(trash);


	trash.clear();
	trash.push_back({ 1, 0 });
	trash.push_back({ 0, -1 });
	dir.pb(trash);


	trash.clear();
	trash.push_back({ -1, 0 });
	trash.push_back({ 0, -1 });
	dir.pb(trash);

}

vector<pii> hole;

int solve() {

	while (l--) {
		int sz = hole.size();
		while (sz--) {
			pii p = *hole.begin();
			hole.erase(hole.begin());

			grid[p.first][p.second] = 1;

			if (l && arr[p.first][p.second] > 0) {
				for (int i = 0; i < dir[arr[p.first][p.second]].size(); i++) {
					int x = p.first + dir[arr[p.first][p.second]][i].first;
					int y = p.second + dir[arr[p.first][p.second]][i].second;
					if (x < 0 || y < 0 || x >= n || y >= m || !arr[x][y] || grid[x][y]) continue;
					bool flag = 0;
					pii negative = { -1 * dir[arr[p.first][p.second]][i].first, -1 * dir[arr[p.first][p.second]][i].second};
					for (int j = 0; j < dir[arr[x][y]].size(); j++) {
						if (negative == dir[arr[x][y]][j]) {
							flag = 1;
							break;
						}
					}
					if (flag) {
						hole.push_back({ x, y });
					}

				}
			}
		}
	}
	int cnt = 0;
	loop(i, n) loop(j, m) if (grid[i][j]) cnt++;
	return cnt;
}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	pre();
	int tt; cin >> tt;
	forl(t, 1, tt) {
		hole.clear();
		memset(grid, 0, sizeof grid);

		cin >> n >> m >> r >> c >> l;
		loop(i, n) loop(j, m) cin >> arr[i][j];
		hole.pb({r, c});
		cout << '#' << t << ' ' << solve() << endl;



	}
}
