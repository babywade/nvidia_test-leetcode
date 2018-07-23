#include "stdafx.h"
#include "maxPrices.h"
#include <algorithm>

using namespace std;
//121.����һ��
int maxProfit01(vector<int>& prices)
{
	if (prices.size() < 2) {
		return 0;
	}
	int maxprofit = prices[prices.size() - 1] - prices[prices.size() - 2];
	int maxprices = prices[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; i--) {
		//�������н���˳�򲢲�Ӱ��������ȷ�ԣ�
		maxprices = max(maxprices, prices[i]);
		maxprofit = max(maxprofit, maxprices - prices[i]);
	}
	return max(maxprofit, 0);
}
//122.���޽��״���
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
//123.ֻ�ܽ�������
int maxProfit03(vector<int>& prices)
{

	return 0;
}
