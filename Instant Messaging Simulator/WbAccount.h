#pragma once
#include "Account.h"
/*
wb’Àªß 
*/
class WbAccount : public Account
{
    public:
        WbAccount();
        virtual ~WbAccount();
        void show_infor();
        void set_weibo();
        static int weiboNumber;
        int get_qq_id();
        void set_qq_id(int);
    private:
        int QQid;
};


