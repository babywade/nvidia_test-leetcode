#include "stdafx.h"
#include "maxPrices.h"
#include <algorithm>
#include <limits>

using namespace std;
//121.交易一次
int maxProfit01(vector<int>& prices)
{
	if (prices.size() < 2) {
		return 0;
	}
	int maxprofit = prices[prices.size() - 1] - prices[prices.size() - 2];
	int maxprices = prices[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; i--) {
		//以下两行交换顺序并不影响结果的正确性；
		maxprices = max(maxprices, prices[i]);
		maxprofit = max(maxprofit, maxprices - prices[i]);
	}
	return max(maxprofit, 0);
}
//122.不限交易次数
int maxProfit02(vector<int>& prices)
{
	int res = 0;
	if (prices.size() <= 1) {
		return res;
	}
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] - prices[i - 1] >= 0) {
			res += prices[i] - prices[i - 1];
		}
	}
	return res;
}
//123.只能交易两次
int maxProfit03(vector<int>& prices)
{
	int buy1 = numeric_limits<int>::min();
	int buy2 = numeric_limits<int>::min();
	int sell1 = 0;
	int sell2 = 0;
	for (int i = 0; i < prices.size(); i++) {
		buy1 = max(buy1, -prices[i]);
		sell1 = max(sell1, buy1 + prices[i]);
		buy2 = max(buy2, sell1 - prices[i]);
		sell2 = max(sell2, buy2 + prices[i]);
	}
	return sell2;
}
//localProfit[i][j]表示前i天最多进行j次交易，且最后一次卖出是在第i天完成的最大利润
//globalProfit[i][j]表示前i天最多进行j次交易所获得的最大利润
//小用例k下是对的，但是当k = 10亿时，1、2两行初始化vector时会内存溢出，抛出bad_alloc exception；
int maxProfit04(int k, vector<int>& prices)
{
	int n = prices.size();
	if (k == 0 || n == 0) {
		return 0;
	}
	//如果k足够大的时候，等价于可以发生无限次交易；
	if (k >= n / 2) {
		int res = 0;
		for (int i = 1; i < n; i++) {
			if (prices[i] - prices[i - 1] > 0) {
				res += prices[i] - prices[i - 1];
			}
		}
		return res;
	}

	vector<vector<int>> localProfit(n, vector<int>(k + 1, 0)); //1
	vector<vector<int>> globalProfit(n, vector<int>(k + 1, 0)); //2
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i < n; i++) {
			localProfit[i][j] = max(localProfit[i - 1][j] + prices[i] - prices[i - 1],
				globalProfit[i - 1][j - 1] + max(0, prices[i] - prices[i - 1]));
			globalProfit[i][j] = max(localProfit[i][j], globalProfit[i - 1][j]);
		}
	}
	return globalProfit[n - 1][k];
}
