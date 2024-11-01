// 3rd maximum 
// Credit by Bhavesh 

#include <stdio.h>

int main()
{
    int a,b,c,d,e,temp,tem;
   
    d=scanf("%d%d%d",&a,&b,&c);
    if(d<3)
    {
        printf("not found");
        goto end;
    }
    
    int i,j,k;
    if(a>=b && a>=c)
    {
        i=a;
        if(b>=c)
        {
            j=b;
            k=c;
        }
        else
        {j=c;
        k=b;}
    }

    if(b>=a && b>=c)
    {
        i=b;
        if(a>=c)
        {
            j=a;
            k=c;
        }
        else
        {
            j=c;
            k=a;
        }
        
    }
    
    if(c>=a && c>=b)
    {
        i=c;
        if(b>=a)
        {
            j=b;
            k=a;
        }
        else
        {
            j=a;
            k=b;
        }
    }
    
    while(scanf("%d",&e)!=-1)
    {
        if(e>i)
        {
            temp=i;
            i=e;
            tem=j;
            j=temp;
            k=tem;
        }
        else if(e<=i && e>=j)
        {
            temp=j;
            j=e;
            k=temp;
        }
        else if(e>=k && e<=j )
        {
            k=e;
        }
        
    }
printf("%d",k);
end:
    return 0;
}
