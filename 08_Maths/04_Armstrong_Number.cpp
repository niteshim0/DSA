bool armstrongNumber(int n) {
    int temp = n;
    long long num = 0;
    while(temp>0){
        int lastDigit = temp%10;
        num = num + lastDigit*lastDigit*lastDigit;
        temp/=10;
    }
    return num == n;
}
// Time Complexity : O(log10(N))
// Space Complexity : O(1)

