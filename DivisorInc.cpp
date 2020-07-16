/*Problem Statement
There is an integer K. You are allowed to add to K any of its divisors not equal to 1 and K. The same operation can be applied to the resulting number and so on. Notice that 
starting from the number 4, we can reach any composite number by applying several such operations. For example, the number 24 can be reached starting from
4 using 5 operations: 4->6->8->12->18->24.

You will solve a more general problem. Given s N and M, return the minimal number of the described operations necessary to transform N into M. Return -1 if M can't be 
obtained from N.

EXAMPLES:

4
24
Returns: 5
The example from the problem statement.

4
576
Returns: 14
The shortest order of operations is: 4->6->8->12->18->27->36->54->81->108->162->243->324->432->576.

8748
83462
Returns: 10
The shortest order of operations is: 8748->13122->19683->26244->39366->59049->78732->83106->83448->83460->83462.
*/

#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
class DivisorInc{
public:
    int countOperations(int N,int M){
        vector<int>Distance(M+1,-1);
        queue<int> Queue;
        Distance[N]=0;
        Queue.push(N);
        while(!Queue.empty()){
            int value=Queue.front();
            Queue.pop();
            if(value==M) break;
            for(int d:getDivisors(value)){
                int nextValue=value+d;
                if(nextValue<=M && Distance[nextValue]== -1){
                    Queue.push(nextValue);
                    Distance[nextValue]=Distance[value]+1;
                }
            }
        }
        return Distance[M];
    }

private:
    vector<int> getDivisors(int value){
        vector<int>divisors;
        for(int d=2;d<=sqrt(value);d++){
            if(value%d==0){
                divisors.push_back(value/d);
                divisors.push_back(d);
            }
        }
        return divisors;
    }
};

int main()
{
    DivisorInc divisorinc;
    int start,ends;
    cin>>start>>ends;
    cout<<divisorinc.countOperations(start,ends)<<endl;
}
