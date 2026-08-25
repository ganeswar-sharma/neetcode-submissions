class Solution {
public:

    bool canEat(long long int rate, vector<int>& arr, int h){
        int noOfH = 0;
        for(int i =0;i<arr.size();i++){
            noOfH = noOfH + ceil((double)arr[i]/rate);
        }
        if(noOfH > h){
            return false;
        }
        return true;
    }


    int minEatingSpeed(vector<int>& arr, int h) {
        int maxRate = INT_MIN;
        int minRate = 1;
        int n = arr.size();
        for(int i =0;i<n;i++){
            maxRate = max(maxRate, arr[i]);
        }
        int ans = 1;
        while(minRate <= maxRate){
            long long int mid = (minRate + maxRate)/2;
            if(canEat(mid,arr,h)){
                ans = mid;
                maxRate = mid -1;
            }
            else{
                minRate = mid + 1;
            }
        }
        return ans;
    }
};
