Implement pow(x, n).

Note: N maybe negative!!!

double myPow(double x, int n) {
    double result = 1.0;
    int power = n;
    while(n != 0){
        if (n%2 == 1 || n%2 == -1) result *= x;
        x *= x;
        n /= 2;
    }
    if (power < 0) return 1/result;
    return result;
}
