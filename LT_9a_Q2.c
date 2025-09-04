#include <stdio.h>
#include <string.h>

char* strmaxstr(char *a, char *b) {
	char *max_s = NULL;
	int max_l = 0;
	
	int len_b = strlen(b);
	
	for(int i = 0; i < len_b; i++) {
		for(int j = i; j < len_b; j++) {
			char temp[j-i+2];
			strncpy(temp, b+i, j-i+1);
			temp[j-i+1] = '\0';
			char *fnd = strstr(a, temp);
			if(fnd && (j-i+1) > max_l) {
				max_l = j-i+1;
				max_s = fnd;
			}
		}
	}
	return max_s;
}

int main() {
	char a[] = "abcee abcdm bdefg";
	char b[] = "abcdf";
	
	char *res = strmaxstr(a, b);
	printf("%s", res);
	
	return 0;
}
