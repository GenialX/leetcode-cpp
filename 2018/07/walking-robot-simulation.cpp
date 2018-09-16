/**
 * https://leetcode.com/problems/walking-robot-simulation/description/
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
class Solution {
    public:
        int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
            int direction = 2;
            vector<int> pos;
            pos.push_back(0);
            pos.push_back(0);
            const int LEFT  = 1;
            const int UP    = 2;
            const int RIGHT = 3;
            const int DOWN  = 4;
            map<int, set<int>> m;
            map<int, set<int>>::iterator it;
            int a = 0;

            for (int i = 0; i < obstacles.size(); ++i) {
                if (m.find(obstacles[i][0]) != m.end()) {
                    set<int> s = m.find(obstacles[i][0])->second;
                    s.insert(obstacles[i][1]);
                    m[obstacles[i][0]] = s;
                    set<int> tmp_s = m.find(0)->second;
                } else {
                    set<int> s;
                    s.insert(obstacles[i][1]);
                    m.insert(pair<int, set<int>>(obstacles[i][0], s));
                }
            }

            for (int i = 0; i < commands.size(); ++i) {
                if (commands[i] == -2) {
                    direction = (direction - 1) > 0 ? direction - 1: 4;
                    continue;
                }
                if (commands[i] == -1) {
                    direction = (direction + 1) > 4 ? 1 : direction + 1;
                    continue;
                }
                switch (direction) {
                    case LEFT:
                        while (commands[i]--) {
                            pos[0]--;
                            it = m.find(pos[0]);
                            if (it != m.end() && (it->second).find(pos[1]) != (it->second).end()) {
                                pos[0]++;
                                break;
                            }
                        }
                        break;
                    case UP:
                        while (commands[i]--) {
                            pos[1]++;
                            it = m.find(pos[0]);
                            if (it != m.end() && (it->second).find(pos[1]) != (it->second).end()) {
                                pos[1]--;
                                break;
                            }
                        }
                        break;
                    case RIGHT:
                        while (commands[i]--) {
                            pos[0]++;
                            it = m.find(pos[0]);
                            if (it != m.end() && (it->second).find(pos[1]) != (it->second).end()) {
                                pos[0]--;
                                break;
                            }
                        }
                        break;
                    case DOWN:
                        while (commands[i]--) {
                            pos[1]--;
                            it = m.find(pos[0]);
                            if (it != m.end() && (it->second).find(pos[1]) != (it->second).end()) {
                                pos[1]++;
                                break;
                            }
                        }
                        break;
                }
                if (a < pos[0] * pos[0] + pos[1] * pos[1]) a = pos[0] * pos[0] + pos[1] * pos[1];
            }

            return a;
        }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    int a1[] = {7,-2,-2,7,5};
    int a2[10][2] = {{-3,2},{-2,1},{0,1},{-2,4},{-1,0},{-2,-3},{0,-3},{4,4},{-3,3},{2,2}};
    vector< vector<int> > v2;
    vector<int> v1 (a1, a1 + sizeof(a1) / sizeof(int) );
    for (int i = 0; i < 10; ++i) {
        vector<int> tv;
        for (int j = 0; j < 2; ++j) {
            tv.push_back(a2[i][j]);
        }
        v2.push_back(tv);
    }
    int a = s->robotSim(v1, v2);
    cout<<a<<endl;
}
