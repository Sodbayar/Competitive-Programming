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
#define oo (int)1e9 + 7
#define ii pair<int, int>
#define forl(i, k, p) for (int i = k; i <= p; i++)
#define loop(i, p) for (int i = 0; i < p; i++)
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&bingo)
#define sffl(a,b)       scanf("%lld %lld",&a,&bingo)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&bingo,&c)
using namespace std;

vector<ll> vec;
int n, k;

bool check(ll mid) {

	ll sum = 0;
	ll cnt = 0;

	loop(i, n) {
		if (vec[i] > mid) return false;
		sum += vec[i];

		if (sum > mid) {
			cnt++;
			sum = vec[i];
		}
		if (cnt > k) return false;

	}
	cnt++;

	return cnt <= k;
}

int main() {


	cin >> n >> k;
	vec.resize(n);

	ll top = 0;
	ll btm = 0;
	loop(i, n) {
		cin >> vec[i];
		top += vec[i];
	}

	ll ans = 0;

	while (btm <= top) {
		ll mid = (btm + top) / 2;
		if (check(mid)) {
			top = mid - 1;
			ans = mid;
		}
		else {
			btm = mid + 1;
		}
	}

	cout << ans << endl;


}