#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int k=19;
vector<int> results=vector<int>(k+1,0);
vector<int> fibonaccis={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,
                        28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,
                        5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,
                        267914296,433494437,701408733};
int max_fib(int t){
    int single_fib=fibonaccis[1];
    int sign=1;
    while(single_fib<t){
        sign++;
        results[single_fib]=1;
        single_fib=fibonaccis[sign];
    }
    single_fib=fibonaccis[sign-1];
    return single_fib;    
}
int main(){
    for(int i=4;i<=k;i++){
        if(!binary_search(fibonaccis.begin(),fibonaccis.end(),i)){
            results[i]=results[max_fib(i)]+results[i-max_fib(i)];
        }
    }
    cout<<results[k]<<endl;
    for(int i=1;i<=k;i++){
        cout<<results[i]<<" ";
    }
    return 0;
}