Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.


int reverse(int x) {
    int result = 0;
    while(x){
        int tail = x%10;

        if (((result*10+tail)-tail)/10 != result) return 0;
        result = result*10 + tail;
        x /= 10;
    }
    return result;
}
