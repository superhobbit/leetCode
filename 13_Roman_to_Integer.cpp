Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.


答案again。。
int romanToInt(string s) {
    int sum = 0;
    if (s.find("IV") != -1) sum -= 2;
    if (s.find("IX") != -1) sum -= 2;
    if (s.find("XL") != -1) sum -= 20;
    if (s.find("XC") != -1) sum -= 20;
    if (s.find("CD") != -1) sum -= 200;
    if (s.find("CM") != -1) sum -= 200;
    for (int i = 0; i < s.size(); ++i){
        if (s.at(i) == 'I') sum += 1;
        if (s.at(i) == 'V') sum += 5;
        if (s.at(i) == 'X') sum += 10;
        if (s.at(i) == 'L') sum += 50;
        if (s.at(i) == 'C') sum += 100;
        if (s.at(i) == 'D') sum += 500;
        if (s.at(i) == 'M') sum += 1000;
    }

    return sum;
}
