#include "stdafx.h"
#include "maxPrices.h"
#include <algorithm>
#include <limits>

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
//localProfit[i][j]��ʾǰi��������j�ν��ף������һ���������ڵ�i����ɵ��������
//globalProfit[i][j]��ʾǰi��������j�ν�������õ��������
//С����k���ǶԵģ����ǵ�k = 10��ʱ��1��2���г�ʼ��vectorʱ���ڴ�������׳�bad_alloc exception��
int maxProfit04(int k, vector<int>& prices)
{
	int n = prices.size();
	if (k == 0 || n == 0) {
		return 0;
	}
	//���k�㹻���ʱ�򣬵ȼ��ڿ��Է������޴ν��ף�
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
