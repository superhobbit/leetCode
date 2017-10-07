Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int maxV = 0;
    int low = prices[0];
    int count = 0;
    for (int i = 1; i < prices.size(); ++i){
        if (prices[i] > prices[i-1]){
            maxV = max(maxV,prices[i]-low);
            if (i == prices.size()-1) count+= maxV;
        }else {
            if (maxV) count+= maxV;
            low = prices[i];
            maxV = 0;
        }
    }
    if (!count) return maxV;
    return count;
}
