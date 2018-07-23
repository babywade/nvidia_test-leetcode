#include "stdafx.h"
#include "maxPrices.h"
#include <algorithm>

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

	return 0;
}
