#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
void type(int n) {
	switch(n) {
		case 0:
			printf(" A");
			break;
		case 10:
			printf(" J");
			break;
		case 11:
			printf(" Q");
			break;
		case 12:
			printf(" K");
			break;
		default:
			printf("%2d", 1+n);
	}
}
int main(int argc, char *argv[]) {
	int bobai=52, i, k, j, kmax;
	int labai[52], human[4][13];
	//bang danh dau cac la bai da duoc chia ra
	bool c[13][4]={false};
	//doi bo so rand moi lan thuc thi
	srand(time(0)); 
	//chia bai
	while(bobai!=0) {
		k=rand()%52;
		while(c[k/4][k%4]==true) {
			if (k==52) 
				k=0;
			else
				k++;
		}
		c[k/4][k%4]=true;
		labai[bobai]=k;
		bobai--;
	}
	//quan li la bai cua tung nguoi
	while(bobai!=52) {
		human[bobai%4][bobai/4]=labai[bobai];			
		bobai++;
	}
	//sap xep la bai
	for(i=0; i<4; i++) {
		for(k=0; k<13; k++) {
			kmax=k;
			for(j=k+1; j<13; j++) 
				if(human[i][j]<human[i][kmax])
					kmax=j;
			if(kmax!=k) {
				j = human[i][k];
				human[i][k]=human[i][kmax];
				human[i][kmax]=j;
			}
		}
	}
	//in ra man hinh cac la bai
	for(i=0; i<4; i++) {
		printf("Nguoi thu %d:\n", i+1);
		for(k=0; k<13; k++) {
			type(human[i][k]/4);
			switch(human[i][k]%4) {
				case 0:
					printf(" co  ;\t");
					break;
				case 1:
					printf(" ro  ;\t");
					break;
				case 2:
					printf(" tep ;\t");
					break;
				default:
					printf(" bich;\t");
					break;
			}
		}
		printf("\n");
	}
	//kiem tra tu quy
	printf("\nKiem tra tu quy:\n");
	for(i=0; i<4; i++) {
		j=0;
		for(k=0; k<13; k++) {
			if (human[i][k]%4==0 && (human[i][k+3]-human[i][k])==3) {
				printf("Nguoi thu %d co tu quy ", i+1);
				type(human[i][k]/4);
				printf("\n");
				j++;
			}	
		}
		if(j==0) 
			printf("Nguoi thu %d khong co tu quy\n", i+1);
	}
	return 0;
}
