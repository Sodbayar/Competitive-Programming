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
int d, l;
int BS(int pos, int num) {

	if (pos >= (1 << (d - 1))) return pos;

	if (num % 2 == 0) {
		return BS((pos << 1) + 1, num / 2);
	}
	return BS(pos << 1, num / 2 + 1);
}

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int tt; cin >> tt;
	while (tt--) {
		cin >> d >> l;
		l %= (1 << (d - 1));
		if (!l) l = (1 << (d - 1));

		cout << BS(1, l) << endl;
	}
	cin.ignore();

}
