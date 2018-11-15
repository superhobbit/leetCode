#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <ctype.h>
#include <sstream>
#include <fstream>
#include <map>

class RangeModule {
public:
    map<int, int>maps;
    RangeModule() {

    }

    void addRange(int left, int right) {
        auto upper = maps.upper_bound(right);
        if(upper != maps.begin()) {
            --upper;
        }
        if(upper->second >= left) {
            right = max(upper->second, right);
            while(upper != maps.begin() && upper->second >= left) {
                left = min(upper->first, left);
                --upper;
            }
        }
        maps[left] = right;
    }

    bool queryRange(int left, int right) {
        auto upper = maps.upper_bound(right);
        if(upper != maps.begin()) {
            --upper;
            return upper->second >= right && upper->first <= left;
        } else {
            return false;
        }
    }

    void removeRange(int left, int right) {
        auto upper = maps.upper_bound(right);
        if(upper != maps.begin()) {
            --upper;
            auto move = upper;
            int new_left = min(move->first, left),
                new_right = max(upper->second, right);
            while(move != maps.begin() && move->second >= left) {
                new_left = min(left, move->first);
                move--;
            }
            maps.erase(move, ++upper);
            if(new_left != left)
                maps[new_left] = left;
            if(new_right != right)
                maps[right] = new_right;
        }
    }

    void printRange() {
        for(auto& a : maps)
            cout << a.first << " " << a.second << endl;
    }
};

int main(int argc, char const *argv[]) {
    RangeModule rm;
    rm.addRange(10,180);
    rm.addRange(150,200);
    rm.addRange(250,500);
    rm.printRange();
    return 0;
}
