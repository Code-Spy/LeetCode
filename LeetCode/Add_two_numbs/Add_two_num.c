/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* result = (struct ListNode *)malloc(sizeof(struct ListNode));
	result->val = 0;
	result->next = NULL;
	struct ListNode* p = result;
	int flag = 0;
	while (l1 || l2 || flag) {
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + flag;
		flag = sum / 10;
		p->val = sum % 10;
		l1 = (l1 ? l1->next:l1);
		l2 = (l2 ? l2->next:l2);
		p->next = (l1 || l2 || flag) ? (struct ListNode *)malloc(sizeof(struct ListNode)) : NULL;
		p = p->next;
	}
	return result;
}