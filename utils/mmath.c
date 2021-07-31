int mabs(int n)
{
    if( n>0 )
        return n;
    else return n*(-1);
}


int findGCD(int a,int b)
{
    a = mabs(a);  b=mabs(b);
     while(a!=b)
     {
          if(a>b)
              return findGCD(a-b,b);
          else
             return findGCD(a,b-a);
     }
     return a;
}


int mlcm(int a, int b)
{
    return ( mabs(a*b) / findGCD(a,b) );
}


int fibo(int n)
{
    if( n==0 )
        return 0;
    else if( n==1 )
        return 1;
    else
    return ( fibo(n-1) + fibo(n-2) );
}