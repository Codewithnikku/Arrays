/*
 * Problem Statement: Best Time to Buy and Sell Stock (one transaction).
 * Algorithm: One-pass Min-Price tracking
 * Pseudocode:
 * 1. Initialize minPrice to infinity and maxProfit to 0.
 * 2. Traverse the prices array:
 *    a. If current price is less than minPrice, update minPrice.
 *    b. Else if current price minus minPrice is greater than maxProfit, update maxProfit.
 * 3. Return maxProfit.
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class StockBuySell{
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i=0; i<prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};

int main(){
    StockBuySell sbs;
    vector<int> prices = {7,1,5,3,6,4};
    cout << sbs.maxProfit(prices) << endl;
    return 0;
}