
/*
    TC - O(N) avg case, O(N**2) Worse case
*/


class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pivot_index = rand() % (right - left + 1) + left;
            int new_pivot_index = partition(nums, left, right, pivot_index);
            if (new_pivot_index == nums.size() - k) {
                return nums[new_pivot_index];
            } else if (new_pivot_index > nums.size() - k) {
                right = new_pivot_index - 1;
            } else {
                left = new_pivot_index + 1;
            }
        }
    }

private:

    void shuffle(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        for (int i = hi; i >= 0; --i) {
            int randomIdx = rand() % (i - lo + 1);
            swap(nums[i], nums[randomIdx]);
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivot_index) {
        int pivot = nums[pivot_index];
        swap(nums[pivot_index], nums[right]);
        int stored_index = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[stored_index]);
                stored_index++;
            }
        }
        swap(nums[right], nums[stored_index]);
        return stored_index;
    }
};