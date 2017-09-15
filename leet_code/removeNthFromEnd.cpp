#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* pPre = head;
    	ListNode* pNext = head;
    	int i = 0;
    	for (; i < n && pNext; ++i) {
    		pNext = pNext->next;
    	}

    	if (!pNext) {
    		if (i == n) {
    			return head->next;
    		}
    	 	return head;
    	}

    	bool flag = false;
    	while (pNext) {
    		pNext = pNext->next;
    		if (!flag) {
    			flag = true;
    			continue;
    		}
    		pPre = pPre->next;
    	}

    	if (pPre->next) {
    		pPre->next = pPre->next->next;
    	}

    	return head;
    }

    ListNode* create_list(int n) {
    	ListNode *pNext = NULL;
    	ListNode *pHead = NULL;

    	for (int i = 1; i <= n; ++i) {
    		ListNode *pNode = new ListNode(i);
    		if (pHead == NULL) {
    			pHead = pNode;
    			pNext = pNode;
    		}
    		else {
    			pNext->next = pNode;
    			pNext = pNext->next;
    		}
    	}
    	return pHead;
    }

    void do_test() {
    	ListNode *pHead = create_list(2);
    	pHead = removeNthFromEnd(pHead, 2);
    	while(pHead) {
    		cout << pHead->val << "->";
    		pHead = pHead->next;
    	}
    	cout << endl;
    }
};

int main(void) 
{
	Solution *solution = new Solution();
	solution->do_test();
	delete solution;
}