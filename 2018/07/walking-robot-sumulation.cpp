#include <iostream>
#include <vector>
#include <stack>

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
            for (unsigned long i = 0; i < commands.size(); ++i) {
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
                            if (isHit(pos, obstacles)) {
                                pos[0]++;
                                break;
                            }
                        }
                        break;
                    case UP:
                        while (commands[i]--) {
                            pos[1]++;
                            if (isHit(pos, obstacles)) {
                                pos[1]--;
                                break;
                            }
                        }
                        break;
                    case RIGHT:
                        while (commands[i]--) {
                            pos[0]++;
                            if (isHit(pos, obstacles)) {
                                pos[0]--;
                                break;
                            }
                        }
                        break;
                    case DOWN:
                        while (commands[i]--) {
                            pos[1]--;
                            if (isHit(pos, obstacles)) {
                                pos[1]++;
                                break;
                            }
                        }
                        break;
                }
            }

            return pos[0] * pos[0] + pos[1] * pos[1];
        }

        bool isHit(vector<int>& commands, vector<vector<int>>& obstacles) {
            for (unsigned long i = 0; i < obstacles.size(); ++i) {
                if (commands[0] == obstacles[i][0] && commands[1] == obstacles[i][1]) return true;
            }
            return false;
        }

};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector<int> l1, l2;
    l1.push_back(-2);
    l1.push_back(4);
    l1.push_back(-1);
    l1.push_back(3);
    vector<vector<int>>  l3;
    l2.push_back(-2);
    l2.push_back(0);
    l3.push_back(l2);
    int i = s->robotSim(l1,l3);
    cout<<i<<endl;
    return i;
}
