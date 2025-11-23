#pragma once
#include"head.h"   
#include"QQAccount.h"
#include"QQGroup.h"
#include"WxAccount.h"
#include"QQClient.h"
#include"WxClient.h"
#include"WbClient.h"
QQClient QQClient1;
WxClient WeixinClient1;
WbClient WeiboClient1;

/*
函数声明 
*/
int str_ex_num(string);//string转化为int 
void recommend_friends(int);//推荐好友

void load();//加载数据文件 
void write();//数据存档 

int is_qq_id(int);//检测qqid是否存在 
int is_wx_id(int);//检测wxid是否存在 
int is_wb_id(int);//检测wbid是否存在 

int login_qq();//qq登录 
int login_wx();//wx登录 
int login_wb();//wb登录 

void qq_group_manage(int);//管理qq群聊 
void wx_group_manage(int);//管理wx群聊 

void menu_qq(int);//qq菜单
void menu_wx(int);//wx菜单
void menu_wb(int);//wb菜单

void sys();//系统主页面 
void select();//选择通讯软件 

void qq();//qq主页面 
void wb();//wb主页面 
void wx();//wx主页面 
