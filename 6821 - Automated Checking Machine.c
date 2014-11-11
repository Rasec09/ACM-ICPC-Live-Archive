#include <stdio.h>

int main()
{
	int i, a[5], b[5];

	while(scanf("%d", &a[0]) != EOF)
	{
		for(i = 1; i < 5; i++)
			scanf("%d", &a[i]);
		
		for(i = 0; i < 5; i++)
			scanf("%d", &b[i]);
	
		for(i = 0; i < 5; i++){
			if(a[i] == b[i]){
				printf("N\n");
				break;
			}
		}
		if(i == 5)	
			printf("Y\n");
	}
	return 0;
}
