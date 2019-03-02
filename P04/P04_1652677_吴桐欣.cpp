//
//  P04_1652677_吴桐欣.cpp
//

#include "P04_1652677_吴桐欣.h"
using namespace std;

int main(void) {
    int n=0;
    int count=0;
    while(true) {
        cout<<"输入皇后个数n(0<n<11):";
        cin>>n;
        if (n && n>0 && n<11) {
            break;
        } else {
            if (cin.fail()) {
                cerr<<"输入了非法字符！"<<endl;
                cin.clear();
                string s;
                cin>>s;
            } else {
                cerr<<"请输入符合条件的数字n！"<<endl;
            }
        }
    }
    cout<<"皇后摆法："<<endl;
    vector<Point> qs;
    List toCheck;
    toCheck.n = n;
    toCheck.initialize();
    for (; ; ) {
        static int i=0;
        static int j=0;
        if (n==1) {i=-1;}
        if (i==-1) {break;}

        for (; j<n; j++) {
            Point cur = {i,j};
    
            //如果当前位置cur可以放置
            if (toCheck.onList(cur)) {
                qs.push_back(cur);                          //放置皇后
                if (cur.x == n-1) {                         //如果这是最后一个皇后
                    count++;
                    cout<<"[方案 #"<<count<<"]"<<endl;
                    //打印结果开始
                    for (int a=0; a<n; a++) {
                        for (int b=0; b<n; b++) {
                            if (b==qs[a].y) {
                                cout<<"x ";
                            } else {
                                cout<<"0 ";
                            }
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                    ///////打印结果结束
                    qs.pop_back();                          //弹出最后一行的皇后
                    //返回上一行
                    i = qs.back().x;
                    j = qs.back().y+1;
                    toCheck.deletePoint(qs.back());
                    qs.pop_back();
                    //////返回上一行
                    if (j == n) {                           //如果上一行已经遍历完，即上一行的皇后在边界上
                        //返回上一行
                        i = qs.back().x;
                        j = qs.back().y+1;
                        toCheck.deletePoint(qs.back());
                        qs.pop_back();
                        //////返回上一行
                    }
                } else {                                    //如果还不是最后一个皇后
                    toCheck.addPoint(cur);
                    i++;
                    j = 0;                                  //跳至下一行
                }
                break;
            }
            
            //如果当前位置cur不能放置
            if (j == n-1) {                                 //如果当前行已经遍历完，即当前位置cur在边界上
                //返回上一行
                i = qs.back().x;
                j = qs.back().y+1;
                toCheck.deletePoint(qs.back());
                qs.pop_back();
                ////////返回上一行
                if (j == n && !qs.empty()) {                //如果上一行已经遍历完，即上一行的皇后在边界上
                    //返回上一行
                    i = qs.back().x;
                    j = qs.back().y+1;
                    toCheck.deletePoint(qs.back());
                    qs.pop_back();
                    ///////返回上一行
                } else if(j == n && qs.empty()) {           //如果第一行已经遍历完
                    i=-1;
                    break;
                }
                break;
            }
        }
    }
    if (n==1) {
        count++;
        cout<<"[方案 #"<<count<<"]"<<endl;
        cout<<"x"<<endl;
    }
    cout<<"共有 "<<count<<" 种解法"<<endl;
    return 0;
}
