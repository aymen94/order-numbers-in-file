#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20

void nomefile(char *nf)
{
	printf(" Name file: ");
	scanf("%s",nf);
	strcat(nf,".txt");
}

void containv(char *nf,int *n)
{
	FILE *FF;
	int c,count=1;
	FF=fopen(nf,"r");
	if(!FF){printf("Error: file not found"); return;}
	while(!feof(FF))
	{
		c=fgetc(FF);
		if(c=='\n')
		count++;
	}
	fclose(FF);
	*n=count;
}
void creav(char *nf,int n)
{
	int *vet;
	vet=malloc((n+1)*sizeof(int));
	FILE *FF;
	FF=fopen(nf,"r");
	int i=0,j,c;
	while(!feof(FF))
	{
		fscanf(FF,"%d",&vet[i]);
		i++;
	}
	fclose(FF);
	
	for(i=0;i<n;i++)
	printf("%d\n",vet[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		
		if(vet[i]>vet[j])
			{
				c=vet[i];
				vet[i]=vet[j];
				vet[j]=c;
			}
	}
		
	for(i=0;i<n;i++)
	printf(" After: %d\n",vet[i]);
	
	FF=fopen(nf,"w");
	i=0;
	while(i<n)
	{
		fprintf(FF,"%d \n",vet[i]);
		i++;
	}
	fclose(FF);
	free(vet);
}
int main()
{
	int n;
	char nf[N];
	nomefile(nf);
	containv(nf,&n);
	creav(nf,n);
}
