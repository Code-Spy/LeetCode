/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	struct ListNode* result = (ListNode *)malloc(sizeof(struct ListNode));
	result->val = 0;
	result->next = NULL;
	struct ListNode* p = result;
	int flag = 0;
	while (l1 || l2) {
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + flag;
		flag = sum / 10;
		p->val = sum % 10;
		p->next = (ListNode *)malloc(sizeof(struct ListNode));
		p = p->next;
		l1 = (l1 ? l1->next:l1);
		l2 = (l2 ? l2->next:l2);
	}
	return result;
}