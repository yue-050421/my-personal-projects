#include "QQAccount.h"
/*
QQAccount
*/
int QQAccount::qqNumber = 0;
QQAccount::QQAccount(){
    isLogin = 0;
    qqNumber++;
    weiXinId = 0;
    isSetWeiBo = 0;
}
QQAccount::~QQAccount(){
}
void QQAccount::set_QQ(int n)
{
	set_id(n);
    //cout<<"输入密码："<<endl;cin>>password;
    inputPassword(password, 20); 
    cout<<"输入QQ昵称:"<<endl;cin>>name;
    cout<<"输入QQ用户生日（xx月xx日）:"<<endl;cin>>birthday[0][0]>>birthday[0][1];
    cout<<"输入QQ创建时间（xx月xx日）:"<<endl;cin>>setTime[0][0]>>setTime[0][1];
    cout<<"输入QQ用户所在城市:"<<endl;cin>>city;
}
void QQAccount::set_QQ()
{
    int pid;
    cout<<"输入QQid:"<<endl;cin>>pid;
	
	
	set_id(pid);
    //cout<<"输入密码："<<endl;cin>>password;
    inputPassword(password, 20); 
    cout<<"输入QQ昵称:"<<endl;cin>>name;
    cout<<"输入QQ用户生日（xx月xx日）:"<<endl;cin>>birthday[0][0]>>birthday[0][1];
    cout<<"输入QQ创建时间（xx月xx日）:"<<endl;cin>>setTime[0][0]>>setTime[0][1];
    cout<<"输入QQ用户所在城市:"<<endl;cin>>city;
}
void QQAccount::show_infor()
{
    cout<<"账号："<<id<<endl;
    cout<<"昵称："<<name<<endl;
    cout<<"生日："<<birthday[0][0]<<"月"<<birthday[0][1]<<"日"<<endl;
    cout<<"创建时间："<<setTime[0][0]<<"月"<<setTime[0][1]<<"日"<<endl;
    cout<<"居住地："<<city<<endl;
    if(weiXinId == 0)
        cout<<"该用户未绑定微信"<<endl;
    else
        cout<<"该用户绑定微信的账号为："<<weiXinId<<endl;
    if(isSetWeiBo == 0)
        cout<<"该用户未绑定微博"<<endl;
    else
        cout<<"该用户绑定微博的账号为："<<isSetWeiBo<<endl;
    if(friendList.empty())
        cout<<"暂无好友"<<endl;
    else{
        cout<<"好友列表："<<endl;
        for(int i=0; i<friendList.size(); i++){
            cout<<friendList[i]<<endl;
        }
    }
    if(groupList.empty())
        cout<<"暂未加入任何QQ群"<<endl;
    else{
        cout<<"QQ群列表:"<<endl;
        for(int i=0; i<groupList.size(); i++)
            cout<<groupList[i]<<endl;
    }
    cout<<endl;
}
void QQAccount::set_weixin_id(int pid){
    weiXinId = pid;
}
void QQAccount::set_weibo_id(int pid){
    isSetWeiBo = pid;
}

int QQAccount::get_weixin_id(){
    return weiXinId;
}
int QQAccount::get_weibo_id(){
    return isSetWeiBo;
}

void QQAccount::set_connect_weibo(){
    WbAccount newWeibo;
    newWeibo.set_id(id);
}
