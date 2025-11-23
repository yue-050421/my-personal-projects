#include"fun.h" 

//函数入口 
int main()
{
    load();
    sys();
    write();
    return 0;
}

/*
数据读写 
*/
void load()
{
	/*
	read--wb
	*/
    int intTemp1,intTemp2;
    string str;
    ifstream infile;
    infile.open("weiBoClient.txt");
    if(!infile) cout<<"error"<<endl;
    getline(infile,str);
    WbAccount::weiboNumber = str_ex_num(str);
    intTemp1 = WbAccount::weiboNumber;
    WeiboClient1.initialise_weibo(WbAccount::weiboNumber);
    WbAccount::weiboNumber -= intTemp1;

    for(int i=0;i<WbAccount::weiboNumber;i++){
        getline(infile,str);
        intTemp1 = str_ex_num(str);
        WeiboClient1.wbClient[i].set_id(intTemp1);

        getline(infile,str);
        WeiboClient1.wbClient[i].set_password(str);

        getline(infile,str);
        WeiboClient1.wbClient[i].set_name(str);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        getline(infile,str);
        intTemp2 = str_ex_num(str);
        WeiboClient1.wbClient[i].set_birthday(intTemp1,intTemp2);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        getline(infile,str);
        intTemp2 = str_ex_num(str);
        WeiboClient1.wbClient[i].set_settime(intTemp1,intTemp2);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        WeiboClient1.wbClient[i].set_qq_id(intTemp1);

        getline(infile,str);
        WeiboClient1.wbClient[i].set_city(str);

        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            WeiboClient1.wbClient[i].no_output_add_friend(intTemp1);
            getline(infile,str);
        }

    }
    infile.close();
    
    /*
    read--wx
    */
    infile.open("weiXinClient.txt");
    if(!infile) cout<<"error"<<endl;
    getline(infile,str);
    WxAccount::weixinNumber = str_ex_num(str);
    intTemp1 = WxAccount::weixinNumber;
    WeixinClient1.initialise_weixin(WxAccount::weixinNumber);
    WxAccount::weixinNumber -= intTemp1;

    for(int i=0;i<WxAccount::weixinNumber;i++){
        getline(infile,str);
        intTemp1 = str_ex_num(str);
        WeixinClient1.weixinClient[i].set_id(intTemp1);

        getline(infile,str);
        WeixinClient1.weixinClient[i].set_password(str);

        getline(infile,str);
        WeixinClient1.weixinClient[i].set_name(str);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        getline(infile,str);
        intTemp2 = str_ex_num(str);
        WeixinClient1.weixinClient[i].set_birthday(intTemp1,intTemp2);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        getline(infile,str);
        intTemp2 = str_ex_num(str);
        WeixinClient1.weixinClient[i].set_settime(intTemp1,intTemp2);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        WeixinClient1.weixinClient[i].set_qq_id(intTemp1);

        getline(infile,str);
        WeixinClient1.weixinClient[i].set_city(str);

        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            WeixinClient1.weixinClient[i].no_output_add_friend(intTemp1);
            getline(infile,str);
        }
        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            WeixinClient1.weixinClient[i].no_output_enter_group(intTemp1);
            getline(infile,str);
        }

    }
    infile.close();
    
    /*
    read--qq
    */
    infile.open("qqClient.txt");
    if(!infile) cout<<"error"<<endl;
    getline(infile,str);
    QQAccount::qqNumber= str_ex_num(str);
    intTemp1 = QQAccount::qqNumber;
    QQClient1.initialise_QQ(QQAccount::qqNumber);
    QQAccount::qqNumber -= intTemp1;
    for(int i=0;i<QQAccount::qqNumber;i++){
        getline(infile,str);
        intTemp1 = str_ex_num(str);
        QQClient1.QQvector[i].set_id(intTemp1);

        getline(infile,str);
        QQClient1.QQvector[i].set_password(str);

        getline(infile,str);
        QQClient1.QQvector[i].set_name(str);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        getline(infile,str);
        intTemp2 = str_ex_num(str);
        QQClient1.QQvector[i].set_birthday(intTemp1,intTemp2);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        getline(infile,str);
        intTemp2 = str_ex_num(str);
        QQClient1.QQvector[i].set_settime(intTemp1,intTemp2);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        QQClient1.QQvector[i].set_weixin_id(intTemp1);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        QQClient1.QQvector[i].set_weibo_id(intTemp1);

        getline(infile,str);
        QQClient1.QQvector[i].set_city(str);

        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            QQClient1.QQvector[i].no_output_add_friend(intTemp1);
            getline(infile,str);
        }
        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            QQClient1.QQvector[i].no_output_enter_group(intTemp1);
            getline(infile,str);
        }

    }
    infile.close();
    /*
    read--group[wx]
    */
    infile.open("weiXinGroup.txt");
    if(!infile) cout<<"error"<<endl;
    getline(infile,str);
    WxGroup::weiXinGroupNumber= str_ex_num(str);
    intTemp1 = WxGroup::weiXinGroupNumber;
    WeixinClient1.initialise_weixin_group(WxGroup::weiXinGroupNumber);
    WxGroup::weiXinGroupNumber -= intTemp1;

    for(int i=0;i<WxGroup::weiXinGroupNumber;i++){
        getline(infile,str);
        intTemp1 = str_ex_num(str);
        WeixinClient1.weixinGroup[i].set_group_id(intTemp1);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        WeixinClient1.weixinGroup[i].set_groupowner_id(intTemp1);

        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            WeixinClient1.weixinGroup[i].no_output_add_member(intTemp1);
            getline(infile,str);
        }
    }infile.close();
    /*
    read--group[qq]
    */
    infile.open("qqGroup.txt");
    if(!infile) cout<<"error"<<endl;
    getline(infile,str);
    QQGroup::qqGroupNumber= str_ex_num(str);
    intTemp1 = QQGroup::qqGroupNumber;
    QQClient1.initialise_qq_group(QQGroup::qqGroupNumber);
    QQGroup::qqGroupNumber -= intTemp1;
    for(int i=0;i<QQGroup::qqGroupNumber;i++){
        getline(infile,str);
        intTemp1 = str_ex_num(str);
        QQClient1.QQgroup[i].set_group_id(intTemp1);

        getline(infile,str);
        intTemp1 = str_ex_num(str);
        QQClient1.QQgroup[i].set_groupowner_id(intTemp1);

        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            QQClient1.QQgroup[i].no_output_set_admin(intTemp1);
            getline(infile,str);
        }

        getline(infile,str);
        while(str != "*"){
            intTemp1 = str_ex_num(str);
            QQClient1.QQgroup[i].no_output_add_member(intTemp1);
            getline(infile,str);
        }
    }infile.close();

}
void write()
{
	/*
    write--wb
    */
    ofstream infile;
    infile.open("weiBoClient.txt",ios::out);
    infile<<WbAccount::weiboNumber<<endl;
    for(int i=0;i<WbAccount::weiboNumber;i++){
        infile<<WeiboClient1.wbClient[i].get_id()<<endl;
        infile<<WeiboClient1.wbClient[i].get_password()<<endl;
        infile<<WeiboClient1.wbClient[i].get_name()<<endl;
        infile<<WeiboClient1.wbClient[i].get_birthday_month()<<endl;
        infile<<WeiboClient1.wbClient[i].get_birthday_day()<<endl;
        infile<<WeiboClient1.wbClient[i].get_settime_month()<<endl;
        infile<<WeiboClient1.wbClient[i].get_settime_day()<<endl;
        infile<<WeiboClient1.wbClient[i].get_qq_id()<<endl;
        infile<<WeiboClient1.wbClient[i].get_city()<<endl;

        if(!WeiboClient1.wbClient[i].get_friendlist().empty()){
            for(int j=0;j<WeiboClient1.wbClient[i].get_friendlist().size();j++){
                infile<<WeiboClient1.wbClient[i].get_friendlist()[j]<<endl;
            }
        }
        infile<<"*"<<endl;
    }infile.close();
    
	/*
    write--wx
    */
    infile.open("weiXinClient.txt",ios::out);

    infile<<WxAccount::weixinNumber<<endl;
    for(int i=0;i<WxAccount::weixinNumber;i++){
        infile<<WeixinClient1.weixinClient[i].get_id()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_password()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_name()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_birthday_month()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_birthday_day()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_settime_month()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_settime_day()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_qq_id()<<endl;
        infile<<WeixinClient1.weixinClient[i].get_city()<<endl;

        for(int j=0;j<WeixinClient1.weixinClient[i].get_friendlist().size();j++){
            infile<<WeixinClient1.weixinClient[i].get_friendlist()[j]<<endl;
        }
        infile<<"*"<<endl;
        for(int j=0;j<WeixinClient1.weixinClient[i].get_grouplist().size();j++){
            infile<<WeixinClient1.weixinClient[i].get_grouplist()[j]<<endl;
        }
        infile<<"*"<<endl;
    }infile.close();
    /*
    write--qq
    */
    infile.open("qqClient.txt",ios::out);
    infile<<QQAccount::qqNumber<<endl;
    for(int i=0;i<QQAccount::qqNumber;i++){
        infile<<QQClient1.QQvector[i].get_id()<<endl;
        infile<<QQClient1.QQvector[i].get_password()<<endl;
        infile<<QQClient1.QQvector[i].get_name()<<endl;
        infile<<QQClient1.QQvector[i].get_birthday_month()<<endl;
        infile<<QQClient1.QQvector[i].get_birthday_day()<<endl;
        infile<<QQClient1.QQvector[i].get_settime_month()<<endl;
        infile<<QQClient1.QQvector[i].get_settime_day()<<endl;
        infile<<QQClient1.QQvector[i].get_weixin_id()<<endl;
        infile<<QQClient1.QQvector[i].get_weibo_id()<<endl;
        infile<<QQClient1.QQvector[i].get_city()<<endl;

        for(int j=0;j<QQClient1.QQvector[i].get_friendlist().size();j++){
            infile<<QQClient1.QQvector[i].get_friendlist()[j]<<endl;
        }
        infile<<"*"<<endl;
        for(int j=0;j<QQClient1.QQvector[i].get_grouplist().size();j++){
            infile<<QQClient1.QQvector[i].get_grouplist()[j]<<endl;
        }
        infile<<"*"<<endl;
    }infile.close();
    /*
    write--group[wx]
    */
    infile.open("weiXinGroup.txt",ios::out);
    infile<<WxGroup::weiXinGroupNumber<<endl;
    for(int i=0;i<WxGroup::weiXinGroupNumber;i++){
        infile<<WeixinClient1.weixinGroup[i].get_group_id()<<endl;
        infile<<WeixinClient1.weixinGroup[i].get_group_owner_id()<<endl;
        for(int j=0;j<WeixinClient1.weixinGroup[i].get_member_id().size();j++){
            infile<<WeixinClient1.weixinGroup[i].get_member_id()[j]<<endl;
        }
        infile<<"*"<<endl;
    }infile.close();
    /*
    write--group[qq]
    */
    QQGroup::qqGroupNumber-=QQGroup::sonGroupNumber;
    infile.open("qqGroup.txt",ios::out);
    infile<<QQGroup::qqGroupNumber<<endl;
    for(int i=0;i<QQGroup::qqGroupNumber;i++){
        if(QQClient1.QQgroup[i].get_father_group_id()!=0){
            i--;
            continue;
        }
        infile<<QQClient1.QQgroup[i].get_group_id()<<endl;
        infile<<QQClient1.QQgroup[i].get_group_owner_id()<<endl;

        for(int j=0;j<QQClient1.QQgroup[i].get_admin_id().size();j++){
            infile<<QQClient1.QQgroup[i].get_admin_id()[j]<<endl;
        }
        infile<<"*"<<endl;

        for(int j=0;j<QQClient1.QQgroup[i].get_member_id().size();j++){
            infile<<QQClient1.QQgroup[i].get_member_id()[j]<<endl;
        }
        infile<<"*"<<endl;
    }infile.close();
}

/*
检测id存在性 
*/
int is_qq_id(int id)
{
    for(int i=0;i<QQClient1.QQvector.size();i++){
        if(id == QQClient1.QQvector[i].get_id())
            return i;
    }
    return -1;
}
int is_wx_id(int id)
{
    for(int i=0;i<WeixinClient1.weixinClient.size();i++){
        if(id == WeixinClient1.weixinClient[i].get_id())
            return i;
    }
    return -1;
}
int is_wb_id(int id)
{
    for(int i=0;i<WeiboClient1.wbClient.size();i++){
        if(id == WeiboClient1.wbClient[i].get_id())
            return i;
    }
    return -1;
}

/*
登录 
*/
int login_qq()
{
    string password;
    int QQtemp,weixinTemp,weiboTemp,number;
    cout<<"输入QQ账号："<<endl;
    cin>>number;
    QQtemp = is_qq_id(number);
    if(QQtemp != -1){
        //cout<<"输入密码："<<endl;
        inputPassword(password, 20); 
        //cin>>password;
        
        if(QQClient1.QQvector[QQtemp].login(password)==-1){
        	qq();
		}
		else{
			QQClient1.QQvector[QQtemp].login(password);
		}
    }
    else{
        cout<<"该账号不存在"<<endl;
        login_qq();
    }
    weixinTemp = is_wx_id(QQClient1.QQvector[QQtemp].get_weixin_id());
    if(weixinTemp != -1){
        WeixinClient1.weixinClient[weixinTemp].no_output_login();
    }
    weiboTemp = is_wb_id(QQClient1.QQvector[QQtemp].get_weibo_id());
    if(weiboTemp != -1){
        WeiboClient1.wbClient[weiboTemp].no_output_login();
    }
    return QQtemp;
}
int login_wx(){
    string password;
    int QQtemp,weixinTemp,weiboTemp,number;
    cout<<"输入微信账号："<<endl;
    cin>>number;
    weixinTemp = is_wx_id(number);
    if(weixinTemp != -1){
        //cout<<"输入密码："<<endl;
        //cin>>password;
        inputPassword(password, 20); 
//        WeixinClient1.weixinClient[weixinTemp].login(password);
        if(WeixinClient1.weixinClient[weixinTemp].login(password)==-1){
        	wx();
		}
		else{
			WeixinClient1.weixinClient[weixinTemp].login(password);
		}
    }
    else{
        cout<<"该账号不存在"<<endl;
        login_wx();
    }
    QQtemp = is_qq_id(WeixinClient1.weixinClient[weixinTemp].get_qq_id());
    if(QQtemp != -1){
        QQClient1.QQvector[QQtemp].no_output_login();
    }
    weiboTemp = is_wb_id(QQClient1.QQvector[QQtemp].get_weibo_id());
    if(weiboTemp != -1){
        WeiboClient1.wbClient[weiboTemp].no_output_login();
    }
    return weixinTemp;
}
int login_wb(){
    string password;
    int QQtemp,weixinTemp,weiboTemp,number;
    cout<<"输入微博账号："<<endl;
    cin>>number;
    weiboTemp = is_wb_id(number);
    if(weiboTemp != -1){
        //cout<<"输入密码："<<endl;
        //cin>>password;
        inputPassword(password, 20); 
//        WeiboClient1.wbClient[weiboTemp].login(password);
        if(WeiboClient1.wbClient[weiboTemp].login(password)==-1){
        	wb();
		}
		else{
			WeiboClient1.wbClient[weiboTemp].login(password);
		}
    }
    else{
        cout<<"该账号不存在"<<endl;
        login_wb();
    }
    QQtemp = is_qq_id(WeiboClient1.wbClient[weiboTemp].get_qq_id());
    if(QQtemp != -1){
        QQClient1.QQvector[QQtemp].no_output_login();
    }
    weixinTemp = is_wx_id(QQClient1.QQvector[QQtemp].get_weixin_id());
    if(weixinTemp != -1){
        WeixinClient1.weixinClient[weixinTemp].no_output_login();
    }
    return weiboTemp;
}

/*
群聊管理 
*/
void qq_group_manage(int site){
    int flag,choose,number,temp;
    flag = 0;
    cout<<"管理的群："<<endl;
    for(int i=0;i<QQClient1.QQgroup.size();i++){
        for(int j=0;j<QQClient1.QQgroup[i].get_admin_id().size();j++){
            if(QQClient1.QQgroup[i].get_admin_id()[j] == QQClient1.QQvector[site].get_id()){
                cout<<QQClient1.QQgroup[i].get_group_id()<<endl;
                flag = 1;
            }
        }
    }
    if(!flag){
        cout<<"你不是任何群的管理员"<<endl;
    }
    else{
        cout<<"输入要进行操作的群："<<endl;
        cin>>number;
        for(int i=0;i<QQClient1.QQgroup.size();i++){
            if(QQClient1.QQgroup[i].get_group_id() == number){
                cout<<"输入操作："<<endl;
                cout<<"1.踢人出群"<<endl;
                cout<<"2.拉人进群"<<endl;
                cout<<"3.设置他人为管理员"<<endl;
                cout<<"4.取消他人的管理员身份"<<endl;
                cout<<"5.创建临时讨论组（讨论组不会保存到文件）："<<endl;
                cout<<"6.查看由该群创建的临时讨论组"<<endl;
                cin>>choose;
                if(choose == 1){
                    cout<<"根据下列群组信息踢人"<<endl;
                    QQClient1.QQgroup[i].show_group_infor();
                    temp=QQClient1.QQgroup[i].delete_member();
                    for(int k=0;k<QQClient1.QQvector.size();k++){
                        if(QQClient1.QQvector[k].get_id()==temp){
                            QQClient1.QQvector[k].no_output_exit_group(QQClient1.QQgroup[i].get_group_id());
                        }
                    }

                }
                if(choose == 2){
                    cout<<"根据下列群组信息拉人"<<endl;
                    QQClient1.QQgroup[i].show_group_infor();
                    temp = QQClient1.QQgroup[i].add_member();
                    for(int k=0;k<QQClient1.QQvector.size();k++){
                        if(QQClient1.QQvector[k].get_id()==temp){
                            QQClient1.QQvector[k].no_output_enter_group(QQClient1.QQgroup[i].get_group_id());
                        }
                    }
                }
                if(choose == 3){
                    cout<<"根据下列群组信息设置管理员"<<endl;
                    QQClient1.QQgroup[i].show_group_infor();
                    QQClient1.QQgroup[i].set_admin();
                }
                if(choose == 4){
                    cout<<"根据下列群组信息取消管理员"<<endl;
                    QQClient1.QQgroup[i].show_group_infor();
                    QQClient1.QQgroup[i].delete_admin();
                }
                if(choose == 5){
                    cout<<"根据下列群组信息创建临时讨论组"<<endl;
                    QQClient1.QQgroup[i].show_group_infor();
                    QQClient1.set_son_group(QQClient1.QQgroup[i].get_group_id());
                }
                if(choose == 6){
                    QQClient1.show_son_group_infor(QQClient1.QQgroup[i].get_group_id());
                }
            }
        }
    }
}
void wx_group_manage(int site){
    int flag,choose,number,temp;
    flag = 0;bool ff = false;
    cout<<"管理的群："<<endl;
    for(int i=0;i<WeixinClient1.weixinGroup.size();i++){
        if(WeixinClient1.weixinGroup[i].get_groupowner_id() == WeixinClient1.weixinClient[site].get_id()){
        	//是群主 
            cout<<WeixinClient1.weixinGroup[i].get_group_id()<<endl;
            flag = 1;
        }
    }
    if(!flag){
        cout<<"你不是任何群的管理员"<<endl;
    }
    else{
        cout<<"输入要进行操作的群："<<endl;
        cin>>number;
        for(int i=0;i<WeixinClient1.weixinGroup.size();i++){
            if(WeixinClient1.weixinGroup[i].get_group_id() == number){
            	for (int ii : WeixinClient1.weixinGroup[i].get_member_id()) {
				        if (ii == WeixinClient1.weixinClient[site].get_id()) {
				            ff = true;
				            break;  //一旦找到就停止遍历
				        }
				    }
            	if(WeixinClient1.weixinGroup[i].get_groupowner_id() == WeixinClient1.weixinClient[site].get_id()){
            	//有这个群  and 是群主
                cout<<"输入操作："<<endl;
                cout<<"1.踢人出群"<<endl;
                cout<<"2.拉人进群"<<endl;
                cout<<"3.查看群信息"<<endl;
                cin>>choose;
                if(choose == 1){
                    cout<<"根据下列群组信息踢人"<<endl;
                    WeixinClient1.weixinGroup[i].show_group_infor();
                    temp=WeixinClient1.weixinGroup[i].delete_member();
                    for(int k=0;k<WeixinClient1.weixinClient.size();k++){
                        if(WeixinClient1.weixinClient[k].get_id()==temp){
                            WeixinClient1.weixinClient[k].no_output_exit_group(WeixinClient1.weixinGroup[i].get_group_id());
                        }
                    }
                }
                if(choose == 2){
                    cout<<"根据下列群组信息拉人"<<endl;
                    WeixinClient1.weixinGroup[i].show_group_infor();
                    temp = WeixinClient1.weixinGroup[i].add_member();
                    for(int k=0;k<WeixinClient1.weixinClient.size();k++){
                        if(WeixinClient1.weixinClient[k].get_id()==temp){
                            WeixinClient1.weixinClient[k].no_output_enter_group(WeixinClient1.weixinGroup[i].get_group_id());
                        }
                    }
                }
                if(choose == 3){
                    WeixinClient1.weixinGroup[i].show_group_infor();
                }
                
                return;
				}
				
				

            	else if(ff){
            	//有这个群  and 是群成员
                cout<<"输入操作："<<endl;
                cout<<"1.拉人进群"<<endl;
                cout<<"2.查看群信息"<<endl;
                cin>>choose;
                if(choose == 1){
                    cout<<"根据下列群组信息拉人"<<endl;
                    WeixinClient1.weixinGroup[i].show_group_infor();
                    temp = WeixinClient1.weixinGroup[i].add_member();
                    for(int k=0;k<WeixinClient1.weixinClient.size();k++){
                        if(WeixinClient1.weixinClient[k].get_id()==temp){
                            WeixinClient1.weixinClient[k].no_output_enter_group(WeixinClient1.weixinGroup[i].get_group_id());
                        }
                    }
                }
                if(choose == 2){
                    WeixinClient1.weixinGroup[i].show_group_infor();
                }
                return;
            }
            }
            
            
        }
    }
}

/*
推荐好友 
*/
void recommend_friends(int site) { 
    int weixinSite, weiboSite, flag, number;
    if (QQClient1.QQvector[site].get_weixin_id() == 0) {
        cout << "该用户未绑定微信" << endl;
    } else {
        flag = 0;
        cout << "微信中可添加的推荐好友：" << endl;
        weixinSite = is_wx_id(QQClient1.QQvector[site].get_weixin_id());
        for (int i = 0; i < WeixinClient1.weixinClient[weixinSite].get_friendlist().size(); i++) {
            bool isRecommended = true; 
            for (int j = 0; j < QQClient1.QQvector[site].get_friendlist().size(); j++) {
                if (WeixinClient1.weixinClient[is_wx_id(WeixinClient1.weixinClient[weixinSite].get_friendlist()[i])].get_qq_id() == QQClient1.QQvector[site].get_friendlist()[j]) {
                    isRecommended = false;
                    break;
                }
            }
            if (isRecommended) {
                cout << WeixinClient1.weixinClient[is_wx_id(WeixinClient1.weixinClient[weixinSite].get_friendlist()[i])].get_qq_id() << endl;
                flag = 1;
            }
        }
        if (!flag) {
            cout << "微信中没有推荐好友" << endl;
        } else {
            cout << "根据以上信息添加推荐好友" << endl;
            number = QQClient1.QQvector[site].get_id();
            QQClient1.add_friend(number); 
        }
    }

    if (QQClient1.QQvector[site].get_weibo_id() == 0) {
        cout << "该用户未绑定微博" << endl;
    } else {
        flag = 0;
        cout << "微博中可添加的推荐好友：" << endl;

        weiboSite = is_wb_id(QQClient1.QQvector[site].get_weibo_id());
        for (int i = 0; i < WeiboClient1.wbClient[weiboSite].get_friendlist().size(); i++) {
            bool isRecommended = true; 

            for (int j = 0; j < QQClient1.QQvector[site].get_friendlist().size(); j++) {
                if (WeiboClient1.wbClient[is_wb_id(WeiboClient1.wbClient[weiboSite].get_friendlist()[i])].get_qq_id() == QQClient1.QQvector[site].get_friendlist()[j]) {
                    isRecommended = false;
                    break;
                }
            }
            if (isRecommended) {
                cout << WeiboClient1.wbClient[is_wb_id(WeiboClient1.wbClient[weiboSite].get_friendlist()[i])].get_qq_id() << endl;
                flag = 1;
            }
        }
        if (!flag) {
            cout << "微博中没有可添加的推荐好友" << endl;
        } else {
            cout << "根据以上信息添加推荐好友" << endl;
            QQClient1.add_friend(QQClient1.QQvector[site].get_id()); 
        }
    }
}


/*
菜单 
*/
void menu_qq(int site){
    int choose=0;
    int number;
    int temp,flag;
    cout<<"输入操作："<<endl;
    cout<<"1.查看个人信息"<<endl;
    cout<<"2.修改个人信息"<<endl;
    cout<<"3.建群"<<endl;//
    cout<<"4.对管理的群进行操作"<<endl;
    cout<<"5.添加好友"<<endl;
    cout<<"6.删除好友"<<endl;
    cout<<"7.加群"<<endl;
    cout<<"8.退群"<<endl;
    cout<<"9.添加微信和微博的推荐好友"<<endl;
    cout<<"10.创建微博并绑定"<<endl;
    cout<<"11.创建微信并绑定"<<endl;
    cout<<"0.返回"<<endl;
    cin>>choose;
    if(choose == 1){
        QQClient1.QQvector[site].show_infor();
        menu_qq(site);
        return;
    }
    if(choose == 2){
        QQClient1.QQvector[site].change_infor();
        menu_qq(site);
        return;
    }
    if(choose == 3){
        QQClient1.set_new_QQ_group(QQClient1.QQvector[site].get_id());
        menu_qq(site);
        return;
    }
    if(choose == 4){
        qq_group_manage(site);
        menu_qq(site);
        return;
    }
    if(choose == 5){
        QQClient1.add_friend(QQClient1.QQvector[site].get_id());
        menu_qq(site);
        return;
    }
    if(choose == 6){
        QQClient1.delete_friend(QQClient1.QQvector[site].get_id());
        menu_qq(site);
        return;
    }
    if(choose == 7){
        QQClient1.enter_group(QQClient1.QQvector[site].get_id());
        menu_qq(site);
        return;
    }
    if(choose == 8){
    	for(int i=0;i<QQClient1.QQgroup.size();i++){
        if(QQClient1.QQgroup[i].get_groupowner_id() == QQClient1.QQvector[site].get_id()){
        	//是群主 
            cout<<"群主不得退群！"<<endl;system("pause");
        system("cls");menu_qq(site);
        }
		}
        QQClient1.exit_group(QQClient1.QQvector[site].get_id());
        menu_qq(site);
        return;
    }
    if(choose == 9){
        recommend_friends(site);
        menu_qq(site);
        return;
    }
    if(choose == 10){
        if(QQClient1.QQvector[site].get_weibo_id() != 0){
            cout<<"你已绑定微博"<<endl;
        }
        else{
            WbAccount newWeibo;
            newWeibo.set_weibo();
            newWeibo.set_id(QQClient1.QQvector[site].get_id());
            newWeibo.set_qq_id(QQClient1.QQvector[site].get_id());
            WeiboClient1.wbClient.push_back(newWeibo);
            QQClient1.QQvector[site].set_weibo_id(newWeibo.get_id());
        }
        menu_qq(site);
        return;
    }
    if(choose == 11){
        if(QQClient1.QQvector[site].get_weixin_id() != 0){
            cout<<"你已绑定微信"<<endl;
        }
        else{
            WxAccount newWeixin;
            newWeixin.set_weixin();
            newWeixin.set_qq_id(QQClient1.QQvector[site].get_id());
            WeixinClient1.weixinClient.push_back(newWeixin);
            QQClient1.QQvector[site].set_weixin_id(newWeixin.get_id());
        }
        menu_qq(site);
        return;
    }
    if(choose == 0){
        qq();
        return;
    }
    else{
        cout<<"输入有误"<<endl;
        menu_qq(site);
        return;
    }
}
void menu_wx(int site){
    int choose=0;
    int number;
    int temp,flag;
    cout<<"输入操作："<<endl;
    cout<<"1.查看个人信息"<<endl;
    cout<<"2.修改个人信息"<<endl;
    cout<<"3.建群"<<endl;
    cout<<"4.对创建的群进行操作"<<endl;
    cout<<"5.添加好友"<<endl;
    cout<<"6.删除好友"<<endl;
    cout<<"7.退群"<<endl;
    cout<<"8.创建QQ并绑定"<<endl;
    cout<<"0.返回"<<endl;
    cin>>choose;
    if(choose == 1){
        WeixinClient1.weixinClient[site].show_infor();
        menu_wx(site);
        return;
    }
    if(choose == 2){
        WeixinClient1.weixinClient[site].change_infor();
        menu_wx(site);
        return;
    }
    if(choose == 3){
        WeixinClient1.set_new_weixin_group(WeixinClient1.weixinClient[site].get_id());
        menu_wx(site);
        return;
    }
    if(choose == 4){
        wx_group_manage(site);
        menu_wx(site);
        return;
    }
    if(choose == 5){
        WeixinClient1.add_friend(WeixinClient1.weixinClient[site].get_id());
        menu_wx(site);
        return;
    }
    if(choose == 6){
        WeixinClient1.delete_friend(WeixinClient1.weixinClient[site].get_id());
        menu_wx(site);
        return;
    }
    if(choose == 7){
    	for(int i=0;i<WeixinClient1.weixinGroup.size();i++){
        if(WeixinClient1.weixinGroup[i].get_groupowner_id() == WeixinClient1.weixinClient[site].get_id()){
        	//是群主 
            cout<<"群主不得退群！"<<endl;system("pause");
        system("cls");menu_wx(site);
        }
		}
        WeixinClient1.exit_group(WeixinClient1.weixinClient[site].get_id());
        menu_wx(site);
        return;
    }
    if(choose == 8){
        if(WeixinClient1.weixinClient[site].get_qq_id() != 0){
            cout<<"你已绑定QQ，不可重复创建"<<endl;
        }
        else{
            QQAccount newQQ;
            newQQ.set_QQ();
            newQQ.set_weixin_id(WeixinClient1.weixinClient[site].get_id());
            QQClient1.QQvector.push_back(newQQ);
            WeixinClient1.weixinClient[site].set_qq_id(newQQ.get_id());
        }
        menu_wx(site);
        return;
    }
    if(choose == 0){
        return;
    }
    else{
        cout<<"输入有误"<<endl;
        menu_wx(site);
        return;
    }
}
void menu_wb(int site){
    int choose=0;
    int number;
    int temp,flag;
    cout<<"输入操作："<<endl;
    cout<<"1.查看个人信息"<<endl;
    cout<<"2.修改个人信息"<<endl;
    cout<<"3.添加好友"<<endl;
    cout<<"4.删除好友"<<endl;
    cout<<"0.返回"<<endl;
    cin>>choose;
    if(choose == 1){
        WeiboClient1.wbClient[site].show_infor();
        menu_wb(site);
        return;
    }
    if(choose == 2){
        WeiboClient1.wbClient[site].change_infor();
        menu_wb(site);
        return;
    }
    if(choose == 3){
        WeiboClient1.add_friend(WeiboClient1.wbClient[site].get_id());
        menu_wb(site);
        return;
    }
    if(choose == 4){
        WeiboClient1.delete_friend(WeiboClient1.wbClient[site].get_id());
        menu_wb(site);
        return;
    }
    if(choose == 0){
        return;
    }
    else{
        cout<<"输入有误"<<endl;
        menu_wb(site);
        return;
    }
}

/*
主界面 
*/
void qq(){
    int choose=0;
    int number;
    int temp;
    string password;
    system("cls");
    cout<<"\n************QQ************"<<endl;
    cout<<"\n\t1.登陆"<<endl;
    cout<<"\n\t2.注册"<<endl;
    cout<<"\n\t3.输出所有已创建的QQ信息"<<endl;
    cout<<"\n\t0.返回"<<endl;
    cout<<"\n输入选择：";
    cin>>choose;
    if(choose == 1){
        menu_qq(login_qq());
        system("pause");
        system("cls");
        return;
    }
    if(choose == 2){
    	int nn;
        cout<<"输入QQid:"<<endl;cin>>nn;
	    if(is_qq_id(nn) != -1){
	    	cout<<"QQid已存在"<<endl;
	    	system("pause");
        system("cls");
	    	qq();
	    }
        QQClient1.set_new_QQ_account(nn);
        system("pause");
        qq();
        return;
    }
    if(choose == 3){
        for(int i=0;i<QQClient1.QQvector.size();i++){
            QQClient1.QQvector[i].show_infor();
        }
        system("pause");
        system("cls");
        qq();
        return;
    }
    if(choose == 0){
    	write();
        select();
        return;
    }
    else{
        system("pause");
        qq();
        return;
    }
}
void wb(){
    int choose=0;
    int number;
    int temp;
    int flag = 0;
    string password;
    system("cls");
    cout<<"\n************微博************"<<endl;
    cout<<"\n\t1.登陆"<<endl;
    cout<<"\n\t2.输出所有已创建的微博信息"<<endl;
    cout<<"\n\t0.返回"<<endl;
    cout<<"\n输入选择：";
    cin>>choose;
    if(choose == 1){
        menu_wb(login_wb());
        wb();
        return;
    }
    if(choose == 2){
        for(int i=0;i<WeiboClient1.wbClient.size();i++){
            WeiboClient1.wbClient[i].show_infor();
        }
        system("pause");
        system("cls");
        wb();
        return;
    }
    if(choose == 0){
    	write();
        select();
        return;
    }
    else{
        system("cls");
        wb();
        return;
    }
}
void wx(){
    int choose=0;
    int number;
    int temp;
    int flag=0;
    string password;
    system("cls");
    cout<<"\n************微信************"<<endl;
    cout<<"\n\t1.登陆"<<endl;
    cout<<"\n\t2.注册"<<endl;
    cout<<"\n\t3.输出所有已创建的微信信息"<<endl;
    cout<<"\n\t0.返回"<<endl;
    cout<<"\n输入选择：";
    cin>>choose;
    if(choose == 1){
        menu_wx(login_wx());
        wx();
        return;
    }
    if(choose == 2){
    	int nn;
        cout<<"输入微信id:"<<endl;cin>>nn;
	    if(is_wx_id(nn) != -1){
	    	cout<<"微信id已存在"<<endl;
	    	system("pause");
        system("cls");
	    	wx();
	    }
    	
        WeixinClient1.set_new_weixin_account(nn);
        wx();
        return;
    }
    if(choose == 3){
        for(int i=0;i<WeixinClient1.weixinClient.size();i++){
            WeixinClient1.weixinClient[i].show_infor();
        }
        system("pause");
        system("cls");
        wx();
        return;
    }
    if(choose == 0){
    	write();
        select();
        return;
    }
    else{
        system("cls");
        wx();
        return;
    }
}
void sys(){
    system("cls");      
    int choose=0;
	cout<<"\n************模拟即时通信系统************"<<endl;
    cout<<"\n\t\t1.进入系统"<<endl;
    cout<<"\n\t\t0.退出"<<endl;
    cout<<"\n输入选择：";
    cin>>choose;
    if(choose>=0&&choose<=2){
        system("cls");
        if(choose == 1){
            select();
            return;
        }
        if(choose == 0)
            exit(0);
    }
    else{
        system("cls");
        sys();
        return;
	}
}
void select(){
    int choose;
    system("cls");
    cout<<"\n1.QQ"<<endl;
    cout<<"\n2.微信"<<endl;
    cout<<"\n3.微博"<<endl;
    cout<<"\n0.返回"<<endl;
    cout<<"\n输入选择：";
    cin>>choose;
    if(choose>=0&&choose<=3){
        if(choose == 1){
            qq();
            return;
        }
        if(choose == 2){
            wx();
            return;
        }
        if(choose == 3){
            wb();
            return;
        }
        if(choose == 0){
        	write();
            sys();
            return;
        }
    }
    else{
        system("cls");
        select();
        return;
	}
}

//string转化为int 
int str_ex_num(string s){
    int num;
    stringstream ss(s);
    ss >> num;
    return num;
}
