#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,**b,i,j,nz1=0,nz2=0;
	int r1,r2,c1,c2;
	printf("\nenter the no. of rows and columns of the first (r1,c1) and then the second matrix (r2,c2) :\n");
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	if(c1!=r2)
	{
		printf("not valid");
	}
	else
	{

        a=(int **)malloc(sizeof(int *)*r1);
        for(i=0;i<r1;i++)
        {
            a[i]=(int *)malloc(sizeof(int)*c1);
        }
        b=(int **)malloc(sizeof(int *)*r2);
        for(i=0;i<r2;i++)
        {
            b[i]=(int *)malloc(sizeof(int)*c2);
        }
        printf("\nenter the element of the first matrix:\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]!=0)
                {
                    nz1++;
                }
            }
        }
        printf("\nenter the element of the second matrix:\n");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                scanf("%d",&b[i][j]);
                if(b[i][j]!=0)
                {
                    nz2++;
                }
            }
        }
        printf("\nmatrix 1:\n");

        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
        printf("\nmatrix 2:\n");

        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d\t",b[i][j]);
            }
            printf("\n");
        }
        int sm1[nz1+1][3],sm2[nz2+1][3],**sm3,m=1;
        sm3=(int **)malloc(sizeof(int *)*(nz1+nz2+1));
        for(i=0;i<(nz1+nz2+1);i++)
        {
            *(sm3+i)=(int *)malloc(sizeof(int)*3);
        }
        sm1[0][0]=r1;
        sm1[0][1]=c1;
        sm1[0][2]=nz1;
        sm2[0][0]=r2;
        sm2[0][1]=c2;
        sm2[0][2]=nz2;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                if(a[i][j]!=0)
                {
                    sm1[m][0]=i;
                    sm1[m][1]=j;
                    sm1[m][2]=a[i][j];
                    m++;
                }
            }
        }
        m=1;
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                if(b[i][j]!=0)
                {
                    sm2[m][0]=i;
                    sm2[m][1]=j;
                    sm2[m][2]=b[i][j];
                    m++;
                }
            }
        }
        printf("\n the first sparse matrix:\n");
        for(i=0;i<nz1+1;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d\t",sm1[i][j]);
            }
            printf("\n");
        }
        printf("\n the second sparse matrix:\n");
        for(i=0;i<nz2+1;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("%d\t",sm2[i][j]);
            }
            printf("\n");
        }

        int k=1,x,s=0;
        for(i=1;i<=nz1;i++)
        {
            for(j=1;j<=nz2;j++)
            {
                if(sm1[i][1]==sm2[j][0])
                {
                    sm3[k][0]=sm1[i][0];
                    sm3[k][1]=sm2[j][1];
                    sm3[k][2]=sm1[i][2]*sm2[j][2];
                    k++;
                }
            }
        }
        sm3[0][0]=r1;
        sm3[0][1]=c2;
        sm3[0][2]=k-1;

        sm3=(int **)realloc(sm3,sizeof(int *)*k);
        for(i=1;i<k-1;i++)
        {
            s=sm3[i][2];
            for(j=i+1;j<k;j++)
            {
                if((sm3[i][0]==sm3[j][0]) && (sm3[i][1]==sm3[j][1]))
                {
                    s=s+sm3[j][2];
                    sm3[j][2]=0;
                }
            }
            sm3[i][2]=s;
            s=0;
        }
        printf("\nthe result:\n");
        for(i=0;i<k;i++)
        {
            for(j=0;j<3;j++)
            {
                if(sm3[i][2]!=0)
                {
                    printf("%d\t",sm3[i][j]);
                }
                else
                {
                    continue;
                }
            }
            printf("\n");
        }
    }

}