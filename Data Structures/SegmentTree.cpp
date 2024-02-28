class SegmentTree {
    public:
        SegmentTree(vector<int> vals) {
            n = vals.size();
            nums = vals;
            tree.resize(4 * n, 0);
            build(0, 0, n-1);
        }

        int query(int left, int right) {
            return query(0, 0, n-1, left, right);
        }

        void update(int idx, int newVal) {
            update(0, 0, n-1, idx, newVal);
        }

    private:
        vector<int> nums;
        vector<int> tree;
        int n;

        void build(int node, int start, int end) {
            if (start == end) {
                tree[node] = nums[start];
                return;
            }
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }

        int query(int node, int start, int end, int left, int right) {
            if (start > right || end < left) {
                return 0;
            }

            if (left <= start && end <= right) {
                return tree[node];
            }

            int mid = (start + end) / 2;
            int leftSum = query(2 * node + 1, start, mid, left, right);
            int rightSum = query(2 * node + 2, mid + 1, end, left, right);

            return leftSum + rightSum;        
        }

        void update(int node, int start, int end, int idx, int newVal) {
            if (start == end) {
                tree[node] = newVal;
                return;
            }

            int mid = (start + end) / 2;

            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, newVal);
            } else {
                update(2 * node + 2, mid + 1, end, idx, newVal);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }

};