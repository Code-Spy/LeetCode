int lengthOfLongestSubstring(char* s) {
	char *p = s;
	int start = 0, i = 0, temp, len = 0, len_1 = 0;
	int  map[128] = { 0 };
	while (*p != '\0') {
		if (map[*p] == 0) {				//	a new char 
			map[*p] = i + 1;				//	mark the char
		}
		else {
			//	a repeated char 	
			temp = map[*p];
			for (int j = start; j < temp; j++)		//mark off previous letters as never appeared
				map[s[j]] = 0;
			len = (i - start) > len ? (i - start) : len;					//	caculate the length 
			start = temp;						//	a new string begin
			map[*p] = i + 1;
		}
		p++;
		i++;
	}
	len = (i - start) > len ? (i - start) : len;
	return len;
}







// a master's code 
int lengthOfLongestSubstring(char* s)
{
	int len = 0;
	char *end = s, *temp;
	char* addressTable[128] = { NULL };
	while (*end) {
		temp = addressTable[*end];
		addressTable[*end] = end;		//mind addressTable['a'] = address of char 'a' 
		if (temp >= s) {				// if temp < s ,mean this char is not appear
			len = end - s>len ? end - s : len;		//	remmber everytime's len  
			s = temp + 1;				// sub the char 
		}end++;
	}
	len = end - s>len ? end - s : len;			// if not the same char ,caculate the len
	return len;
}