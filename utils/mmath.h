int findGCD(int a,int b)
{
     while(a!=b)
     {
          if(a>b)
              return findGCD(a-b,b);
          else
             return findGCD(a,b-a);
     }
     return a;
}