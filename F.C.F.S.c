#include<conio.h>
#include<stdio.h>
struct pr{
	int pi,ex,at,ta,w;
}*t;
int wait(int);
int turn(int);
void main()
{
	int n,i,tex,*g,j,f;
	printf("enter number of processes...");
	scanf("%d",&n);
	t=(struct pr *)calloc(n,sizeof(struct pr));
	for(i=0;i<n;i++){
		printf("enter pi,ex,at for %d process...\n",i+1);
		scanf("%d %d %d",&t[i].pi,&t[i].ex,&t[i].at);
		t[i].w=wait(i);
		t[i].ta=turn(i);
	}
	printf("\nTable..\npi\tex\tat\tta\tw\n--------------------------------------\n");
	for(i=0;i<n;i++)
		printf("%d\t%d\t%d\t%d\t%d\n",t[i].pi,t[i].ex,t[i].at,t[i].ta,t[i].w);
	tex=t[n-1].ta+t[n-1].at;
	printf("\n\nGraph..\npi\t");
	for(i=0;i<=tex;i++)
		printf("%0.2d ",i);
	printf("\n");
	for(i=0;i<n;i++)
	{
		f=0;
		printf("%d\t",i+1);
		for(j=0;j<=tex;j++)
		{
			if(t[i].at==j)
				printf("|  ");
			else if(j<t[i].ta+t[i].at&&j>t[i].w+t[i].at)
				printf("-  ");
			else if(j==t[i].ta+t[i].at)
				printf("|  ");
			else
				printf("   ");	
		}
		printf("\n");
	}
}
int wait(int a)
{
	int s;
	if(a==0)
		return 0;
	s=t[a-1].ta+t[a-1].at-t[a].at;
	if(s<0)
		return 0;
	return s;
}
int turn(int a)
{
	return t[a].w+t[a].ex;
}
