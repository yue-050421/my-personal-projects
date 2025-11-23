#include "QQClient.h"
/*
QQClient
*/
QQClient::QQClient()
{
}
QQClient::~QQClient()
{
}
void QQClient::initialise_QQ(int qqNumber){
    for(int i=0;i<qqNumber;i++){
        QQAccount temp;
        QQvector.push_back(temp);
    }
}
void QQClient::initialise_qq_group(int qqGroupNumber){
    for(int i=0;i<qqGroupNumber;i++){
        QQGroup temp;
        QQgroup.push_back(temp);
    }
}
void QQClient::set_new_QQ_account(int n){
    QQAccount newQQ;
    newQQ.set_QQ(n);
    QQvector.push_back(newQQ);
}
void QQClient::set_new_QQ_account(){
    QQAccount newQQ;
    newQQ.set_QQ();
    QQvector.push_back(newQQ);
}
void QQClient::set_new_QQ_group(int QQid){
    int i;
    QQGroup newgroup;
    for(i=0;i<QQvector.size();i++){
        if(QQvector[i].get_id()==QQid){
            QQvector[i].no_output_enter_group(newgroup.set_group(QQid));
            //cout<<"测试“："<<QQvector[i].getQQgroupList().at(0)<<"完成"<<endl;
            cout<<"创建群成功"<<endl;
            QQgroup.push_back(newgroup);
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}
void QQClient::show_QQ_infor(int QQid){
    int i;
    for(i=0;i<QQvector.size();i++){
        cout<<QQvector[i].get_id()<<endl;
        if(QQvector[i].get_id()==QQid){
            QQvector[i].show_infor();
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}
void QQClient::change_QQ_infor(int QQid){
    int i;
    for(i=0;i<QQvector.size();i++){
        if(QQvector[i].get_id()==QQid){
            QQvector[i].change_infor();
        }
    }
}
void QQClient::add_friend(int QQid){
    int i,j,number;
    for(i=0;i<QQvector.size();i++){
        if(QQvector[i].get_id()==QQid){
            cout<<"输入要加为好友的qq账号："<<endl;
            cin>>number;
            setbuf(stdin, NULL);
            for(j=0;j<QQvector.size();j++){
                if(QQvector[j].get_id() == number){
                    if(QQvector[i].add_friend(number))
                        QQvector[j].no_output_add_friend(QQid);
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
void QQClient::delete_friend(int QQid){
    int i,j,number;
    for(i=0;i<QQvector.size();i++){
        if(QQvector[i].get_id()==QQid){
            cout<<"输入想要删除好友的qq账号："<<endl;
            cin>>number;
            setbuf(stdin, NULL);
            for(j=0;j<QQvector.size();j++){
                if(QQvector[j].get_id() == number){
                    if(QQvector[i].delete_friend(number)){
                        QQvector[j].no_output_delete_friend(QQid);
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
void QQClient::enter_group(int QQid){
    int i,groupNumber,j,temp;
    for(i=0;i<QQvector.size();i++){
        if(QQvector[i].get_id()==QQid){
            cout<<"输入要加入群的账号："<<endl;
            cin>>groupNumber;
            for(j=0;j< QQgroup.size();j++){
                if(QQgroup[j].get_group_id() == groupNumber){
                    if(QQvector[i].enter_group(groupNumber)){
                        QQgroup[j].add_member(QQid);
                        cout<<"入群成功"<<endl;
                        return;
                    }
                }
                cout<<"查无此群"<<endl;
                return;
            }
//            cout<<"查无此群"<<endl;
            return;
        }
    }
    cout<<"该用户不存在"<<endl;
}
void QQClient::exit_group(int QQid){
    int i,groupNumber,j;
    for(i=0;i<QQvector.size();i++){
        if(QQvector[i].get_id()==QQid){
            cout<<"输入要退出群的账号："<<endl;
            cin>>groupNumber;
            for(j=0;j< QQgroup.size();j++){
                if(QQgroup[j].get_group_id() == groupNumber){
                    if(QQvector[i].exit_group(groupNumber)){
                        
                        QQgroup[j].delete_member(QQid);
                        cout<<"退群成功"<<endl;
                        return;
                    }
                }
            }
            cout<<"查无此群！"<<endl;
            return;
        }
    }
    cout<<"该用户不存在！！"<<endl;
}
void QQClient::show_group_infor(int groupid){
    for(int i=0;i<QQgroup.size();i++){
        if(QQgroup[i].get_group_id() == groupid){
            QQgroup[i].show_group_infor();
            return;
        }
    }
    cout<<"该群不存在"<<endl;
}
void QQClient::show_son_group_infor(int groupid){
    for(int i=0;i<QQgroup.size();i++){
        if(QQgroup[i].get_father_group_id() == groupid){
            QQgroup[i].show_son_group_infor();
            return;
        }
    }
    cout<<"该群不存在"<<endl;
}
void QQClient::set_admin(int groupid){
    for(int i=0;i<QQgroup.size();i++){
        if(QQgroup[i].get_group_id() == groupid){
            QQgroup[i].set_admin();
            return;
        }
    }
    cout<<"该群不存在"<<endl;
}
int QQClient::judge_groupid_exist(int id){
    int flag = 1;
    int number = id;
    while(flag){
        flag  = 0;
        for(int j=0;j<QQgroup.size();j++){
            if(QQgroup[j].get_group_id() == number){
                cout<<"该群账号已存在,请重新输入"<<endl;
                cin>>number;
                flag = 1;
            }
        }
    }
    return number;
}
void QQClient::set_son_group(int groupid){
    int number,flag = 1,songroupid;
    for(int i=0;i<QQgroup.size();i++){
        if(QQgroup[i].get_group_id() == groupid){
            cout<<"输入临时讨论组账号："<<endl;
            cin>>songroupid;
            songroupid = judge_groupid_exist(songroupid);
            set_new_son_group(groupid,songroupid);
            QQgroup[i].get_son_group_id().push_back(songroupid);
            while(flag){
                cout<<"输入要拉入临时讨论组的账号："<<endl;
                for(int k=0;k<QQgroup[i].get_member_id().size();k++){
                    cout<<QQgroup[i].get_member_id()[k]<<endl;
                }
                cin>>number;
                for(int j=0;j<QQgroup.size();j++){
                    if(QQgroup[j].get_group_id() == songroupid){
                        QQgroup[j].add_member(number);
                    }
                }
                for(int j=0;j<QQvector.size();j++){
                    if(QQvector[j].get_id() == number){
                        QQvector[j].enter_group(songroupid);
                    }
                }
                cout<<"0.结束\n1.继续拉人\n"<<endl;
                cin>>flag;
            }
            return;
        }
    }
    cout<<"该群不存在"<<endl;
}
void QQClient::set_new_son_group(int groupid,int number){
    QQGroup songroup;
    songroup.set_group_id(number);
    songroup.set_father_group_id(groupid);
    QQgroup.push_back(songroup);
    for(int i;i<QQgroup.size();i++){
        if(QQgroup[i].get_group_id() == groupid){
            QQgroup[i].get_son_group_id().push_back(number);
        }
    }
    QQGroup::sonGroupNumber++;
}
