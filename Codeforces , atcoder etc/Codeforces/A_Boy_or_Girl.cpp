
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() 
{
    string username;
    cin >> username;
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    a=b=c=d=e=f=g=h=i=j=k=l=m=n=o=p=q=r=s=t=u=v=w=x=y=z=0;
    char chars[username.length()];
    for (int ref=0; ref<username.length(); ref++)
    {
        chars[ref] = username[ref];
    }
    for (int ref2=0; ref2<username.length(); ref2++)
    {
        if (chars[ref2] == 'a')
        {
            a = 1;
        }
        else if (chars[ref2] == 'b')
        {
            b = 1;
        }
        else if (chars[ref2] == 'c')
        {
            c = 1;
        }
        else if (chars[ref2] == 'd')
        {
            d = 1;
        }
        else if (chars[ref2] == 'e')
        {
            e = 1;
        }
        else if (chars[ref2] == 'f')
        {
            f = 1;
        }
        else if (chars[ref2] == 'g')
        {
            g = 1;
        }
        else if (chars[ref2] == 'h')
        {
            h = 1;
        }
        else if (chars[ref2] == 'i')
        {
            i = 1;
        }
        else if (chars[ref2] == 'j')
        {
            j = 1;
        }
        else if (chars[ref2] == 'k')
        {
            k = 1;
        }
        else if (chars[ref2] == 'l')
        {
            l = 1;
        }
        else if (chars[ref2] == 'm')
        {
            m = 1;
        }
        else if (chars[ref2] == 'n')
        {
            n = 1;
        }
        else if (chars[ref2] == 'o')
        {
            o = 1;
        }
        else if (chars[ref2] == 'p')
        {
            p = 1;
        }
        else if (chars[ref2] == 'q')
        {
            q = 1;
        }
        else if (chars[ref2] == 'r')
        {
            r = 1;
        }
        else if (chars[ref2] == 's')
        {
            s = 1;
        }
        else if (chars[ref2] == 't')
        {
            t = 1;
        }
        else if (chars[ref2] == 'u')
        {
            u = 1;
        }
        else if (chars[ref2] == 'v')
        {
            v = 1;
        }
        else if (chars[ref2] == 'w')
        {
            w = 1;
        }
        else if (chars[ref2] == 'x')
        {
            x = 1;
        }
        else if (chars[ref2] == 'y')
        {
            y = 1;
        }
        else if (chars[ref2] == 'z')
        {
            z = 1;
        }    }
    int ref3 = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
    if(ref3 % 2 == 1)
    {
        cout << "IGNORE HIM!";
    }
    else
    {
        cout << "CHAT WITH HER!";
    }
}