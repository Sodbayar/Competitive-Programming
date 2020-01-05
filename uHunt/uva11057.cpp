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
	int arr[10010];
	while (cin >> n) {
		loop(i, n) cin >> arr[i];

		sort(arr, arr + n);

		int m; cin >> m;
		cin.ignore();
		cin.ignore();
		int minn = oo;
		int idx1 = 0, idx2 = 0;
		loop(i, n) {
			int target = m - arr[i];
			int pos = upper_bound(arr, arr + n, target) - arr;
			pos--;
			//cout << target << "   " << pos << endl;
			if (pos > 0 && pos != i && pos != n && m == (arr[i] + arr[pos]) && abs(arr[i] - arr[pos]) < minn) {
				idx1 = i; idx2 = pos;
				minn = abs(arr[i] - arr[pos]);
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", arr[idx1], arr[idx2]);
	}
}
