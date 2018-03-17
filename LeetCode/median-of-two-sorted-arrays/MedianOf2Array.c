struct NumArray
{
	int num;
	struct NumArray * next;
};

// my low function;
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	struct NumArray * node = (struct NumArray *) malloc(sizeof(struct NumArray));
	struct NumArray * temp = node;
	int num1 = 0, num2 = 0;
	double answer = 0;
	//边界值处理
	if (nums1Size == 0 && nums2Size == 0) {
		free(node);
		return 0;
	}
	if (nums1Size == 0) {
		free(node);
		return  nums2Size % 2 == 0 ? ((double)nums2[nums2Size / 2 - 1] + (double)nums2[nums2Size / 2]) / 2 : (double)nums2[nums2Size / 2];
	}

	if (nums2Size == 0) {
		free(node);
		return  nums1Size % 2 == 0 ? ((double)nums1[nums1Size / 2 - 1] + (double)nums1[nums1Size / 2]) / 2 : (double)nums1[nums1Size / 2];
	}
	//边界值处理
	for (int i = 0; i < (nums1Size + nums2Size) / 2 + 1; i++) {
		temp->num = nums1[num1] < nums2[num2] ? nums1[num1] : nums2[num2];
		nums1[num1] < nums2[num2] ? num1++ : num2++;
		if (num1 >= nums1Size) {
			num1 = nums1Size - 1;
			nums1[num1] = INT_MAX;
		}
		if (num2 >= nums2Size) {
			num2 = nums2Size - 1;
			nums2[num2] = INT_MAX;
		}
		temp->next = (struct NumArray *) malloc(sizeof(struct NumArray));
		temp = temp->next;
		temp->next = NULL;
	}
	temp = node;
	if ((nums1Size + nums2Size) % 2 == 0) {
		for (int i = 0; i < (nums1Size + nums2Size) / 2 - 1; i++)
			temp = temp->next;
		answer = temp->num;
		temp = temp->next;
		answer = (answer + temp->num) / 2;
	}
	else {
		for (int i = 0; i < (nums1Size + nums2Size) / 2; i++)
			temp = temp->next;
		answer = temp->num;
	}
	while (node != NULL) {
		temp = node->next;
		free(node);
		node = temp;
	} //释放内存
	return answer;

}







//-----------------------------------------------------------------//
// the function of O(log(m+n))
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums2Size == 0 && nums1Size == 0) return 0;
	if (nums1Size > nums2Size)   return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
	int minidx = 0, maxidx = nums1Size, i, j, num1, mid = (nums1Size + nums2Size + 1) >> 1, num2;
	while (minidx <= maxidx)
	{
		i = (minidx + maxidx) >> 1;
		j = mid - i;
		if (i<nums1Size && j>0 && nums2[j - 1] > nums1[i]) minidx = i + 1;
		else if (i>0 && j<nums2Size && nums2[j] < nums1[i - 1]) maxidx = i - 1;
		else
		{
			if (i == 0) num1 = nums2[j - 1];
			else if (j == 0) num1 = nums1[i - 1];
			else num1 = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
			break;
		}
	}
	if (((nums1Size + nums2Size) & 1)) return num1;
	if (i == nums1Size) num2 = nums2[j];
	else if (j == nums2Size) num2 = nums1[i];
	else num2 = nums1[i]<nums2[j]? nums1[i]: nums2[j];
	return (num1 + num2) / 2.;

}









