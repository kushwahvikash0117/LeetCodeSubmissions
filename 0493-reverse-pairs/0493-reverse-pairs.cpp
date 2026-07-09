class Solution {
    void merge(vector<int>& arr, int left, 
                     int mid, int right){
                         
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    int countPairs(vector<int> &arr, int left, int mid, int right){
        int high = mid + 1;
        int cnt = 0;
        for(int i = left; i <= mid; i++){
            while(high <= right && (long long)arr[i] > (long long)2 * arr[high]) high++;
            cnt += (high - (mid+1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& arr, int left, int right){
        int cnt = 0;
        if (left >= right)
            return cnt;

        int mid = left + (right - left) / 2;
        cnt += mergeSort(arr, left, mid);
        cnt += mergeSort(arr, mid + 1, right);
        cnt += countPairs(arr, left, mid, right);
        merge(arr, left, mid, right);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};