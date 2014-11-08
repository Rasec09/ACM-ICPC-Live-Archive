#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 100002

struct partido
{
	int a, b;
} p[MAX];

bool operator<(struct partido i, struct partido j)
{
	if(i.a - i.b > j.a - j.b)
		return true;
	return false;
}

int main()
{
	int N, G, total = 0;

	while(scanf("%d %d", &N, &G) != EOF)
	{
		for(int i = 0; i < N; i++){
			scanf("%d %d", &p[i].a, &p[i].b);
		}	
		sort(p, p + N);
		for(int i = 0; i < N; i++){
			if(p[i].a > p[i].b){
				total += 3;
			}
			else if(p[i].a == p[i].b){
				total++;
				if(G > 0){
					G--;	
					total += 2;
				}
			}
			else if(p[i].b - p[i].a <= G){
				G -= p[i].b - p[i].a;
				total++;
				if(G > 0){
					G--;
					total += 2;
				}
			}
		}
		printf("%d\n", total);
		total = 0;
	}
	return 0;
}
