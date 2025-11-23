#include "WxClient.h"
/*
WxClient
*/
WxClient::WxClient()
{
}
WxClient::~WxClient()
{
}
void WxClient::set_new_weixin_account(int nn){
    WxAccount newWeixin;
    newWeixin.set_weixin(nn);
    weixinClient.push_back(newWeixin);
}
void WxClient::set_new_weixin_account(){
    WxAccount newWeixin;
    newWeixin.set_weixin();
    weixinClient.push_back(newWeixin);
}
void WxClient::set_new_weixin_group(int weixinId){
    int i;
    WxGroup newgroup;
    for(i=0;i<weixinClient.size();i++){
        if(weixinClient[i].get_id()==weixinId){
            weixinClient[i].no_output_enter_group(newgroup.set_group(weixinId));
            cout<<"建群成功"<<endl;
            weixinGroup.push_back(newgroup);
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}
void WxClient::show_weixin_infor(int weixinId){
    int i;
    for(i=0;i<weixinClient.size();i++){
        cout<<weixinClient[i].get_id()<<endl;
        if(weixinClient[i].get_id()==weixinId){
            weixinClient[i].show_infor();
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}


void WxClient::show_group_infor(int groupid){
    for(int i=0;i<weixinGroup.size();i++){
        if(weixinGroup[i].get_group_id() == groupid){
            weixinGroup[i].show_group_infor();
            return;
        }
    }
    cout<<"该群不存在"<<endl;
}

void WxClient::change_weixin_infor(int id){
    int i;
    for(i=0;i<weixinClient.size();i++){
        if(weixinClient[i].get_id()==id){
            weixinClient[i].change_infor();
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}

void WxClient::add_friend(int id){
    int i,j,number;
    for(i=0;i<weixinClient.size();i++){
        if(weixinClient[i].get_id()==id){
            cout<<"输入要加为好友的微信账号："<<endl;
            cin>>number;
            setbuf(stdin, NULL);
            for(j=0;j<weixinClient.size();j++){
                if(weixinClient[j].get_id() == number){
                    if(weixinClient[i].add_friend(number))
                        weixinClient[j].no_output_add_friend(id);
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

void WxClient::delete_friend(int id){
    int i,j,number;
    for(i=0;i<weixinClient.size();i++){
        if(weixinClient[i].get_id()==id){
            cout<<"输入要删除好友的微信账号："<<endl;
            cin>>number;
            setbuf(stdin, NULL);
            for(j=0;j<weixinClient.size();j++){
                if(weixinClient[j].get_id() == number){
                    if(weixinClient[i].delete_friend(number)){
                        weixinClient[j].no_output_delete_friend(id);
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


void WxClient::enter_group(int id){
    int i,groupNumber,j,temp;
    for(i=0;i<weixinClient.size();i++){
        if(weixinClient[i].get_id()==id){
            cout<<"请输入要加入群的账号："<<endl;
            cin>>groupNumber;
            for(j=0;j< weixinGroup.size();j++){
                if(weixinGroup[j].get_group_id() == groupNumber){
                    if(weixinClient[i].enter_group(groupNumber)){
                        weixinGroup[j].add_member(id);
                        cout<<"入群成功"<<endl;
                        return;
                    }
                }
            }
            cout<<"查无此群"<<endl;
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}

void WxClient::exit_group(int id){
    int i,groupNumber,j;
    for(i=0;i<weixinClient.size();i++){
        if(weixinClient[i].get_id()==id){
            cout<<"输入要退出群的账号："<<endl;
            cin>>groupNumber;
            for(j=0;j< weixinGroup.size();j++){
                if(weixinGroup[j].get_group_id() == groupNumber){
                    if(weixinClient[i].exit_group(groupNumber)){
                        
                        weixinGroup[j].delete_member(id);
                        cout<<"退群成功"<<endl;
                        return;
                    }
                }
            }
            cout<<"查无此群"<<endl;
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}

int WxClient::judge_groupid_exist(int id){
    int flag = 1;
    int number = id;
    while(flag){
        flag  = 0;
        for(int j=0;j<weixinGroup.size();j++){
            if(weixinGroup[j].get_group_id() == number){
                cout<<"群账号已存在,请重新输入"<<endl;
                cin>>number;
                flag = 1;
            }
        }
    }
    return number;
}


void WxClient::initialise_weixin(int weixinNumber){
    for(int i=0;i<weixinNumber;i++){
        WxAccount temp;
        weixinClient.push_back(temp);
    }
}

void WxClient::initialise_weixin_group(int weixinGroupNumber){
    for(int i=0;i<weixinGroupNumber;i++){
        WxGroup temp;
        weixinGroup.push_back(temp);
    }
}

