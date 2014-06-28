#include <stdio.h>

typedef struct
{
	int m,n,y;
	int addr;
}stack;

int akm(int m,int n)
{
	int y,top=0;
	stack s[40000];
	s[top].m=m;
	s[top].n=n;
	s[top].addr=4;
	top++;
p0:
	if(s[top-1].m==0)
    {
		s[top-1].y=s[top-1].n+1;
		if (s[top-1].addr==1) goto p1;
		if (s[top-1].addr==2) goto p2;
		if (s[top-1].addr==3) goto p3;
		if (s[top-1].addr==4) goto p4;
     }
	else 
	{
		if(s[top-1].n==0)
		{
			s[top].m=s[top-1].m-1;
			s[top].n=1;
			s[top].addr=1;
			top++;
			goto p0;
		}
		else
		{
			s[top].m=s[top-1].m;
			s[top].n=s[top-1].n-1;
			s[top].addr=2; 
			top++;
			goto p0;
		}
p1: 
		top--;
		s[top-1].y=s[top].y;
		if (s[top-1].addr==1) goto p1;
		if (s[top-1].addr==2) goto p2;
		if (s[top-1].addr==3) goto p3;
		if (s[top-1].addr==4) goto p4;
p2: 
		top--;
		s[top-1].y=s[top].y;
		s[top].m=s[top-1].m-1;
		s[top].n=s[top-1].y;
		s[top].addr=3;
		top++;
		goto p0;
p3: 
		top--;
		s[top-1].y=s[top].y;
		if (s[top-1].addr==1) goto p1;
		if (s[top-1].addr==2) goto p2;
		if (s[top-1].addr==3) goto p3;
		if (s[top-1].addr==4) goto p4;
p4: 
		y=s[top-1].y;
		top--;
		return y;
	}
}

int akm1(int m,int n)
{
	int y;
  
	if(m==0) y=n+1;
  
	else if (n==0)y=akm1(m-1,1);
       
	else
	{
		y=akm1(m,n-1);
		y=akm1(m-1,y);
	}
	
	return y;
}

int main()
{
	int m,n,y;
	scanf("%d %d",&m,&n);
	y=akm(m,n);
	printf("y=%d",y);
	return 0;
}