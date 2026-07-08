class Solution {
    vector<int> generateRow(int rowIndex){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);
        for(int colIndex = 0; colIndex < rowIndex; colIndex++){
            ans = ans * (rowIndex - colIndex);
            ans = ans / (colIndex + 1);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};