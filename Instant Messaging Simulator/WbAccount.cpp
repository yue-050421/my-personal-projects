#include "WbAccount.h"
/*
WbAccount
*/
int WbAccount::weiboNumber = 0;
WbAccount::WbAccount()
{
    isLogin = 0;
    weiboNumber++;
}
WbAccount::~WbAccount()
{
}
void WbAccount::set_weibo(){
    cout<<"输入微博昵称:"<<endl;cin>>name;
    //cout<<"输入密码："<<endl;cin>>password;
    inputPassword(password, 20); 
    cout<<"输入用户生日[xx月xx日]:"<<endl;cin>>birthday[0][0]>>birthday[0][1];
    cout<<"输入创建时间[xx月xx日]:"<<endl;cin>>setTime[0][0]>>setTime[0][1];
    cout<<"输入用户所在城市:"<<endl;cin>>city;
}
void WbAccount::show_infor(){
    cout<<"账号："<<id<<endl;
    cout<<"昵称："<<name<<endl;
    cout<<"生日："<<birthday[0][0]<<"月"<<birthday[0][1]<<"日"<<endl;
    cout<<"创建时间："<<setTime[0][0]<<"月"<<setTime[0][1]<<"日"<<endl;
    cout<<"居住地："<<city<<endl;
    cout<<"绑定的QQ账号:"<<QQid<<endl;
    if(friendList.empty())
        cout<<"暂无好友"<<endl;
    else{
        cout<<"好友列表:"<<endl;
        for(int i=0; i<friendList.size(); i++)
            cout<<friendList[i]<<endl;
    }
    cout<<endl;
}

int WbAccount::get_qq_id(){
    return QQid;
}

void WbAccount::set_qq_id(int pid){
    QQid = pid;
}

