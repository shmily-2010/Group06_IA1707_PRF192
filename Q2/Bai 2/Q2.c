#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct balo{
	char name[100];
	int weight,value;
	float quantity;
	int choice;
};
int main(){
	int n,m,i,j;
	FILE *f=fopen("BAG.txt","r");
	FILE *fo=fopen("BAGOUT.txt","w");
	fscanf(f,"%d%d",&n,&m);
	struct balo sp[n];
	for(i=0;i<n;i++){
		fscanf(f,"%d",&sp[i].weight);
		fscanf(f,"%d",&sp[i].value);
		fscanf(f,"%s",&sp[i].name);
		sp[i].quantity=(float)sp[i].value/sp[i].weight;
	}struct balo sp1[n];
	for(i=0;i<n;i++){
		sp1[i]=sp[i];
	}for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(sp[i].quantity<sp[j].quantity){
				struct balo temp=sp[i];
				sp[i]=sp[j];
				sp[j]=temp;
			}
		}
	}int res=0;
	for(i=0;i<n;i++){
		sp[i].choice=m/sp[i].weight;
		m-=sp[i].choice*sp[i].weight;
		res+=sp[i].choice*sp[i].value;
		if(m==0) break;
	}for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(strcmp(sp1[i].name,sp[j].name)==0){
				sp1[i].choice=sp[j].choice;
			}
		}
	}fprintf(fo,"%d\n",res);
	for(i=0;i<n;i++){
		if(sp1[i].choice)
		fprintf(fo,"%s %d\n",sp1[i].name,sp1[i].choice);
	}fclose(f);
	fclose(fo);
}
