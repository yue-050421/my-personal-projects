#pragma once
#include "head.h"
#include "WbAccount.h"
/*
wbͨѶ 
*/
class WbClient
{
    public:
        WbClient();
        virtual ~WbClient();
        vector<WbAccount>wbClient;
        static int weiboNumber;
        void add_friend(int);
        void delete_friend(int);
        void set_new_weibo_account();
        void initialise_weibo(int);
        void show_weibo_infor(int);
        void change_weibo_infor(int);
};

