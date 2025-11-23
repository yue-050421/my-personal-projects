#pragma once
#include "head.h"
/*
’Àªß 
*/
class Account
{
    public:
        Account();
        ~Account();
        int add_friend(int);
        int no_output_add_friend(int);
        int delete_friend(int);
        int no_output_delete_friend(int);
        int enter_group(int);
        void no_output_enter_group(int);
        int exit_group(int);
        int no_output_exit_group(int);
        int get_id();
        int get_birthday_month();
        int get_birthday_day();
        int get_settime_month();
        int get_settime_day();
        string get_name();
        string get_city();
        vector<int> get_friendlist();
        vector<int> get_grouplist();
        string get_password();
        int get_is_login();
        void set_id(int);
        void set_name(string);
        void set_birthday(int,int);
        void set_settime(int,int);
        void set_city(string);
        void set_password(string);
        virtual void show_infor()=0;
        void change_infor();
        int login(string);
        void no_output_login();
    protected:
        int id;
        string password;
        int isLogin;
        string name;
        int birthday[1][2];
        int setTime[1][2];
        string city;
        vector<int> friendList;
        vector<int> groupList;
};

