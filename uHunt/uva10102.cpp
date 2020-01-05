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
	int n;
	while (cin >> n) {
		vector<pii> ones, threes;

		loop(i, n) {
			string str; cin >> str;

			for (int j = 0; j < str.size(); j++) {
				if (str[j] == '1') ones.pb({ i, j });
				else if (str[j] == '3') threes.pb({ i, j });
			}
		}

		int minn = oo;
		int maxx = -oo;

		for (auto one : ones) {
			minn = oo;
			for (auto three : threes) {
				minn = min(minn, abs(one.first - three.first) + abs(one.second - three.second));
			}
			maxx = max(maxx, minn);
		}
		cout << maxx << endl;
	}

}
