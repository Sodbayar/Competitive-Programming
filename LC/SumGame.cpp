#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
//https://leetcode.com/contest/biweekly-contest-56/

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int nearestExit(vector<vector<char> >& maze, vector<int>& entrance) {
    int ans = 0;
    queue<pair<pair<int, int>, int> > bfs;
    int n = maze.size();
    int m = maze[0].size();
    pair<pair<int, int>, int> p{{entrance[0], entrance[1]}, 0};
    vector<vector<bool> > vis(n, vector<bool>(m, 0));
    vis[entrance[0]][entrance[1]] = 1;

    bfs.push(p);
    
    while (!bfs.empty()) {
        ans++;
        int x = bfs.front().first.first;
        int y = bfs.front().first.second;
        int cnt = bfs.front().second;
        bfs.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy] == '+' || vis[xx][yy]) {
                continue;
            }

            if (xx == 0 || yy == 0 || xx == n - 1 || yy == m - 1) {
                return cnt + 1;
            }
            pair<pair<int, int>, int> newNode{{xx, yy}, cnt + 1};
            vis[xx][yy] = 1;
            bfs.push(newNode);

         }

    }


    return -1;
}

bool sumGame(string num) {
    int n = num.length();
    int diff = 0;
    int count = 0; //counting the questions marks one side, because 2 ? on 2 sides cancel each other

    for (int i = 0; i < n; i++) {
        if (num[i] == '?') {
            count += i < n / 2 ? 1 : -1;
        }    
        else {
            if (i < n / 2) diff += num[i] - '0';
            else diff -= num[i] - '0';
        }
    }
    if (count % 2) return true;

    if (diff == -9 * (count / 2)) { //Alice tentsuulehguin tuld 9g ch yumu tavila gehed Bob ni 0-g tavina. Tgher neg talda bga 2 asuultin temdeg ni niileed 9 tei tentsuu(that's why count/2)
                                    //Tegher uldegdel buyu diff ni uldsen count/2 * 9 tei ued l Bob yalna
        return false;
    }
    return true;
}

int main() {

}