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

	int n; cin >> n;
	vector<string> vec(n);
	loop(i, n) {
		cin >> vec[i];
	}

	vector<vi> dp(n, vi(n, 0));
	dp[0][0] = vec[0][0] == '.';
	
	forl(i, 0, n - 1) {
		forl(j, 0, n - 1) {
			int option1 = 0;
			int option2 = 0;

			if (vec[i][j] != '*') {

				if (i > 0) (dp[i][j] += dp[i - 1][j]) %= oo;
				if (j > 0) (dp[i][j] += dp[i][j - 1]) %= oo;

			}
		}
	}

	cout << dp[n - 1][n - 1] << endl;

}
