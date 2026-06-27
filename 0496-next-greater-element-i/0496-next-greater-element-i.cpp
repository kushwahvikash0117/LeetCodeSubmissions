class Solution {
public:
    int nge(vector<int> &arr, int el){
        stack<int> st;
        for(int i=arr.size()-1; i>=0; i--){
            if(st.empty()){
                if(arr[i] == el) return -1;
                st.push(arr[i]);
            }
            else{
                if(arr[i] == el){
                    if(st.top() > el) return st.top();
                    while(!st.empty() && st.top() < el){
                        st.pop();
                    }
                    if(st.empty()) return -1;
                    return st.top();
                }
                st.push(arr[i]);
            }
        }
        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(nge(nums2, nums1[i]));
        }
        return ans;
    }
};