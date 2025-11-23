#include "WxAccount.h"
/*
WxAccount
*/ 
int WxAccount::weixinNumber = 0;
WxAccount::WxAccount()
{
    QQid = 0;
    weixinNumber++;
}
WxAccount::~WxAccount()
{
}
void WxAccount::set_weixin(int nn){
    id=nn;

    inputPassword(password, 20); 
    cout<<"输入微信名字:"<<endl;cin>>name;
    cout<<"输入微信用户生日（xx月xx日）:"<<endl;cin>>birthday[0][0]>>birthday[0][1];
    cout<<"输入微信创建时间（xx月xx日）:"<<endl;cin>>setTime[0][0]>>setTime[0][1];
    cout<<"输入微信用户所在城市:"<<endl;cin>>city;
}
void WxAccount::set_weixin(){
    cout<<"输入微信id:"<<endl;cin>>id;
    //cout<<"输入微信密码:"<<endl;cin>>password;
    inputPassword(password, 20); 
    cout<<"输入微信名字:"<<endl;cin>>name;
    cout<<"输入微信用户生日（xx月xx日）:"<<endl;cin>>birthday[0][0]>>birthday[0][1];
    cout<<"输入微信创建时间（xx月xx日）:"<<endl;cin>>setTime[0][0]>>setTime[0][1];
    cout<<"输入微信用户所在城市:"<<endl;cin>>city;
}

void WxAccount::show_infor(){
    cout<<"账号："<<id<<endl; bool flag=false;
    cout<<"昵称："<<name<<endl;
    cout<<"生日："<<birthday[0][0]<<"月"<<birthday[0][1]<<"日"<<endl;
    cout<<"创建时间："<<setTime[0][0]<<"月"<<setTime[0][1]<<"日"<<endl;
    cout<<"居住地："<<city<<endl;
    if(QQid == 0)
        cout<<"该用户暂未绑定QQ"<<endl;
    else
        cout<<"该用户绑定的QQ的账号为："<<QQid<<endl;
    if(friendList.empty())
        cout<<"暂无好友"<<endl;
    else{
        cout<<"好友列表："<<endl;
        for(int i=0; i<friendList.size(); i++)
            cout<<friendList[i]<<endl;
    }
    if(groupList.empty())
        cout<<"\n暂未加入任何微信群"<<endl;
    else{
        cout<<"微信群列表:"<<endl;
        for(int i=0; i<groupList.size(); i++)
            cout<<groupList[i]<<endl;
    }
    cout<<endl;
}

int WxAccount::get_qq_id(){
    return QQid;
}

void WxAccount::set_qq_id(int pid){
    QQid = pid;
}

