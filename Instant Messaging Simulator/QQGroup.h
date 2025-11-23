#pragma once
#include "head.h"
#include "Group.h"
/*
qqȺ 
*/
class QQGroup : public Group
{
    public:
        QQGroup();
        virtual ~QQGroup();
        static int qqGroupNumber;
        static int sonGroupNumber;
        int set_group(int);
        void set_admin();
        void set_father_group_id(int);
        void no_output_set_admin(int);
        void show_group_infor();
        void delete_admin();
        int delete_member();
        void delete_member(int);
        void show_son_group_infor();
        int get_father_group_id();
        vector<int> get_son_group_id();
        vector<int> get_admin_id();
    protected:
        vector<int>adminId;
        string groupType;
        vector<int>sonGroupId;
        int fatherGroupId;
};

