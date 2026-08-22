class Solution {
public:

    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
       bool ans = false;
       int l = 1;
       int r = num;
       while(l <= r){
        long long int mid = (l + r)/2;
        long long int square = mid * mid;
        if(square == num){
            ans = true;
            break;
        }
        else if(square < num){
            l = mid + 1;
        }
        else{
            r = mid -1;
        }
        } 
        return ans;
    }
};