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



ll factorial(int n) {
	ll ret = 1;
	forl(i, 2, n) ret *= i;
	return ret;
}

void solve(ll n, string str) {

	if (str.size() == 1) {
		cout << str[0] << endl;
		return;
	}

	ll fac = factorial(str.size() - 1);
	int pos = n / fac;
	cout << str[pos];
	str.erase(str.begin() + pos);

	n -= pos * fac;

	solve(n, str);

}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int tt; cin >> tt;
	while (tt--) {
		string str; ll n;
		cin >> str >> n;
		sort(str.begin(), str.end());
		solve(n, str);


	}
}
