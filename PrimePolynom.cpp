/*Problem Statement
A prime number is an integer greater than 1 that has no positive divisors other than 1 and itself. The first prime numbers are 2, 3, 5, 7, 11, 13, 17, ...

It is known that no non-constant polynomial function P(n) exists that evaluates to a prime number for all integers n. But there are some famous quadratic polynomials that are
prime for all non-negative integers less than M (M depends on the polynomial).

You will be given s A, B and C. Your method should return the smallest non-negative integer M such that A*M2 + B*M + C is not a prime number.

Examples

1
-1
41
Returns: 41
This is one of the famous polynomials.

1
1
41
Returns: 40

1
1
-13
Returns: 0
No negative numbers are prime.

*/
#include <iostream>

using namespace std;

class PrimePolynom{
public:
    int isPrime(int number){
        if(number<2) return false;
        for(int j=2;j*j<=number;j++){
            if(number%j==0)
                return false;
        }
        return true;
    }
    int reveal(int A,int B,int C){
        for(int i=0;1;i++){
            if(!isPrime(A*i*i+B*i+C))
                return i;
        }
    }
};

int main()
{
    PrimePolynom prime;
    int A,B,C;
    cin>>A>>B>>C;
    cout<<prime.reveal(A,B,C)<<endl;
}
