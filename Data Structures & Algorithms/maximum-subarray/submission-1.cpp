class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int maxSum = INT_MIN;
        bool allNegative = true;
        int maxElement = INT_MIN;
        for (int i=0;i<n;i++) {
            if (arr[i] >= 0){
                allNegative = false;
                break;
            }
            maxElement = max(maxElement, arr[i]);
        }   
        if(allNegative){
            return maxElement;
        }
        for(int i =0;i<n;i++){
            if(sum + arr[i] < 0){
                sum = 0;
                continue;
            }
            sum = sum + arr[i];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
