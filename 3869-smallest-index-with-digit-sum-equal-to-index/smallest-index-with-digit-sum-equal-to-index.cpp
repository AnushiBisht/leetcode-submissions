class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i == sumOfDigit(nums[i])){
                return i;
            }
        }
        return -1;
    }

    int sumOfDigit(int n){
        int sum = 0;
        while(n){
            int digit = n%10;
            sum+=digit;
            n=n/10;
        }
        return sum;
    }
};