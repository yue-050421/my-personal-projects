#pragma once
#include "head.h"
/*
Ⱥ 
*/
class Group
{
    public:
        Group();
        virtual ~Group();
        vector<int>memberId;
        virtual int set_group(int)=0;
        virtual void show_group_infor()=0;
        int add_member();
        void add_member(int);
        void no_output_add_member(int);
        virtual int delete_member()=0;
        void enter_group(int);
        int get_group_id();
        vector<int> get_member_id();
        int get_group_owner_id();
        virtual void delete_member(int)=0;
        void output_member_id();
        int get_groupowner_id();
        void set_group_id(int);
        void set_groupowner_id(int);
    protected:
        int groupId;
        int groupOwnerId;
};
