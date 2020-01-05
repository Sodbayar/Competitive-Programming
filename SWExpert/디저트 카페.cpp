//TLE if you use set<int> s instead of int deserts[]
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

int n;
int arr[22][22];

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, -1, 1};
pii strt;
int ans = -oo;
int deserts[111];

void solve(int x, int y, int s[], int dir, int rnd, int cnt) {
	//cout << x << "    " << y << endl;
	if (rnd == 4){
		if (x == strt.first && y == strt.second) {
			ans = max(ans, cnt);
			return;
		}
	}
	if (rnd > 4) return;

	for (int i = dir; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;

		if (s[arr[xx][yy]]) continue;

		s[arr[xx][yy]] = 1;
		solve(xx, yy, s, i, dir == i ? rnd : rnd + 1, cnt + 1);
		s[arr[xx][yy]] = 0;
	}

}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	memset(deserts, 0, sizeof deserts);
	int tt; cin >> tt;
	forl(t, 1, tt) {
		cin >> n;
		ans = -oo;
		loop(i, n) loop(j, n) cin >> arr[i][j];
		set<int> ss;
		for (int i = 0; i < n - 2; i++) {
			for (int j = 1; j < n - 1; j++) {
				strt = {i, j};
				solve(i, j, deserts, -1, 0, 0);
			}
		}
		cout << '#' << t << ' ';
		ans == -oo ? cout << "-1" : cout << ans;
		cout << endl;

	}
}
