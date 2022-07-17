#include <stdio.h>

void main()
{
	int run_range, reduce_fule;
	float km_fule;

	printf("Input Your run range : ");
	scanf("%d", &run_range);
	printf("Input Your reduce fule : ");
	scanf("%d", &reduce_fule);

	if (run_range <= 0 || reduce_fule <= 0)
		printf("Input Value is Error \n");
	else {
		km_fule = (float)reduce_fule / (float)run_range;
		printf("Your Car Range per Fule is : %5.3f \n", km_fule);
	}

}
