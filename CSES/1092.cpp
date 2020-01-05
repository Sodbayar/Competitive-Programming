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
	ll n; cin >> n;
	ll sum = (n * (n + 1)) / 2;
	if (sum % 2 == 0) {
		cout << "YES\n";


		vector<ll> v;

		sum /= 2;
		ll i = n;
		ll e = 0;
		//cout << "SUM : " << sum << endl;
		while (true) {
			v.pb(i);
			sum -= i--;

			if (!sum) break;

			if (sum <= i) {
				v.pb(sum);
				e = sum;
				break;
			}

		}
		cout << v.size() << endl;
		for (auto& u : v) {
			cout << u << ' ';
		}
		cout << endl << n - v.size() << endl;
		forl(iter, 1, i) {
			if (iter == e) continue;
			cout << iter << ' ';
		}


	}
	else {
		cout << "NO\n";
	}

}
