#include<stdio.h>
#include<stdlib.h>
int** triplet(int, int); //input plus triplet generation
int** trans_sort(int**,int);//transpose and then sort the rows
int** triplet(int m,int n)
{
	int i,count=0,j,k=1;
	int** p=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
		 p[i]=(int*)malloc(n*sizeof(int)); //matrix
    printf("\nEnter the element: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("\n%d",&p[i][j]);
			if(p[i][j]!=0)
			{
				count++;
			}
		}
		
	}
	printf("count = %d",count);
	int** trip=(int**)malloc((count+1)*sizeof(int*));
	for(i=0;i<count+1;i++)
		trip[i]=(int*)malloc(3*sizeof(int));
	trip[0][0]=m;trip[0][1]=n;trip[0][3]=count;
			
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			
			if(p[i][j]!=0)
			{
				trip[k][0]=i;
				trip[k][1]=j;
				trip[k][2]=p[i][j];
				k++;
			}
		}
	}
	return trip;
}
int** transort(int** trip,int count)
{
	printf("In trans\n");
	int temp,i,j;
	for(i=0;i<count;i++)
	{
		temp=trip[i][0];
		trip[i][0]=trip[i][1];
		trip[i][1]=temp;
	}
	
	printf("Transpose done\n");
	
	for(i=1;i<count-1;i++)
	{
		for(j=1;j<count-i-1;j++)
		{
			if(trip[j][0]>trip[j+1][0])
			{
				temp=trip[j][0];
				trip[j][0]=trip[j+1][0];
				trip[j+1][0]=temp;
				temp=trip[j][1];
				trip[j][1]=trip[j+1][1];
				trip[j+1][1]=temp;
				temp=trip[j][2];
				trip[j][2]=trip[j+1][2];
				trip[j+1][2]=temp;
			}
		}
	}
	printf("sorting done\n");
	return trip;
}
int main(void)
{
	int n1,m1,n2,m2,i,j,k=1,x,col,row;
	printf("Enter order of first matrix:\n");
	scanf("%d%d",&n1,&m1);
	printf("Enter order of second matrix:\n");
	scanf("%d%d",&m2,&n2);
	printf("\nFor Matrix 1\n");
	int** a=triplet(n1,m1);
	printf("\nFor Matrix 2\n");
	int** b1=triplet(n2,m2);
	int** b=transort(b1,b1[0][2]+1);
	int t1=a[0][2], t2=b[0][2];
	int** c=(int**)malloc((t1+t2)*sizeof(int*));
	for(i=0;i<(t1+t2);i++)
		c[i]=(int*)malloc(3*sizeof(int));
	printf("initialized\n");
	c[0][0]=a[0][0];
	printf("initialied\n");
	c[0][1]=b[0][0];
	printf("initialied\n");
	c[0][2]=0;
	printf("initialied\n");
	for(i=1;i<=t1;i++)
	{
		col=a[i][1]; printf("here\n");
		for(j=1;j<=t2;j++)
		{
			if(col==b[j][1])
			{
				c[k][0]=a[i][0];
				c[k][1]=b[j][0];
				c[k][2]=a[i][2]*b[j][2];k++;
			}
		}
	}
	printf("mul\n");
	for(i=1;i<k;i++)
	{
		col=c[i][1];row=c[i][0];
		for(j=i+1;j<=k;j++)
		{
			if(c[j][0]==row && c[j][1]==col)
			{
					c[i][2]=c[i][2]+c[j][2];
				for(x=j;x<k;x++)
				{
					c[x][0]=c[x+1][0];
					c[x][1]=c[x+1][1];
					c[x][2]=c[x+1][2];
				}
				k=k-1;
			}
		}
	}
	c[0][2]=k-1;
return 0;
}