#pragma once
#include "head.h"
#include "QQAccount.h"
#include "Account.h"
#include "QQGroup.h"
/*
qqͨѶ 
*/
class QQClient
{
    public:
        QQClient();
        virtual ~QQClient();
        vector<QQAccount>QQvector;
        vector<QQGroup>QQgroup;
        void set_new_QQ_group(int);
        void set_new_son_group(int,int);
        void set_new_QQ_account();
        void set_admin(int);
        void set_new_QQ_account(int); 
        void set_son_group(int);
        void show_QQ_infor(int);
        void show_group_infor(int);
        void show_son_group_infor(int);
        void change_QQ_infor(int);
        void add_friend(int);
        void delete_friend(int);
        void enter_group(int);
        void exit_group(int);
        int judge_groupid_exist(int id);
        void initialise_QQ(int);
        void initialise_qq_group(int);
};

