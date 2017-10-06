Implement int sqrt(int x).

Compute and return the square root of x.

use long instead of int: if use int, cpu can't calculate int_max

int mySqrt(int x) {
    long result = x;
    while(result * result > x){
        result = (result + x/result)/2;
    }
    return result;
}
