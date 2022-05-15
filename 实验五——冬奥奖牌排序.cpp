#include<stdio.h>

struct Country
{
	char name[100];
	int goldNum;
	int silverNum;
	int bronzeNum;
	int totalNum;
};
typedef struct Country Country;

void printCountry(Country c)
{
	printf("%s\t%d\t%d\t%d\t%d\n",c.name,c.goldNum,c.silverNum,c.bronzeNum,c.totalNum);
}

void bubbleSort(Country a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j].goldNum<a[j+1].goldNum)
			{
				Country temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int main()
{
	Country c[8];
	FILE* fp=fopen("C:\\test.txt","r");
	if(fp==NULL)
	{
		printf("Error!\n");
		return 0;
	}
	for(int i=0;i<8;i++)
	{
		fscanf(fp,"%s %d %d %d %d",c[i].name,&c[i].goldNum,&c[i].silverNum,&c[i].bronzeNum,&c[i].totalNum);
	}
	fclose(fp);
	
	bubbleSort(c,8);
	
	FILE* outfp=fopen("C:/newnew.txt","w");
	for(int i=0;i<8;i++)
	{
		fprintf(fp,"%s\t%d\t%d\t%d\t%d\n",c[i].name,c[i].goldNum,c[i].silverNum,c[i].bronzeNum,c[i].totalNum);
	}
	fclose(outfp);
	
	
	return 0;
}

