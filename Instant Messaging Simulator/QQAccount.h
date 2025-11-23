#pragma once
#include "head.h"    
#include "Account.h"
#include "WbAccount.h"
/*
qq’Àªß 
*/
class QQAccount : public Account
{
    public:
        QQAccount();
        virtual ~QQAccount();
        void set_QQ();void set_QQ(int);
        void show_infor();
        void set_connect_weibo();
        void set_weixin_id(int);
        void set_weibo_id(int);
        int get_weixin_id();
        int get_weibo_id();
        static int qqNumber;
    private:
        int weiXinId;
        int isSetWeiBo;
};

