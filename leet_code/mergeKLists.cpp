

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }

   
    ListNode* megetLists(ListNode* l1, ListNode* l2) {
    	if (!l1) {
    		return l2;
    	}

    	if (!l2) {
    		return l1;
    	}

    	ListNode* pNode;
    	ListNode* pHead;

    	if (l1->val <= l2->val) {
    		pNode = l1;
    		l1 = l1->next;
    	}
    	else {
    		pNode = l2;
    		l2 = l2->next;
    	}

    	pHead = pNode;

    	while (l1 && l2) {
    		if (l1->val <= l2) {
    			pNode->next = l1;
    			l1 = l1->next;
    		}
    		else {
    			pNode->next = l2;
    			l2 = l2->next;
    		}
    		pNode = pNode->next;
    	}
    	pNode->next = l1? l1: l2;
    	return pHead;
    }
};
