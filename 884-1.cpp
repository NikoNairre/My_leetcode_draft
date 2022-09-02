#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
stringstream ss;
ss << "hello ";
ss << "world!";
stringstream a;
a<<"No password";

std::cout << ss.str() << std::endl;
cout<<a.str()<<endl;
a.str("");
a<<"RNM, refund money!";
std::cout<<a.str()<<endl;
// 對stringstream而言，operator<< 是一直往字串流中寫字元
// 而不是覆蓋之前輸入的字元，這一點不同於str()成員函式方法,str()函式建立的是一個臨時的string物件
//這個string物件在函式str()語句結束就會被銷燬，因而一般使用時應先宣告一個string物件s，將str()賦值給s
//const string s=ss.str();//這樣會有一個string拷貝的過程
/*又或者是const string& s=ss.str();這樣就是用s直接引用了ss.str()這個臨時變數，就“延長了臨時變數ss.str()的
生命週期”，使得ss.str()生命結束時刻和s一樣*/
return 0;
}