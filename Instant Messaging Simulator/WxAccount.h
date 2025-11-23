#pragma once
#include "Account.h"
/*
wx’Àªß 
*/
class WxAccount : public Account
{
    public:
        WxAccount();
        virtual ~WxAccount();
        static int weixinNumber;
        void set_weixin();
        void show_infor();
        int get_qq_id();
        void set_qq_id(int);
		void set_weixin(int );
    private:
        int QQid;
};


