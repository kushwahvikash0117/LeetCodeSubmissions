class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int xr = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                xr = xr ^ grid[i][j];
                xr = xr ^ (i*n + j + 1);
            }
        }
        int number = xr & (-xr);
        int zero = 0;
        int one = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // one club
                if((grid[i][j] & number) != 0){
                    one = one ^ grid[i][j];
                }
                // zeroth club
                else{
                    zero = zero ^ grid[i][j];
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int val = i*n + j + 1;
                // one club
                if((val & number) != 0){
                    one = one ^ val;
                }
                // zeroth club
                else{
                    zero = zero ^ val;
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == zero) cnt++;
            }
        }

        if(cnt == 2) return {zero, one};
        return {one, zero};
    }
};