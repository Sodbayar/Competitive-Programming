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
	int n, x; cin >> n >> x;
	vector<pii> vec;

	loop(i, n) {
		int in; cin >> in;
		vec.pb({ in, i });
	}

	sort(vec.begin(), vec.end());

	int i = 0, j = n - 1;

	while (i < j) {
		int sum = vec[i].first + vec[j].first;
		if (x == sum) {
			cout << vec[i].second + 1 << ' ' << vec[j].second + 1 << endl;
			return 0;
		}
		if (sum > x) {
			j--;
		}
		else i++;
	}
	cout << "IMPOSSIBLE\n";


}
