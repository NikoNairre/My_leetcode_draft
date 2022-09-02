#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> position_blank(string test) {  //记录句子中所有空格的下标  
    vector<int>blank_array;
    blank_array.push_back(0);
    for (int i = 0; i < test.size(); i++) {
        if (test[i] == ' ') {
            blank_array.push_back(i);
        }
    }
    blank_array.push_back(test.size());
    return blank_array;      //这个返回的数组中存储了所有空格的下标
}

vector<string> seperation_words(string test) {     //将句子中的所有单词按空格进行分隔
    vector<int> blanks = position_blank(test);     //借助空格下标来分词（句子不能以空格开头）
    vector<string> words;                          //string类型数组存储句子中的每个单词
    words.push_back(test.substr(blanks[0], blanks[1])); //第一个单词储存时，属于特殊情况
    for (int i = 1; i < blanks.size() - 1; i++) {   //剩下单词的储存遵循下列方法
        if (blanks[i + 1] - blanks[i] > 1) {
            words.push_back(test.substr(blanks[i] + 1, blanks[i + 1] - blanks[i] - 1));
        }
    }
    return words;                                 //返回存储句子单词的数组
}
int main() {
    string a = "qte1i   1-,, yv03a  r12r2stw 4 d,tnirlsj pb !16- 9 b  dnlgrig 8   n!88qyfjly   0g f5hgfg0u9lux7 - 6ega 0p36 pnw  ae  0m  -v  q3zdw09b9qju q0! s-  jk 04 e1ik  2 3  k a1qe.ac,-w j,keef76xz8  -!zhc s b u -z. ,,b -rei 83ooj 899 af w1irv u o3jk21 71i60pq3,.rzbhc.-  t9 xlk5g  ovn 8f9  ztw 7siy p-yl856r, ma39xtl!t-o c 2x 2 drj!ms0w ysy  u0tcw8u.im c 0ke.5sk  dn8.mh qi   8xmt -bxmr  z 1r 5 umyk 8rbe!dif kmes n rp icnb s 0yc1e 8  e1 !f  .u lh  n a -iinnm!a08dfgq ,lux,j 8fyqt hcbajnb4swuxtqm4j1  ic04 o,i4lka id 0srlb  y 2k  1g  3m nptj   53rh, zim7mkd2hqf64 chotiijcemj!m dif7iiq m2e ve!9!r1 jw okyahf! r6kskaodd h eug.yc,3j ilkd 9vlpipfc  g5y   7u 5pt531!4s 4  si !lg x50-   kc51ca34s pl 9w,mgj3  5fy,.3d shi ct a k2nx8l xum9sgyp6r   rj! 8  m!1k gm  typy . oee08!!j0,2iwq  9 ywd w rhpoc s6118y c5.qw4d  tlrjs.!9 mpioexe. xmicv  ,z g2 p6 bhtm!  ,w 7 ";
    while (a[0] ==' ') {     //去除句子开头的空格，方便分词
        a.erase(0,1);        
    }
    vector<string>all_words = seperation_words(a);//分词
/*   for (int i = 0; i < all_words.size(); i++) {
        cout << all_words[i] << " ";
    }                                          //注释的程序可以输出句子中所有分开出来的单词
    cout << endl;               */
    int count = 0;         //单词是否合法的计数器
    for (auto item : all_words) {     //依次检查每个单词是否合法
        bool is_valid = true;      //表示单词是否合法的布尔值，初始化为true
        int num_of_insert = 0;     //统计连字符“-”的数目
        int signs = 0;             //统计符号的数目
        for (int i = 0; i < item.size(); i++) {
            if (item[i] >= 48 and item[i] <= 57) {  //若单词含有数字0-9，则不合法
                is_valid = false;
                break;                 //这里和以下的break都表示当该单词已经不合法时，跳出判断的循环，继续下一个单词的判断
            }
            if (item[i] == '-') {num_of_insert++;}
            if (item[i] == '!' or item[i] == ',' or item[i] == '.') {signs++;}
            if (num_of_insert >= 2) {  //连字符数目超过1，该单词不合法
                is_valid = false;
                break;
            }
            if (signs >= 2) {         //符号数目超过1，该单词不合法
                is_valid = false;
                break;
            }
        }
        if (is_valid) {            //在循环外，即使这时的is_value为真，也不能保证合法，需要排除特殊情况
            if (item[0] == '-' or item[item.size() - 1] == '-') {   //若连字符出现在单词首末位，则单词不合法
                is_valid = false;
            }                                 //下一行，若is_value依然为真，则开始检查符号，当单词中唯一的符号不在单词末尾，则单词不合法
            else if (signs == 1 and (item[item.size() - 1] == '!' or item[item.size() - 1] == ',' or item[item.size() - 1] == '.')) {
                if (item.size() > 1) {       //像"!",",","."这样的单词是合法的，需要对长度大于1的单词进行判断 
                    if (item[item.size() - 2] == '-') {  //像"xxx-!"，虽然连字符不在末位，但这种单词不合法
                        is_valid = false;
                    }
                    else {
                        is_valid = true;
                    }
                }
            }                          //下一行，当单词中唯一的符号不在单词末位时，单词不合法
            else if (signs == 1 and (item[item.size() - 1] != '!' and item[item.size() - 1] != ',' and item[item.size() - 1] != '.')) {
                is_valid = false;
            }
        }
        if (is_valid) { count++; }   //经过一系列检验，如果单词依然合法，则计数器加1
    }
    cout << count << endl;
    return 0;
}