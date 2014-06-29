#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
#define M 200010  
#define oo 10000000000LL  
  
int ans,n;  
long long a[M];  
long long cha=oo;  
  
int main()  
{  
    int i,j,first,second;  
    scanf("%d",&n);  
    for(i=1,first=second=0;i<=n;i++)  
    {  
        scanf("%lld",&a[i]);  
        if(a[i]!=-1)  
        {  
            if(second)  
            {  
                if(!first) first=i;  
            }  
            else second=i;  
        }  
    }  
    if(!first)  
    {  
        puts("1");  
        return 0;  
    }  
    if( (a[first]-a[second])%(first-second) || a[first]-(a[first]-a[second])/(first-second)*(first-1)<=0 )  
    {  
        ans=2;  
        cha=oo;  
    }  
    else  
    {  
        ans=1;  
        cha=(a[first]-a[second])/(first-second);  
    }  
    for(j=first-1;j>=1;j--) a[j]=0;  
    for(i=first+1;i<=n;i++)  
    {  
        if(a[i]!=-1)  
        {  
            if((a[i]-a[first])%(i-first))  
            {  
                ans++;  
                if(cha!=oo)  
                {  
                    for(j=first+1;j<=n;j++)  
                    {  
                        if(a[j]!=-1||a[j-1]+cha<=0) break;  
                        a[j]=a[j-1]+cha;  
                    }  
                }  
                else  
                {  
                    for(j=i-1;j>=first;j--) a[j]=0;  
                }  
                first=i;  
                cha=oo;  
            }  
            else  
            {  
                if(cha==oo)  
                {  
                    cha=(a[i]-a[first])/(i-first);  
                    for(j=first-1;j>=1;j--)  
                    {  
                        if(a[j]!=-1||a[j+1]-cha<=0) break;  
                        a[j]=a[j+1]-cha;  
                    }  
                    if(a[j]==-1)  
                    {  
                        ans++;  
                        cha=oo;  
                        for(j=i-1;j>=first;j--) a[j]=0;  
                    }  
                    else  
                    {  
                        for(j=i+1;j<=n;j++)  
                        {  
                            if(a[j]!=-1||a[j-1]+cha<=0) break;  
                            a[j]=a[j-1]+cha;  
                        }  
                    }  
                    first=i;  
                }  
                else  
                {  
                    if(cha==(a[i]-a[first])/(i-first))  
                    {  
                        for(j=first+1;j<i;j++) a[j]=0;  
                        first=i;  
                    }  
                    else  
                    {  
                        ans++;  
                        for(j=first+1;j<i;j++)  
                        {  
                            if(a[j]!=-1||a[j-1]+cha<=0) break;  
                            a[j]=a[j-1]+cha;  
                        }  
                        first=i;  
                        cha=oo;  
                    }  
                }  
            }  
        }  
    }  
    if(cha<0)  
    {  
        for(j=first+1;j<=n;j++)  
        {  
            if(a[j-1]+cha<=0)  
            {  
                ans++;  
                break;  
            }  
            a[j]=a[j-1]+cha;  
        }  
    }  
    printf("%d\n",ans);  
    return 0;  
}  
