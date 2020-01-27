// Time Complexity: O(n)
// Space Complexity: O(n)
struct P {
    int x;
    int y;
    P(int xx, int yy) : x(xx), y(yy) {};
    bool operator==(const P &other) const {
        return x == other.x && y == other.y;
    };
};

// see more at https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
struct KeyHasher {
    int operator()(const P& k) const {
        return (hash<int>()(k.x)) ^ (hash<int>()(k.y) << 10);
    };
};

class Solution {
public:
    double dis(vector<int> p1, vector<int> p2) {
        return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        int N = points.size();
        unordered_map<P, bool, KeyHasher> c;
        for (auto p : points) {
            c[P(p[0], p[1])] = true;
        }
        double area = INT_MAX;

        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    int x = points[i][0] + points[j][0] - points[i][0] + points[k][0] - points[i][0];
                    int y = points[i][1] + points[j][1] - points[i][1] + points[k][1] - points[i][1];
                    P p = P(x, y);
                    if (c.find(p) != c.end()) {
                        int product = (points[k][1] - points[i][1]) * (points[j][1] - points[i][1]) + (points[k][0] - points[i][0]) * (points[j][0] - points[i][0]);
                        if (product == 0) {
                            double d1 = dis(points[i], points[j]);
                            double d2 = dis(points[i], points[k]);
                            area = min(area, d1 * d2);
                        }
                    }
                }
            }
        }

        return area == INT_MAX ? 0 : area;
    }
};
