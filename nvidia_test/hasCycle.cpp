#include "stdafx.h"
#include "hasCycle.h"

bool hasCycle(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return false;
	}
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != nullptr && fast->next != nullptr && fast != slow) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return fast == slow ? true : false;
}