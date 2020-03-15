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
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
typedef long long ll;
using namespace std;


int main() {
	int n; cin >> n;
	vector<pii> vec;
	loop(i, n) {
		int a, d; cin >> a >> d;
		vec.pb({a, d});
	}
	sort(vec.begin(), vec.end());

	ll time = 0;
	ll reward = 0;

	for (auto& u : vec) {
		reward += u.second - (u.first + time);
		time += u.first;
	}
	cout << reward;


}
