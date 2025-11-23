#include "WbClient.h"
/*
WbClient
*/
WbClient::WbClient()
{
}
WbClient::~WbClient()
{
}
void WbClient::set_new_weibo_account(){
    WbAccount newWeibo;
    newWeibo.set_weibo();
    wbClient.push_back(newWeibo);
}
void WbClient::show_weibo_infor(int weiboId){
    int i;
    for(i=0;i<wbClient.size();i++){
        cout<<wbClient[i].get_id()<<endl;
        if(wbClient[i].get_id()==weiboId){
            wbClient[i].show_infor();
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}
void WbClient::change_weibo_infor(int id){
    int i;
    for(i=0;i<wbClient.size();i++){
        if(wbClient[i].get_id()==id){
            wbClient[i].change_infor();
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}
void WbClient::add_friend(int id){
    int i,j,number;
    for(i=0;i<wbClient.size();i++){
        if(wbClient[i].get_id()==id){
            cout<<"输入要加为好友的微信账号："<<endl;
            cin>>number;
            setbuf(stdin, NULL);
            for(j=0;j<wbClient.size();j++){
                if(wbClient[j].get_id() == number){
                    if(wbClient[i].add_friend(number))
                        wbClient[j].no_output_add_friend(id);
                    else
                        cout<<"添加好友失败"<<endl;
                    return;
                }
            }
            cout<<"该用户不存在"<<endl;
            return;
        }
    }
}
void WbClient::delete_friend(int id){
    int i,j,number;
    for(i=0;i<wbClient.size();i++){
        if(wbClient[i].get_id()==id){
            cout<<"输入要删除好友的微博账号："<<endl;
            cin>>number;
            setbuf(stdin, NULL);
            for(j=0;j<wbClient.size();j++){
                if(wbClient[j].get_id() == number){
                    if(wbClient[i].delete_friend(number)){
                        wbClient[j].no_output_delete_friend(id);
                        return;
                    }
                    else{
                        cout<<"删除好友失败"<<endl;
                        return;
                    }
                }
            }
            cout<<"该用户不存在"<<endl;
            return;
        }
    }
}
void WbClient::initialise_weibo(int weiboNumber){
    for(int i=0;i<weiboNumber;i++){
        WbAccount temp;
        wbClient.push_back(temp);
    }
}

