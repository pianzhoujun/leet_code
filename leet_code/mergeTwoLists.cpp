#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if (!l1) {
    		return l2;
    	}

    	if (!l2) {
    		return l1;
    	}

        ListNode *pNode;
       	if (l1->val <= l2->val) {
       		pNode = l1;
       		l1 = l1->next;
       	}
       	else {
       		pNode = l2;
       		l2 = l2->next;
       	}
       	ListNode *pHead = pNode;

       	// TODO  ---->  special 
       	while (l1 && l2) {
       		if (l1->val <= l2->val) {
       			pNode->next = l1;
       			l1 = l1->next;
       		}
       		else {
       			pNode->next = l2;
       			l2 = l2->next;
       		}
       		pNode = pNode->next;
       	}
       	pNode->next = l1 ? l1: l2;
       	return pHead;
    }

    ListNode* create_list(vector<int> data) {
    	ListNode *pNext = NULL;
    	ListNode *pHead = NULL;

    	for (int i = 0; i < data.size(); ++i) {
    		ListNode *pNode = new ListNode(data[i]);
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
    	int data_1[] = {1};
    	int data_2[] = {2, 4, 6, 6, 8, 10};

    	vector<int> vec_1(data_1, data_1 + sizeof(data_1)/sizeof(data_1[0]));
    	vector<int> vec_2(data_2, data_2 + sizeof(data_2)/sizeof(data_2[0]));

    	ListNode *pHead_1 = create_list(vec_1);
    	ListNode *pHead_2 = create_list(vec_2);

    	ListNode* pHead = mergeTwoLists(pHead_1, pHead_2);
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