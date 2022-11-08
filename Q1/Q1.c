#include<stdio.h>

int main()
{	int k,n;
	double a=1,b=1,c=1,result;
	FILE* f = fopen ("TO HOP.INP", "ab");
    int i;
    scanf ("%d %d",&n,&k);
    fscanf(f,"%d %d",&n,&k);
    fprintf (f,"%d %d\n",n,k);
	for(i=1;i<=n;i++) a=a*i;
	for(i=1;i<=k;i++) b=b*i;
	for(i=1;i<=n-k;i++)  c=c*i;
	result=a/(b*c);
	FILE* fp1 = fopen("TO HOP.OUT","ab");
	printf("%0.f\n",result);
    fprintf(fp1,"\n%0.f\n",result);
    fclose(f);
    fclose(fp1);
}

