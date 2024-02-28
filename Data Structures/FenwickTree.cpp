class FenwickTree {
    public:
        vector<int> bit;
        int size;

        FenwickTree(int n) {
            bit.resize(n+1, 0);
            size = n;
        }

        void update(int idx, int delta) {
            idx++;
            while (idx <= size) {
                bit[idx] += delta;
                idx += idx & (-idx);
            }
        }

        int query(int idx) {
            idx++;
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
};