#include "Group.h"
/*
Group
*/
Group::Group()
{
}
Group::~Group()
{
}
int Group::add_member()
{
    int temp;
    int i;
    std::cout<<"输入要拉入群的账号："<<endl;
    cin>>temp;
    for(i=0;i<memberId.size();i++){
        if(memberId[i] == temp){
            cout<<"该成员已为群成员"<<endl;
            return 0;
        }
    }
    memberId.push_back(temp);
    cout<<"成功拉入.."<<endl;
    return temp;
}
void Group::enter_group(int id)
{
    int i;
    for(i=0;i<memberId.size();i++)
	{
        if(memberId[i] == id){
            cout<<"你已为群成员"<<endl;
            return;
        }
    }
    memberId.push_back(id);
}
void Group::add_member(int pid)
{
    memberId.push_back(pid);
}
void Group::output_member_id(){
    for(int i=0;i<memberId.size();i++)
	{
        cout<<memberId[i]<<endl;
    }
}
int Group::get_group_id()
{
    return groupId;
}
void Group::set_group_id(int pid)
{
    groupId = pid;
}
void Group::set_groupowner_id(int pid)
{
    groupOwnerId = pid;
}
void Group::no_output_add_member(int pid)
{
    memberId.push_back(pid);
}
int Group::get_group_owner_id(){
    return groupOwnerId;
}
vector<int> Group::get_member_id(){
    return memberId;
}
int Group::get_groupowner_id(){
    return groupOwnerId;
}

