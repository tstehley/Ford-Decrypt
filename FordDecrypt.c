#include <stdio.h>
#include <math.h>

int chunkify(char *instr,int start){
	int i;
	int bcounter =8;
	int cur;
	int outt;
	for (i=0;i<8;i++){
		bcounter -= 1;
		if (instr[i+start] == '\0'){
			return -1;
		}
		cur = instr[i+start] - '0';
		outt += cur << bcounter;
		//printf("%d\n",cur);
	}
	//printf("%d\n",outt);
	return outt;
}
int main (void){
	char dat[1024];
	FILE *fp;
	fp = fopen("gfbinaryRaw.txt","r");
	fscanf(fp,"%s",dat);
	fclose(fp);
	printf("%s\n",dat);
	int i =0;
	int numbo;
	while(1){
		numbo = chunkify(dat,i);
		if (numbo == -1){
			break;
		}
		printf("%d %x %c\n",numbo, numbo,numbo);
		i +=8;
	}
	return 0;
}
