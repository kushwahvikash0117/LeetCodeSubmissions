class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<long long> prev(target+1, 0), cur(target+1, 0);

        for(int T = 0; T <= target; T++){
            if(T % coins[0] == 0) prev[T] = T / coins[0];
            else prev[T] = 1e9;
        }

        for(int ind = 0; ind < n; ind++){
            for(int T = 0; T <= target; T++){
                long long notTake = 0 + prev[T];
                long long take = INT_MAX;
                if(coins[ind] <= T){
                    take = 1 + cur[T - coins[ind]];
                }
                cur[T] = min(take, notTake);
            }
            prev = cur;
        }

        long long ans = prev[target];
        if(ans >= 1e9) return -1;
        return ans;
    }
};