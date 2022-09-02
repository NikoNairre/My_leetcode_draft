#include<iostream>
using namespace std;

int main(){
    const int N =5;
    int a[N][N]={0};
    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    } 
    system("Pause");
}