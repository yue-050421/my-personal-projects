#pragma once
#include "head.h"
#include "WxAccount.h"
#include "WxGroup.h"
/*
wxͨѶ 
*/
class WxClient
{
    public:
        WxClient();
        virtual ~WxClient();
        vector<WxAccount>weixinClient;
        vector<WxGroup>weixinGroup;
        void set_new_weixin_group(int);
        void set_new_weixin_account();
        void show_weixin_infor(int);
        void show_group_infor(int);
        void set_new_weixin_account(int);
        void change_weixin_infor(int);
        void add_friend(int);
        void delete_friend(int);
        void enter_group(int);
        void exit_group(int);
        int judge_groupid_exist(int id);
        void initialise_weixin(int);
        void initialise_weixin_group(int);
};

