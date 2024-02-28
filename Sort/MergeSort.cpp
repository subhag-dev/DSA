#define ll long long

/*
    TC - O(NLogN) avg case, O(NLogN) Worse case
*/

class Solution {
public:

    void merge(int left, int mid, int right, vector<int> &nums) {
        int l = left, r = mid+1, curr = 0;
        vector<int> tmp(right - left + 1);

        while (l <= mid && r <= right) {
            tmp[curr++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        }

        while (l <= mid) {
            tmp[curr++] = nums[l++];
        }

        while (r <= right) {
            tmp[curr++] = nums[r++];
        }

        for (int i=left; i<=right; ++i) {
            nums[i] = tmp[i-left];
        }
    }

    int merge_sort(int start, int end, vector<int> &nums) {
        if (start >= end) return 0;
        int mid = start + (end - start) / 2;
        int j = mid+1;
        int ans = merge_sort(start, mid, nums) + merge_sort(mid+1, end, nums);
        for (int i=start; i<=mid; ++i) {
            while(j <= end && nums[i] > 2LL * nums[j])
                j++;
            ans += j-(mid+1);
        }
        merge(start, mid, end, nums);
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(0, n-1, nums);
    }
};