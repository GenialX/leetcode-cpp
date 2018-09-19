#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
    public:
        vector< vector<int> > walk(int r0, int c0, int direction, int step, int R, int C) {
            vector< vector<int> > a;
            while (step--) {
                switch(direction) {
                    case 1:
                        c0++;
                        break;
                    case 2:
                        r0++;
                        break;
                    case 3:
                        c0--;
                        break;
                    case 4:
                        r0--;
                        break;
                    default:
                        break;
                }
                if (r0 <= R - 1 && c0 <= C - 1 && r0 >= 0 && c0 >= 0) {
                    vector<int> aa;
                    aa.push_back(r0);
                    aa.push_back(c0);
                    a.push_back(aa);
                }
            }
            vector<int> aa;
            aa.push_back(r0);
            aa.push_back(c0);
            a.push_back(aa); // cur pos at last index
            return a;
        }

        int changeD(int c_d) {
            switch(c_d) {
                case 1:
                    return 2;
                    break;
                case 2:
                    return 3;
                    break;
                case 3:
                    return 4;
                    break;
                case 4:
                    return 1;
                    break;
                default:
                    break;
            }
            return -1;
        }

        vector< vector<int> > spiralMatrixIII(int R, int C, int r0, int c0) {
            int i = 0, step = 1, direction = 1;
            vector< vector<int> > a, b;
            vector<int> aa;
            aa.push_back(r0);
            aa.push_back(c0);
            a.push_back(aa);
            while ((int)a.size() < R * C) {
                b = walk(r0, c0, direction, step, R, C); 
                for (int j = 0; j < (int)b.size(); j++) {
                    if (j < (int)b.size() - 1) a.push_back(b[j]); 
                    if (j == (int)b.size() - 1) {
                        r0 = b[j][0];
                        c0 = b[j][1];
                        break; 
                    } 
                }

                // do changes
                direction = changeD(direction);
                i++; 
                if (i % 2 == 0) step++;
            }
            return a;
        }
};

int main(int argc, char * argv[]) {
    Solution * s = new Solution();
    vector< vector<int> > c;
    c = s->spiralMatrixIII(1, 4, 0, 0);
    for (int i = 0; i < (int)c.size(); i++) {
        cout<<"i:"<<i<<" 0:"<<c[i][0]<<" 1:"<<c[i][1]<<endl;
    }
    return 0;
}
