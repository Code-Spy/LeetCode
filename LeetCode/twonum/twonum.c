typedef struct HashNode {
	int key;
	int val;
} HashNode;

typedef struct HashMap {
	int size;
	HashNode** storage;
} HashMap;

HashMap* hash_create(int size);
void hash_destroy(HashMap* hashMap);
void hash_set(HashMap* hashMap, int key, int value);
HashNode* hash_get(HashMap* hashMap, int key);

HashMap* hash_create(int size) {
	HashMap* hashMap = (HashMap*) malloc(sizeof(HashMap));
	hashMap->size = size;
	hashMap->storage = (HashNode**)calloc(size, sizeof(HashNode*));
	return hashMap;
}

void hash_destroy(HashMap* hashMap) {
	for (int i = 0; i < hashMap->size; i++) {
		HashNode *node;
		if ((node = hashMap->storage[i])) {
			free(node);
		}
	}
	free(hashMap->storage);
	free(hashMap);
}

void hash_set(HashMap *hashMap, int key, int value) {
	int hash = abs(key) % hashMap->size;
	HashNode* node;
	while ((node = hashMap->storage[hash])) {
		if (hash < hashMap->size - 1) {
			hash++;
		}
		else {
			hash = 0;
		}
	}
	node = (HashNode *) malloc(sizeof(HashNode));
	node->key = key;
	node->val = value;
	hashMap->storage[hash] = node;
}

HashNode* hash_get(HashMap *hashMap, int key) {
	int hash = abs(key) % hashMap->size;
	HashNode* node;
	while ((node = hashMap->storage[hash])) {
		if (node->key == key) {
			return node;
		}

		if (hash < hashMap->size - 1) {
			hash++;
		}
		else {
			hash = 0;
		}
	}

	return NULL;
}

int* twoSum(int* nums, int numsSize, int target) {
	HashMap* hashMap;
	HashNode* node;
	int rest, i;

	// make the hashMap 2x size of the numsSize
	hashMap = hash_create(numsSize * 2);
	for (i = 0; i < numsSize; i++) {
		rest = target - nums[i];
		node = hash_get(hashMap, rest);
		if (node) {
			int* result =(int *) malloc(sizeof(int) * 2);
			result[0] = node->val + 1;
			result[1] = i + 1;
			hash_destroy(hashMap);
			return result;
		}
		else {
			hash_set(hashMap, nums[i], i);
		}
	}
}


int* twoSum(int* nums, int numsSize, int target) {
	int* array = (int *)malloc( sizeof(int) * 2);
	for (int i = 0; i < numsSize; i++)
		for (int j = i + 1; j < numsSize; j++)
		{
			if (nums[i] == target - nums[j])
			{
				array[0] = i;
				array[1] = j;
			}
		}
	return array;
    
}