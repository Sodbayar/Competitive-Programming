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

	vi vec(n);

	loop(i, n) {
		cin >> vec[i];
	}

	ll cursum = 0;
	int cnt = 0;
	unordered_map<int, int> prevSum;

	loop(i, n) {

		cursum += vec[i];

		if (cursum == x) cnt++;

		if (prevSum.find(cursum - x) != prevSum.end()) {
			cnt += prevSum[cursum - x];
		}

		prevSum[cursum]++;
	}
	cout << cnt << endl;
}
