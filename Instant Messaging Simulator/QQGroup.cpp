#include "QQGroup.h"
/*
QQGroup
*/
int QQGroup::qqGroupNumber = 0;
int QQGroup::sonGroupNumber = 0;
QQGroup::QQGroup()
{
    qqGroupNumber++;
    fatherGroupId = 0;
}
QQGroup::~QQGroup()
{
}
int QQGroup::set_group(int QQid){
    groupOwnerId = QQid;
    adminId.push_back(QQid);
    cout<<"输入群账号："<<endl;
    cin>>groupId;
    memberId.push_back(groupOwnerId);
    return groupId;
}
void QQGroup::set_admin(){
    int adminid;
    int i;
    cout<<"输入要设置成管理员的账号：";
    cin>>adminid;
    for(i=0;i<memberId.size();i++){
        if(memberId[i] == adminid){
            adminId.push_back(adminid);
            cout<<"设置成功"<<endl;
            return;
        }
    }
    cout<<"群中无此人"<<endl;
}
void QQGroup::show_group_infor(){
    int i;
    cout<<"群主账号："<<groupOwnerId<<endl;
    if(adminId.empty()){
        cout<<"该群未设置管理员"<<endl;
    }
    else{
        cout<<"群管理员账号："<<endl;
        for(i=0;i<adminId.size();i++){
            cout<<adminId[i]<<endl;
        }
    }
    cout<<"所有群成员账号："<<endl;
    for(i=0;i<memberId.size();i++){
        cout<<memberId[i]<<endl;
    }
    if(sonGroupId.empty());
    else{
        cout<<"所有临时讨论组账号："<<endl;
        for(int i=0;i<sonGroupId.size();i++){
            cout<<sonGroupId[i]<<endl;
        }
    }
}
int QQGroup::delete_member(){
    int temp;
    int i;
    cout<<"输入要踢出群的QQ账号："<<endl;
    cin>>temp;
    for(i=0;i<memberId.size();i++){
        if(memberId[i] == temp){
            memberId.erase(memberId.begin()+i);
            cout<<"踢出成功"<<endl;
            for(int k=0;k<adminId.size();k++){
                if(adminId[k] == temp)
                    adminId.erase(adminId.begin()+k);
            }
            return temp;
        }
    }
    cout<<"群中无此人"<<endl;
    return 0;
}
void QQGroup::delete_member(int QQid){
    for(int i=0;i<memberId.size();i++){
        if(memberId[i] == QQid){
            memberId.erase(memberId.begin()+i);
        }
    }
    for(int i=0;i<adminId.size();i++){
        if(adminId[i] == QQid)
            adminId.erase(adminId.begin()+i);
    }
}
void QQGroup::delete_admin(){
    int adminid;
    int i;
    cout<<"输入要取消管理员的账号：";
    cin>>adminid;
    for(i=0;i<adminId.size();i++){
        if(adminId[i] == adminid){
            cout<<"取消成功"<<endl;
            adminId.erase(adminId.begin()+i);
            return;
        }
        
    }
cout<<"该成员不是管理员"<<endl;
}
void QQGroup::show_son_group_infor(){
    cout<<"主群："<<fatherGroupId<<endl;
    cout<<"临时讨论组成员："<<endl;
    for(int i=0;i<memberId.size();i++){
        cout<<memberId[i]<<endl;
    }
}
int QQGroup::get_father_group_id(){
    return fatherGroupId;
}
vector<int> QQGroup::get_son_group_id(){
    return sonGroupId;
}
void QQGroup::set_father_group_id(int pid){
    fatherGroupId = pid;
}
void QQGroup::no_output_set_admin(int pid){
    adminId.push_back(pid);
}

vector<int> QQGroup::get_admin_id(){
    return adminId;
}

