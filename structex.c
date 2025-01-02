#include <stdio.h>
#include <string.h>

struct course {
	char name[32];
	char course_id[16];
	int credits;
	int type;
	char cat[16];
};

int main(void)
{
	struct course courses[100];
	int cnt = 0;
	while (scanf("%31s %15s %d %d %15s",
			courses[cnt].name,
			courses[cnt].course_id,
			&courses[cnt].credits,
			&courses[cnt].type,
			courses[cnt].cat) == 5) {
		cnt++;
		if (cnt >= 100) {
			printf("Maximum number of courses.\n");
			break;
		}
	}
	int total_credits = 0, lab_credits = 0, theory_credits[6] = {0};
	char *categories[] = {"PCC", "HSSC", "LC", "LLC", "OE", "DE"};
	for (int i = 0; i < cnt; i++) {
		total_credits += courses[i].credits;
		if (courses[i].type == 2) {
			lab_credits += courses[i].credits;
		}
		else if (courses[i].type == 2) {
			lab_credits += courses[i].credits;
		}
		if (courses[i].type == 1) {
			for (int j = 0; j < 6; j++) {
				if (strcmp(courses[i].cat, categories[j]) == 0) {
					theory_credits[j] += courses[i].credits;
					break;
				}
			}
		}
	}
	printf("%d\n", total_credits);
	printf("%d\n", lab_credits);
	for (int i = 0; i < 6; i++) {
		printf("%s %d\n", categories[i], theory_credits[i]);
	}
	return 0;
}