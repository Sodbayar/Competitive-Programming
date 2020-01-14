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

int n, x;
vi vec;

int main() {
	cin >> n >> x;
	loop(i, n) {
		int in; cin >> in;
		vec.pb(in);
	}
	sort(vec.begin(), vec.end());

	int i = 0, j = vec.size() - 1;
	int ans = 0;

	while (i <= j) {
		if (x - vec[j] < vec[i]) j--;
		else {
			i++, j--;
		}
		ans++;
	}
	cout << ans;



}
