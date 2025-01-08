#include <stdio.h>
#include <string.h>
#define THEORY 1
#define LAB 2
#define TUTORIAL 3
struct course { 
	char name[32];
	char course_id[16];
	int credits; 
	int type; 
	char category[16];
};
typedef struct course course;
int sumcredits(course a[], int i) {
	int sum = 0, j = 0;
	while (j < i) {
		sum = sum + a[j].credits;
		j++;
	}
	return sum;
}
int sumlab(course a[], int i) {
	int j = 0, sum = 0;
	while (j < i) {
		if (a[j].type == 2) {
			sum = sum + a[j].credits;
		}	
		j++;
	}
	return sum;
}
void final (course a[], int i) {
	int j, sum = 0;
	for (j = 0; j < i; j++) {
		if (strcmp(a[j].category, "PCC") == 0) {
			sum = sum + a[j].credits;
		}	
	}
	printf("PCC %d\n", sum);
	sum = 0;
	for (j = 0; j < i; j++) {
		if (strcmp(a[j].category, "HSSC") == 0) {
			sum = sum + a[j].credits;
		}	
	}
	printf("HSSC %d\n", sum);
	sum = 0;
	for (j = 0; j < i; j++) {
		if (strcmp(a[j].category, "LC") == 0) {
			sum = sum + a[j].credits;
		}	
	}
	printf("LC %d\n", sum);
	sum = 0;
	for (j = 0; j < i; j++) {
		if (strcmp(a[j].category, "LLC") == 0) {
			sum = sum + a[j].credits;
		}	
	}
	printf("LLC %d\n", sum);
	sum = 0;
	for (j = 0; j < i; j++) {
		if (strcmp(a[j].category, "OE") == 0) {
			sum = sum + a[j].credits;
		}	
	}
	printf("OE %d\n", sum);
	sum = 0;
	for (j = 0; j < i; j++) {
		if (strcmp(a[j].category, "DE") == 0) {
			sum = sum + a[j].credits;
		}	
	}
	printf("DE %d\n", sum);			
}						
int main() {
	struct course a[32];
	int i = 0, x, y;
	while (scanf("%s %s %d %d %s", a[i].name, a[i].course_id, &a[i].credits, &a[i].type, a[i].category) == 5) {
		i++;
	}
	x = sumcredits(a, i);
	printf("%d\n", x);
	y = sumlab(a, i);
	printf("%d\n", y);
	final(a, i);
	return 0;
}		
