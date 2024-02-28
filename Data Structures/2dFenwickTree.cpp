class FenwickTree {
    public:
        vector<vector<int> > bit;
        int r, c;

        FenwickTree(int m, int n) {
            r = m;
            c = n;
            bit.resize(r + 1, vector<int>(c + 1, 0));
        }

        void update(int x, int y, int delta) {
            x++;
            while (x <= r) {
                int yIdx = y + 1;
                while (yIdx <= c) {
                    bit[x][yIdx] += delta;
                    yIdx += yIdx & (-yIdx);
                }
                x += x & (-x);
            }
        }

        int query(int x1, int y1) {
            x1++;
            int sum = 0;
            while (x1 > 0) {
                int yIdx = y1 + 1;
                while (yIdx > 0) {
                    sum += bit[x1][yIdx];
                    yIdx -= yIdx & (-yIdx);
                }
                x1 -= x1 & (-x1);
            }
            return sum;
        }
};