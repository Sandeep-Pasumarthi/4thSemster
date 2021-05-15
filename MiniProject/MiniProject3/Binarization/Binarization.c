/*Program to convert grayscale image to binary image using Otsu's algorithm.

theory referred from wikipedia.
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y) x>y?x:y
typedef long long int lli;

lli arr[256];											

int otsu(lli k)											
{														
	int i,thres=-1;
	long double w0=0,w1=0,u0=0,u1=0,u10;								
	long double temp=0.0,mx=0.0;										
	for(i=0;i<256;i++) 									
	{
		w1+=arr[i];
		u1+=(arr[i]*i);
	}
	u10=u1;
	for(i=0;i<256;i++)
	{
		w0+=arr[i];
		w1-=arr[i];
		u0+=(i*arr[i]);
		u1-=(i*arr[i]);
		if(w0!=0 && w0!=1)
		{
			long double x=(u0*w1-u1*w0);
			long double y=k*k*w0*w1;
			temp=(x*x)/y;			     
			if(temp>=mx) 						
			{
				mx=temp;
				thres=i;						
			}
		}
	}
	printf("\n%Ld\n",k);
	return thres;
}

int main(int argc,char *argv[])
{
	FILE *fp,*op;
	fp=fopen(argv[1],"r");
	op=fopen(argv[2],"wb");
	if(fp==NULL || op==NULL)
	{
		printf("The file could not be opened!!Aborting...");
		exit(0);
	}

	int i,j; 
	int width,height,max_value,*p,temp; 
	char c,magic[4];
	int thres;	

	for(i=0;i<256;i++) arr[i]=0;

	fgets(magic,3,fp);                    
	fscanf(fp,"\n");					 
	
	fscanf(fp,"%c",&c);
	if(c=='#')  while(c!='\n') c=fgetc(fp);			
	else fseek(fp,-1,SEEK_CUR);
	
	fscanf(fp,"\n%d %d",&width,&height); 
	fscanf(fp,"\n%d",&max_value); 		 
	
	p=(int*)malloc(height*width*sizeof(int));
	int w=0,h=0; 
	
	for(i=0;i<height;i++) 					
	{   
		for(j=0;j<width;j++)
		{
			fscanf(fp,"%d\n",&temp);
			*(p+i*width+j)=temp;
			arr[temp]++;
		}		
		if(feof(fp)) break;
	}

	thres=otsu(height*width);					
	max_value=1;								
	strcpy(magic,"P1");							
	fprintf(op,"%s\n",magic);
	fprintf(op,"%d %d\n",width,height);
	//fprintf(op,"%d\n",max_value);             

	for(i=0;i<height;i++)
	{   
		for(j=0;j<width;j++)
		{
			if(*(p+i*width+j)<=thres) temp=1;			
			else temp=0;								
			fprintf(op,"%d\n",temp);
		}		
	}

	printf("The threshold value calculated using otsu's technique is: %d\n",thres);
	fclose(fp); 
	fclose(op);
	return 0;
}	