class Solution {
public:
    bool isPalindrome(int x) {
        int reverse_num = 0;
        int real_num = x;
        while(x>0){
            int n=x%10;
            if (reverse_num > INT_MAX/10 || 
                reverse_num < INT_MIN/10)
                return 0;
            reverse_num=(reverse_num*10)+n;
            x=x/10;
        }
        if(real_num == reverse_num){
            return true;
        }else{
            return false;
        }
    }
};