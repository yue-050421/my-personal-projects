#include "WxGroup.h"
/*
WxGroup
*/
int WxGroup::weiXinGroupNumber = 0;
WxGroup::WxGroup()
{
    weiXinGroupNumber++;
}
WxGroup::~WxGroup()
{
}
void WxGroup::show_group_infor(){
    int i;
    cout<<"群主账号："<<groupOwnerId<<endl;
    cout<<"所有群成员账号："<<endl;
    for(i=0;i<memberId.size();i++){
        cout<<memberId[i]<<endl;
    }
}

int WxGroup::delete_member(){
    int temp;
    int i;
    cout<<"输入要踢出群的成员账号："<<endl;
    cin>>temp;
    for(i=0;i<memberId.size();i++){
        if(memberId[i] == temp){
            memberId.erase(memberId.begin()+i);
            cout<<"踢出成功"<<endl;
            return temp;
        }
    }
    cout<<"群中无此人"<<endl;
    return 0;
}

void WxGroup::delete_member(int id){
    for(int i=0;i<memberId.size();i++){
        if(memberId[i] == id){
            memberId.erase(memberId.begin()+i);
            cout<<"删除成功"<<endl;
            return;
        }
    }
}

int WxGroup::set_group(int id){
    groupOwnerId = id;
    memberId.push_back(id);
    cout<<"输入群id:"<<endl;
    cin>>groupId;
    return groupId;
}

