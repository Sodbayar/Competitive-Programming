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



int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int tt; cin >> tt;

	forl(t, 1, tt) {
		int n; cin >> n;
		int coin[1001];
		loop(i, n) cin >> coin[i];
		int sum = coin[0], ans = 1;

		forl(i, 1, n - 2) {
			if (sum + coin[i] < coin[i + 1]) {
				ans++;
				sum += coin[i];
			}
		}
		cout << ans + 1 << endl;
	}
}
