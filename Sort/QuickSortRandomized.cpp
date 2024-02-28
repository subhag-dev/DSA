
/*
    TC - O(NLogN) avg case, O(N**2) Worse case
*/

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

void quickSort(vector<int> &nums, int low, int high) {
	if (low >= high) return;
    int pivotIdx = rand() % (high - low + 1) + low;
	int pivot = partitionArray(nums, low, high);
	quickSort(nums, low, pivot);
	quickSort(nums, pivot + 1, high);
}