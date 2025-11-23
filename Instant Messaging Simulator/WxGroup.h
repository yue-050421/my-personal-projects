#pragma once
#include "Group.h"
/*
wxȺ 
*/
class WxGroup : public Group
{
    public:
        WxGroup();
        virtual ~WxGroup();
        static int weiXinGroupNumber;
        int set_group(int);
        void show_group_infor();
        int delete_member();
        void delete_member(int);
};


