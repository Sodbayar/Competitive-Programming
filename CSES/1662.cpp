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


int main() {

	int n; cin >> n;

	vi v(n);
	vector<ll> remainders(n);

	ll currsum = 0;
	loop(i, n) {
		cin >> v[i];
		currsum += v[i];
		remainders[((currsum % n) + n) % n]++;
	}


	ll cnt = 0;
	loop(i, n) {
		cnt += (remainders[i] * (remainders[i] - 1)) / 2;
	}
	cnt += remainders[0];
	cout << cnt << endl;

}