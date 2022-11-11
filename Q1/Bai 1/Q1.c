#include<stdio.h>

int main()
{	int k,n;
	double a=1,b=1,c=1,result;
	FILE* f = fopen ("TOHOP.INP", "ab");
    int i;
    printf("Nhap n: ");
    scanf ("%d",&n);
    printf("Nhap k: ");
    scanf ("%d",&k);
    fscanf(f,"%d %d",&n,&k);
    fprintf (f,"%d %d\n",n,k);
    if(n<=k){
    	printf("ERROR Please re-enter\n");
	}
	for(i=1;i<=n;i++) a=a*i;
	for(i=1;i<=k;i++) b=b*i;
	for(i=1;i<=n-k;i++)  c=c*i;
	result=a/(b*c);
	FILE* fp1 = fopen("TOHOP.OUT","ab");
	printf("%0.f\n",result);
    fprintf(fp1,"\n%0.f\n",result);
    fclose(f);
    fclose(fp1);
    return 0;
}

