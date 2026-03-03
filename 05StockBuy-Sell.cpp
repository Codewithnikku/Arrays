/*
 * Problem Statement: Best Time to Buy and Sell Stock (one transaction).
 * Algorithm: One-pass Min-Price tracking
 * Pseudocode:
 * 1. Initialize minPrice to infinity and maxProfit to 0.
 * 2. Traverse the prices array:
 *    a. If current price is less than minPrice, update minPrice.
 *    b. Else if current price minus minPrice is greater than maxProfit, update maxProfit.
 * 3. Return maxProfit.

 intuition:
    - We need to find the minimum price to buy the stock and the maximum profit to sell the stock.
    - We can traverse the array once and keep track of the minimum price seen so far and the maximum profit that can be achieved.

    Approach:
        - Initialize minPrice to infinity and maxProfit to 0.
        - Traverse the prices array:
            - If current price is less than minPrice, update minPrice.
            - Else if current price minus minPrice is greater than maxProfit, update maxProfit.
        - Return maxProfit.
        
    complexity:
        - Time: O(n)
        - Space: O(1)
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