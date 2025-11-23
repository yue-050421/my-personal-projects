#include "Account.h"
/*
Account
*/
Account::Account()
{
}
Account::~Account()
{
}
int Account::add_friend(int number)
{
    for(int i=0; i<friendList.size(); i++)
	{
        if(friendList[i]==number){
            cout<<"该成员已经是你的好友"<<endl;
            return 0;
        }
    }
    friendList.push_back(number);
    cout<<"好友添加成功"<<endl;
    return 1;
}
int Account::no_output_add_friend(int number)
{
    friendList.push_back(number);
    return 1;
}
int Account::delete_friend(int number)
{
    for(int i=0 ; i<friendList.size(); i++)
	{
        if(friendList[i] == number)
		{
            friendList.erase(friendList.begin()+i);
            cout<<"好友删除成功"<<endl;
            return 1;
        }
    }
    return 0;
}
int Account::no_output_delete_friend(int number)
{
    for(int i=0 ; i<friendList.size(); i++)
	{
        if(friendList[i] == number)
		{
            friendList.erase(friendList.begin()+i);
            return 1;
        }
    }
    return 0;
}
int Account::enter_group(int groupNumber)
{
     for(int i=0; i<groupList.size(); i++)
	 {
        if(groupList[i] == groupNumber)
		{
            cout<<"已在 "<<groupNumber<<" 群中"<<endl;
            return 0;
        }
    }
    groupList.push_back(groupNumber);
    cout<<"入群成功"<<endl;
    return 1;
}
void Account::no_output_enter_group(int groupid)
{
    groupList.push_back(groupid);
}
int Account::exit_group(int groupNumber)
{
    for(int i=0 ; i<groupList.size(); i++)
	{
        if(groupList[i] == groupNumber)
		{
            groupList.erase(groupList.begin()+i);
            cout<<"已退群"<<endl;
            return 1;
        }
    }
    cout<<"退群失败（确认是否进入过该群）"<<endl;
    return 0;
}
int Account::no_output_exit_group(int groupNumber)
{
    for(int i=0 ; i<groupList.size(); i++)
	{
        if(groupList[i] == groupNumber)
		{
            groupList.erase(groupList.begin()+i);
            return 1;
        }
    }
    return 0;
}
void Account::change_infor()
{
    int ch,pid;
    string pname,pcity;
    cout<<"输入需要修改的编号："<<endl;
    cout<<"1.昵称"<<endl<<"2.所在城市"<<endl;
    cin>>ch;
    if(ch == 1)
	{
        cout<<"输入新昵称："<<endl;
        cin>>pname;
        name = pname;
    }
    if(ch == 2)
	{
        cout<<"输入新的所在城市："<<endl;
        cin>>pcity;
        city = pcity;
    }
}
void Account::set_id(int pid)
{
    id = pid;
}
void Account::set_name(string pname)
{
    name = pname;
}
void Account::set_birthday(int month,int day)
{
    birthday[0][0] = month;
    birthday[0][1] = day;
}
void Account::set_settime(int month,int day)
{
    setTime[0][0] = month;
    setTime[0][1] = day;
}
void Account::set_city(string pcity)
{
    city = pcity;
}
int Account::get_id()
{
    return id;
}
string Account::get_name()
{
    return name;
}
string Account::get_city()
{
    return city;
}
vector<int> Account::get_friendlist()
{
    return friendList;
}
vector<int> Account::get_grouplist()
{
    return groupList;
}
int Account::get_birthday_month()
{
    return birthday[0][0];
}
int Account::get_birthday_day()
{
    return birthday[0][1];
}
int Account::get_settime_month()
{
    return setTime[0][0];
}
int Account::get_settime_day()
{
    return setTime[0][1];
}
int Account::get_is_login()
{
    return isLogin;
}
//int Account::login(string str)
//{
//    if(str == password)
//        isLogin = 1;
//    else{
//        while(str != password)
//		{
//            cout<<"密码错误，请重新输入"<<endl;
//            //cin>>str;
//            inputPassword(str, 20); 
//        }
//        isLogin = 1;
//    }
//}
int Account::login(string str)
{
	string f;
    if(str == password)
        isLogin = 1;
    else{
        while(str != password)
		{
            cout<<"密码错误！"<<endl;
            cout<<"是否重新输入？[y/n]"<<endl;
            cin>>f;
            if(f=="y")
            {
            	inputPassword(str, 20);
			}
			else{
				break;
			}
            //cin>>str;
//            inputPassword(str, 20); 
        }
        return -1;
    }
}
void Account::set_password(string str)
{
    password = str;
}
string Account::get_password()
{
    return password;
}
void Account::no_output_login()
{
    isLogin = 1;
}

