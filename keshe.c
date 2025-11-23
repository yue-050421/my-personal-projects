#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>


#define NAME_SIZE 50
#define NUM_SIZE 20
#define CAMPUS_SIZE 100
#define EPOCHS 10000 //循环次数 ，10000轮循环 
#define ALPHA 0.02 // 学习率
#define error_test 100
double x[10];
double y[10];


//某学生成绩结构体
typedef struct chengji
{
	int xueqi;              //修读学期
	int xuefen;             //学分
	char xueke[50];         //学科名
	float chengji;          //成绩
	float jidian;           //绩点
	struct chengji* next;
}chengji;


//学生结构体（包括学生信息和具体成绩）
typedef struct student
{
	char name[50];              //姓名
	char sex[10];               //性别
	char num[20];               //学号
	char major[100];            //学院
	int semester;               //学年
	char school_district[100];  //校区
	float grade;                //综合分数
	float GPA;                  //综合绩点
	int ranking;                //排名
	char role_code[10];         //密码
	int credit;                 //已修学分
	chengji* head;              //成绩头结点
	struct student* next;
}Student;


//某学科结构体（包括学生姓名、学号、成绩、绩点、名次）
typedef struct class {
	char xuehao[20];           //学号
	char Name[50];             //姓名
	float Chengji;             //成绩
	float Jidian;              //绩点
	int paiming;               //排名
	struct class* next;
}xueke;


//老师/教务处结构体
typedef struct Teacher
{
	char T_name[50];        //名字
	char T_num[20];        //账号
	char T_key[20];         //密码
	struct Teacher* next;   //连接链表节点的指针
}Teacher;


//学生论文结构体
typedef struct Paper
{
	char Paper_student_number[50];//学生学号
	char Paper_writer[50];//论文作者
	char Paper_name[50];//论文名称/期刊名称/会议名称
	char Paper_time[50];//发表时间
	char Paper_page[50];//卷/期/论文号/页码范围
	char Paper_level[50];//论文级别信息
	char Paper_points[50];//加分信息
	struct Paper* next;//连接链表节点的指针
}Paper;


//学生项目结构体
typedef struct Project
{
	char Project_student_number[50];//学生学号
	char Project_writer[50];//项目成员
	char Project_teacher_name[50];//指导教师
	char Project_name[50];//项目名称
	int Project_number[50];//项目编号
	char Project_start_time[50];//立项时间
	char Project_end_time[50];//结项时间
	char Project_status[50];//在项目中是否为负责人或第二名
	struct Project* next;//连接链表的指针
}Project;


//学生竞赛结构体
typedef struct Awards
{
	char Awards_student_number[50];//学生学号
	char Award_project_name[50];//竞赛项目名称
	char Award_unit[50];//主办单位
	char Award_name[50];//获奖人
	char Award_level[50];//获奖等级
	char Award_time[50];//获奖时间
	struct Awards* next;//连接链表的指针
}Awards;


// 定义线性回归模型参数
typedef struct LinearRegression {
	double theta0;
	double theta1;
} LinearRegression;


//所有函数声明

//含
void login(void);
void teacher_login(void);
void dean_office_login(void);
void student_login(void);
void teacher_interface(Teacher* head, Teacher* p);
void dean_office_interface(void);
void student_interface(Student* head, Student* p);
Teacher* T_build(void);
Teacher* D_build(void);
void print(Teacher* head);
void teacher_modifyTea(void);
void teacher_modifyKey(Teacher* head, Teacher* p);
void student_modifyKey(Student* head, Student* p);
void student_addStu(Student* top);
void student_deleteStu(Student* top);
void student_modifyStu(Student* top);
void student_transferMajor(Student* top);
void student_rebuild(Student* top);
void student_degrade(Student* top);
void student_inquiry(Student* head, Student* tmp);
int knotNumber(Teacher* head);
int sknotNumber(Student* head);
int cknotNumber(chengji* head);
void graduate_recommendation_ranking(Student* top);
void graduate_abroad_ranking(Student* top);
void teacher_delete(void);
void teacher_add(void);
void student_addinform(Student* top);
void student_addinform_hand(Student* top);
void student_addinform_file(Student* top);
void student_addgrade(Student* top);
void student_addgrade_hand(Student* top);
void student_addgrade_file(Student* top);
void student_inquiry_total(Student* head, Student* tmp);
void student_inquiry_detail(Student* head, Student* tmp);
void student_queryStu(Student* top);
void statisticsSubject(Teacher* head, Teacher* p);
void student_quality_education(Student* head, Student* tmp);
void student_paper(Student* top, Student* tmp);
void student_project(Student* top, Student* tmp);
void student_awards(Student* top, Student* tmp);
void withdraw(void);

//燕
Student* student_creat(void);
Student* GPA(Student* top);
void chengji_print_S(chengji* top);
void student_print_S(Student* top);
Student* PJGPA(Student* top);
void jiemian(char ch[20], int xueqi);
xueke* xueke_creat(Student* top);
xueke* sort(xueke* top);
xueke* PM(xueke* h);
void print_S(xueke* head);
float pingjunfen(xueke* head);
float pingjunjidian(xueke* head);
float jigelv(xueke* head);
float zuigaofen(xueke* head);
Student* jiafen(Student* top);
Student* not_write_jiafen(Student* top);

//悦
Paper* Paper_build(void);
Project* Project_build(void);
Awards* Awards_build(void);
void Service(void);
void Find(void);
void Add(void);
void Modify(void);
void Student_find(void);
void single_find(void);
void Paper_Find_way(void);
void Awards_Find_way(void);
void Project_Find_way(void);
void single_project_student_find(void);
void single_awards_student_find(void);
void single_paper_student_find(void);
void Name_find_paper(void);
void Level_find_paper(void);
void Name_find_project(void);
void Level_find_project(void);
void Name_find_awards(void);
void Level_find_awards(void);
void Add_Paper(void);
void Add_Awards(void);
void Add_Project(void);
void Modify_Paper(void);
void Modify_Awards(void);
void Modify_Project(void);
void print_awards(Awards* head);
void print_project(Project* head);
void Print_project(Project* head);
void print_paper(Paper* head);
void error_find(void);
void Find_error(void);
void After_student_find(void);
void After_single_find(void);
void After_Add_Paper(void);
void After_Add_project(void);
void After_Add_awards(void);
void After_Modify_Paper(void);
void After_Modify_project(void);
void After_Modify_Awards(void);
void Error_student_number_paper(void);

//凡
void student_single_query(Student* top);
void student_prediction(Student* top);
void gradient(double* x, double* y, int size, LinearRegression* lr);
double predict(double x, LinearRegression lr);
void student_grade_query(Teacher* head, Teacher* p);
void student_single_prediction(Student* head, Student* p);
void student_ranking(Student* top);
void sort_choice_year(void);
void sort_choice_way(void);
Student* sort_grade_up(Student* top, char x[3], int y);
Student* sort_grade_down(Student* top, char x[3], int y);
Student* sort_GPA_up(Student* top, char x[3], int y);
void sort_print(Student* head, char str[5], int semester1);
Student* sort_GPA_down(Student* head, char x[3], int y);
Student* sort_num_down(Student* head, char x[3], int y);
Student* sort_num_up(Student* head, char x[3], int y);
Student* full_ranking1(Student* head, char x[3], int y);
Student* full_ranking2(Student* top);


//函数---创建学生链表
Student* student_creat(void)
{

	Student* top = (Student*)malloc(sizeof(Student));
	top->next = NULL;

	FILE* fp = NULL;
	fp = fopen("student_information.txt", "r+");

	if (fp == NULL)
	{
		printf("FILE NOT FOUNG");
		exit(-1);
	}
	Student* last = top;
	while (1)
	{
		Student* tmp = (Student*)malloc(sizeof(Student));
		if (!tmp)
			exit(-1);
		if (11 != fscanf(fp, "%s%s%s%s%d%s%f%f%d%s%d", tmp->name, tmp->sex, tmp->num, tmp->major, &tmp->semester, tmp->school_district, &tmp->grade, &tmp->GPA, &tmp->ranking, tmp->role_code, &tmp->credit))
		{
			free(tmp);
			break;
		}                                                     //fscanf返回值不是11即为数据读完，录入完毕，释放空间，退出循环

		tmp->head = (chengji*)malloc(sizeof(chengji));
		tmp->head->next = NULL;
		chengji* tail = tmp->head;

		while (1)
		{

			chengji* p = (chengji*)malloc(sizeof(chengji));
			if (!p)
				exit(-1);

			if (5 != fscanf(fp, "%d%d%s%f%f", &p->xueqi, &p->xuefen, p->xueke, &p->chengji, &p->jidian))
			{
				free(p);
				break;
			}
			tail->next = p;                                    //新的链表尾
			tail = p;                                          //更新链表尾
			tail->next = NULL;
		}

		last->next = tmp;                                    //新的链表尾
		last = tmp;                                          //更新链表尾
		last->next = NULL;                                   //最后一个结点指向空
	}
	fclose(fp);
	top = GPA(top);                                               //填入每个科目的GPA
	top = PJGPA(top);                                             //计算平均GPA以及平均成绩并填入链表
	top = jiafen(top);                                            //计算素质类项目加分
	top = full_ranking2(top);                                   //计算排名
	return top;
}


//函数---创建学生论文链表
Paper* Paper_build(void)
{
	Paper* head = (Paper*)malloc(sizeof(Paper));     //链表头结点
	head->next = NULL;
	FILE* fp = NULL;
	fp = fopen("paper.txt", "r+");           //以读的方式打开文件paper
	if (fp == NULL)
	{
		printf("FILE NOT FOUND");
		exit(-1);
	}                                                      //如果没有文件，则退出并显示未找到文件

	Paper* cur = head;                                   //尾结点

	while (1)                                              //循环读入所有数据并依次存于链表
	{
		Paper* tmp = (Paper*)malloc(sizeof(Paper));  //进行操作的临时结点
		if (!tmp)
			exit(-1);

		if (7 != fscanf(fp, "%s%s%s%s%s%s%s", tmp->Paper_student_number, tmp->Paper_writer, tmp->Paper_name, tmp->Paper_time, tmp->Paper_page, tmp->Paper_level, tmp->Paper_points))
		{
			free(tmp);
			break;
		}                                                   //fscanf返回值不是7即为数据读完，录入完毕，释放空间，退出循环

		cur->next = tmp;                                    //新的链表尾
		cur = tmp;                                          //更新链表尾
		cur->next = NULL;                                   //最后一个结点指向空
	}
	fclose(fp);
	return head;                                        //返回头结点
}


//函数---创建学生项目链表
Project* Project_build(void)
{
	Project* head = (Project*)malloc(sizeof(Project));     //链表头结点
	head->next = NULL;
	FILE* fp = NULL;
	fp = fopen("project.txt", "r+");           //以读的方式打开文件paper
	if (fp == NULL)
	{
		printf("FILE NOT FOUND");
		exit(-1);
	}                                                      //如果没有文件，则退出并显示未找到文件

	Project* cur = head;                                   //尾结点

	while (1)                                              //循环读入所有数据并依次存于链表
	{
		Project* tmp = (Project*)malloc(sizeof(Project));  //进行操作的临时结点
		if (!tmp)
			exit(-1);

		if (8 != fscanf(fp, "%s%s%s%s%s%s%s%s", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status))
		{
			free(tmp);
			break;
		}                                                   //fscanf返回值不是8即为数据读完，录入完毕，释放空间，退出循环
		cur->next = tmp;                                   //新的链表尾
		cur = tmp;                                          //更新链表尾
		cur->next = NULL;                                   //最后一个结点指向空
	}
	fclose(fp);
	return head;                                        //返回头结点
}


//函数---创建学生竞赛链表
Awards* Awards_build(void)
{
	Awards* head = (Awards*)malloc(sizeof(Awards));     //链表头结点
	head->next = NULL;
	FILE* fp = NULL;
	fp = fopen("award.txt", "r+");           //以读的方式打开文件paper
	if (fp == NULL)
	{
		printf("FILE NOT FOUND");
		exit(-1);
	}                                                      //如果没有文件，则退出并显示未找到文件

	Awards* cur = head;                                   //尾结点

	while (1)                                              //循环读入所有数据并依次存于链表
	{
		Awards* tmp = (Awards*)malloc(sizeof(Awards));  //进行操作的临时结点
		if (!tmp)
			exit(-1);

		if (6 != fscanf(fp, "%s %s  %s %s  %s  %s ", tmp->Awards_student_number, tmp->Award_project_name, tmp->Award_unit, tmp->Award_name, tmp->Award_level, tmp->Award_time))
		{
			free(tmp);
			break;
		}                                                   //fscanf返回值不是6即为数据读完，录入完毕，释放空间，退出循环

		cur->next = tmp;                                    //新的链表尾
		cur = tmp;                                          //更新链表尾
		cur->next = NULL;                                   //最后一个结点指向空
	}
	fclose(fp);
	return head;                                        //返回头结点
}


//函数---构建老师信息的链表，并从文件teacher中读取数据
Teacher* T_build(void)
{

	Teacher* head = (Teacher*)malloc(sizeof(Teacher));     //链表头结点
	head->next = NULL;

	FILE* fp = NULL;
	fp = fopen("teacher.txt", "r+");           //以读的方式打开文件teacher

	if (fp == NULL)
	{
		printf("FILE NOT FOUND");
		exit(-1);
	}                                                      //如果没有文件，则退出并显示未找到文件

	Teacher* cur = head;                                   //尾结点

	while (1)                                              //循环读入所有数据并依次存于链表
	{
		Teacher* tmp = (Teacher*)malloc(sizeof(Teacher));  //进行操作的临时结点
		if (!tmp)
			exit(-1);

		if (3 != fscanf(fp, "%s%s%s", tmp->T_name, tmp->T_num, tmp->T_key))
		{
			free(tmp);
			break;
		}                                                   //fscanf返回值不是3即为数据读完，录入完毕，释放空间，退出循环

		cur->next = tmp;                                    //新的链表尾
		cur = tmp;                                          //更新链表尾
		cur->next = NULL;                                   //最后一个结点指向空
	}
	fclose(fp);
	return head;                                        //返回头结点

}


//函数---构建教务处信息的链表，并从文件deanoffice中读取数据
Teacher* D_build(void)
{

	Teacher* head = (Teacher*)malloc(sizeof(Teacher));     //链表头结点
	head->next = NULL;

	FILE* fp = NULL;
	fp = fopen("deanoffice.txt", "r+");           //以读的方式打开文件teacher

	if (fp == NULL)
	{
		printf("FILE NOT FOUND");
		exit(-1);
	}                                                      //如果没有文件，则退出并显示未找到文件

	Teacher* cur = head;                                   //尾结点

	while (1)                                              //循环读入所有数据并依次存于链表
	{
		Teacher* tmp = (Teacher*)malloc(sizeof(Teacher));  //进行操作的临时结点
		if (!tmp)
			exit(-1);

		if (3 != fscanf(fp, "%s%s%s", tmp->T_name, tmp->T_num, tmp->T_key))
		{
			free(tmp);
			break;
		}                                                   //fscanf返回值不是3即为数据读完，录入完毕，释放空间，退出循环

		cur->next = tmp;                                    //新的链表尾
		cur = tmp;                                          //更新链表尾
		cur->next = NULL;                                   //最后一个结点指向空
	}
	fclose(fp);
	return head;                                        //返回头结点

}


//函数---输出学生具体成绩
void chengji_print_S(chengji* top)
{

	chengji* p1 = top->next;
	printf("\033[44m学期       学分       学科       成绩       绩点\033[0m\n");
	while (p1 != NULL)
	{
		printf("%-10d %-10d %-10s %-10.1f %-10.2f\n", p1->xueqi, p1->xuefen, p1->xueke, p1->chengji, p1->jidian);
		p1 = p1->next;
	}
}


//函数---输出学生所有信息（教务处端功能3-1查询全部学生信息）
void student_print_S(Student* top)
{

	Student* p;
	p = top->next;
	while (p != NULL)
	{
		printf("\033[44m姓名       性别       学号         学院           学年        校区            均分       GPA       排名       已修学分  \033[0m\n");
		printf("%-10s %-10s %-12s %-15s %-10d %-15s %-10.1f %-10.2f %-10d %-5d\n", p->name, p->sex, p->num, p->major, p->semester, p->school_district, p->grade, p->GPA, p->ranking, p->credit);
		chengji_print_S(p->head);
		printf("\n\n");
		p = p->next;
	}

	printf("                              ******************************************************\n");
	printf("                              ||                 返回上一层请输入1                ||\n");
	printf("                              ||                  返回首页请输入2                 ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");

	char going[error_test];
	while (1)
	{
		scanf("%s", going);
		if (strcmp(going, "1") == 0)
		{
			student_queryStu(top);
			break;
		}
		else if (strcmp(going, "2") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(going, "3") == 0)
		{
			login();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---打印Teacher链表,head是哨兵结点
void print(Teacher* head)
{

	Teacher* p;

	p = head->next;
	int i = 0;                  //计数器
	while (p != NULL) {
		printf("%d", ++i);
		printf("%s %s %s\n", p->T_name, p->T_num, p->T_key);

		p = p->next;

	}
}


//函数---打印Awards链表，head是指向单链首节点的指针
void print_awards(Awards* head)
{
	Awards* p;
	p = head->next;
	int i = 1;
	while (p != NULL)
	{
		printf("%-4d", i++);
		printf("%-30s%-21s%-20s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);                  //将文件中的数据打印出来
		if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
			printf("0.4\n");
		else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
			printf("0.2\n");
		else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
			printf("0.1\n");
		else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
			printf("0.05\n");
		else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
			printf("0.02\n");
		else
			printf("0\n");        //计算绩点
		p = p->next;
	}
}


//函数---打印Project链表，head是指向单链首节点的指针
void print_project(Project* head)
{
	Project* p;
	p = head->next;
	int i = 1;
	while (p != NULL)
	{
		printf("%d     ", i++);
		printf("%-20s%-12s%-15s%-12s%-16s%-15s%-12s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);          //将文件中的数据打印出来
		if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
			printf("0.4\n");
		else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
			printf("0.2\n");
		else
			printf("0\n");                                     //其他人不加GPA

		p = p->next;
	}
}


//函数---按项目打印Project链表
void Print_project(Project* head)
{
	Project* p;
	Project* q;
	q = head->next;
	while (q->next->next != 0)
	{
		q = q->next;
	}
	p = head->next;
	int i = 1;
	while (p->next != NULL)
	{
		printf("%-7d", i++);
		printf("%-25s%-11s%-19s%-14s%-16s%-15s\n%", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time);
		if (strcmp(p->Project_number, p->next->Project_number) == 0)
		{
			while (strcmp(p->Project_number, p->next->Project_number) == 0)
			{
				p = p->next;
				if (p->next == NULL)
				{
					break;
				}
			}
			if (p->next == NULL)
				break;
		}


		p = p->next;
	}
	if (strcmp(p->Project_number, q->Project_number) != 0)
	{
		printf("%-7d", i++);
		printf("%-25s%-11s%-19s%-14s%-16s%-15s\n%", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time);
	}
}


//函数---打印Paper链表, head是指向单链表首结点的指针
void print_paper(Paper* head)
{
	Paper* p;
	p = head->next;
	int i = 0;
	while (p != NULL)
	{
		printf("%-5d", ++i);
		printf("%-18s%-32s%-20s%-20s%-10s%-7s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);
		if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
			printf("0.4\n");
		else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
			printf("0.2\n");
		else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
			printf("0.1\n");
		else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
			printf("0.05\n");
		else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
			printf("0.02\n");
		else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
			printf("0.01\n");
		else
			printf("0\n");
		p = p->next;
	}
}


//函数---计算具体绩点（算出每个人每个学科的绩点，并把值填入链表top）
Student* GPA(Student* top) {
	int sum = 0;
	int i = 0;
	int flag = 0;
	float ave = 0.0;
	chengji* p;
	Student* tmp = top->next;
	while (tmp != NULL) {
		p = tmp->head->next;                                                         //遍历每个节点
		while (p != NULL) {
			if (p->chengji < 60)
				p->jidian = 0.00;
			else if ((p->chengji >= 60) && (p->chengji < 64))
				p->jidian = 1.00;
			else if ((p->chengji >= 64) && (p->chengji < 67))
				p->jidian = 1.30;
			else if ((p->chengji >= 67) && (p->chengji < 70))
				p->jidian = 1.70;
			else if ((p->chengji >= 70) && (p->chengji < 74))
				p->jidian = 2.00;
			else if ((p->chengji >= 74) && (p->chengji < 77))
				p->jidian = 2.30;
			else if ((p->chengji >= 77) && (p->chengji < 80))
				p->jidian = 2.70;
			else if ((p->chengji >= 80) && (p->chengji < 84))
				p->jidian = 3.00;
			else if ((p->chengji >= 84) && (p->chengji < 87))
				p->jidian = 3.30;
			else if ((p->chengji >= 87) && (p->chengji < 90))
				p->jidian = 3.70;
			else if ((p->chengji >= 90) && (p->chengji <= 100))
				p->jidian = 4.00;
			p = p->next;
		}
		tmp = tmp->next;
	}

	FILE* fp = NULL;
	fp = fopen("student_information.txt", "w");
	if (fp == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	Student* pp = top->next;
	chengji* qq;
	while (pp != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%s\t%.1f\t%.2f\t%d\t%s\t%d\t", pp->name, pp->sex, pp->num, pp->major, pp->semester, pp->school_district, pp->grade, pp->GPA, pp->ranking, pp->role_code, pp->credit);      //打开文件并进行复写
		if (pp->head == NULL)
		{
			fprintf(fp, "\n");
			pp = pp->next;
			continue;
		}
		else
		{
			qq = pp->head->next;
			while (qq != NULL)
			{
				fprintf(fp, "%d\t%d\t%s\t%.1f\t%.2f\t", qq->xueqi, qq->xuefen, qq->xueke, qq->chengji, qq->jidian);
				qq = qq->next;
			}
			fprintf(fp, "\n");
			pp = pp->next;
		}
	}
	fclose(fp);


	return top;
}


//函数---计算平均绩点（算出每个人的平均绩点（不计算重修后成绩以及转专业前的成绩），并把值填入链表top）
Student* PJGPA(Student* top) {
	int sum = 0;
	int i = 0;
	int flag = 0;
	float ave = 0.0;
	float cj = 0.0;
	chengji* p;
	Student* tmp = top->next;
	while (tmp != NULL) {
		sum = 0;
		flag = 0;
		ave = 0.0;
		cj = 0.0;
		p = tmp->head->next;
		while (p != NULL) {
			if ((p->xueke[strlen(p->xueke) - 1] != 'c') && (p->xueke[strlen(p->xueke) - 1] != 'z')) {
				cj = cj + (p->chengji) * (p->xuefen);
				ave = ave + (p->xuefen) * (p->jidian);
				sum = sum + p->xuefen;
				p = p->next;
			}
			else
				p = p->next;
		}
		tmp->GPA = ave / sum;
		tmp->grade = cj / sum;
		tmp = tmp->next;
	}

	FILE* fp = NULL;
	fp = fopen("student_information.txt", "w");
	if (fp == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	Student* pp = top->next;
	chengji* qq;
	while (pp != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%s\t%.1f\t%.2f\t%d\t%s\t%d\t", pp->name, pp->sex, pp->num, pp->major, pp->semester, pp->school_district, pp->grade, pp->GPA, pp->ranking, pp->role_code, pp->credit);      //打开文件并进行复写
		if (pp->head == NULL)
		{
			fprintf(fp, "\n");
			pp = pp->next;
			continue;
		}
		else
		{
			qq = pp->head->next;
			while (qq != NULL)
			{
				fprintf(fp, "%d\t%d\t%s\t%.1f\t%.2f\t", qq->xueqi, qq->xuefen, qq->xueke, qq->chengji, qq->jidian);
				qq = qq->next;
			}
			fprintf(fp, "\n");
			pp = pp->next;
		}
	}
	fclose(fp);


	return top;
}


//函数---计算素质类项目加分，加到学生的平均绩点(top->GPA)
Student* jiafen(Student* top) {
	Student* tmp = top->next;

	float sum;                                                              //科研成果类对应加分
	float ave;                                                              //竞赛获奖对应加分
	Paper* head;
	int paperA;
	int paperB;
	int paperC;
	int paperD;
	int paperE;
	int paperF;
	head = Paper_build();

	Project* q;
	int peopleA;
	int peopleB;
	q = Project_build();

	Awards* r;
	int awardA;
	int awardB;
	int awardC;
	int awardD;
	int awardE;
	r = Awards_build();
	while (tmp != NULL) {
		sum = 0.0;
		Paper* p = head->next;
		paperA = 0;
		paperB = 0;
		paperC = 0;
		paperD = 0;
		paperE = 0;
		paperF = 0;
		Project* p0 = q->next;
		peopleA = 0;
		peopleB = 0;

		ave = 0.0;
		Awards* p1 = r->next;
		awardA = 0;
		awardB = 0;
		awardC = 0;
		awardD = 0;
		awardE = 0;
		while (p != NULL) {                                                                                  //考虑论文加分
			if (strcmp(tmp->num, p->Paper_student_number) == 0) {
				if ((strcmp(p->Paper_level, "A") == 0) && (paperA == 0) && (sum <= 0.4)) {                       //A类论文绩点加0.4
					paperA++;
					sum = 0.4;
				}
				else if ((strcmp(p->Paper_level, "B") == 0) && (paperB == 0) && (sum <= 0.2)) {                   //B类论文绩点加0.2
					paperB++;
					sum = 0.2;
				}
				else if ((strcmp(p->Paper_level, "C") == 0) && (paperC == 0) && (sum <= 0.1)) {               //C类论文绩点加0.1
					paperC++;
					sum = 0.1;
				}
				else if ((strcmp(p->Paper_level, "D") == 0) && (paperD == 0) && (sum <= 0.05)) {            //D类论文绩点加0.05
					paperD++;
					sum = 0.05;
				}
				else if ((strcmp(p->Paper_level, "E") == 0) && (paperE == 0) && (sum <= 0.02)) {            //E类论文绩点加0.02
					paperE++;
					sum = 0.02;
				}
				else if ((strcmp(p->Paper_level, "F") == 0) && (paperF == 0) && (sum <= 0.01)) {            //F类论文绩点加0.01
					paperF++;
					sum = 0.01;
				}
			}
			p = p->next;
		}
		while (p0 != NULL) {                                                                                //考虑项目加分
			if ((strcmp(tmp->num, p0->Project_student_number) == 0)) {
				if ((strcmp(p0->Project_status, "负责人") == 0) && (peopleA == 0) && (sum <= 0.4))                  //项目负责人GPA加0.4
					sum = 0.4;
				else if ((strcmp(p0->Project_status, "第二名") == 0) && (peopleB == 0) && (sum <= 0.2))             //项目第二名GPA加0.2
					sum = 0.2;
			}
			p0 = p0->next;
		}
		while (p1 != NULL) {
			if (strcmp(tmp->num, p1->Awards_student_number) == 0) {
				if ((strcmp(p1->Award_level, "A类竞赛金奖") == 0) && (awardA == 0) && (ave <= 0.4))
					ave = 0.4;
				else if (((strcmp(p1->Award_level, "A类竞赛银奖") == 0) || (strcmp(p1->Award_level, "B类竞赛金奖") == 0)) && (awardB == 0) && (ave <= 0.2))
					ave = 0.2;
				else if (((strcmp(p1->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p1->Award_level, "B类竞赛银奖") == 0) || (strcmp(p1->Award_level, "C类竞赛金奖") == 0)) && (awardC == 0) && (ave <= 0.1))
					ave = 0.1;
				else if (((strcmp(p1->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p1->Award_level, "C类竞赛银奖") == 0)) && (awardD == 0) && (ave <= 0.05))
					ave = 0.05;
				else if ((strcmp(p1->Award_level, "C类竞赛铜奖") == 0) && (awardE == 0) && (ave <= 0.02))
					ave = 0.02;

			}
			p1 = p1->next;
		}
		if (sum + ave > 0.4)
			tmp->GPA = tmp->GPA + 0.4;                                                        //科研成果加分以及竞赛累计加分不超过0.4
		else
			tmp->GPA = tmp->GPA + sum + ave;
		tmp = tmp->next;
	}

	FILE* fp = NULL;
	fp = fopen("student_information.txt", "w");
	if (fp == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	Student* pp = top->next;
	chengji* qq;
	while (pp != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%s\t%.1f\t%.2f\t%d\t%s\t%d\t", pp->name, pp->sex, pp->num, pp->major, pp->semester, pp->school_district, pp->grade, pp->GPA, pp->ranking, pp->role_code, pp->credit);      //打开文件并进行复写
		if (pp->head == NULL)
		{
			fprintf(fp, "\n");
			pp = pp->next;
			continue;
		}
		else
		{
			qq = pp->head->next;
			while (qq != NULL)
			{
				fprintf(fp, "%d\t%d\t%s\t%.1f\t%.2f\t", qq->xueqi, qq->xuefen, qq->xueke, qq->chengji, qq->jidian);
				qq = qq->next;
			}
			fprintf(fp, "\n");
			pp = pp->next;
		}
	}
	fclose(fp);


	return top;
}


//函数---计算素质类项目加分,不写入文件版
Student* not_write_jiafen(Student* top) {
	Student* tmp = top->next;

	float sum;                                                              //科研成果类对应加分
	float ave;                                                              //竞赛获奖对应加分
	Paper* head;
	int paperA;
	int paperB;
	int paperC;
	int paperD;
	int paperE;
	int paperF;
	head = Paper_build();

	Project* q;
	int peopleA;
	int peopleB;
	q = Project_build();

	Awards* r;
	int awardA;
	int awardB;
	int awardC;
	int awardD;
	int awardE;
	r = Awards_build();
	while (tmp != NULL) {
		sum = 0.0;
		Paper* p = head->next;
		paperA = 0;
		paperB = 0;
		paperC = 0;
		paperD = 0;
		paperE = 0;
		paperF = 0;
		Project* p0 = q->next;
		peopleA = 0;
		peopleB = 0;

		ave = 0.0;
		Awards* p1 = r->next;
		awardA = 0;
		awardB = 0;
		awardC = 0;
		awardD = 0;
		awardE = 0;
		while (p != NULL) {                                                                                  //考虑论文加分
			if (strcmp(tmp->num, p->Paper_student_number) == 0) {
				if ((strcmp(p->Paper_level, "A") == 0) && (paperA == 0) && (sum <= 0.4)) {                       //A类论文绩点加0.4
					paperA++;
					sum = 0.4;
				}
				else if ((strcmp(p->Paper_level, "B") == 0) && (paperB == 0) && (sum <= 0.2)) {                   //B类论文绩点加0.2
					paperB++;
					sum = 0.2;
				}
				else if ((strcmp(p->Paper_level, "C") == 0) && (paperC == 0) && (sum <= 0.1)) {               //C类论文绩点加0.1
					paperC++;
					sum = 0.1;
				}
				else if ((strcmp(p->Paper_level, "D") == 0) && (paperD == 0) && (sum <= 0.05)) {            //D类论文绩点加0.05
					paperD++;
					sum = 0.05;
				}
				else if ((strcmp(p->Paper_level, "E") == 0) && (paperE == 0) && (sum <= 0.02)) {            //E类论文绩点加0.02
					paperE++;
					sum = 0.02;
				}
				else if ((strcmp(p->Paper_level, "F") == 0) && (paperF == 0) && (sum <= 0.01)) {            //F类论文绩点加0.01
					paperF++;
					sum = 0.01;
				}
			}
			p = p->next;
		}
		while (p0 != NULL) {                                                                                //考虑项目加分
			if ((strcmp(tmp->num, p0->Project_student_number) == 0)) {
				if ((strcmp(p0->Project_status, "负责人") == 0) && (peopleA == 0) && (sum <= 0.4))                  //项目负责人GPA加0.4
					sum = 0.4;
				else if ((strcmp(p0->Project_status, "第二名") == 0) && (peopleB == 0) && (sum <= 0.2))             //项目第二名GPA加0.2
					sum = 0.2;
			}
			p0 = p0->next;
		}
		while (p1 != NULL) {
			if (strcmp(tmp->num, p1->Awards_student_number) == 0) {
				if ((strcmp(p1->Award_level, "A类竞赛金奖") == 0) && (awardA == 0) && (ave <= 0.4))
					ave = 0.4;
				else if (((strcmp(p1->Award_level, "A类竞赛银奖") == 0) || (strcmp(p1->Award_level, "B类竞赛金奖") == 0)) && (awardB == 0) && (ave <= 0.2))
					ave = 0.2;
				else if (((strcmp(p1->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p1->Award_level, "B类竞赛银奖") == 0) || (strcmp(p1->Award_level, "C类竞赛金奖") == 0)) && (awardC == 0) && (ave <= 0.1))
					ave = 0.1;
				else if (((strcmp(p1->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p1->Award_level, "C类竞赛银奖") == 0)) && (awardD == 0) && (ave <= 0.05))
					ave = 0.05;
				else if ((strcmp(p1->Award_level, "C类竞赛铜奖") == 0) && (awardE == 0) && (ave <= 0.02))
					ave = 0.02;

			}
			p1 = p1->next;
		}
		if (sum + ave > 0.4)
			tmp->GPA = tmp->GPA + 0.4;                                                        //科研成果加分以及竞赛累计加分不超过0.4
		else
			tmp->GPA = tmp->GPA + sum + ave;
		tmp = tmp->next;
	}

	return top;
}


//函数---计算排名1
Student* full_ranking1(Student* head, char x[3], int y) {
	Student* p = NULL, * p0 = NULL, * r = NULL, * r0 = NULL, * q = NULL, * tail = NULL;
	chengji* t, * m1, * m2;
	int flag = 0;
	float a;              //交换中间量
	int b;
	char str[20];       //交换中间量
	p = head->next;
	t = p->head->next;
	m1 = p->head->next;
	m2 = p->next->head->next;
	while (p != NULL) {
		flag = 0;
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			r = p;
			p0 = p;
			flag = 0;
			while (flag == 0) {
				flag = 1;
				do {
					if (p->next == NULL)break;
					if (p->GPA < p->next->GPA) {
						a = p->grade;
						p->grade = p->next->grade;
						p->next->grade = a;

						strcpy(str, p->name);
						strcpy(p->name, p->next->name);
						strcpy(p->next->name, str);

						strcpy(str, p->sex);
						strcpy(p->sex, p->next->sex);
						strcpy(p->next->sex, str);

						strcpy(str, p->major);
						strcpy(p->major, p->next->major);
						strcpy(p->next->major, str);

						strcpy(str, p->school_district);
						strcpy(p->school_district, p->next->school_district);
						strcpy(p->next->school_district, str);

						strcpy(str, p->role_code);
						strcpy(p->role_code, p->next->role_code);
						strcpy(p->next->role_code, str);

						a = p->GPA;
						p->GPA = p->next->GPA;
						p->next->GPA = a;

						b = p->ranking;
						p->ranking = p->next->ranking;
						p->next->ranking = b;

						strcpy(str, p->num);
						strcpy(p->num, p->next->num);
						strcpy(p->next->num, str);

						b = p->credit;
						p->credit = p->next->credit;
						p->next->credit = b;

						t = p->head->next;
						p->head->next = p->next->head->next;
						p->next->head->next = t;

						flag = 0;
					}
					else if ((p->GPA == p->next->GPA) && (p->GPA != 0)) {
						m1 = p->head->next;
						m2 = p->next->head->next;
						q = p;
						tail = p->next;
						while (m1 != NULL)
						{
							if (strcmp(m1->xueke, "英语") == 0)
							{
								break;
							}
							m1 = m1->next;
						}
						while (m2 != NULL)
						{
							if (strcmp(m2->xueke, "英语") == 0)
							{
								break;
							}
							m2 = m2->next;
						}
						if (m1->jidian < m2->jidian)
						{
							a = p->grade;
							p->grade = p->next->grade;
							p->next->grade = a;

							strcpy(str, p->name);
							strcpy(p->name, p->next->name);
							strcpy(p->next->name, str);

							strcpy(str, p->sex);
							strcpy(p->sex, p->next->sex);
							strcpy(p->next->sex, str);

							strcpy(str, p->major);
							strcpy(p->major, p->next->major);
							strcpy(p->next->major, str);

							strcpy(str, p->school_district);
							strcpy(p->school_district, p->next->school_district);
							strcpy(p->next->school_district, str);

							strcpy(str, p->role_code);
							strcpy(p->role_code, p->next->role_code);
							strcpy(p->next->role_code, str);

							a = p->GPA;
							p->GPA = p->next->GPA;
							p->next->GPA = a;

							b = p->ranking;
							p->ranking = p->next->ranking;
							p->next->ranking = b;

							strcpy(str, p->num);
							strcpy(p->num, p->next->num);
							strcpy(p->next->num, str);

							b = p->credit;
							p->credit = p->next->credit;
							p->next->credit = b;

							t = p->head->next;
							p->head->next = p->next->head->next;
							p->next->head->next = t;

						}
						else if (m1->jidian == m2->jidian) {
							m1 = p->head->next;
							m2 = p->next->head->next;
							while (m1 != NULL)
							{
								if (strcmp(m1->xueke, "微积分1") == 0)
								{
									break;
								}
								m1 = m1->next;
							}
							while (m2 != NULL)
							{
								if (strcmp(m2->xueke, "微积分1") == 0)
								{
									break;
								}
								m2 = m2->next;
							}
							if (m1->jidian < m2->jidian) {
								a = p->grade;
								p->grade = p->next->grade;
								p->next->grade = a;

								strcpy(str, p->name);
								strcpy(p->name, p->next->name);
								strcpy(p->next->name, str);

								strcpy(str, p->sex);
								strcpy(p->sex, p->next->sex);
								strcpy(p->next->sex, str);

								strcpy(str, p->major);
								strcpy(p->major, p->next->major);
								strcpy(p->next->major, str);

								strcpy(str, p->school_district);
								strcpy(p->school_district, p->next->school_district);
								strcpy(p->next->school_district, str);

								strcpy(str, p->role_code);
								strcpy(p->role_code, p->next->role_code);
								strcpy(p->next->role_code, str);

								a = p->GPA;
								p->GPA = p->next->GPA;
								p->next->GPA = a;

								b = p->ranking;
								p->ranking = p->next->ranking;
								p->next->ranking = b;

								strcpy(str, p->num);
								strcpy(p->num, p->next->num);
								strcpy(p->next->num, str);

								b = p->credit;
								p->credit = p->next->credit;
								p->next->credit = b;

								t = p->head->next;
								p->head->next = p->next->head->next;
								p->next->head->next = t;
							}
						}
					}
					if (p->next != NULL) {
						p = p->next;
					}
					else break;
					if (p->next == NULL)break;
				} while (p->next->semester == y);
				p = r;
			}
			break;

		}
		else p = p->next;
		flag = 0;
	}

	p = head->next;
	while (p != NULL) {
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			int i = 1;
			while (p->semester == y) {
				p->ranking = i;
				if (p->next != NULL) {
					p = p->next;
				}
				else break;
				i++;
			}
		}
		p = p->next;
	}

	FILE* fp = NULL;
	fp = fopen("student_information.txt", "w");
	if (fp == NULL) {
		printf("Error opening file.\n");
		exit(-1);
	}
	Student* pp = head->next;
	chengji* qq;
	while (pp != NULL)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%s\t%.1f\t%.2f\t%d\t%s\t%d\t", pp->name, pp->sex, pp->num, pp->major, pp->semester, pp->school_district, pp->grade, pp->GPA, pp->ranking, pp->role_code, pp->credit);      //打开文件并进行复写
		if (pp->head == NULL)
		{
			fprintf(fp, "\n");
			pp = pp->next;
			continue;
		}
		else
		{
			qq = pp->head->next;
			while (qq != NULL)
			{
				fprintf(fp, "%d\t%d\t%s\t%.1f\t%.2f\t", qq->xueqi, qq->xuefen, qq->xueke, qq->chengji, qq->jidian);
				qq = qq->next;
			}
			fprintf(fp, "\n");
			pp = pp->next;
		}
	}
	fclose(fp);

	return head;
}


//函数---计算排名2
Student* full_ranking2(Student* top) {
	top = full_ranking1(top, "55", 1);
	top = full_ranking1(top, "55", 2);
	top = full_ranking1(top, "55", 3);
	top = full_ranking1(top, "24", 1);
	top = full_ranking1(top, "24", 2);
	top = full_ranking1(top, "24", 3);
	top = full_ranking1(top, "06", 1);
	top = full_ranking1(top, "06", 2);
	top = full_ranking1(top, "06", 3);
	top = full_ranking1(top, "10", 1);
	top = full_ranking1(top, "10", 2);
	top = full_ranking1(top, "10", 3);
	top = full_ranking1(top, "21", 1);
	top = full_ranking1(top, "21", 2);
	top = full_ranking1(top, "21", 3);
	top = full_ranking1(top, "70", 1);
	top = full_ranking1(top, "70", 2);
	top = full_ranking1(top, "70", 3);
	top = full_ranking1(top, "03", 1);
	top = full_ranking1(top, "03", 2);
	top = full_ranking1(top, "03", 3);
	top = full_ranking1(top, "14", 1);
	top = full_ranking1(top, "14", 2);
	top = full_ranking1(top, "14", 3);
	top = full_ranking1(top, "11", 1);
	top = full_ranking1(top, "11", 2);
	top = full_ranking1(top, "11", 3);
	top = full_ranking1(top, "07", 2);
	top = full_ranking1(top, "07", 3);
	top = full_ranking1(top, "07", 1);
	return top;
}


//函数---计算教师链表结点数
int knotNumber(Teacher* head)
{
	int n = 0;
	Teacher* p = head->next;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}


//函数---计算学生链表结点数
int sknotNumber(Student* head)
{
	int n = 0;
	Student* p = head->next;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}


//函数---计算成绩链表结点数
int cknotNumber(chengji* head)
{
	int n = 0;
	chengji* p = head->next;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}


//函数---总登录界面
void login(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **                   成绩管理系统                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                      1.学生                      ||\n");
	printf("                              ||                      2.教师                      ||\n");
	printf("                              ||                     3.教务处                     ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n\n");
	printf("\n                              欢迎使用成绩管理系统！\n\n\n");
	printf("                              （退出系统请按0）\n");
	printf("                              请输入您的身份（输入前方的序号）：");

	char identity[error_test];
	while (1)
	{
		scanf("%s", identity);
		getchar();
		if (strcmp(identity,"1") == 0)
		{
			student_login();
			break;
		}
		else if (strcmp(identity, "2") == 0)
		{
			teacher_login();
			break;
		}
		else if (strcmp(identity, "3") == 0)
		{
			dean_office_login();
			break;
		}
		else if (strcmp(identity, "0") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m\n                              您的选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教师端登录
void teacher_login(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **              成绩管理系统（教师端）              **\n");
	printf("                              ******************************************************\n");
	printf("                              欢迎使用成绩管理系统！\n");
	printf("                              尊敬的老师，您好：\n");
	printf("                              ******************************************************\n");
	printf("                              （返回上一层请输入：“返回”）\n");
	printf("                              请输入账号：");                                                  //初始界面

	char T_num_input[20], T_key_input[20];     //老师输入的账号、密码
	Teacher* head = T_build();                   //创建链表
	Teacher* p;
	int time = 0;                              //计数器
	int numm = knotNumber(head);

	while (1)
	{
		gets(T_num_input);                     //输入账号

		if (strcmp(T_num_input, "返回") == 0)login();
		p = head->next;
		time = 0;
		while (p != NULL)                      //遍历链表
		{
			if (strcmp(p->T_num, T_num_input) == 0)        //寻找老师输入的账号对应的教师信息（密码）
			{

				while (1)
				{
					printf("                              请输入密码：");
					char ch = 'a';
					int ikey = 0;                             //计数器

					while (1)                                 //实现隐藏密码，使密码输出为*
					{
						ch = getch();
						if (ch == '\r')
						{
							break;
						}
						if (ch == '\b')
						{
							if (ikey > 0)
							{
								T_key_input[ikey - 1] = '\0';
								ikey--;
							}
							printf("\b");
							printf(" \b");
							continue;
						}
						T_key_input[ikey++] = ch;
						printf("*");
					}
					T_key_input[ikey] = '\0';


					if (strcmp(p->T_key, T_key_input) == 0)   //验证密码
					{
						teacher_interface(head, p);
						break;                                                              //登录成功后的界面
					}
					else
					{
						printf("\033[31m\n                              密码错误！请重新输入!\033[0m\n");     //密码错误要求重新输入
						time--;
					}
				}
				break;
			}
			else
			{
				p = p->next;
				time++;                        //寻找账号的过程
			}
		}
		if (time == numm)
		{
			printf("\033[31m                              该账号不存在！请重新输入：\033[0m");   //没有找到输入的账号，要求重新输入

		}
		else
		{
			break;
		}

	}
}


//函数---教师端界面
void teacher_interface(Teacher* head, Teacher* p)
{
	system("cls");                        //清屏
	printf("                              ******************************************************\n");
	printf("                              **              成绩管理系统（教师端）              **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                  1.查询学生成绩                  ||\n");
	printf("                              ||                  2.统计学科数据                  ||\n");
	printf("                              ||                  3.教师密码修改                  ||\n");
	printf("                              ||                  退出系统请按0                   ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");

	char ch[error_test];              //选项
	while (1)
	{
		scanf("%s", ch);
		if (strcmp(ch,"3") == 0)
		{
			teacher_modifyKey(head, p);
			break;
		}
		else if (strcmp(ch, "2") == 0)
		{
			statisticsSubject(head, p);
			break;
		}
		else if (strcmp(ch, "1") == 0)
		{
			student_grade_query(head, p);
			break;
		}
		else if (strcmp(ch, "0") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              您的输入不正确，请输入正确的选项：\033[0m");
		}
	}
}


//函数---教务处端登录
void dean_office_login(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **             成绩管理系统（教务处端）             **\n");
	printf("                              ******************************************************\n");
	printf("                              欢迎使用成绩管理系统！\n");
	printf("                              尊敬的老师，您好：\n");
	printf("                              ******************************************************\n");
	printf("                              （返回上一层请输入：“返回”）\n");
	printf("                              请输入账号：");                     //初始界面

	char D_num_input[20], D_key_input[20];     //老师输入的账号、密码
	Teacher* dhead = D_build();                   //创建链表
	Teacher* m;
	int ti = 0;                              //计数器

	while (1)
	{
		gets(D_num_input);                     //输入账号
		if (strcmp(D_num_input, "返回") == 0)login();
		m = dhead->next;
		ti = 0;
		while (m != NULL)                      //遍历链表
		{
			if (strcmp(m->T_num, D_num_input) == 0)        //寻找老师输入的账号对应的教师信息（密码）
			{

				while (1)
				{
					printf("                              请输入密码：");
					char ch = 'a';
					int ikey = 0;                             //计数器

					while (1)                                 //实现隐藏密码，使密码输出为*
					{
						ch = getch();
						if (ch == '\r')
						{
							break;
						}
						if (ch == '\b')
						{
							if (ikey > 0)
							{
								D_key_input[ikey - 1] = '\0';
								ikey--;
							}
							printf("\b");
							printf(" \b");
							continue;
						}
						D_key_input[ikey++] = ch;
						printf("*");
					}
					D_key_input[ikey] = '\0';


					if (strcmp(m->T_key, D_key_input) == 0)   //验证密码
					{
						dean_office_interface();
						break;                                                              //登录成功后的界面
					}
					else
					{
						printf("\033[31m\n                              密码错误！请重新输入!\033[0m\n");     //密码错误要求重新输入
						ti--;
					}
				}
				break;
			}
			else
			{
				m = m->next;
				ti++;                        //寻找账号的过程
			}
		}
		if (ti == knotNumber(dhead))
		{
			printf("\033[31m                              该账号不存在！请重新输入：\033[0m");   //没有找到输入的账号，要求重新输入

		}
		else
		{
			break;
		}

	}
}


//函数---教务处端界面
void dean_office_interface(void)
{
	system("cls");                        //清屏
	printf("                              ******************************************************\n");
	printf("                              **             成绩管理系统（教务处端）             **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                1.增加学生信息/成绩               ||\n");
	printf("                              ||                  2.删除学生信息                  ||\n");
	printf("                              ||                  3.查询学生信息                  ||\n");
	printf("                              ||                  4.修改学生成绩                  ||\n");
	printf("                              ||           5.学生学习态度评估及保研预测           ||\n");
	printf("                              ||                  6.教师信息修改                  ||\n");
	printf("                              ||                   7.转专业管理                   ||\n");
	printf("                              ||                  8.重修成绩录入                  ||\n");
	printf("                              ||                    9.降级管理                    ||\n");
	printf("                              ||                  10.大三保研排名                 ||\n");
	printf("                              ||                  11.大三出国排名                 ||\n");
	printf("                              ||                 12.素质类项目管理                ||\n");
	printf("                              ||                   退出系统请按0                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");

	Student* top;
	top = student_creat();
	char ch[error_test];

	while (1)
	{
		scanf("%s", ch);
		if (strcmp(ch, "1") == 0)
		{
			student_addStu(top);
			break;
		}
		else if (strcmp(ch, "2") == 0)
		{
			student_deleteStu(top);
			break;
		}
		else if (strcmp(ch, "3") == 0)
		{
			student_queryStu(top);
			break;
		}
		else if (strcmp(ch, "4") == 0)
		{
			student_modifyStu(top);
			break;
		}
		else if (strcmp(ch, "5") == 0)
		{
			student_prediction(top);
			break;
		}
		else if (strcmp(ch, "6") == 0)
		{
			teacher_modifyTea();
			break;
		}
		else if (strcmp(ch, "7") == 0)
		{
			student_transferMajor(top);
			break;
		}
		else if (strcmp(ch, "8") == 0)
		{
			student_rebuild(top);
			break;
		}
		else if (strcmp(ch, "9") == 0)
		{
			student_degrade(top);
			break;
		}
		else if (strcmp(ch, "10") == 0)
		{
			graduate_recommendation_ranking(top);
			break;
		}
		else if (strcmp(ch, "11") == 0)
		{
			graduate_abroad_ranking(top);
			break;
		}
		else if (strcmp(ch, "12") == 0)
		{
			Service();
			break;
		}
		else if (strcmp(ch, "0") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              您的输入不正确，请输入正确的选项：\033[0m");
		}
	}
}


//函数---学生端登录
void student_login(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **              成绩管理系统（学生端）              **\n");
	printf("                              ******************************************************\n");
	printf("                              欢迎使用成绩管理系统！\n");
	printf("                              亲爱的同学，您好：\n");
	printf("                              ******************************************************\n");
	printf("                              （返回上一层请输入：“返回”）\n");
	printf("                              请输入账号：");                                                  //初始界面
	

	char S_num_input[20], S_key_input[20];     //学生输入的账号、密码
	Student* head = student_creat();                   //创建链表

	Student* p;
	int time = 0;                              //计数器
	int numm = sknotNumber(head);

	while (1)
	{
		gets(S_num_input);                     //输入账号
		if (strcmp(S_num_input, "返回") == 0)login();
		p = head->next;
		time = 0;
		while (p != NULL)                      //遍历链表
		{
			if (strcmp(p->num, S_num_input) == 0)        //寻找学生输入的账号对应的学生信息（密码）
			{

				while (1)
				{
					printf("                              请输入密码：");
					char ch = 'a';
					int ikey = 0;                             //计数器

					while (1)                                 //实现隐藏密码，使密码输出为*
					{
						ch = getch();
						if (ch == '\r')
						{
							break;
						}
						if (ch == '\b')
						{
							if (ikey > 0)
							{
								S_key_input[ikey - 1] = '\0';
								ikey--;
							}
							printf("\b");
							printf(" \b");
							continue;
						}
						S_key_input[ikey++] = ch;
						printf("*");
					}
					S_key_input[ikey] = '\0';


					if (strcmp(p->role_code, S_key_input) == 0)   //验证密码
					{
						student_interface(head, p);
						break;                                                              //登录成功后的界面
					}
					else
					{
						printf("\033[31m\n                              密码错误！请重新输入!\033[0m\n");     //密码错误要求重新输入
						time--;
					}
				}
				break;
			}
			else
			{
				p = p->next;
				time++;                        //寻找账号的过程
			}
		}
		if (time == numm)
		{
			printf("\033[31m                              该账号不存在！请重新输入：\033[0m");   //没有找到输入的账号，要求重新输入

		}
		else
		{
			break;
		}

	}
}


//函数---学生端界面
void student_interface(Student* head, Student* p)
{
	system("cls");                        //清屏
	printf("                              ******************************************************\n");
	printf("                              **              成绩管理系统（学生端）              **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                    1.成绩查询                    ||\n");
	printf("                              ||           2.学生学习态度评估及保研预测           ||\n");
	printf("                              ||                    3.密码修改                    ||\n");
	printf("                              ||                 4.素质类项目查询                 ||\n");
	printf("                              ||                  退出系统请按0                   ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");

	char ch[error_test];              //选项
	while (1)
	{
		scanf("%s", ch);
		if (strcmp(ch, "3") == 0)
		{
			student_modifyKey(head, p);
			break;
		}
		else if (strcmp(ch, "1") == 0)
		{
			student_inquiry(head, p);
			break;
		}
		else if (strcmp(ch, "4") == 0)
		{
			student_quality_education(head, p);
			break;
		}
		else if (strcmp(ch, "2") == 0)
		{
			student_single_prediction(head, p);
			break;
		}
		else if (strcmp(ch, "0") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              您的输入不正确，请输入正确的选项：\033[0m");
		}
	}
}


//函数---教师端功能1（查询学生成绩）
void student_grade_query(Teacher* head, Teacher* p)
{
	Student* top = student_creat();
	system("cls");
	int start1;
start1:
	printf("                              *      请输入您的查询方式（支持模糊查询）：  *  \n");
	printf("                              *               1.姓名查询                   *\n");
	printf("                              *               2.学号查询                   *\n");
	printf("                                             （输入前方的序号即可）：       \n");
	printf("                              *               #按“0”返回上一界面#        *\n");
	printf("                              ");
	char search_way[error_test];
	scanf("%s", search_way);
	system("cls");
	if (strcmp(search_way,"1") == 0) {
		printf("                              *      请输入您想查询学生姓名的关键字：    *  \n");
		printf("                              *          #按“0”返回上一界面#           *  \n");
		printf("                              ");
		char input[20];
		int q = 0;
		while (q == 0) {
			scanf("%s", input);
			if (strcmp(input, "0") == 0) {

				goto start1;
			}
			else {
				Student* current = top;
				int found = 0;
				while (current != NULL) {
					if (strstr(current->name, input) != NULL) {
						printf("\n\033[44m姓名       性别       学号         学院           学年        校区            均分       GPA       排名\033[0m\n");
						printf("%-10s %-10s %-12s %-15s %-10d %-15s %-10.1f %-10.2f %-10d\n", current->name, current->sex, current->num, current->major, current->semester, current->school_district, current->grade, current->GPA, current->ranking);
						chengji_print_S(current->head);
						found = 1;
						q = 1;
					}
					current = current->next;
				}
				current = top;
				if (!found) {
					printf("\033[31m                              对不起，无相关学生,请重新输入关键字:\033[0m");
				}
			}
		}
		printf("\n***********************继续查询请按1，返回个人首页请按2,退出系统请按3***************************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start1;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				teacher_interface(head, p);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}

	}
	else if (strcmp(search_way, "2") == 0) {
		printf("                        *请输入您想查询学生学号（可输入任意位数，查询学号包含输入数字的所有学生）：*  \n");
		printf("                        *                          #按“0”返回上一界面#                           *  \n");
		printf("                        ");
		char input[20];
		int q = 0;
		while (q == 0) {
			scanf("%s", input);
			if (strcmp(input, "0") == 0) {
				goto start1;
			}
			else {
				Student* current = top;
				int found = 0;
				while (current != NULL) {
					if (strstr(current->num, input) != NULL) {
						printf("\n\033[44m姓名       性别       学号         学院           学年        校区            均分       GPA       排名\033[0m\n");
						printf("%-10s %-10s %-12s %-15s %-10d %-15s %-10.1f %-10.2f %-10d\n", current->name, current->sex, current->num, current->major, current->semester, current->school_district, current->grade, current->GPA, current->ranking);
						chengji_print_S(current->head);
						found = 1;
						q = 1;
					}
					current = current->next;
				}
				current = top;
				if (!found) {
					printf("\033[31m                        对不起，无相关学生,请重新输入学号内容:\033[0m");
				}
			}
		}
		printf("\n***********************继续查询请按1，返回个人首页请按2,退出系统请按3***************************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start1;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				teacher_interface(head, p);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(search_way, "0") == 0) {
		teacher_interface(head, p);
	}
	else {
		printf("\033[31m无该查询类别！请重新输入您的查询方式：\033[0m\n");
		goto start1;
	}
}


//函数---教师端功能2（统计学科数据）
void statisticsSubject(Teacher* head, Teacher* p)
{
	system("cls");
	printf("                              *****************************************************************\n");
	printf("                              **                        学科数据统计                         **\n");
	printf("                              *****************************************************************\n");
	printf("                                                                                               \n");

	Student* top = student_creat();
	xueke* h = xueke_creat(top);
	float PJF;


	sort(h);                                                //对该年级该学科所有学生信息进行排序
	PM(h);                                                  //把每个人的排名输入链表
	PJF = pingjunfen(h);                                    //打印该学科平均分
	PJF = pingjunjidian(h);                                 //打印该学科平均绩点
	PJF = jigelv(h);                                        //打印该学科及格率
	PJF = zuigaofen(h);                                     //打印该学科最高分
	print_S(h);                                             //输出该专业该学科所有学生成绩信息

	printf("\n\n                              ******************************************************\n");
	printf("                              ||                   继续查询请输入1                ||\n");
	printf("                              ||                   返回首页请输入2                ||\n");
	printf("                              ||                   退出系统请输入3                ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			statisticsSubject(head, p);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			teacher_interface(head, p);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教师端功能2---教师界面显示某个专业有哪些学科的函数
void jiemian(char ch[20], int xueqi)
{
	if (strcmp(ch, "24-建筑学院") == 0)
	{
		if (xueqi == 3)
		{
			printf("                              （微积分1   建筑设计  建筑概论  英语      基础物理  数据结构  建筑构造\n");
			printf("                                近代史    线性代数  微积分2   离散数学   军事理论  历史      政治\n");
			printf("                                应用数学  基础化学  建筑材料  计算机设计 建筑力学）\n");
		}
		else if (xueqi == 2)
		{
			printf("                              （微积分1  建筑设计   建筑概论  英语      基础物理  数据结构  建筑构造\n");
			printf("                                近代史    线性代数  微积分2   离散数学  军事理论)\n");
		}
		else if (xueqi == 1)
		{
			printf("                                （微积分1  建筑设计  建筑概论  英语  基础物理  数据结构)\n");
		}
	}
	else if (strcmp(ch, "06-经济学院") == 0)
	{
		if (xueqi == 3)
		{
			printf("                               (政治经济  微积分1   线性代数  英语        微观经济  概率论    统计学 \n");
			printf("                                国际经济  会计学    宏观经济  微积分2     离散数学  货币银行  财政学 \n");
			printf("                                企业管理  市场营销  国际金融  经济学说史  军事理论  c语言）         \n");
		}
		else if (xueqi == 2)
		{
			printf("                               (政治经济  微积分1   线性代数  英语     微观经济  概率论  统计学\n");
			printf("                                国际经济  会计学    宏观经济  微积分2  离散数学）\n");
		}
		else if (xueqi == 1)
			printf("                                 (政治经济  微积分1  线性代数  英语  微观经济  概率论)\n");
	}
	else if (strcmp(ch, "10-数学学院") == 0)
	{
		if (xueqi == 3)
		{
			printf("                               (微积分1   线性代数    英语      微积分2     概率论    军事理论  离散数学\n");
			printf("                                近代史    基础物理    c语言     解析几何    数值分析  政治      基础化学\n");
			printf("                                数据结构  应用数学    拓扑学    常微分方程  数学模型  几何学)\n");
		}
		else if (xueqi == 2)
		{
			printf("                               (微积分1   线性代数  英语   微积分2   概率论  军事理论  离散数学\n");
			printf("                                近代史    基础物理  c语言  解析几何  数值分析)\n");
		}
		else if (xueqi == 1)
			printf("                                 (微积分1  线性代数  英语  微积分2  概率论  军事理论)\n");
	}
	else if (strcmp(ch, "21-计算机科学与技术") == 0)
	{
		if (xueqi == 3)
		{
			printf("                               (微积分1   线性代数  英语         数字逻辑        微机原理  军事理论  近代史\n");
			printf("                                离散数学  政治      计算机导论   电路原理        数学分析  基础物理  数据结构\n");
			printf("                                Java      人工智能  模拟电子技术 计算机组成原理  操作系统  面向对象设计)\n");
		}
		else if (xueqi == 2)
		{
			printf("                               (微积分1   线性代数  英语        数字逻辑  微机原理  军事理论  近代史 \n");
			printf("                                离散数学  政治      计算机导论  电路原理  数学分析)\n");
		}
		else if (xueqi == 1)
			printf("                                 (微积分1  线性代数  英语  数字逻辑  微机原理  军事理论)\n");
	}
	else if (strcmp(ch, "70-临床医学") == 0) {
		if (xueqi == 3) {
			printf("                               (基础化学  细胞生物学  英语        人体解剖学  免疫学  微积分1  有机化学\n");
			printf("                                近代史    政治        高等数学    病理学      诊断学  外科手术  内科    \n");
			printf("                                药理学    预防医学    神经生物学  基础物理    c语言   生理学)\n");
		}
		else if (xueqi == 2) {
			printf("                               (基础化学  细胞生物学  英语      人体解剖学  免疫学  微积分1  有机化学  \n");
			printf("                                近代史    政治        高等数学  病理学      诊断学)\n");
		}
		else if (xueqi == 1)
			printf("                                 (基础化学  细胞生物学  英语  人体解剖学  免疫学  微积分1)\n");
	}
	else if (strcmp(ch, "03-外语学院") == 0) {
		if (xueqi == 3) {
			printf("                               (英语      微积分1   政治      c语言     军事理论  英语听力  法语   \n");
			printf("                                德语      近代史    口语      英语阅读  英语笔译  应用数学  微积分2 \n");
			printf("                                商务英语  基础物理  英语口译  英语写作  英语文学)\n");
		}
		else if (xueqi == 2) {
			printf("                                 (英语      微积分1   政治  c语言    军事理论  英语听力  法语  \n");
			printf("                                  德语      近代史    口语  英语阅读 英语笔译)\n");
		}
		else if (xueqi == 1)
			printf("                                 (英语  微积分1  政治  c语言  军事理论  英语听力)\n");
	}
	else if (strcmp(ch, "14-汉语言文学") == 0) {
		if (xueqi == 3) {
			printf("                               (现代文学  古代文学  英语      古代汉语  微积分1    外国文学  微积分2\n");
			printf("                                大学写作  近代史    军事理论  汉语研究  中国文学史  文学概论  政治  \n");
			printf("                                语言学    中国通史  c语言     音韵学)\n");
		}
		else if (xueqi == 2) {
			printf("                               (现代文学  古代文学  英语      古代汉语  微积分1  外国文学  微积分2  \n");
			printf("                                大学写作  近代史    军事理论  汉语研究  中国文学史)\n");
		}
		else if (xueqi == 1)
			printf("                                 (现代文学  古代文学  英语  古代汉语  微积分1  外国文学)\n");
	}
	else if (strcmp(ch, "11-物理学院") == 0) {
		if (xueqi == 3) {
			printf("                               (量子力学    微积分1    英语      近代物理  数学物理方法  理论力学  热学  \n");
			printf("                                电磁学      光学       电动力学  固体物理  物理实验      政治      原子物理\n");
			printf("                                统计物理学  天体物理  大气物理学)\n");
		}
		else if (xueqi == 2) {
			printf("                               (量子力学  微积分1  英语      近代物理  数学物理方法  理论力学  热学  \n");
			printf("                                电磁学    光学     电动力学  固体物理  物理实验)\n");
		}
		else if (xueqi == 1)
			printf("                                 (量子力学  微积分1  英语  近代物理  数学物理方法  理论力学)\n");
	}
	else if (strcmp(ch, "55-软件学院") == 0)
	{
		if (xueqi == 3)
		{
			printf("                               (微积分1   英语      线性代数  计算机导论  面向对象设计  数据结构  \n");
			printf("                                离散数学  政治      近代史    课程设计    微积分2       软件工程导论\n");
			printf("                                基础物理  程序设计  数字逻辑  军事理论    Java          Python)\n");
		}
		else if (xueqi == 2)
		{
			printf("                               (微积分1   英语  线性代数  计算机导论  面向对象设计  数据结构  \n");
			printf("                                离散数学  政治  近代史    课程设计    微积分2       软件工程导论)\n");
		}
		else if (xueqi == 1)
			printf("                                 (微积分1  英语  线性代数  计算机导论  面向对象设计  数据结构)\n");
	}
	else if (strcmp(ch, "07-法学院") == 0)
	{
		if (xueqi == 3)
		{
			printf("                               (微积分1  法理学    逻辑学    行政诉讼    国际公法  英语     \n");
			printf("                                宪法     刑法      法制史    环境资源法  法律英语  公文处理与写作 \n");
			printf("                                行政法   民法总则  刑事诉讼  民事诉讼    近代史    军事理论)\n");
		}
		else if (xueqi == 2)
		{
			printf("                                (微积分1  法理学  逻辑学  行政诉讼    国际公法  英语   \n");
			printf("                                 宪法     刑法    法制史  环境资源法  法律英语  公文处理与写作)\n");
		}
		else if (xueqi == 1)
			printf("                                 (微积分1  法理学  逻辑学  行政诉讼  国际公法  英语)\n");
	}
}


//函数---教师端功能2---某专业某年级某学科成绩链表
xueke* xueke_creat(Student* top) {

	xueke* h = NULL;
	xueke* p0 = NULL, * p1 = NULL;
	Student* tmp = top->next;
	chengji* p = NULL;
	chengji* q = NULL;
	char ch[100];
	char str[20];
	char st = 'y';
	int xueqi;
	char kecheng[20];
	int i = 0;
	int a;
	int j;
	int b = 0;
	int flag = 0;
	int m = 0;
	int n = 0;
	int r = 0;
	while (m == 0) {
		while (flag == 0) {
			printf("                              *****************************************************************\n");
			printf("                              *请输入您想查询的专业：                                         *\n");
			printf("                              *1.建筑学院   2.经济学院   3.数学学院     4.计算机科学与技术    *\n");
			printf("                              *5.临床医学   6.外语学院   7.汉语言文学   8.物理学院            *\n");
			printf("                              *9.软件学院   10.法学院                                         *\n");
			printf("                              *（输入前面的序号即可）                                         *\n");
			printf("                              *****************************************************************\n");
			printf("                              ");
			scanf("%d", &a);
			if (a==1) {
				strcpy(ch, "24-建筑学院");
				flag = 1;
			}
			else if (a==2) {
				strcpy(ch, "06-经济学院");
				flag = 1;
			}
			else if (a==3) {
				strcpy(ch, "10-数学学院");
				flag = 1;
			}
			else if (a==4) {
				strcpy(ch, "21-计算机科学与技术");
				flag = 1;
			}
			else if (a==5) {
				strcpy(ch, "70-临床医学");
				flag = 1;
			}
			else if (a==6) {
				strcpy(ch, "03-外语学院");
				flag = 1;
			}
			else if (a==7) {
				strcpy(ch, "14-汉语言文学");
				flag = 1;
			}
			else if (a==8) {
				strcpy(ch, "11-物理学院");
				flag = 1;
			}
			else if (a==9) {
				strcpy(ch, "55-软件学院");
				flag = 1;
			}
			else if (a==10) {
				strcpy(ch, "07-法学院");
				flag = 1;
			}
			else
				printf("\033[31m                              输入错误，请重新输入！\033[0m\n");
		}
		while (n == 0) {
			printf("                              *****************************************************************\n");
			printf("                              *请输入您想要查询的年级：                                       *\n");
			printf("                              *1.大一    2.大二   3.大三                                      *\n");
			printf("                              *(输入前面的序号即可)                                           *\n");
			printf("                              *****************************************************************\n");
			printf("                              ");
			scanf("%d", &xueqi);
			if (xueqi==1 || xueqi==2 || xueqi==3)
				n = 1;
			else
				printf("\033[31m                              输入错误，请重新输入！\033[0m\n");
		}
		while (r == 0) {
			printf("                              *****************************************************************\n");
			printf("                              *请输入您想要查询的学科：                                       *\n");
			jiemian(ch, xueqi);
			printf("                              *****************************************************************\n");
			printf("                              ");
			scanf("%s", kecheng);
			tmp = top->next;
			while ((tmp != NULL) && ((strcmp(tmp->major, ch) != 0) || (tmp->semester != xueqi))) {
				tmp = tmp->next;
			}
			p = tmp->head->next;
			while (p != NULL) {
				if (strcmp(p->xueke, kecheng) == 0)
					r = 1;
				p = p->next;                                    //遍历链表，检查老师输入的学科是否正确,如果正确，则r=1，跳出循环
			}

			if (r == 1) {
				tmp = top->next;
				while (tmp != NULL) {
					while ((tmp != NULL) && ((strcmp(tmp->major, ch) != 0) || (tmp->semester != xueqi))) {
						tmp = tmp->next;
					}                                           //遍历链表找到对应学生
					if (tmp == NULL)
						break;
					p1 = (xueke*)malloc(sizeof(xueke));
					strcpy(p1->xuehao, tmp->num);
					strcpy(p1->Name, tmp->name);
					p = tmp->head->next;
					while (strcmp(p->xueke, kecheng) != 0) {
						p = p->next;
					}
					p1->paiming = 0;
					p1->Chengji = p->chengji;
					p1->Jidian = p->jidian;

					if (i == 0)
						h = p1;
					else
						p0->next = p1;
					p0 = p1;

					tmp = tmp->next;
					i++;
				}
				p1->next = NULL;
				system("cls");
				printf("\033[44m专业：");
				printf("%s   ", ch);
				printf("年级：");
				printf("%d   ", xueqi);
				printf("学科：");
				printf("%s\033[0m   ", kecheng);

				m = 1;
			}
			else
				printf("\033[31m                              输入错误，请重新输入！\033[0m\n");
		}
	}
	return h;
}


//函数---教师端功能2---某专业某年级某学科成绩降序排序
xueke* sort(xueke* top) {
	xueke* p, * p0, * r, * r0, * q;
	p = p0 = r = r0 = q = NULL;
	int flag = 0;
	float a;
	char ch[20];
	char str[50];
	while (flag == 0) {
		flag = 1;
		for (p = top; p->next != NULL; p = p->next) {
			if (p->Chengji < p->next->Chengji) {
				a = p->Chengji;
				p->Chengji = p->next->Chengji;
				p->next->Chengji = a;
				a = p->Jidian;
				p->Jidian = p->next->Jidian;
				p->next->Jidian = a;
				strcpy(ch, p->xuehao);
				strcpy(p->xuehao, p->next->xuehao);
				strcpy(p->next->xuehao, ch);
				strcpy(ch, p->Name);
				strcpy(p->Name, p->next->Name);
				strcpy(p->next->Name, ch);
				flag = 0;
			}
		}
	}
	return top;
}


//函数---教师端功能2---把排名填入学生成绩链表
xueke* PM(xueke* h) {
	xueke* q1;
	int i = 1;
	q1 = h;
	while (q1 != NULL) {
		q1->paiming = i;
		if ((q1->next != NULL) && ((q1->Chengji) == (q1->next->Chengji)))
			i--;
		i++;
		q1 = q1->next;
	}
	return h;
}


//函数---教师端功能2---打印某专业某学科所有学生成绩
void print_S(xueke* head) {
	xueke* p = head;
	printf("\n学号     姓名        成绩    绩点   排名\n");
	while (p != NULL) {
		printf("%s %-8s    %.1f    %.2f    %d\n", p->xuehao, p->Name, p->Chengji, p->Jidian, p->paiming);
		p = p->next;
	}
}


//函数---教师端功能2---算出并打印某专业某年级某学科平均分
float pingjunfen(xueke* head) {
	int i = 0;
	float PJF;
	float sum = 0.0;
	xueke* p = head->next;
	while (p != NULL) {
		sum = sum + p->Chengji;
		p = p->next;
		i++;
	}
	PJF = sum / i;
	printf("\033[44m平均分：");
	printf("%.1f\033[0m   ", PJF);
	return PJF;
}


//函数---教师端功能2---算出并打印某专业某年级某学科平均绩点
float pingjunjidian(xueke* head) {
	int i = 0;
	float JD;
	float sum = 0.0;
	xueke* p = head->next;
	while (p != NULL) {
		sum = sum + p->Jidian;
		p = p->next;
		i++;
	}
	JD = sum / i;
	printf("\033[44m平均绩点：");
	printf("%.1f\033[0m   ", JD);
	return JD;
}


//函数---教师端功能2---算出并打印某专业某年级某学科及格率
float jigelv(xueke* head) {
	int i = 0;
	float jige;
	int sum = 0;
	xueke* p = head->next;
	while (p != NULL) {
		if ((p->Chengji) >= 60)
			sum++;
		p = p->next;
		i++;
	}
	jige = (float)100 * sum / i;
	printf("\033[44m及格率：");
	printf("%.1f%%\033[0m   ", jige);
	return jige;
}


//函数---教师端功能2---算出并打印某专业某年级某学科最高分
float zuigaofen(xueke* head) {
	xueke* p = head;
	float max = p->Chengji;
	while (p != NULL) {
		if ((p->Chengji) > max)
			max = p->Chengji;
		p = p->next;
	}
	printf("\033[44m最高分：");
	printf("%.1f\033[0m\n", max);
	return max;
}


//函数---教师端功能3（教师密码修改）
void teacher_modifyKey(Teacher* head, Teacher* p)
{
	Teacher* copy = p;
	system("cls");                                          //清屏
	printf("                              ******************************************************\n");
	printf("                              **                   教师密码修改                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");

	char ch;
	int ikeyII = 0, ikeyIII = 0, ikeyIV = 0;                            //计数器

	FILE* fpp = NULL;                                             //为之后修改文件做准备

	char originalKey[20], newKeyI[20], newKeyII[20];            //输入的原密码、新密码、重复的新密码

	printf("\n                              请输入您的原密码：");
	getchar();

	while (1)
	{
		while (1)                                 //实现隐藏密码，使密码输出为*
		{
			ch = getch();
			if (ch == '\r')
			{
				break;
			}
			if (ch == '\b')
			{
				if (ikeyII > 0)
				{
					originalKey[ikeyII - 1] = '\0';
					ikeyII--;
				}
				printf("\b");
				printf(" \b");
				continue;
			}

			originalKey[ikeyII++] = ch;
			printf("*");
		}
		originalKey[ikeyII] = '\0';


		if (strcmp(p->T_key, originalKey) == 0)                 //验证原密码是否正确
		{
			printf("\n\n                              请输入您的新密码（6位）：");
			while (1)
			{
				while (1)                                 //实现隐藏密码，使密码输出为*
				{
					ch = getch();
					if (ch == '\r')
					{
						break;
					}
					if (ch == '\b')
					{
						if (ikeyIII > 0)
						{
							newKeyI[ikeyIII - 1] = '\0';
							ikeyIII--;
						}
						printf("\b");
						printf(" \b");
						continue;
					}
					newKeyI[ikeyIII++] = ch;
					printf("*");
				}
				newKeyI[ikeyIII] = '\0';


				if (strlen(newKeyI) != 6)                        //验证新密码的长度
				{
					printf("\033[31m\n\n                              密码设置必须为6位，请您重新设置：\033[0m");
					ikeyII = 0;
					ikeyIII = 0;
					ikeyIV = 0;
				}
				else
				{
					printf("\n\n                              请再次输入您的新密码：");

					while (1)                                    //实现隐藏密码，使密码输出为*
					{
						ch = getch();
						if (ch == '\r')
						{
							break;
						}
						if (ch == '\b')
						{
							if (ikeyIV > 0)
							{
								newKeyII[ikeyIV - 1] = '\0';
								ikeyIV--;
							}
							printf("\b");
							printf(" \b");
							continue;
						}
						newKeyII[ikeyIV++] = ch;
						printf("*");
					}
					newKeyII[ikeyIV] = '\0';


					if (strcmp(newKeyI, newKeyII) == 0)                      //验证两次输入的新密码是否一致
					{
						strcpy(p->T_key, newKeyI);                           //更新链表中密码部分
						strcpy(copy->T_key, newKeyI);
						printf("\n\n                              修改密码成功！\n");

						p = head->next;
						fpp = fopen("teacher.txt", "w");

						if (fpp == NULL)
						{
							printf("FILE NOT FOUND");
							exit(0);
						}

						while (p != NULL)
						{
							fprintf(fpp, "%s\t%s\t%s\n", p->T_name, p->T_num, p->T_key);      //打开文件并进行复写
							p = p->next;
						}

						fclose(fpp);

						break;
					}
					else
					{
						printf("\033[31m\n\n                              密码输入不一致，请重新设置,请输入您的新密码：\033[0m");
						ikeyII = 0;
						ikeyIII = 0;
						ikeyIV = 0;
					}
				}
			}
			break;
		}
		else
		{
			printf("\033[31m\n                              密码错误！请重新输入您的原密码：\033[0m");
			ikeyII = 0;
			ikeyIII = 0;
			ikeyIV = 0;
		}
	}

	printf("                              ******************************************************\n");
	printf("                              ||                  返回首页请输入1                 ||\n");
	printf("                              ||                  退出系统请输入2                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			teacher_interface(head, copy);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项错误，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能1（学生信息/成绩增加）
void student_addStu(Student* top)
{

	system("cls");                //清屏

	printf("                              ******************************************************\n");
	printf("                              **                   学生信息增加                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                  1.新生信息录入                  ||\n");
	printf("                              ||                  2.学期成绩录入                  ||\n");
	printf("                              ||                 返回上一层请按0                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");                             //界面

	char ch[error_test];         //选项

	while (1)
	{
		scanf("%s", ch);            //输入选项
		if (strcmp(ch,"1") == 0)
		{
			student_addinform(top);
			break;
		}
		else if (strcmp(ch, "2") == 0)
		{
			student_addgrade(top);
			break;
		}
		else if (strcmp(ch, "0") == 0)
		{
			dean_office_interface();
			break;
		}
		else
		{
			printf("\033[31m                              您输入的序号不正确，请重新输入：\033[0m");
		}
	}

}


//函数---教务处端功能1-1（新生信息录入）
void student_addinform(Student* top)
{
	system("cls");                   //清屏
	printf("                              ******************************************************\n");
	printf("                              **                   新生信息录入                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                    1.手动输入                    ||\n");
	printf("                              ||                    2.文件导入                    ||\n");
	printf("                              ||                 返回上一层请按0                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");

	char c[error_test];

	while (1)
	{
		scanf("%s", c);
		if (strcmp(c,"1") == 0)
		{
			student_addinform_hand(top);
			break;
		}
		else if (strcmp(c, "2") == 0)
		{
			student_addinform_file(top);
			break;
		}
		else if (strcmp(c, "0") == 0)
		{
			student_addStu(top);
			break;
		}
		else
		{
			printf("\033[31m                              您输入的序号不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能1-1-1（新生信息手动输入）
void student_addinform_hand(Student* top)
{
	system("cls");

	Student* new = (Student*)malloc(sizeof(Student));                  //新增结点
	Student* now = top->next;                                          //尾结点

	printf("                              请按提示填写新同学信息：\n");
	printf("                              1.姓名：");
	scanf("%s", new->name);
	printf("                              2.性别：");
	scanf("%s", new->sex);
	printf("                              3.学号：");
	scanf("%s", new->num);

	while (now != NULL)
	{

		if (strcmp(now->num, new->num) == 0)                                                //判断学号有无重复（给输错的空间）
		{
			printf("\033[31m                              您输入的学号已存在，请重新输入：\033[0m");
			scanf("%s", new->num);
			now = top->next;
		}
		else
		{
			now = now->next;
		}
	}

	printf("                              4.学院（“学院代码-学院名称”形式）：");
	scanf("%s", new->major);
	printf("                              5.学年（1/2/3）：");
	scanf("%d", &new->semester);
	printf("                              6.所在校区：");
	scanf("%s", new->school_district);
	printf("                              7.初始密码：");
	scanf("%s", new->role_code);


	new->grade = 0;
	new->GPA = 0;
	new->ranking = 0;
	new->credit = 0;
	new->head = NULL;

	now = top->next;

	while (now->next != NULL)
	{
		if ((strcmp(now->major, new->major) == 0) && (now->semester == new->semester))
		{
			if ((strcmp(now->next->major, new->major) != 0) || (now->next->semester != new->semester))
			{
				new->next = now->next;
				now->next = new;
				break;
			}
		}
		now = now->next;
	}

	top = full_ranking2(top);

	printf("\n                              新生信息录入成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续录入请输入1                 ||\n");
	printf("                              ||                 返回上一层请输入2                ||\n");
	printf("                              ||              返回信息增加页面请输入3             ||\n");
	printf("                              ||                  返回首页请输入4                 ||\n");
	printf("                              ||                  退出系统请输入5                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_addinform_hand(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_addinform(top);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			student_addStu(top);
			break;
		}
		else if (strcmp(shift, "4") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "5") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能1-1-2（新生信息文件导入）
void student_addinform_file(Student* top)
{
	Student* now = top->next;                                          //尾结点
	system("cls");
	FILE* fp;
	fp = fopen("newstudent.txt", "r");
	if (fp == NULL)
	{
		printf("FILE NOT FOUNG");
		exit(-1);
	}

	while (1)
	{
		Student* new = (Student*)malloc(sizeof(Student));                  //新增结点
		new->next = NULL;
		now = top->next;
		if (!new)
			exit(-1);
		if (7 != fscanf(fp, "%s%s%s%s%d%s%s", new->name, new->sex, new->num, new->major, &new->semester, new->school_district, new->role_code))
		{
			free(new);
			break;
		}                                                     //fscanf返回值不是7即为数据读完，录入完毕，释放空间，退出循环
		strcat(new->name, "\0");
		strcat(new->sex, "\0");
		strcat(new->num, "\0");
		strcat(new->major, "\0");
		strcat(new->school_district, "\0");
		strcat(new->role_code, "\0");

		new->grade = (float)0;
		new->GPA = (float)0;
		new->ranking = 0;
		new->credit = 0;
		new->head = NULL;

		while (now->next != NULL)
		{
			if ((strcmp(now->major, new->major) == 0) && (now->semester == new->semester))
			{
				if ((strcmp(now->next->major, new->major) != 0) || (now->next->semester != new->semester))
				{
					new->next = now->next;
					now->next = new;
					break;
				}
			}
			now = now->next;
		}
	}

	fclose(fp);

	top = full_ranking2(top);

	printf("\n                              新生信息录入成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续录入请输入1                 ||\n");
	printf("                              ||                 返回上一层请输入2                ||\n");
	printf("                              ||              返回信息增加页面请输入3             ||\n");
	printf("                              ||                  返回首页请输入4                 ||\n");
	printf("                              ||                  退出系统请输入5                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_addinform_file(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_addinform(top);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			student_addStu(top);
			break;
		}
		else if (strcmp(shift, "4") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "5") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能1-2（学期成绩录入）
void student_addgrade(Student* top)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **                   学期成绩录入                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                    1.手动输入                    ||\n");
	printf("                              ||                    2.文件导入                    ||\n");
	printf("                              ||                 返回上一层请按0                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您的录入方式（输入前方的序号）：");

	char y[error_test];

	while (1)
	{

		scanf("%s", y);

		if (strcmp(y,"1") == 0)
		{
			student_addgrade_hand(top);
			break;
		}
		else if (strcmp(y, "2") == 0)
		{
			student_addgrade_file(top);
			break;
		}
		else if (strcmp(y, "0") == 0)
		{
			student_addStu(top);
			break;
		}
		else
		{
			printf("\033[31m                              您输入的序号不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能1-2-1（学期成绩手动输入）
void student_addgrade_hand(Student* top)
{
	system("cls");
	printf("                              请输入您要录入成绩的学生学号：");
	char stunum[20];

	Student* q = top->next;
	int n = 0;
	while (1)
	{
		scanf("%s", stunum);                       //录入成绩的学生学号
		q = top->next;
		while (q != NULL)
		{
			if (strcmp(stunum, q->num) == 0)                  //找到该学生
			{
				chengji* tmp = q->head->next;
				while (tmp->next != NULL)                     //找到该学生成绩链表的链表尾
				{
					tmp = tmp->next;
				}

				printf("                              请输入您要录入的学科数量：");
				int i, k;
				scanf("%d", &i);

				printf("                              请根据提示填入成绩信息：\n\n");


				for (k = 1; k <= i; k++)
				{
					chengji* p = (chengji*)malloc(sizeof(chengji));

					printf("                              *学科%d：\n", k);
					printf("                              1.修读学期：");
					scanf("%d", &p->xueqi);
					printf("                              2.学分：");
					scanf("%d", &p->xuefen);
					q->credit = q->credit + p->xuefen;
					printf("                              3.学科名：");
					scanf("%s", p->xueke);
					printf("                              4.成绩：");
					scanf("%f", &p->chengji);
					p->jidian = 0;

					if (p->xueqi != q->semester)
					{
						if (p->xueqi > q->semester)
						{
							q->semester = p->xueqi;
						}
					}

					tmp->next = p;
					tmp = p;
					tmp->next = NULL;

				}
				break;
			}
			else
			{
				q = q->next;
				n++;
			}
		}
		if (sknotNumber(top) == n)
		{
			printf("\033[31m                              该学号不存在，请重新输入：\033[0m");
			n = 0;
		}
		else
		{
			break;
		}
	}
	top = GPA(top);
	top = PJGPA(top);
	top = jiafen(top);
	top = full_ranking2(top);

	printf("\n                              成绩录入成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续录入请输入1                 ||\n");
	printf("                              ||                 返回上一层请输入2                ||\n");
	printf("                              ||              返回信息增加页面请输入3             ||\n");
	printf("                              ||                  返回首页请输入4                 ||\n");
	printf("                              ||                  退出系统请输入5                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");

	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_addgrade_hand(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_addgrade(top);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			student_addStu(top);
			break;
		}
		else if (strcmp(shift, "4") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "5") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能1-2-2（学期成绩文件导入）
void student_addgrade_file(Student* top)
{
	system("cls");

	FILE* fpp = NULL;
	fpp = fopen("newgrade.txt", "r+");
	char stunum[20], stuname[20];

	if (fpp == NULL)
	{
		printf("FILE NOT FOUNG");
		exit(-1);
	}

	Student* tmp = top->next;
	chengji* tail = (chengji*)malloc(sizeof(chengji));
	while (1)
	{
		if (2 != fscanf(fpp, "%s%s", stuname, stunum))
		{
			break;
		}
		strcat(stuname, "\0");
		strcat(stunum, "\0");
		tmp = top->next;
		while (tmp != NULL)
		{
			if (strcmp(stunum, tmp->num) == 0)
			{
				tail = tmp->head->next;
				while (tail->next != NULL)
				{
					tail = tail->next;
				}
				while (1)
				{
					chengji* nnew = (chengji*)malloc(sizeof(chengji));
					if (5 != fscanf(fpp, "%d%d%s%f%f", &nnew->xueqi, &nnew->xuefen, nnew->xueke, &nnew->chengji, &nnew->jidian))
					{
						break;
					}
					strcat(nnew->xueke, "\0");
					tmp->credit = tmp->credit + nnew->xuefen;

					tail->next = nnew;
					tail = tail->next;
					tail->next = NULL;
				}
				break;
			}
			else
			{
				tmp = tmp->next;
			}
		}
	}
	fclose(fpp);

	top = GPA(top);
	top = PJGPA(top);
	top = jiafen(top);
	top = full_ranking2(top);

	printf("\n                              成绩录入成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续录入请输入1                 ||\n");
	printf("                              ||                 返回上一层请输入2                ||\n");
	printf("                              ||              返回信息增加页面请输入3             ||\n");
	printf("                              ||                  返回首页请输入4                 ||\n");
	printf("                              ||                  退出系统请输入5                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_addgrade_file(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_addgrade(top);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			student_addStu(top);
			break;
		}
		else if (strcmp(shift, "4") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "5") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能2（学生信息移除）
void student_deleteStu(Student* top)
{

	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **                    学生信息移除                  **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");

	printf("                              请输入该学生的学号：");

	Paper* head1 = Paper_build();
	Paper* p1, * q1;
	p1 = head1;
	q1 = head1->next;
	Awards* head2 = Awards_build();
	Awards* p2, * q2;
	q2 = head2->next;
	p2 = head2;
	Project* head3 = Project_build();
	Project* p3, * q3;
	q3 = head3->next;
	p3 = head3;
	Student* q = top->next;
	Student* p = top;
	int n = 0;
	char delenum[20];
	while (1)
	{
		scanf("%s", delenum);
		while (q != NULL)
		{
			if (strcmp(delenum, q->num) == 0)
			{
				p->next = q->next;
				free(q);
				n = n - 1;
				break;

			}
			else
			{
				p = q;
				q = q->next;
				n++;
			}
		}
		if (sknotNumber(top) == n)
		{
			printf("\033[31m                              您输入的学号不存在，请重新输入：\033[0m");
			n = 0;
			p = top;
			q = top->next;
		}
		else
		{
			break;
		}
	}
	int a1 = 0;
	while (q1 != NULL)
	{
		if (strcmp(q1->Paper_student_number, delenum) == 0)
		{
			a1 = 1;
			p1->next = q1->next;
			p1 = head1;
			q1 = head1->next;
		}
		else
		{
			p1 = p1->next;
			q1 = q1->next;
		}
	}
	int a2 = 0;
	while (q2 != NULL)
	{
		if (strcmp(q2->Awards_student_number, delenum) == 0)
		{
			a2 = 1;
			p2->next = q2->next;
			p2 = head2;
			q2 = head2->next;
		}
		else
		{
			p2 = p2->next;
			q2 = q2->next;
		}
	}
	int a3 = 0;
	while (q3 != NULL)
	{
		if (strcmp(q3->Project_student_number, delenum) == 0)
		{
			a3 = 1;
			p3->next = q3->next;
			p3 = head3;
			q3 = head3->next;
		}
		else
		{
			p3 = p3->next;
			q3 = q3->next;
		}
	}
	if (sknotNumber(top) != n)
	{
		if (a1 != 0)
		{
			FILE* fpp1;
			Paper* tmp1;
			fpp1 = fopen("paper.txt", "w");
			if (fpp1 == NULL)
			{
				printf("FILE NOT FOUND");
				exit(0);
			}
			tmp1 = head1->next;
			while (tmp1 != NULL)
			{
				fprintf(fpp1, "%s  %s  %s  %s  %s  %s  %s  \n", tmp1->Paper_student_number, tmp1->Paper_writer, tmp1->Paper_name, tmp1->Paper_time, tmp1->Paper_page, tmp1->Paper_level, tmp1->Paper_points);
				tmp1 = tmp1->next;
			}


			fclose(fpp1);
		}
		if (a2 != 0)
		{
			Awards* tmp2;
			FILE* fpp2;
			fpp2 = fopen("award.txt", "w");
			if (fpp2 == NULL)
			{
				printf("FILE NOT FOUND");
				exit(0);
			}
			tmp2 = head2->next;
			while (tmp2 != NULL)
			{
				fprintf(fpp2, "%s  %s  %s  %s  %s  %s\n", tmp2->Awards_student_number, tmp2->Award_project_name, tmp2->Award_unit, tmp2->Award_name, tmp2->Award_level, tmp2->Award_time);
				tmp2 = tmp2->next;
			}
			fclose(fpp2);
		}
		if (a3 != 0)
		{
			FILE* fpp3;
			Project* tmp3;
			fpp3 = fopen("project.txt", "w");
			if (fpp3 == NULL)
			{
				printf("FILE NOT FOUND");
				exit(0);
			}
			tmp3 = head3->next;
			while (tmp3 != NULL)
			{
				fprintf(fpp3, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp3->Project_student_number, tmp3->Project_writer, tmp3->Project_teacher_name, tmp3->Project_name, tmp3->Project_number, tmp3->Project_start_time, tmp3->Project_end_time, tmp3->Project_status);
				tmp3 = tmp3->next;
			}
			fclose(fpp3);
		}
	}
	top = full_ranking2(top);

	printf("\n                              学生信息删除成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                   继续移除请输入1                ||\n");
	printf("                              ||                   返回首页请输入2                ||\n");
	printf("                              ||                   退出系统请输入3                ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_deleteStu(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能3（学生信息查询）
void student_queryStu(Student* top)
{
	system("cls");                //清屏

	printf("                              ******************************************************\n");
	printf("                              **                   学生信息查询                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                1.查询全部学生信息                ||\n");
	printf("                              ||                 2.查询某学生信息                 ||\n");
	printf("                              ||                  3.查询学生排名                  ||\n");
	printf("                              ||                  返回上一层请按0                 ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");                             //界面

	char ch[error_test];         //选项

	while (1)
	{
		scanf("%s", ch);
		if (strcmp(ch,"1") == 0)
		{
			student_print_S(top);
			break;
		}
		else if (strcmp(ch, "2") == 0)
		{
			student_single_query(top);
			break;
		}
		else if (strcmp(ch, "3") == 0)
		{
			student_ranking(top);
			break;
		}
		else if (strcmp(ch, "0") == 0)
		{
			dean_office_interface();
			break;
		}
		else
		{
			printf("\033[31m\n                              您输入的序号不正确，请重新输入：\033[0m");
		}
	}

}


//函数---教务处端功能3-2（查询某学生信息）
void student_single_query(Student* top)
{
	system("cls");
	int start1;
start1:
	printf("                              **********************************************\n");
	printf("                              **              查询某学生信息              **\n");
	printf("                              **********************************************\n");
	printf("                                                                            \n");
	printf("                              *      请输入您的查询方式（支持模糊查询）：  *\n");
	printf("                              *               1.姓名查询                   *\n");
	printf("                              *               2.学号查询                   *\n");
	printf("                                             （输入前方的序号即可）：       \n");
	printf("                              *               #按“0”返回上一界面#        *\n");
	printf("                              ");
	char search_way[error_test];
	scanf("%s", search_way);
	system("cls");
	if (strcmp(search_way,"1") == 0) {
		printf("                              *      请输入您想查询学生姓名的关键字：    *  \n");
		printf("                              *          #按“0”返回上一界面#           *  \n");
		printf("                              ");
		char input[20];
		int q = 0;
		while (q == 0) {
			scanf("%s", input);
			if (strcmp(input, "0") == 0) {

				goto start1;
			}
			else {
				Student* current = top;
				int found = 0;
				while (current != NULL) {
					if (strstr(current->name, input) != NULL) {
						printf("\n\033[44m姓名       性别       学号         学院           学年        校区            均分       GPA       排名\033[0m\n");
						printf("%-10s %-10s %-12s %-15s %-10d %-15s %-10.1f %-10.2f %-10d\n", current->name, current->sex, current->num, current->major, current->semester, current->school_district, current->grade, current->GPA, current->ranking);
						chengji_print_S(current->head);
						found = 1;
						q = 1;
					}
					current = current->next;
				}
				current = top;
				if (!found) {
					printf("\033[31m                              对不起，无相关学生,请重新输入关键字:\033[0m");
				}
			}
		}
		printf("\n***********************继续查询请按1，返回查询首页请按2，返回个人首页请按3,退出系统请按4***************************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start1;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m选项输入不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(search_way, "2") == 0) {
		printf("                        *请输入您想查询学生学号（可输入任意位数，查询学号包含输入数字的所有学生）：*  \n");
		printf("                        *                          #按“0”返回上一界面#                           *  \n");
		printf("                        ");
		char input[20];
		int q = 0;
		while (q == 0) {
			scanf("%s", input);
			if (strcmp(input, "0") == 0) {
				goto start1;
			}
			else {
				Student* current = top;
				int found = 0;
				while (current != NULL) {
					if (strstr(current->num, input) != NULL) {
						printf("\n\033[44m姓名       性别       学号         学院           学年        校区            均分       GPA       排名\033[0m\n");
						printf("%-10s %-10s %-12s %-15s %-10d %-15s %-10.1f %-10.2f %-10d\n", current->name, current->sex, current->num, current->major, current->semester, current->school_district, current->grade, current->GPA, current->ranking);
						chengji_print_S(current->head);
						found = 1;
						q = 1;
					}
					current = current->next;
				}
				current = top;
				if (!found) {
					printf("\033[31m                        对不起，无相关学生,请重新输入学号内容:\033[0m");
				}
			}
		}
		printf("\n***********************继续查询请按1，返回查询首页请按2，返回教务处端首页请按3,退出系统请按4***************************\n");
		
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start1;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m选项输入不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(search_way, "0") == 0) {
		student_queryStu(top);
	}
	else {
		printf("\033[31m无该查询类别！请重新输入您的查询方式：\033[0m\n");
		goto start1;
	}
}


//函数---教务处端功能3-3（学生排名查询）
void student_ranking(Student* top)
{
	system("cls");
	int start3;
start3:
	printf("                              **********************************************\n");
	printf("                              **               学生排名查询               **\n");
	printf("                              **********************************************\n");
	printf("                                                                            \n");
	printf("                              *            请选择您需要查询的专业：        *\n");
	printf("                              *             1.软件                         *\n");
	printf("                              *             2.法学                         *\n");
	printf("                              *             3.建筑                         *\n");
	printf("                              *             4.经济                         *\n");
	printf("                              *             5.物理                         *\n");
	printf("                              *             6.数学                         *\n");
	printf("                              *             7.外语                         *\n");
	printf("                              *             8.临床医学                     *\n");
	printf("                              *             9.汉语言文学                   *\n");
	printf("                              *             10.计算机科学与技术            *\n");
	printf("                                           （输入前方的序号即可）          *\n");
	printf("                              *             #按“0”返回上一界面#          *\n");
	char choice_major[error_test];
	scanf("%s", choice_major);
	system("cls");
	if (strcmp(choice_major,"1") == 0) {
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				top=sort_grade_up(top, "55", 1);
				sort_print(top, "55", 1);
			}
			else if (sort_way == 4) {
				top=sort_grade_down(top, "55", 1);
				sort_print(top, "55", 1);
			}
			else if (sort_way == 1) {
				top=sort_GPA_up(top, "55", 1);
				sort_print(top, "55", 1);
			}
			else if (sort_way == 2) {
				top=sort_GPA_down(top, "55", 1);
				sort_print(top, "55", 1);
			}
			else if (sort_way == 5) {
				top=sort_num_up(top, "55", 1);
				sort_print(top, "55", 1);
			}
			else if (sort_way == 6) {
				top=sort_num_down(top, "55", 1);
				sort_print(top, "55", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				top=sort_grade_up(top, "55", 2);
				sort_print(top, "55", 2);
			}
			else if (sort_way == 4) {
				top=sort_grade_down(top, "55", 2);
				sort_print(top, "55", 2);
			}
			else if (sort_way == 1) {
				top=sort_GPA_up(top, "55", 2);
				sort_print(top, "55", 2);
			}
			else if (sort_way == 2) {
				top=sort_GPA_down(top, "55", 2);
				sort_print(top, "55", 2);
			}
			else if (sort_way == 5) {
				top=sort_num_up(top, "55", 2);
				sort_print(top, "55", 2);
			}
			else if (sort_way == 6) {
				top=sort_num_down(top, "55", 2);
				sort_print(top, "55", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				top=sort_grade_up(top, "55", 3);
				sort_print(top, "55", 3);
			}
			else if (sort_way == 4) {
				top=sort_grade_down(top, "55", 3);
				sort_print(top, "55", 3);
			}
			else if (sort_way == 1) {
				top=sort_GPA_up(top, "55", 3);
				sort_print(top, "55", 3);
			}
			else if (sort_way == 2) {
				top=sort_GPA_down(top, "55", 3);
				sort_print(top, "55", 3);
			}
			else if (sort_way == 5) {
				top=sort_num_up(top, "55", 3);
				sort_print(top, "55", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "55", 3);
				sort_print(top, "55", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "2") == 0) {
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "07", 1);
				sort_print(top, "07", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "07", 1);
				sort_print(top, "07", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "07", 1);
				sort_print(top, "07", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "07", 1);
				sort_print(top, "07", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "07", 1);
				sort_print(top, "07", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "07", 1);
				sort_print(top, "07", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "07", 2);
				sort_print(top, "07", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "07", 2);
				sort_print(top, "07", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "07", 2);
				sort_print(top, "07", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "07", 2);
				sort_print(top, "07", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "07", 2);
				sort_print(top, "07", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "07", 2);
				sort_print(top, "07", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "07", 3);
				sort_print(top, "07", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "07", 3);
				sort_print(top, "07", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "07", 3);
				sort_print(top, "07", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "07", 3);
				sort_print(top, "07", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "07", 3);
				sort_print(top, "07", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "07", 3);
				sort_print(top, "07", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "3") == 0) {
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "24", 1);
				sort_print(top, "24", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "24", 1);
				sort_print(top, "24", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "24", 1);
				sort_print(top, "24", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "24", 1);
				sort_print(top, "24", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "24", 1);
				sort_print(top, "24", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "24", 1);
				sort_print(top, "24", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "24", 2);
				sort_print(top, "24", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "24", 2);
				sort_print(top, "24", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "24", 2);
				sort_print(top, "24", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "24", 2);
				sort_print(top, "24", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "24", 2);
				sort_print(top, "24", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "24", 2);
				sort_print(top, "24", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3, "24", 3) {
				sort_grade_up(top, "24", 3);
				sort_print(top, "24", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "24", 3);
				sort_print(top, "24", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "24", 3);
				sort_print(top, "24", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "24", 3);
				sort_print(top, "24", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "24", 3);
				sort_print(top, "24", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "24", 3);
				sort_print(top, "24", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "4") == 0) {
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "06", 1);
				sort_print(top, "06", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "06", 1);
				sort_print(top, "06", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "06", 1);
				sort_print(top, "06", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "06", 1);
				sort_print(top, "06", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "06", 1);
				sort_print(top, "06", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "06", 1);
				sort_print(top, "06", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "06", 2);
				sort_print(top, "06", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "06", 2);
				sort_print(top, "06", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "06", 2);
				sort_print(top, "06", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "06", 2);
				sort_print(top, "06", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "06", 2);
				sort_print(top, "06", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "06", 2);
				sort_print(top, "06", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "06", 3);
				sort_print(top, "06", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "06", 3);
				sort_print(top, "06", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "06", 3);
				sort_print(top, "06", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "06", 3);
				sort_print(top, "06", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "06", 3);
				sort_print(top, "06", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "06", 3);
				sort_print(top, "06", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "5") == 0) {
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "11", 1);
				sort_print(top, "11", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "11", 1);
				sort_print(top, "11", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "11", 1);
				sort_print(top, "11", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "11", 1);
				sort_print(top, "11", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "11", 1);
				sort_print(top, "11", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "11", 1);
				sort_print(top, "11", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "11", 2);
				sort_print(top, "11", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "11", 2);
				sort_print(top, "11", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "11", 2);
				sort_print(top, "11", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "11", 2);
				sort_print(top, "11", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "11", 2);
				sort_print(top, "11", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "11", 2);
				sort_print(top, "11", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(top, "11", 3);
				sort_print(top, "11", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(top, "11", 3);
				sort_print(top, "11", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(top, "11", 3);
				sort_print(top, "11", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(top, "11", 3);
				sort_print(top, "11", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(top, "11", 3);
				sort_print(top, "11", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(top, "11", 3);
				sort_print(top, "11", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "6") == 0) {
		Student* head = top;
		int start_choice_year1;
	start_choice_year1:
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "10", 1);
				sort_print(head, "10", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "10", 1);
				sort_print(head, "10", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "10", 1);
				sort_print(head, "10", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "10", 1);
				sort_print(head, "10", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "10", 1);
				sort_print(head, "10", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "10", 1);
				sort_print(head, "10", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "10", 2);
				sort_print(head, "10", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "10", 2);
				sort_print(head, "10", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "10", 2);
				sort_print(head, "10", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "10", 2);
				sort_print(head, "10", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "10", 2);
				sort_print(head, "10", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "10", 2);
				sort_print(head, "10", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "10", 3);
				sort_print(head, "10", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "10", 3);
				sort_print(head, "10", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "10", 3);
				sort_print(head, "10", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "10", 3);
				sort_print(head, "10", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "10", 3);
				sort_print(head, "10", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "10", 3);
				sort_print(head, "10", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else {
			printf("无该年级学生，请重新输入！");
			goto start_choice_year1;
		}

		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "7") == 0) {
		Student* head = top;
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "03", 1);
				sort_print(head, "03", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "03", 1);
				sort_print(head, "03", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "03", 1);
				sort_print(head, "03", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "03", 1);
				sort_print(head, "03", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "03", 1);
				sort_print(head, "03", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "03", 1);
				sort_print(head, "03", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "03", 2);
				sort_print(head, "03", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "03", 2);
				sort_print(head, "03", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "03", 2);
				sort_print(head, "03", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "03", 2);
				sort_print(head, "03", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "03", 2);
				sort_print(head, "03", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "03", 2);
				sort_print(head, "03", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "03", 2);
				sort_print(head, "03", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "03", 2);
				sort_print(head, "03", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "03", 2);
				sort_print(head, "03", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "03", 2);
				sort_print(head, "03", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "03", 2);
				sort_print(head, "03", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "03", 2);
				sort_print(head, "03", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "8") == 0) {
		Student* head = top;
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "70", 1);
				sort_print(head, "70", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "70", 1);
				sort_print(head, "70", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "70", 1);
				sort_print(head, "70", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "70", 1);
				sort_print(head, "70", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "70", 1);
				sort_print(head, "70", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "70", 1);
				sort_print(head, "70", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "70", 2);
				sort_print(head, "70", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "70", 2);
				sort_print(head, "70", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "70", 2);
				sort_print(head, "70", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "70", 2);
				sort_print(head, "70", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "70", 2);
				sort_print(head, "70", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "70", 2);
				sort_print(head, "70", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "70", 3);
				sort_print(head, "70", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "70", 3);
				sort_print(head, "70", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "70", 3);
				sort_print(head, "70", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "70", 3);
				sort_print(head, "70", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "70", 3);
				sort_print(head, "70", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "70", 3);
				sort_print(head, "70", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "9") == 0) {
		Student* head = top;
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "14", 1);
				sort_print(head, "14", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "14", 1);
				sort_print(head, "14", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "14", 1);
				sort_print(head, "14", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "14", 1);
				sort_print(head, "14", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "14", 1);
				sort_print(head, "14", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "14", 1);
				sort_print(head, "14", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "14", 2);
				sort_print(head, "14", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "14", 2);
				sort_print(head, "14", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "14", 2);
				sort_print(head, "14", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "14", 2);
				sort_print(head, "14", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "14", 2);
				sort_print(head, "14", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "14", 2);
				sort_print(head, "14", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "14", 3);
				sort_print(head, "14", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "14", 3);
				sort_print(head, "14", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "14", 3);
				sort_print(head, "14", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "14", 3);
				sort_print(head, "14", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "14", 3);
				sort_print(head, "14", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "14", 3);
				sort_print(head, "14", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "10") == 0) {
		Student* head = top;
		sort_choice_year();
		int choice_year;
		printf("                              ");
		scanf("%d", &choice_year);
		if (choice_year == 1) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "21", 1);
				sort_print(head, "21", 1);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "21", 1);
				sort_print(head, "21", 1);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "21", 1);
				sort_print(head, "21", 1);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "21", 1);
				sort_print(head, "21", 1);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "21", 1);
				sort_print(head, "21", 1);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "21", 1);
				sort_print(head, "21", 1);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 2) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "21", 1);
				sort_print(head, "21", 2);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "21", 1);
				sort_print(head, "21", 2);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "21", 1);
				sort_print(head, "21", 2);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "21", 1);
				sort_print(head, "21", 2);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "21", 1);
				sort_print(head, "21", 2);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "21", 1);
				sort_print(head, "21", 2);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}
		}
		else if (choice_year == 3) {
			sort_choice_way();
			int sort_way;
			printf("\n                              ");
			scanf("%d", &sort_way);
			if (sort_way == 0) {
				student_queryStu(top);
			}
			else if (sort_way == 3) {
				sort_grade_up(head, "21", 3);
				sort_print(head, "21", 3);
			}
			else if (sort_way == 4) {
				sort_grade_down(head, "21", 3);
				sort_print(head, "21", 3);
			}
			else if (sort_way == 1) {
				sort_GPA_up(head, "21", 3);
				sort_print(head, "21", 3);
			}
			else if (sort_way == 2) {
				sort_GPA_down(head, "21", 3);
				sort_print(head, "21", 3);
			}
			else if (sort_way == 5) {
				sort_num_up(head, "21", 3);
				sort_print(head, "21", 3);
			}
			else if (sort_way == 6) {
				sort_num_down(head, "21", 3);
				sort_print(head, "21", 3);
			}
			else {
				printf("无该种排名方式，请重新输入：\n");
				goto start3;
			}

		}
		printf("\n*******************继续查询请按1，返回查询主页请按2，返回教务处端主页请按3，退出系统请按4*******************\n");
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				goto start3;
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				student_queryStu(top);
				break;
			}
			else if (strcmp(going, "3") == 0)
			{
				dean_office_interface();
				break;
			}
			else if (strcmp(going, "4") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m输入选项不正确，请重新输入：\033[0m");
			}
		}
	}
	else if (strcmp(choice_major, "0") == 0) {
		system("cls");
		student_queryStu(top);
	}
	else {
		printf("\033[31m对不起，无该专业！\033[0m");
		goto start3;
	}
}


//函数---排名查询年级选择
void sort_choice_year(void) {
	printf("                              *  请选择您需要查询的年级：(输入前面序号即可) *\n");
	printf("                              *             1.23级                          *\n");
	printf("                              *             2.22级                          *\n");
	printf("                              *             3.21级                          *\n");
}


//函数---排名查询方式选择
void sort_choice_way(void) {
	printf("                              *             1.按照平均绩点升序排名        *\n");
	printf("                              *             2.按照平均绩点降序排名        *\n");
	printf("                              *             3.按照平均成绩升序排名        *\n");
	printf("                              *             4.按照平均成绩降序排名        *\n");
	printf("                              *             5.按照学号升序排名        *\n");
	printf("                              *             6.按照学号降序排名        *\n");
	printf("                                           （输入前方的序号即可）          *\n");
}


//函数---排名---按照平均成绩升序排序
Student* sort_grade_up(Student* top, char x[3], int y) {
	Student* p, * p0, * r, * r0, * q;
	p = top->next;
	chengji* t;
	p0 = r = r0 = q = NULL;
	int flag = 0;
	float a;
	int b;
	char str[20];
	while (p != NULL) {
		flag = 0;
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			r = p;
			p0 = p;
			flag = 0;
			while (flag == 0) {
				flag = 1;
				do {
					if (p->next == NULL)break;
					if (p->grade > p->next->grade) {
						a = p->grade;
						p->grade = p->next->grade;
						p->next->grade = a;

						strcpy(str, p->name);
						strcpy(p->name, p->next->name);
						strcpy(p->next->name, str);

						strcpy(str, p->sex);
						strcpy(p->sex, p->next->sex);
						strcpy(p->next->sex, str);

						strcpy(str, p->major);
						strcpy(p->major, p->next->major);
						strcpy(p->next->major, str);

						strcpy(str, p->school_district);
						strcpy(p->school_district, p->next->school_district);
						strcpy(p->next->school_district, str);

						strcpy(str, p->role_code);
						strcpy(p->role_code, p->next->role_code);
						strcpy(p->next->role_code, str);

						a = p->GPA;
						p->GPA = p->next->GPA;
						p->next->GPA = a;

						b = p->ranking;
						p->ranking = p->next->ranking;
						p->next->ranking = b;

						strcpy(str, p->num);
						strcpy(p->num, p->next->num);
						strcpy(p->next->num, str);

						b = p->credit;
						p->credit = p->next->credit;
						p->next->credit = b;

						t = p->head->next;
						p->head->next = p->next->head->next;
						p->next->head->next = t;

						flag = 0;
					}
					if (p->next != NULL) {
						p = p->next;
					}
					else break;
					if (p->next == NULL)break;
				} while (p->next->semester == y);
				p = r;
			}
			break;
		}
		else p = p->next;
		flag = 0;
	}
	return top;
}


//函数---排名---按照平均成绩降序排序
Student* sort_grade_down(Student* top, char x[3], int y) {
	Student* p, * p0, * r, * r0, * q;
	p = top->next;
	chengji* t;
	p0 = r = r0 = q = NULL;
	int flag = 0;
	float a;
	int b;
	char str[20];
	while (p != NULL) {
		flag = 0;
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			r = p;
			p0 = p;
			flag = 0;
			while (flag == 0) {
				flag = 1;
				do {
					if (p->next == NULL)break;
					if (p->grade < p->next->grade) {
						a = p->grade;
						p->grade = p->next->grade;
						p->next->grade = a;

						strcpy(str, p->name);
						strcpy(p->name, p->next->name);
						strcpy(p->next->name, str);

						strcpy(str, p->sex);
						strcpy(p->sex, p->next->sex);
						strcpy(p->next->sex, str);

						strcpy(str, p->major);
						strcpy(p->major, p->next->major);
						strcpy(p->next->major, str);

						strcpy(str, p->school_district);
						strcpy(p->school_district, p->next->school_district);
						strcpy(p->next->school_district, str);

						strcpy(str, p->role_code);
						strcpy(p->role_code, p->next->role_code);
						strcpy(p->next->role_code, str);

						a = p->GPA;
						p->GPA = p->next->GPA;
						p->next->GPA = a;

						b = p->ranking;
						p->ranking = p->next->ranking;
						p->next->ranking = b;

						strcpy(str, p->num);
						strcpy(p->num, p->next->num);
						strcpy(p->next->num, str);

						b = p->credit;
						p->credit = p->next->credit;
						p->next->credit = b;

						t = p->head->next;
						p->head->next = p->next->head->next;
						p->next->head->next = t;
						flag = 0;
					}
					if (p->next != NULL) {
						p = p->next;
					}
					else break;
					if (p->next == NULL)break;
				} while (p->next->semester == y);
				p = r;
			}
			break;

		}
		else p = p->next;
		flag = 0;

	}
	return top;
}


//函数---排名---按照GPA升序排序
Student* sort_GPA_up(Student* top, char x[3], int y) {
	Student* p, * p0, * r, * r0, * q;
	p = top->next;
	chengji* t;
	p0 = r = r0 = q = NULL;
	int flag = 0;
	float a;
	int b;
	char str[20];
	while (p != NULL) {
		flag = 0;
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			r = p;
			p0 = p;
			flag = 0;
			while (flag == 0) {
				flag = 1;
				do {
					if (p->next == NULL)break;
					if (p->GPA > p->next->GPA) {
						a = p->grade;
						p->grade = p->next->grade;
						p->next->grade = a;

						strcpy(str, p->name);
						strcpy(p->name, p->next->name);
						strcpy(p->next->name, str);

						strcpy(str, p->sex);
						strcpy(p->sex, p->next->sex);
						strcpy(p->next->sex, str);

						strcpy(str, p->major);
						strcpy(p->major, p->next->major);
						strcpy(p->next->major, str);

						strcpy(str, p->school_district);
						strcpy(p->school_district, p->next->school_district);
						strcpy(p->next->school_district, str);

						strcpy(str, p->role_code);
						strcpy(p->role_code, p->next->role_code);
						strcpy(p->next->role_code, str);

						a = p->GPA;
						p->GPA = p->next->GPA;
						p->next->GPA = a;

						b = p->ranking;
						p->ranking = p->next->ranking;
						p->next->ranking = b;

						strcpy(str, p->num);
						strcpy(p->num, p->next->num);
						strcpy(p->next->num, str);

						b = p->credit;
						p->credit = p->next->credit;
						p->next->credit = b;

						t = p->head->next;
						p->head->next = p->next->head->next;
						p->next->head->next = t;

						flag = 0;
					}
					if (p->next != NULL) {
						p = p->next;
					}
					else break;
					if (p->next == NULL)break;
				} while (p->next->semester == y);
				p = r;
			}
			break;

		}
		else p = p->next;
		flag = 0;

	}
	return top;
}


//函数---排名---按照GPA降序排序
Student* sort_GPA_down(Student* head, char x[3], int y) {
	Student* p, * p0, * r, * r0, * q;
	p = head->next;
	chengji* t;
	p0 = r = r0 = q = NULL;
	int flag = 0;
	float a;
	int b;
	char str[20];
	while (p != NULL) {
		flag = 0;
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			r = p;
			p0 = p;
			flag = 0;
			while (flag == 0) {
				flag = 1;
				do {
					if (p->next == NULL)break;
					if (p->GPA < p->next->GPA) {
						a = p->grade;
						p->grade = p->next->grade;
						p->next->grade = a;

						strcpy(str, p->name);
						strcpy(p->name, p->next->name);
						strcpy(p->next->name, str);

						strcpy(str, p->sex);
						strcpy(p->sex, p->next->sex);
						strcpy(p->next->sex, str);

						strcpy(str, p->major);
						strcpy(p->major, p->next->major);
						strcpy(p->next->major, str);

						strcpy(str, p->school_district);
						strcpy(p->school_district, p->next->school_district);
						strcpy(p->next->school_district, str);

						strcpy(str, p->role_code);
						strcpy(p->role_code, p->next->role_code);
						strcpy(p->next->role_code, str);

						a = p->GPA;
						p->GPA = p->next->GPA;
						p->next->GPA = a;

						b = p->ranking;
						p->ranking = p->next->ranking;
						p->next->ranking = b;

						strcpy(str, p->num);
						strcpy(p->num, p->next->num);
						strcpy(p->next->num, str);

						b = p->credit;
						p->credit = p->next->credit;
						p->next->credit = b;

						t = p->head->next;
						p->head->next = p->next->head->next;
						p->next->head->next = t;
						flag = 0;
					}
					if (p->next != NULL) {
						p = p->next;
					}
					else break;
					if (p->next == NULL)break;
				} while (p->next->semester == y);
				p = r;
			}
			break;

		}
		else p = p->next;
		flag = 0;

	}
	return head;
}


//函数---排名---按照学号降序
Student* sort_num_down(Student* head, char x[3], int y) {
	Student* p, * p0, * r, * r0, * q;
	p = head->next;
	chengji* t;
	p0 = r = r0 = q = NULL;
	int flag = 0;
	float a;
	int b;
	char str[20];
	while (p != NULL) {
		flag = 0;
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			r = p;
			p0 = p;
			flag = 0;
			while (flag == 0) {
				flag = 1;
				do {
					if (p->next == NULL)break;
					if (strcmp(p->num, p->next->num) < 0) {
						a = p->grade;
						p->grade = p->next->grade;
						p->next->grade = a;

						strcpy(str, p->name);
						strcpy(p->name, p->next->name);
						strcpy(p->next->name, str);

						strcpy(str, p->sex);
						strcpy(p->sex, p->next->sex);
						strcpy(p->next->sex, str);

						strcpy(str, p->major);
						strcpy(p->major, p->next->major);
						strcpy(p->next->major, str);

						strcpy(str, p->school_district);
						strcpy(p->school_district, p->next->school_district);
						strcpy(p->next->school_district, str);

						strcpy(str, p->role_code);
						strcpy(p->role_code, p->next->role_code);
						strcpy(p->next->role_code, str);

						a = p->GPA;
						p->GPA = p->next->GPA;
						p->next->GPA = a;

						b = p->ranking;
						p->ranking = p->next->ranking;
						p->next->ranking = b;

						strcpy(str, p->num);
						strcpy(p->num, p->next->num);
						strcpy(p->next->num, str);

						b = p->credit;
						p->credit = p->next->credit;
						p->next->credit = b;

						t = p->head->next;
						p->head->next = p->next->head->next;
						p->next->head->next = t;
						flag = 0;
					}
					if (p->next != NULL) {
						p = p->next;
					}
					else break;
					if (p->next == NULL)break;
				} while (p->next->semester == y);
				p = r;
			}
			break;

		}
		else p = p->next;
		flag = 0;

	}
	return head;
}


//函数---排名---按照学号升序
Student* sort_num_up(Student* head, char x[3], int y) {
	Student* p, * p0, * r, * r0, * q;
	p = head->next;
	chengji* t;
	p0 = r = r0 = q = NULL;
	int flag = 0;
	float a;
	int b;
	char str[20];
	while (p != NULL) {
		flag = 0;
		if ((strncmp(p->major, x, 2) == 0) && (p->semester == y)) {
			r = p;
			p0 = p;
			flag = 0;
			while (flag == 0) {
				flag = 1;
				do {
					if (p->next == NULL)break;
					if (strcmp(p->num, p->next->num) > 0) {
						a = p->grade;
						p->grade = p->next->grade;
						p->next->grade = a;

						strcpy(str, p->name);
						strcpy(p->name, p->next->name);
						strcpy(p->next->name, str);

						strcpy(str, p->sex);
						strcpy(p->sex, p->next->sex);
						strcpy(p->next->sex, str);

						strcpy(str, p->major);
						strcpy(p->major, p->next->major);
						strcpy(p->next->major, str);

						strcpy(str, p->school_district);
						strcpy(p->school_district, p->next->school_district);
						strcpy(p->next->school_district, str);

						strcpy(str, p->role_code);
						strcpy(p->role_code, p->next->role_code);
						strcpy(p->next->role_code, str);

						a = p->GPA;
						p->GPA = p->next->GPA;
						p->next->GPA = a;

						b = p->ranking;
						p->ranking = p->next->ranking;
						p->next->ranking = b;

						strcpy(str, p->num);
						strcpy(p->num, p->next->num);
						strcpy(p->next->num, str);

						b = p->credit;
						p->credit = p->next->credit;
						p->next->credit = b;

						t = p->head->next;
						p->head->next = p->next->head->next;
						p->next->head->next = t;
						flag = 0;
					}
					if (p->next != NULL) {
						p = p->next;
					}
					else break;
					if (p->next == NULL)break;
				} while (p->next->semester == y);
				p = r;
			}
			break;

		}
		else p = p->next;
		flag = 0;

	}
	return head;
}


//函数---排名---输出排名函数
void sort_print(Student* head, char str[5], int semester1) {
	char str1[5];
	strcpy(str1, str);
	Student* p;
	p = head->next;
	int i = 1;
	while (p != NULL) {
		if ((strncmp(p->major, str1, 2) == 0) && (p->semester == semester1)) {
			printf("%d  ", i);
			printf("%s %s %s %s %d %s %.1f %.2f\n", p->name, p->sex, p->num, p->major, p->semester, p->school_district, p->grade, p->GPA);
			p = p->next;
			i++;
		}
		else p = p->next;
	}
}


//函数---教务处端功能4（学生成绩修改）
void student_modifyStu(Student* top)
{

	system("cls");              //清屏

	printf("                              ******************************************************\n");
	printf("                              **                   学生成绩修改                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              请输入您要修改成绩的学生学号：");                             //界面
	char stunum[20];
	Student* q = top->next;
	int m = 0, n = 0;

	while (1)
	{
		scanf("%s", stunum);                       //学生学号
		while (q != NULL)
		{
			if (strcmp(stunum, q->num) == 0)                  //找到该学生
			{
				chengji* s = q->head->next;
				chengji* p = q->head->next;
				char subject[50];
				printf("                              请输入您要修改的科目名称：");
				while (s != NULL)
				{
					printf("\n                              \033[4m%s\033[0m", s->xueke);
					s = s->next;
				}
				printf("\n                              ");
				while (1)
				{
					m = 0;
					p = q->head->next;
					scanf("%s", subject);
					while (p != NULL)
					{
						if (strcmp(subject, p->xueke) == 0)           //找到该学科
						{
							float gra;
							printf("                              请输入该学生该科目修改后的成绩：");
							scanf("%f", &gra);
							p->chengji = gra;                            //修改成绩
							break;

						}
						else
						{
							p = p->next;
							m++;
						}
					}
					if (m == cknotNumber(q->head))
					{
						printf("\033[31m                              未找到该学科，请重新输入：\033[0m");
					}
					else
					{
						break;
					}
				}
				break;
			}
			else
			{
				q = q->next;
				n++;
			}
		}
		if (sknotNumber(top) == n)
		{
			printf("\033[31m                              该学号不存在，请重新输入：\033[0m");
			n = 0;
			q = top->next;
		}
		else
		{
			break;
		}
	}

	top = GPA(top);
	top = PJGPA(top);
	top = jiafen(top);
	top = full_ranking2(top);

	printf("\n                              修改成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续修改请输入1                 ||\n");
	printf("                              ||                  返回首页请输入2                 ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_modifyStu(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能5（学生学习态度评估及保研预测）
void student_prediction(Student* top)
{
	system("cls");
	printf("                              *****************************************************************\n");
	printf("                              **                 学生学习态度评估及保研预测                  **\n");
	printf("                              *****************************************************************\n\n");
	int start_way;
start_way:
	printf("                              您要通过                         查询需要预测的学生：\n");
	printf("                                              1.学号\n");
	printf("                                              2.姓名\n");
	printf("                                        (该功能仅可预测大二大三学生)\n");
	printf("                                             请输入序号：");
	char pre_way[error_test];
	scanf("%s", pre_way);
	if (strcmp(pre_way,"2") == 0) {
		char input_name[20];
		printf("                              请输入您要预测的学生姓名：");
		scanf("%s", &input_name);
		Student* current = top;
		int found = 0;
		int time = 0;
		while (current != NULL) {

			if (strcmp(current->name, input_name) == 0) {
				chengji* p = current->head->next;//p指向该学生的成绩的头节点
				float sum_xuefen = 0.0;
				float GPA_every_year = 0.0;
				if ((current->semester == 2) || (current->semester == 3)) {

					//x[]数组中存放学期数，相当于横坐标
					for (int i = 0; i < (current->semester) * 2 - 1; i++) {
						x[i] = i + 1;
					}

					//y[]数组中存放每学期的绩点，相当于纵坐标
					for (int j = 0; j < (current->semester); j++) {
						while (p != NULL) {
							if (p->xueqi == j + 1) {
								sum_xuefen += p->xuefen;
								GPA_every_year += (p->xuefen) * (p->jidian);
								p = p->next;
							}
							else
							{
								p = p->next;
							}
						}
						y[j] = GPA_every_year / sum_xuefen;
						sum_xuefen = 0;
						GPA_every_year = 0.0;
						p = current->head->next;
					}

					//调用训练模型
					LinearRegression lr;
					gradient(x, y, (current->semester), &lr);
					int want_pre;
					int start_pre;
				start_pre:
					printf("                              请输入你想查询的学年数：(输入1至4的数字代表学年数)");
					scanf("%d", &want_pre);

					//调用预测函数返回值即为预测成绩
					if ((want_pre > current->semester) && (want_pre <= 4)) {
						printf("                              \033[44m系统预测该学年绩点为：%.2f\033[0m", predict(want_pre, lr));
						printf("\n***************************继续预测请按1，返回教务处端首页请按2,退出系统请按3***************************\n");
						char going[error_test];
						while (1)
						{
							scanf("%s", going);
							if (strcmp(going, "1") == 0)
							{
								goto start_way;
								break;
							}
							else if (strcmp(going, "2") == 0)
							{
								dean_office_interface();
								break;
							}
							else if (strcmp(going, "3") == 0)
							{
								withdraw();
								break;
							}
							else
							{
								printf("\033[31m输入选项不正确，请重新输入：\033[0m");
							}
						}
					}
					else {
						printf("\033[31m                              该学年成绩不可预测，请重新输入！\033[0m");
						goto start_pre;
					}
				}
				else {
					printf("\033[31m                              对不起，该年级学生不可预测！请重新进行预测：\033[0m\n");
					printf("\n");
					goto start_way;
				}
			}
			current = current->next;
			time++;
			if (current->next == NULL) {
				break;
			}
		}
		if (time == 100) {
			printf("\033[31m                              对不起，未找到该学生，请重新预测！\033[0m\n");
			goto start_way;
		}
	}
	else if (strcmp(pre_way, "1") == 0) {
		char input_num[20];
		printf("                              请输入您要预测的学生学号：");
		scanf("%s", &input_num);
		Student* current = top;

		int found = 0;
		int time = 0;//计数器
		while (current != NULL) {
			double x[10];
			double y[10];
			if (strcmp(current->num, input_num) == 0) {
				//x[]数组中存放学期数，相当于横坐标
				chengji* p = current->head->next;//p指向该学生的成绩的头节点
				float sum_xuefen = 0.0;
				float GPA_every_year = 0.0;
				if ((current->semester == 2) || (current->semester == 3)) {
					for (int i = 0; i < current->semester; i++) {
						x[i] = i + 1;
					}

					//y[]数组中存放每学期的绩点，相当于纵坐标
					for (int j = 0; j < (current->semester); j++) {
						while (p != NULL) {
							if (p->xueqi == j + 1) {
								sum_xuefen += p->xuefen;
								GPA_every_year += (p->xuefen) * (p->jidian);
								p = p->next;
							}
							else
							{
								p = p->next;
							}
						}
						y[j] = GPA_every_year / sum_xuefen;
						sum_xuefen = 0;
						GPA_every_year = 0.0;
						p = current->head->next;
					}

					//调用训练模型
					LinearRegression lr;
					gradient(x, y, (current->semester), &lr);
					int want_pre;
					int start_pre1;
				start_pre1:
					printf("                              请输入你想查询的学年数：(输入1至4的数字代表学年数)");
					scanf("%d", &want_pre);
					//调用预测函数返回值即为预测成绩
					if ((want_pre > current->semester) && (want_pre <= 4)) {
						printf("                              \033[44m系统预测该学年绩点为：%.2f\033[0m", predict(want_pre, lr));
						printf("\n***************************继续预测请按1，返回教务处端首页请按2,退出系统请按3***************************\n");
				
						char going[error_test];
						while (1)
						{
							scanf("%s", going);
							if (strcmp(going, "1") == 0)
							{
								goto start_way;
								break;
							}
							else if (strcmp(going, "2") == 0)
							{
								dean_office_interface();
								break;
							}
							else if (strcmp(going, "3") == 0)
							{
								withdraw();
								break;
							}
							else
							{
								printf("\033[31m输入选项不正确，请重新输入：\033[0m");
							}
						}
					}
					else {
						printf("\033[31m                              该学年成绩不可预测，请重新输入！\033[0m");
						goto start_pre1;
					}
				}
				else {
					printf("\033[31m                              对不起，该年级学生不可预测！请重新进行预测：\033[0m\n");
					printf("\n");
					goto start_way;
				}
			}
			current = current->next;
			time++;
			if (current->next == NULL) {
				break;
			}
		}
		if (time == 100) {
			printf("\033[31m                              对不起，未找到该学生，请重新预测！\033[0m\n");
			goto start_way;
		}
	}
	else {
		printf("\033[31m                              无该种输入方式，请重新输入！\033[0m\n");
		goto start_way;
	}

}


//函数---梯度下降算法
void gradient(double* x, double* y, int size, LinearRegression* lr) {
	// 初始化模型参数
	double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;

	// 计算 x、y 的累加和
	for (int i = 0; i < size; i++) {
		sum_x += x[i];
		sum_y += y[i];
		sum_xx += x[i] * x[i];
		sum_xy += x[i] * y[i];
	}

	// 初始化模型参数
	lr->theta0 = 0;
	lr->theta1 = 0;

	// 使用梯度下降进行模型训练
	for (int epoch = 0; epoch < EPOCHS; epoch++) {
		double delta_theta0 = 0, delta_theta1 = 0;

		// 计算偏导数的累加和
		for (int i = 0; i < size; i++) {
			double y_hat = lr->theta0 + lr->theta1 * x[i];//预测值
			delta_theta0 += y_hat - y[i];//预测值与实际值的差，累加
			delta_theta1 += (y_hat - y[i]) * x[i];
		}

		delta_theta0 *= 1.0 / size;
		delta_theta1 *= 1.0 / size;//求平均偏导率

		// 更新模型参数
		lr->theta0 -= ALPHA * delta_theta0;
		lr->theta1 -= ALPHA * delta_theta1;
	}
}


//函数---预测函数
double predict(double x, LinearRegression lr) {
	if ((lr.theta0 + lr.theta1 * x) >= 4) {
		return 3.98;
	}
	else if (lr.theta0 + lr.theta1 * x <= 1) {
		return 1.10;
	}
	else return  lr.theta0 + lr.theta1 * x;
}


//函数---教务处端功能6（教师信息修改）
void teacher_modifyTea(void)
{

	system("cls");                   //清屏
	printf("                              ******************************************************\n");
	printf("                              **                   教师信息修改                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                  1.删除教师信息                  ||\n");
	printf("                              ||                  2.增加教师信息                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                  返回上一层请按0                 ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");                      //教师信息修改界面

	char choice[error_test];                                                   //选项

	while (1)
	{

		scanf("%s", choice);          //输入选项

		if (strcmp(choice,"2") == 0)
		{
			teacher_add();
			break;
		}

		else if (strcmp(choice, "1") == 0)
		{
			teacher_delete();
			break;
		}
		else if (strcmp(choice, "0") == 0)
		{
			dean_office_interface();
			break;
		}
		else
		{
			printf("\033[31m                              您的输入不正确，请输入正确的选项：\033[0m");
		}
	}
}


//函数---教务处端功能6-1（删除教师信息）
void teacher_delete(void)
{

	FILE* fpp = NULL;                                             //为之后修改文件做准备

	Teacher* head = T_build();
	Teacher* p = head->next, * q = head;

	int l = 0, len = knotNumber(head);

	system("cls");                                      //清屏
	printf("                              ******************************************************\n");
	printf("                              **                   删除教师信息                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");

	char delete_nameTea[50], delete_numTea[20], delete_keyTea[20];            //输入的想要删除的教师结点
	printf("                              请按照提示注销教师信息：\n");

	while (1)
	{
		l = 0;
		p = head->next;
		q = head;
		printf("                              1.教师姓名：");                 //输入部分
		scanf("%s", delete_nameTea);
		printf("                              2.教师工号：");
		scanf("%s", delete_numTea);

		while (p != NULL)                                                     //遍历链表，寻找目标结点
		{
			if ((strcmp(delete_numTea, p->T_num) == 0) && (strcmp(delete_nameTea, p->T_name) == 0))
			{
				q->next = p->next;
				break;
			}
			else
			{
				q = p;
				p = p->next;
				l++;
			}
		}

		if (l == len)                                             //验证输入的信息是否正确
		{
			printf("\033[31m                              您输入的信息有误，请重新输入教师信息：\033[0m\n");
		}
		else
		{
			break;
		}
	}

	p = head->next;

	fpp = fopen("teacher.txt", "w");                                           //以复写的方式将删除后的链表重新写入文件

	if (fpp == NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	}

	while (p != NULL)
	{
		fprintf(fpp, "%s\t%s\t%s\n", p->T_name, p->T_num, p->T_key);      //打开文件并进行复写
		p = p->next;
	}

	fclose(fpp);
	printf("\n                              删除成功！\n\n");
	printf("                              ******************************************************\n");
	printf("                              ||                  继续删除请输入1                 ||\n");
	printf("                              ||                 返回上一层请输入2                ||\n");
	printf("                              ||                  返回首页请输入3                 ||\n");
	printf("                              ||                  退出系统请输入4                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");

	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			teacher_delete();
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			teacher_modifyTea();
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "4") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能6-2（增加教师信息）
void teacher_add(void)
{
	FILE* fpp = NULL;                                             //为之后修改文件做准备

	Teacher* head = T_build();
	Teacher* p = head->next, * q = head;

	int l = 0, len = knotNumber(head);

	system("cls");                                      //清屏
	printf("                              ******************************************************\n");
	printf("                              **                   增加教师信息                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");

	char addName[20], addNum[20], addKey[20];

	printf("                              请输入新增教师姓名：");                   //输入姓名
	scanf("%s", addName);

	printf("                              请输入新增教师工号（账号）：");
	scanf("%s", addNum);
	while (p != NULL)
	{
		if (strcmp(addNum, p->T_num) == 0)
		{
			printf("\033[31m                              您输入的账号已存在，请重新输入：\033[0m");   //验证账号是否存在
			scanf("%s", addNum);
			p = head->next;
		}
		else
		{
			p = p->next;
		}
	}

	printf("                              请为新增教师设置初始密码（6位）：");
	while (1)
	{
		scanf("%s", addKey);                                                        //输入密码
		getchar();
		if (strlen(addKey) != 6)                                                    //验证密码长度
		{
			printf("\033[31m                              密码设置不符合要求6位格式，请重新输入：\033[0m");
		}
		else
		{
			break;
		}
	}

	p = head->next;
	while (p != NULL)
	{
		p = p->next;
	}
	p = (Teacher*)malloc(sizeof(Teacher));

	strcpy(p->T_name, addName);                                                     //存入链表尾
	strcpy(p->T_num, addNum);
	strcpy(p->T_key, addKey);

	p->next = NULL;

	fpp = fopen("teacher.txt", "a");
	if (fpp == NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	}
	fprintf(fpp, "%s\t%s\t%s\n", addName, addNum, addKey);                          //打开文件并进行添加
	fclose(fpp);
	printf("\n                              增加成功！\n\n");
	printf("                              ******************************************************\n");
	printf("                              ||                  继续增加请输入1                 ||\n");
	printf("                              ||                 返回上一层请输入2                ||\n");
	printf("                              ||                  返回首页请输入3                 ||\n");
	printf("                              ||                  退出系统请输入4                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			teacher_add();
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			teacher_modifyTea();
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "4") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能7（转专业管理）
void student_transferMajor(Student* top)
{
	system("cls");             //清屏

	printf("                              ******************************************************\n");
	printf("                              **                    转专业管理                    **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              请输入转专业的学生学号：");                                           //界面

	char stunum[20];

	Student* q = top->next;
	Student* qh = top;
	int n = 0;

	while (1)
	{
		scanf("%s", stunum);                       //学生学号
		while (q != NULL)
		{

			if (strcmp(stunum, q->num) == 0)                  //找到该学生
			{
				printf("\n                              请确认是否为该同学：\n\n");
				printf("                              姓名             性别               学号            原专业      学年\n\n");
				printf("                              %-10s\t%-10s\t%-10s\t%-10s\t%-20d", q->name, q->sex, q->num, q->major, q->semester);       //确认过程，防止输入错误

				char answer[5], newmajor[50], newdistrict[50];

				printf("\n\n                              请输入是/否:");
				scanf("%s", answer);

				if (strcmp(answer, "是") == 0)
				{
					printf("\n                              请按照提示输入：");
					printf("\n                              1.新专业（输入格式为专业代码-专业名称）：");
					scanf("%s", newmajor);
					printf("\n                              2.新校区：");
					scanf("%s", newdistrict);

					strcpy(q->major, newmajor);
					strcpy(q->school_district, newdistrict);                          //修改信息

					chengji* pp = q->head->next;
					char nonsubject[20];

					while (1)
					{
						pp = q->head->next;
						int i = 0;
						chengji* sub = q->head->next;
						while (sub != NULL)
						{
							printf("\n                              \033[4m%s\033[0m", sub->xueke);
							sub = sub->next;
						}
						printf("\n                              请输入该学生与转后专业无关的现修学科（请在学科名称后添加'z'：）");      //给无关科目做标记，方便转专业后的排名计算
						scanf("%s", nonsubject);
						while (pp != NULL)
						{
							int size = strlen(pp->xueke);
							if (strncmp(nonsubject, pp->xueke, size) == 0)
							{
								q->credit = q->credit - pp->xuefen;
								strcpy(pp->xueke, nonsubject);
								break;
							}
							else
							{
								pp = pp->next;
								i++;
							}
						}
						if (i == cknotNumber(q->head))
						{
							printf("\n\033[31m                              未找到相关学科！\033[0m");
						}
						printf("\n                              是否还有其他学科（填是/否）：");
						char answ[5];
						scanf("%s", answ);

						if (strcmp(answ, "是") == 0)
						{
							continue;
						}
						else
						{
							break;
						}
					}
					break;
				}

				else
				{
					printf("\033[31m                              请重新输入转专业学生学号：\033[0m");
					q = top->next;
					qh = top;
					n = 0;
					scanf("%s", stunum);                       //学生学号
				}
			}
			else
			{
				qh = q;
				q = q->next;
				n++;
			}
		}
		if (sknotNumber(top) == n)
		{
			printf("\033[31m                              该学号不存在，请重新输入：\033[0m");
			q = top->next;
			qh = top;
			n = 0;
		}
		else
		{
			break;
		}
	}

	Student* q0 = q;
	qh->next = q->next;
	Student* now = top->next;
	while (now->next != NULL)
	{
		if ((strcmp(now->major, q0->major) == 0) && (now->semester == q0->semester))
		{
			if ((strcmp(now->next->major, q0->major) != 0) || (now->next->semester != q0->semester))
			{
				q0->next = now->next;
				now->next = q0;
				break;
			}
		}
		now = now->next;
	}
	top = GPA(top);
	top = PJGPA(top);
	top = jiafen(top);
	top = full_ranking2(top);

	printf("\n                              转专业学生信息修改成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续添加请输入1                 ||\n");
	printf("                              ||                  返回首页请输入2                 ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_transferMajor(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}

}


//函数---教务处端功能8（重修成绩录入）
void student_rebuild(Student* top)
{

	system("cls");                //清屏

	printf("                              ******************************************************\n");
	printf("                              **                   重修成绩录入                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              请输入重修的学生学号：");

	char stunum[20];

	Student* q = top->next;
	int n = 0;
	while (1)
	{
		scanf("%s", stunum);                       //学生学号
		while (q != NULL)
		{
			if (strcmp(stunum, q->num) == 0)                  //找到该学生
			{
				chengji* tmp = q->head->next;
				chengji* tt = q->head->next;
				while (tmp->next != NULL)                     //找到该学生成绩链表的链表尾
				{
					tmp = tmp->next;
				}

				printf("\n                              请输入重修学科名称：");
				chengji* s = q->head->next;
				while (s != NULL)
				{
					printf("\n                              \033[4m%s\033[0m", s->xueke);
					s = s->next;
				}
				printf("\n                              ");
				char rebuildSub[20];
				int m = 0, d, b;

				while (1)
				{
					scanf("%s", rebuildSub);
					while (tt != NULL)
					{
						if (strcmp(rebuildSub, tt->xueke) == 0)
						{
							d = tt->xueqi;
							b = tt->xuefen;
							break;
						}
						else
						{
							tt = tt->next;
							m++;
						}
					}
					if (m == cknotNumber(q->head))
					{
						printf("\033[31m\n                              该学科不存在，请重新输入：\033[0m");
						m = 0;
						tt = q->head->next;
					}
					else
					{
						break;
					}
				}

				chengji* p = (chengji*)malloc(sizeof(chengji));

				strcpy(p->xueke, strcat(rebuildSub, "c"));                       //重修后的学科名后加'c'
				p->xueqi = d;
				p->xuefen = b;
				p->jidian = 0;
				printf("\n                              请输入该学科重修成绩：");
				scanf("%f", &p->chengji);

				tmp->next = p;
				tmp = p;
				tmp->next = NULL;

				break;
			}
			else
			{
				q = q->next;
				n++;
			}
		}
		if (sknotNumber(top) == n)
		{
			printf("\033[31m                              该学号不存在，请重新输入：\033[0m");
			n = 0;
			q = top->next;
		}
		else
		{
			break;
		}
	}

	top = GPA(top);
	top = PJGPA(top);
	top = jiafen(top);
	top = full_ranking2(top);

	printf("\n                              重修成绩录入成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续添加请输入1                 ||\n");
	printf("                              ||                  返回首页请输入2                 ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_rebuild(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能9（降级管理）
void student_degrade(Student* top)
{

	system("cls");                //清屏

	printf("                              ******************************************************\n");
	printf("                              **                     降级管理                     **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              请输入降级的学生学号：");                                         //界面

	char stunum[20];
	Student* q = top->next;
	Student* qh = top;
	int m = 0, n = 0;

	while (1)
	{
		scanf("%s", stunum);                       //学生学号
		while (q != NULL)
		{
			if (strcmp(stunum, q->num) == 0)                  //找到该学生
			{
				printf("\n                              请确认是否为该同学：\n\n");
				printf("                              姓名             性别               学号             专业        学年\n\n");
				printf("                              %-10s\t%-10s\t%-10s\t%-10s\t%-20d", q->name, q->sex, q->num, q->major, q->semester);       //确认过程，防止输入错误

				char answer[5];
				printf("\n\n                              请输入是/否:");
				scanf("%s", answer);

				if (strcmp(answer, "是") == 0)
				{
					q->semester -= 1;                             //学年管理
					break;
				}
				else
				{
					printf("\033[31m                              请重新输入申请降级的学生学号：\033[0m");
					qh = top;
					q = top->next;
					n = 0;
					scanf("%s", stunum);                       //学生学号
				}

			}
			else
			{
				qh = q;
				q = q->next;
				n++;
			}
		}
		if (sknotNumber(top) == n)
		{
			printf("\033[31m                              该学号不存在，请重新输入：\033[0m");
			q = top->next;
			qh = top;
			n = 0;
		}
		else
		{
			break;
		}
	}
	Student* q0 = q;
	qh->next = q->next;
	Student* now = top->next;
	while (now->next != NULL)
	{
		if ((strcmp(now->major, q0->major) == 0) && (now->semester == q0->semester))
		{
			if ((strcmp(now->next->major, q0->major) != 0) || (now->next->semester != q0->semester))
			{
				q0->next = now->next;
				now->next = q0;
				break;
			}
		}
		now = now->next;
	}

	top = full_ranking2(top);

	printf("\n                              降级信息修改成功！\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续添加请输入1                 ||\n");
	printf("                              ||                  返回首页请输入2                 ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_degrade(top);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能10（大三保研排名）
void graduate_recommendation_ranking(Student* top)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **                   大三保研排名                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              请输入您要查询的学院（“学院代号-学院名称”形式）：");
	char searchMajor[50];
	Student* tmp = top->next;
	while (1)
	{
		scanf("%s", searchMajor);
		tmp = top->next;
		int kk = 0;
		while (tmp != NULL)
		{
			if (strcmp(searchMajor, tmp->major) == 0)
			{
				break;
			}
			else
			{
				kk++;
			}
			tmp = tmp->next;
		}
		if (kk == sknotNumber(top))
		{
			printf("\033[31m                              该学院不存在，请重新输入：\033[0m");
		}
		else
		{
			break;
		}
	}
	tmp = top->next;
	Student* front = top;
	chengji* rmp = NULL;
	while (tmp != NULL)
	{
		if ((tmp->semester == 3) && (strcmp(searchMajor, tmp->major) == 0))
		{
			float grade_sum = 0;
			float credit_sum = 0;
			rmp = tmp->head->next;
			char p;
			while (rmp != NULL)
			{
				if ((rmp->xueke[strlen(rmp->xueke) - 1] != 'z') && (rmp->xueke[strlen(rmp->xueke) - 1] != 'c'))
				{
					grade_sum += ((rmp->jidian) * (rmp->xuefen));
					credit_sum += rmp->xuefen;
				}
				rmp = rmp->next;
			}
			tmp->GPA = grade_sum / credit_sum;
		}
		tmp = tmp->next;
	}
	front = top;
	tmp = top->next;
	while (tmp != NULL)
	{
		rmp = tmp->head->next;
		if ((tmp->semester != 3) || (strcmp(searchMajor, tmp->major) != 0))
		{
			front->next = tmp->next;
			tmp = front->next;
		}
		else
		{
			int number = cknotNumber(tmp->head);
			int k = 0;
			while (rmp != NULL)
			{
				if (rmp->chengji < 60)
				{
					front->next = tmp->next;
					tmp = front->next;
					break;
				}
				k++;
				rmp = rmp->next;
			}
			if (k == number)
			{
				front = tmp;
				tmp = tmp->next;
			}
		}

	}
	top = not_write_jiafen(top);

	int i = 0, count = 0, num;
	Student* p, * q, * tail;
	p = top->next;
	count = sknotNumber(top);
	for (i = 0; i < count - 1; i++)
	{
		num = count - i - 1;
		q = top->next;
		p = q->next;
		tail = top;
		while (num--)
		{
			if (q->GPA < p->GPA)
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;
			q = tail->next;
			p = q->next;
		}
	}

	if (sknotNumber(top) >= 2)
	{
		p = top;
		q = top->next;
		tail = q->next;
		chengji* m1, * m2;
		while (tail != NULL)
		{
			if (q->GPA == tail->GPA)
			{
				m1 = q->head->next;
				m2 = tail->head->next;
				while (m1 != NULL)
				{
					if (strcmp(m1->xueke, "英语") == 0)
					{
						break;
					}
					m1 = m1->next;
				}
				while (m2 != NULL)
				{
					if (strcmp(m2->xueke, "英语") == 0)
					{
						break;
					}
					m2 = m2->next;
				}
				if (m1->jidian < m2->jidian)
				{
					q->next = tail->next;
					p->next = tail;
					tail->next = q;
				}
				else if (m1->jidian == m2->jidian)
				{
					m1 = q->head->next;
					m2 = tail->head->next;
					while (m1 != NULL)
					{
						if (strcmp(m1->xueke, "微积分1") == 0)
						{
							break;
						}
						m1 = m1->next;
					}
					while (m2 != NULL)
					{
						if (strcmp(m2->xueke, "微积分1") == 0)
						{
							break;
						}
						m2 = m2->next;
					}
					if (m1->jidian < m2->jidian)
					{
						q->next = tail->next;
						p->next = tail;
						tail->next = q;
					}

				}
			}
			p = p->next;
			q = q->next;
			tail = tail->next;
		}
	}

	if (sknotNumber(top) == 0)
		printf("\033[31m\n                              没有找到符合保研条件的学生！\033[0m\n");
	else
	{
		int r = 1;
		printf("\n                              排名      姓名              学号          GPA\n\n");
		Student* tt = top->next;
		while (tt != NULL)
		{
			printf("                              %-5d\t%-15s\t%-15s\t%-10.2f\n", r++, tt->name, tt->num, tt->GPA);
			tt = tt->next;
		}
	}
	printf("\n\n                              ******************************************************\n");
	printf("                              ||                  返回首页请输入1                 ||\n");
	printf("                              ||                  退出系统请输入2                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能11（大三出国排名）
void graduate_abroad_ranking(Student* top)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                              **                   大三出国排名                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              请输入您要查询的学院（“学院代号-学院名称”形式）：");
	char searchMajor[50];
	Student* tmp = top->next;
	while (1)
	{
		scanf("%s", searchMajor);
		tmp = top->next;
		int kk = 0;
		while (tmp != NULL)
		{
			if (strcmp(searchMajor, tmp->major) == 0)
			{
				break;
			}
			else
			{
				kk++;
			}
			tmp = tmp->next;
		}
		if (kk == sknotNumber(top))
		{
			printf("\033[31m                              该学院不存在，请重新输入：\033[0m");
		}
		else
		{
			break;
		}
	}
	tmp = top->next;
	Student* front = top;
	chengji* rmp = NULL, * kmp = NULL;
	while (tmp != NULL)
	{
		if ((tmp->semester == 3) && (strcmp(searchMajor, tmp->major) == 0))
		{
			float grade_sum = 0;
			float credit_sum = 0;
			rmp = tmp->head->next;
			char p;

			while (rmp != NULL)
			{
				if (rmp->xueke[strlen(rmp->xueke) - 1] == 'c')
				{
					kmp = tmp->head->next;
					while (kmp != NULL)
					{
						if ((strncmp(rmp->xueke, kmp->xueke, (strlen(rmp->xueke) - 1))==0) && (rmp != kmp))
						{
							kmp->chengji = (kmp->chengji) > (rmp->chengji) ? (kmp->chengji) : (rmp->chengji);
							kmp->jidian = (kmp->jidian) > (rmp->jidian) ? (kmp->jidian) : (rmp->jidian);
							break;
						}
						kmp = kmp->next;
					}
				}
				rmp = rmp->next;
			}

			rmp = tmp->head->next;
			while (rmp != NULL)
			{
				if ((rmp->xueke[strlen(rmp->xueke) - 1] != 'z') && (rmp->xueke[strlen(rmp->xueke) - 1] != 'c'))
				{
					grade_sum += ((rmp->jidian) * (rmp->xuefen));
					credit_sum += rmp->xuefen;
				}
				rmp = rmp->next;
			}
			tmp->GPA = grade_sum / credit_sum;
		}
		tmp = tmp->next;
	}
	front = top;
	tmp = top->next;
	while (tmp != NULL)
	{
		rmp = tmp->head->next;
		if ((tmp->semester != 3) || (strcmp(searchMajor, tmp->major) != 0))
		{
			front->next = tmp->next;
			tmp = front->next;
		}
		else
		{
			front = tmp;
			tmp = tmp->next;
		}
	}

	top = not_write_jiafen(top);

	int i = 0, count = 0, num;
	Student* p, * q, * tail;
	p = top->next;
	count = sknotNumber(top);
	for (i = 0; i < count - 1; i++)
	{
		num = count - i - 1;
		q = top->next;
		p = q->next;
		tail = top;
		while (num--)
		{
			if (q->GPA < p->GPA)
			{
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;
			q = tail->next;
			p = q->next;
		}
	}
	if (sknotNumber(top) >= 2)
	{
		p = top;
		q = top->next;
		tail = q->next;
		chengji* m1, * m2;
		while (tail != NULL)
		{
			if (q->GPA == tail->GPA)
			{
				m1 = q->head->next;
				m2 = tail->head->next;
				while (m1 != NULL)
				{
					if (strcmp(m1->xueke, "英语") == 0)
					{
						break;
					}
					m1 = m1->next;
				}
				while (m2 != NULL)
				{
					if (strcmp(m2->xueke, "英语") == 0)
					{
						break;
					}
					m2 = m2->next;
				}
				if (m1->jidian < m2->jidian)
				{
					q->next = tail->next;
					p->next = tail;
					tail->next = q;
				}
				else if (m1->jidian == m2->jidian)
				{
					m1 = q->head->next;
					m2 = tail->head->next;
					while (m1 != NULL)
					{
						if (strcmp(m1->xueke, "微积分1") == 0)
						{
							break;
						}
						m1 = m1->next;
					}
					while (m2 != NULL)
					{
						if (strcmp(m2->xueke, "微积分1") == 0)
						{
							break;
						}
						m2 = m2->next;
					}
					if (m1->jidian < m2->jidian)
					{
						q->next = tail->next;
						p->next = tail;
						tail->next = q;
					}

				}
			}
			p = p->next;
			q = q->next;
			tail = tail->next;
		}
	}
	int r = 1;
	printf("\n                              排名      姓名              学号          GPA\n\n");
	Student* tt = top->next;
	while (tt != NULL)
	{
		printf("                              %-5d\t%-15s\t%-15s\t%-10.2f\n", r++, tt->name, tt->num, tt->GPA);
		tt = tt->next;
	}
	printf("\n\n                              ******************************************************\n");
	printf("                              ||                  返回首页请输入1                 ||\n");
	printf("                              ||                  退出系统请输入2                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---教务处端功能12（素质类项目管理）
void Service(void)
{
	system("cls");
	int start1;
	start1:
	printf("                              ******************************************************\n");
	printf("                                               请选择您要进行的业务                 \n");
	printf("                                                      1.查询                        \n");
	printf("                                                      2.增加                        \n");
	printf("                                                      3.修改                        \n");
	printf("                                                  返回上一层请按0                   \n");
	printf("                                               请选择您要进行的业务:                \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char m[error_test];
	scanf("%s", m);
	if (strcmp(m,"1") == 0)
	{
		Find();
	}
	else if (strcmp(m, "2") == 0)
	{
		system("cls");
		Add();
	}
	else if (strcmp(m, "3") == 0)
	{
		system("cls");
		Modify();
	}
	else if (strcmp(m, "0") == 0)
	{
		dean_office_interface();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入:              \n");
		printf("                              ******************************************************\n");
		goto start1;

	}
}


//函数---教务处端功能12-1（查询）
void Find(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                    请选择查看所有素质类成绩或单独查看某位同学成绩     \n");
	printf("                                              查看全部素质类成绩请输入1                \n");
	printf("                                                单独查看某成绩请输入2                  \n");
	printf("                                                   返回上一层请按0                     \n");
	printf("                                                       请输入：                        \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char n[error_test];
	scanf("%s", n);
	if (strcmp(n,"1") == 0)
	{
		system("cls");
		Student_find();
	}
	else if (strcmp(n, "2") == 0)
	{
		system("cls");
		single_find();
	}
	else if (strcmp(n, "0") == 0)
	{
		Service();
	}
	else
	{
		Find_error();
	}
}


//函数---教务处端功能12-2（增加）
void Add(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                  论文类请输入1                  \n");
	printf("                                                  获奖类请输入2                  \n");
	printf("                                                  项目类请输入3                  \n");
	printf("                                                  返回上一层请按0                \n");
	printf("                                                   请输入数字：                  \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	while (1)
	{
		scanf("%s", i);
		if (strcmp(i,"1") == 0)
		{
			Add_Paper();
			break;
		}
		else if (strcmp(i, "2") == 0)
		{
			Add_Awards();
			break;
		}
		else if (strcmp(i, "3") == 0)
		{
			Add_Project();
			break;
		}
		else if (strcmp(i, "0") == 0)
		{
			Service();
			break;
		}
		else
		{
			printf("                              ******************************************************\n");
			printf("                                            输入选项不正确，请重新输入：\n");
			printf("                              ******************************************************\n");

		}
	}
}


//函数---教务处端功能12-3（修改）
void Modify(void)
{
	system("cls");
	int start1;
	start1:
	printf("                              ******************************************************\n");
	printf("                                                  论文类请输入1                  \n");
	printf("                                                  获奖类请输入2                  \n");
	printf("                                                  项目类请输入3                  \n");
	printf("                                                  返回上一层请按0                \n");
	printf("                                                   请输入数字：                  \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	system("cls");
	if (strcmp(i,"1") == 0)
		Modify_Paper();
	else if (strcmp(i, "2") == 0)
		Modify_Awards();
	else if (strcmp(i, "3") == 0)
		Modify_Project();
	else if (strcmp(i, "0") == 0)
		Service();
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：                   \n");
		printf("                              ******************************************************\n");
		goto start1;
	}
}


//函数---教务处端功能12-1-1（查询全部）
void Student_find(void)
{
	system("cls");
	int start1;
	start1:
	printf("                              ******************************************************\n");
	printf("                                              查询论文类信息请输入1            \n");
	printf("                                              查询项目类信息请输入2            \n");
	printf("                                              查询获奖信息请输3                \n");                                  //分类查询素质类项目成绩
	printf("                                              返回上一层请按0                  \n");
	printf("                                                  请输入数字：                 \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char m[error_test];
	scanf("%s", m);
	system("cls");
	if (strcmp(m,"1") == 0)
	{
		printf("编号 论文作者         论文名称/期刊名称/会议名称     发表时间  卷/期/论文号/页码范围  论文级别信息    加分信息  GPA\n");
		Paper* head = Paper_build();                                                                              //建立论文类链表
		print_paper(head);                                                 //打印成绩
	}
	else if (strcmp(m, "2") == 0)
	{
		printf("编号      项目成员            指导教师    项目名称         项目编号        立项时间        结项时间    \n");
		Project* head = Project_build();                                //建立项目类链表
		Print_project(head);                           //打印成绩
	}
	else if (strcmp(m, "3") == 0)
	{
		printf("编号 竞赛项目名称                   主办单位            获奖人             获奖等级           获奖时间     GPA\n");
		Awards* head = Awards_build();                         //建立奖项类链表
		print_awards(head);                       //打印成绩
	}
	else if (strcmp(m, "0") == 0)
	{
		Find();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：               \n");
		printf("                              ******************************************************\n");
		goto start1;
	}
	After_student_find();
}


//函数---教务处端功能12-1-2（查询具体）
void  single_find(void)
{
	system("cls");
	int startp;
startp:
	printf("                              ******************************************************\n");
	printf("                                                  查询论文类信息请输1                     \n");
	printf("                                                  查询项目类信息请输2                     \n");
	printf("                                                  查询获奖类信息请输3                     \n");
	printf("                                                  返回上一层请按0                         \n");
	printf("                                                     请输入数字：                         \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char p[error_test];
	scanf("%s", p);
	if (strcmp(p,"1") == 0)
	{
		system("cls");
		Paper_Find_way();
	}
	else if (strcmp(p, "2") == 0)
	{
		system("cls");
		Project_Find_way();
	}
	else if (strcmp(p, "3") == 0)
	{
		system("cls");
		Awards_Find_way();
	}
	else if (strcmp(p, "0") == 0)
	{
		Find();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                               输入错误，请重新输入:                 \n");
		printf("                              ******************************************************\n");
		goto startp;
	}
}


//函数---教务处端功能12-1-2-1
void Paper_Find_way(void)
{
	char i[error_test];
	printf("                              ******************************************************\n");
	printf("                                                     请输入查询方式                 \n");
	printf("                                                     按学号查询请输入1              \n");
	printf("                                                     按名称查询请输入2              \n");
	printf("                                                     按论文等级查询请输入3          \n");
	printf("                                                     返回上一层请按0                \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	while (1)
	{
		scanf("%s", i);
		if (strcmp(i,"1") == 0)
		{
			system("cls");
			single_paper_student_find();
			break;
		}
		else if (strcmp(i, "2") == 0)
		{
			system("cls");
			Name_find_paper();
			break;
		}
		else if (strcmp(i, "3") == 0)
		{
			system("cls");
			Level_find_paper();
			break;
		}
		else if (strcmp(i, "0") == 0)
		{
			system("cls");
			single_find();
			break;
		}
		else
		{
			printf("                              ******************************************************\n");
			printf("                                           输入选项不正确，请重新输入：\n");
			printf("                              ******************************************************\n");

		}
	}
}


//函数---教务处端功能12-1-2-3
void Awards_Find_way(void)
{
	char i[error_test];
	printf("                              ******************************************************\n");
	printf("                                                    请输入查询方式                 \n");
	printf("                                                    按学号查询请输入1              \n");
	printf("                                                    按名称查询请输入2              \n");
	printf("                                                    按奖项等级查询请输入3          \n");
	printf("                                                    返回上一层请按0                \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	while (1)
	{
		scanf("%s", i);
		if (strcmp(i,"1") == 0)
		{
			single_awards_student_find();
			break;
		}
		else if (strcmp(i, "2") == 0)
		{
			Name_find_awards();
			break;
		}
		else if (strcmp(i, "3") == 0)
		{
			Level_find_awards();
			break;
		}
		else if (strcmp(i, "0") == 0)
		{
			single_find();
			break;
		}
		else
		{
			printf("                              ******************************************************\n");
			printf("                                           输入选项不正确，请重新输入：\n");
			printf("                              ******************************************************\n");

		}
	}
}


//函数---教务处端功能12-1-2-2
void Project_Find_way(void)
{
	char i[error_test];
	printf("                              ******************************************************\n");
	printf("                                                    请输入查询方式                 \n");
	printf("                                                    按学号查询请输入1              \n");
	printf("                                                    按名称查询请输入2              \n");
	printf("                                                    按项目代号查询请输入3          \n");
	printf("                                                    返回上一层请按0                \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	while (1)
	{
		scanf("%s", i);
		if (strcmp(i,"1") == 0)
		{
			single_project_student_find();
			break;
		}
		else if (strcmp(i, "2") == 0)
		{
			Name_find_project();
			break;
		}
		else if (strcmp(i, "3") == 0)
		{
			Level_find_project();
			break;
		}
		else if (strcmp(i, "0") == 0)
		{
			single_find();
			break;
		}
		else
		{
			printf("                              ******************************************************\n");
			printf("                                           输入选项不正确，请重新输入：\n");
			printf("                              ******************************************************\n");

		}
	}
}


//函数---教务处端功能12-1-2-2-1
void single_project_student_find(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                    请输入学号:                       \n");
	printf("                              ******************************************************\n");
	getchar();
	char number[20];
	int i = 1;
	gets(number);//输入学号
	system("cls");
	Project* head = Project_build();
	Project* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Project_student_number, number) == 0)               //比对学号，找到学生
		{
			printf("编号    项目成员        指导教师       项目名称         项目编号      立项时间        结项时间   在项目中职务    GPA\n");
			printf("%d     ", i++);
			printf("%-20s%-10s%-22s%-12s%-16s%-15s%-12s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);
			if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
				printf("0.4\n");
			else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
				printf("0.2\n");
			else
				printf("0\n");                                     //其他人不加GPA
			p = p->next;
			break;
		}
		else
		{
			p = p->next;
			if (p == NULL)                           //如果匹配不到此同学则输出查无此人
			{
				printf("                              ******************************************************\n");
				printf("                                                     查无此人                   \n");
				printf("                                                回到上一页面请输入1             \n");
				printf("                                               回到素质类首页请输入2            \n");
				printf("                                                      请输入：                  \n");
				printf("                              ******************************************************\n");
				printf("                              ");
				char o[error_test];
				scanf("%s", o);
				system("cls");
				if (strcmp(o,"1") == 0)
				{
					single_project_student_find();
				}
				else if (strcmp(o, "2") == 0)
				{
					Service();
				}
				else
				{
					system("cls");
					printf("                              ******************************************************\n");
					printf("                                                  输入错误，请重新输入：        \n");
					printf("                              ******************************************************\n");
					error_find();
				}
			}
		}
	}
	while (p != NULL)
	{
		if (strcmp(p->Project_student_number, number) == 0)               //比对学号，找到学生
		{
			printf("%d     ", i++);
			printf("%-20s%-10s%-22s%-12s%-16s%-15s%-12s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);
			if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
				printf("0.4\n");
			else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
				printf("0.2\n");
			else
				printf("0\n");                                     //其他人不加GPA
			p = p->next;

		}
		else
			p = p->next;
	}
	while (1)
	{
		printf("                                                                                            \n");
		printf("                                                                                            \n");
		printf("                                                                                            \n");
		printf("                                                                                            \n");
		printf("                              ******************************************************\n");
		printf("                                                 继续查询请输入1\n");
		printf("                                                 返回素质类首页请输入2\n");
		printf("                                                 请输入:\n");
		printf("                              ******************************************************\n");
		printf("                              ");
		char u[error_test];
		scanf("%s", u);
		if (strcmp(u,"1") == 0)
		{
			single_project_student_find();
			break;
		}
		else if (strcmp(u, "2") == 0)
		{
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                                 输入错误，请重新输入：                 \n");
			printf("                              ******************************************************\n");
		}
	}
}


//函数---教务处端功能12-1-2-3-1
void single_awards_student_find(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                    请输入学号:                       \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char number[20];
	int i = 1;
	gets(number);//输入学号
	system("cls");
	Awards* head = Awards_build();
	Awards* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Awards_student_number, number) == 0)
		{
			printf("编号    竞赛项目名称                主办单位            获奖人             获奖等级           获奖时间     GPA\n");
			printf("%-4d", i++);
			printf("%-30s%-22s%-19s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
			if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
				printf("0.4\n");
			else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
				printf("0.2\n");
			else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
				printf("0.1\n");
			else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
				printf("0.05\n");
			else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
				printf("0.02\n");
			p = p->next;
			break;
		}
		else
		{
			p = p->next;
			if (p == NULL)
			{
				printf("                              ******************************************************\n");
				printf("                                                     查无此人                   \n");
				printf("                                                回到上一页面请输入1             \n");
				printf("                                                回到素质类首页请输入2           \n");
				printf("                                                请输入：                        \n");
				printf("                              ******************************************************\n");
				printf("                              ");
				char o[error_test];
				scanf("%s", o);
				system("cls");
				if (strcmp(o,"1") == 0)
				{
					single_awards_student_find();
				}
				else if (strcmp(o, "2") == 0)
				{
					Service();
				}
				else
				{
					system("cls");
					printf("                              ******************************************************\n");
					printf("                                               输入错误，请重新输入：        \n");
					printf("                              ******************************************************\n");
					error_find();
				}
			}
		}
	}
	while (p != NULL)
	{
		if (strcmp(p->Awards_student_number, number) == 0)
		{
			printf("%-4d", i++);
			printf("%-30s%-22s%-19s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
			if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
				printf("0.4\n");
			else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
				printf("0.2\n");
			else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
				printf("0.1\n");
			else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
				printf("0.05\n");
			else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
				printf("0.02\n");
			p = p->next;
		}
		else
		{
			p = p->next;
		}
	}
	while (1)
	{
		printf("                                                                                                   \n");
		printf("                                                                                                   \n");
		printf("                                                                                                   \n");
		printf("                                                                                                   \n");
		printf("                              ******************************************************\n");
		printf("                                                 继续查询请输入1\n");
		printf("                                                 返回素质类首页请输入2\n");
		printf("                                                 请输入:\n");
		printf("                              ******************************************************\n");
		printf("                              ");
		char u[error_test];
		scanf("%s", u);
		if (strcmp(u,"1") == 0)
		{
			single_awards_student_find();
			break;
		}
		else if (strcmp(u, "2") == 0)
		{
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                                输入错误，请重新输入：                 \n");
			printf("                              ******************************************************\n");
		}
	}
}


//函数---教务处端功能12-1-2-1-1
void single_paper_student_find(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                    请输入学号:                       \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char number[20];
	int i = 1;
	gets(number);//输入学号
	system("cls");
	Paper* head = Paper_build();
	Paper* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Paper_student_number, number) == 0)
		{
			printf("编号  论文作者         论文名称/期刊名称/会议名称        发表时间   卷/期/论文号/页码范围    论文级别信息  加分信息 GPA\n");
			printf("%-7d", i++);
			printf("%-18s%-32s%-20s%-20s%-10s%-9s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);

			if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
				printf("0.4\n");
			else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
				printf("0.2\n");
			else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
				printf("0.1\n");
			else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
				printf("0.05\n");
			else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
				printf("0.02\n");
			else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
				printf("0.01\n");
			else
				printf("0\n");
			p = p->next;
			break;
		}
		else
		{
			p = p->next;
			if (p == NULL)
			{
				printf("                              ******************************************************\n");
				printf("                                                     查无此人                   \n");
				printf("                                                回到上一页面请输入1             \n");
				printf("                                                回到素质类首页请输入2           \n");
				printf("                                                请输入：                        \n");
				printf("                              ******************************************************\n");
				printf("                              ");
				char o[error_test];
				scanf("%s", o);
				system("cls");
				if (strcmp(o,"1") == 0)
				{
					single_paper_student_find();
				}
				else if (strcmp(o, "2") == 0)
				{
					Service();
				}
				else
				{
					system("cls");
					printf("                              ******************************************************\n");
					printf("                                                 输入错误，请重新输入：        \n");
					printf("                              ******************************************************\n");
					error_find();
				}
			}
		}
	}
	while (p != NULL)
	{

		if (strcmp(p->Paper_student_number, number) == 0)
		{
			printf("%-7d", i++);
			printf("%-18s%-32s%-20s%-20s%-10s%-9s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);

			if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
				printf("0.4\n");
			else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
				printf("0.2\n");
			else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
				printf("0.1\n");
			else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
				printf("0.05\n");
			else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
				printf("0.02\n");
			else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
				printf("0.01\n");
			else
				printf("0\n");
			p = p->next;

		}
		else
		{
			p = p->next;
		}
	}
	while (1)
	{
		printf("                                                                                                   \n");
		printf("                                                                                                   \n");
		printf("                                                                                                   \n");
		printf("                                                                                                   \n");
		printf("                              ******************************************************\n");
		printf("                                                  继续查询请输入1\n");
		printf("                                                  返回素质类首页请输入2\n");
		printf("                                                  请输入:\n");
		printf("                              ******************************************************\n");
		printf("                              ");
		char u[error_test];
		scanf("%s", u);
		if (strcmp(u,"1") == 0)
		{
			single_paper_student_find();
			break;
		}
		else if (strcmp(u, "2") == 0)
		{
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                                输入错误，请重新输入：                 \n");
			printf("                              ******************************************************\n");
		}
	}
}


//函数---教务处端功能12-1-2-1-2
void Name_find_paper(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  请输入论文名字:                     \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char name[50];
	int i = 1;
	gets(name);//输入论文名字
	system("cls");
	Paper* head = Paper_build();
	Paper* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Paper_name, name) == 0)
		{

			printf("编号  论文作者       论文名称/期刊名称/会议名称        发表时间   卷/期/论文号/页码范围    论文级别信息  加分信息 GPA\n");
			printf("%-6d", i++);
			printf("%-17s%-32s%-20s%-20s%-10s%-9s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);

			if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
				printf("0.4");
			else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
				printf("0.2");
			else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
				printf("0.1");
			else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
				printf("0.05");
			else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
				printf("0.02");
			else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
				printf("0.01");
			else
				printf("0");
			break;


		}
		else
		{
			p = p->next;
			if (p == NULL)
			{
				printf("                              ******************************************************\n");
				printf("                                                不存在此名字的论文              \n");
				printf("                                                回到上一页面请输入1             \n");
				printf("                                                回到素质类首页请输入2           \n");
				printf("                                                请输入：                        \n");
				printf("                              ******************************************************\n");
				printf("                              ");
				char o[error_test];
				scanf("%s", o);
				system("cls");
				if (strcmp(o,"1") == 0)
				{
					Paper_Find_way();
				}
				else if (strcmp(o, "2") == 0)
				{
					Service();
				}
				else
				{
					system("cls");
					printf("                              ******************************************************\n");
					printf("                                                输入错误，请重新输入：        \n");
					printf("                              ******************************************************\n");
					error_find();
				}
			}


		}
	}
	char o[error_test];
	while (1)
	{
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                              ******************************************************\n");
		printf("                                              继续查询请输入1                  \n");
		printf("                                              回到素质类首页请输入2            \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		scanf("%s", o);
		if (strcmp(o,"1") == 0)
		{
			system("cls");
			Name_find_paper();
			break;
		}
		else if (strcmp(o, "2") == 0)
		{
			system("cls");
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                               输入错误，请重新输入:              \n");
			printf("                              ******************************************************\n");
		}
	}
}


//函数---教务处端功能12-1-2-1-3
void Level_find_paper(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  请输入论文级别:                     \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char level[20];
	int i = 1;
	gets(level);                                            //输入论文级别
	system("cls");
	Paper* head = Paper_build();
	Paper* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Paper_level, level) == 0)
		{

			printf("编号  论文作者       论文名称/期刊名称/会议名称        发表时间   卷/期/论文号/页码范围    论文级别信息  加分信息 GPA\n");
			printf("%-7d", i++);
			printf("%-16s%-32s%-20s%-20s%-10s%-9s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);

			if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
				printf("0.4\n");
			else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
				printf("0.2\n");
			else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
				printf("0.1\n");
			else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
				printf("0.05\n");
			else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
				printf("0.02\n");
			else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
				printf("0.01\n");
			else
				printf("0\n");
			break;

		}
		else
		{
			p = p->next;
		}
	}
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
			if (strcmp(p->Paper_level, level) == 0)
			{
				printf("%-7d", i++);
				printf("%-16s%-32s%-20s%-20s%-10s%-9s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);

				if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
					printf("0.4\n");
				else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
					printf("0.2\n");
				else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
					printf("0.1\n");
				else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
					printf("0.05\n");
				else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
					printf("0.02\n");
				else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
					printf("0.01\n");
				else
					printf("0\n");
			}
		}


	}
	if (i == 1)
	{
		printf("                              ******************************************************\n");
		printf("                                                不存在此级别的论文              \n");
		printf("                                                回到上一页面请输入1             \n");
		printf("                                                回到素质类首页请输入2           \n");
		printf("                                                请输入：                        \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		char o[error_test];
		scanf("%s", o);
		system("cls");
		if (strcmp(o,"1") == 0)
		{
			Paper_Find_way();
		}
		else if (strcmp(o, "2") == 0)
		{
			Service();
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                              输入错误，请重新输入：        \n");
			printf("                              ******************************************************\n");
			error_find();
		}
	}
	char o[error_test];
	while (1)
	{
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                              ******************************************************\n");
		printf("                                              继续查询请输入1                  \n");
		printf("                                              回到素质类首页请输入2            \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		scanf("%s", o);
		if (strcmp(o,"1") == 0)
		{
			system("cls");
			Level_find_paper();
			break;
		}
		else if (strcmp(o, "2") == 0)
		{
			system("cls");
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                               输入错误，请重新输入:              \n");
			printf("                              ******************************************************\n");
		}
	}
}


//函数---教务处端功能12-1-2-2-2
void Name_find_project(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                  请输入项目名称:                     \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char name[20];
	int i = 1;
	gets(name);                                            //输入项目名称
	system("cls");
	Project* head = Project_build();
	Project* p;
	Project* q;
	q = head;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Project_name, name) == 0)
		{
			printf("编号    项目成员        指导教师       项目名称         项目编号      立项时间        结项时间   在项目中职务    GPA\n");
			printf("%d     ", i++);
			printf("%-20s%-10s%-22s%-12s%-16s%-15s%-12s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);
			if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
				printf("0.4\n");
			else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
				printf("0.2\n");
			else
				printf("0\n");                                     //其他人不加GPA
			p = p->next;
			q = q->next;
			break;
		}
		p = p->next;
		q = q->next;
	}

	if (i == 1)
	{
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                              ******************************************************\n");
		printf("                                                不存在此名字的项目              \n");
		printf("                                                回到上一页面请输入1             \n");
		printf("                                                回到素质类首页请输入2           \n");
		printf("                                                请输入：                        \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		char o[error_test];
		scanf("%s", o);
		system("cls");
		if (strcmp(o,"1") == 0)
		{
			Project_Find_way();
		}
		else if (strcmp(o, "2") == 0)
		{
			Service();
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                              输入错误，请重新输入：        \n");
			printf("                              ******************************************************\n");
			error_find();
		}
	}
	while (p != NULL)
	{
		if ((strcmp(p->Project_name, name) == 0) && (strcmp(p->Project_number, q->Project_number) != 0))
		{
			printf("%d     ", i++);
			printf("%-20s%-10s%-22s%-12s%-16s%-15s%-12s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);
			if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
				printf("0.4\n");
			else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
				printf("0.2\n");
			else
				printf("0\n");                                     //其他人不加GPA
			p = p->next;
			q = q->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	char o[error_test];
	while (1)
	{
		printf("                              ******************************************************\n");
		printf("                                              继续查询请输入1                  \n");
		printf("                                              回到素质类首页请输入2            \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		scanf("%s", o);
		if (strcmp(o,"1") == 0)
		{
			system("cls");
			Name_find_project();
			break;
		}
		else if (strcmp(o, "2") == 0)
		{
			system("cls");
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                               输入错误，请重新输入:              \n");
			printf("                              ******************************************************\n");
		}
	}


}


//函数---教务处端功能12-1-2-2-3
void Level_find_project(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                  请输入项目代号:                     \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char code[20];
	int i = 1;
	gets(code);                                            //输入项目代号
	system("cls");
	Project* head = Project_build();
	Project* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Project_number, code) == 0)
		{
			printf("编号    项目成员        指导教师       项目名称         项目编号      立项时间        结项时间   在项目中职务   GPA\n");
			printf("%d     ", i++);
			printf("%-20s%-10s%-22s%-12s%-16s%-15s%-12s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);
			if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
				printf("0.4");
			else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
				printf("0.2");
			else
				printf("0");                                     //其他人不加GPA
			break;
		}
		else
		{
			p = p->next;
		}
	}
		if (i == 1)
		{
			printf("                                                                                    \n");
			printf("                                                                                    \n");
			printf("                                                                                    \n");
			printf("                                                                                    \n");
			printf("                              ******************************************************\n");
			printf("                                                不存在此代号的项目              \n");
			printf("                                                回到上一页面请输入1             \n");
			printf("                                                回到素质类首页请输入2           \n");
			printf("                                                请输入：                        \n");
			printf("                              ******************************************************\n");
			printf("                              ");
			char o[error_test];
			scanf("%s", o);
			system("cls");
			if (strcmp(o,"1") == 0)
			{
				Project_Find_way();
			}
			else if (strcmp(o, "2") == 0)
			{
				Service();
			}
			else
			{
				system("cls");
				printf("                              ******************************************************\n");
				printf("                                              输入错误，请重新输入：        \n");
				printf("                              ******************************************************\n");
				error_find();
			}
		}


	char o[error_test];
	while (1)
	{
		printf("                              ******************************************************\n");
		printf("                                              继续查询请输入1                  \n");
		printf("                                              回到素质类首页请输入2            \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		scanf("%s", o);
		if (strcmp(o,"1") == 0)
		{
			system("cls");
			Level_find_project();
			break;
		}
		else if (strcmp(o, "2") == 0)
		{
			system("cls");
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                               输入错误，请重新输入:              \n");
			printf("                              ******************************************************\n");
		}
	}

}


//函数---教务处端功能12-1-2-3-2
void Name_find_awards(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                  请输入奖项名称:                     \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char name[20];
	int i = 1;
	gets(name);                                            //输入奖项名称
	system("cls");
	Awards* head = Awards_build();
	Awards* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Award_project_name, name) == 0)
		{
			printf("编号    竞赛项目名称                主办单位            获奖人             获奖等级           获奖时间     GPA\n");
			printf("%-4d", i++);
			printf("%-30s%-21s%-20s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
			if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
				printf("0.4\n");
			else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
				printf("0.2\n");
			else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
				printf("0.1\n");
			else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
				printf("0.05\n");
			else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
				printf("0.02\n");
			p = p->next;
			break;
		}
		else
		{
			p = p->next;
			if (p == NULL && i == 1)
			{
				printf("                              ******************************************************\n");
				printf("                                                无人获得此类奖项                \n");
				printf("                                                回到上一页面请输入1             \n");
				printf("                                                回到素质类首页请输入2           \n");
				printf("                                                请输入：                        \n");
				printf("                              ******************************************************\n");
				printf("                              ");
				char o[error_test];
				scanf("%s", o);
				system("cls");
				if (strcmp(o,"1") == 0)
				{
					Awards_Find_way();
				}
				else if (strcmp(o, "2") == 0)
				{
					Service();
				}
				else
				{
					system("cls");
					printf("                              ******************************************************\n");
					printf("                                              输入错误，请重新输入：        \n");
					printf("                              ******************************************************\n");
					error_find();
				}
			}
			else if (p == NULL && i != 1)
			{
				break;
			}
		}
	}
	while (p != NULL)
	{
		if (strcmp(p->Award_project_name, name) == 0)
		{
			printf("%-4d", i++);
			printf("%-30s%-21s%-20s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
			if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
				printf("0.4\n");
			else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
				printf("0.2\n");
			else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
				printf("0.1\n");
			else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
				printf("0.05\n");
			else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
				printf("0.02\n");
			p = p->next;
		}
		else
		{
			p = p->next;
		}
	}
	char o[error_test];
	while (1)
	{
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                              ******************************************************\n");
		printf("                                                继续查询请输入1                  \n");
		printf("                                                回到素质类首页请输入2            \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		scanf("%s", o);
		if (strcmp(o,"1") == 0)
		{
			system("cls");
			Name_find_awards();
			break;
		}
		else if (strcmp(o, "2") == 0)
		{
			system("cls");
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                                输入错误，请重新输入:              \n");
			printf("                              ******************************************************\n");
		}
	}

}


//函数---教务处端功能12-1-2-3-3
void Level_find_awards(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                  请输入奖项级别:                     \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	getchar();
	char level[20];
	int i = 1;
	gets(level);                                            //输入奖项级别
	system("cls");
	Awards* head = Awards_build();
	Awards* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Award_level, level) == 0)
		{
			printf("编号    竞赛项目名称                主办单位            获奖人             获奖等级           获奖时间     GPA\n");
			printf("%-4d", i++);
			printf("%-30s%-21s%-20s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
			if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
				printf("0.4\n");
			else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
				printf("0.2\n");
			else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
				printf("0.1\n");
			else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
				printf("0.05\n");
			else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
				printf("0.02\n");
			break;
		}
		else
		{
			p = p->next;
		}
	}
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			p = p->next;
			if (strcmp(p->Award_level, level) == 0)
			{
				printf("%-4d", i++);
				printf("%-30s%-21s%-20s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
				if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
					printf("0.4\n");
				else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
					printf("0.2\n");
				else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
					printf("0.1\n");
				else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
					printf("0.05\n");
				else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
					printf("0.02\n");
			}
		}
	}


	if (i == 1)
	{
		printf("                              ******************************************************\n");
		printf("                                                不存在此级别的奖项                   \n");
		printf("                                                回到上一页面请输入1             \n");
		printf("                                                回到素质类首页请输入2           \n");
		printf("                                                请输入：                        \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		char o[error_test];
		scanf("%s", o);
		system("cls");
		if (strcmp(o,"1") == 0)
		{
			Awards_Find_way();
		}
		else if (strcmp(o, "2") == 0)
		{
			Service();
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                              输入错误，请重新输入：        \n");
			printf("                              ******************************************************\n");
			error_find();
		}
	}
	char o[error_test];
	while (1)
	{
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                                                                                    \n");
		printf("                              ******************************************************\n");
		printf("                                              继续查询请输入1                  \n");
		printf("                                              回到素质类首页请输入2            \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		scanf("%s", o);
		if (strcmp(o,"1") == 0)
		{
			system("cls");
			Level_find_awards();
			break;
		}
		else if (strcmp(o, "2") == 0)
		{
			system("cls");
			Service();
			break;
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                               输入错误，请重新输入:              \n");
			printf("                              ******************************************************\n");
		}
	}


}


//函数---教务处端功能12-2-1
void Add_Paper(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                             请输入要增加的学生信息\n");
	Paper* head = Paper_build();
	Paper* p = head;
	while (p != NULL)
	{
		p = p->next;
	}
	p = (Paper*)malloc(sizeof(Paper));
	printf("                                             1.学号:");
	char Add_student_number[50];
	scanf("%s", Add_student_number);
	strcpy(p->Paper_student_number, Add_student_number);
	printf("                                             2.学生姓名:");
	char Add_student_name[50];
	scanf("%s", Add_student_name);
	strcpy(p->Paper_writer, Add_student_name);
	char Add_Paper_name[50];
	printf("                                             3.论文名称 / 期刊名称 / 会议名称:");
	scanf("%s", Add_Paper_name);
	strcpy(p->Paper_name, Add_Paper_name);
	printf("                                             4.发表时间:");
	char Add_Paper_time[50];
	scanf("%s", Add_Paper_time);
	strcpy(p->Paper_time, Add_Paper_time);
	printf("                                             5.卷 / 期 / 论文号 / 页码范围:");
	char Add_student_page[50];
	scanf("%s", Add_student_page);
	strcpy(p->Paper_page, Add_student_page);
	printf("                                             6.论文级别信息（A，B,C,D,E,F):");
	char Add_student_level[50];
	scanf("%s", Add_student_level);
	strcpy(p->Paper_level, Add_student_level);
	printf("                                             7.加分信息:");
	char Add_student_point[50];
	scanf("%s", Add_student_point);
	strcpy(p->Paper_points, Add_student_point);

	int page;
page:
	printf("                                        请确认您添加的信息全部正确\n");
	printf("                                        信息正确请输入1\n");
	printf("                                        信息存在错误请输入0\n");
	printf("                              ******************************************************\n");
	char b[error_test];
	scanf("%s", b);
	if (strcmp(b,"0") == 0)
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                   请重新输入\n");
		printf("                              ******************************************************\n");
		Add_Paper();
	}
	else if (strcmp(b, "1") == 0)
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                      添加成功\n");
		printf("                              ******************************************************\n");
		p->next = NULL;
		FILE* fpp;
		fpp = fopen("paper.txt", "a");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		fprintf(fpp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", Add_student_number, Add_student_name, Add_Paper_name, Add_Paper_time, Add_student_page, Add_student_level, Add_student_point);
		p = p->next;
		fclose(fpp);
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                             选项输入错误，请重新输入\n");
		printf("                              ******************************************************\n");
		goto page;
	}
	After_Add_Paper();

}


//函数---教务处端功能12-2-2
void Add_Awards(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                               请输入要增加的学生信息\n");
	Awards* head = Awards_build();
	Awards* p = head;
	while (p != NULL)
	{
		p = p->next;
	}
	p = (Awards*)malloc(sizeof(Awards));
	printf("                                                       1.学号:");
	char Add_student_number[50];
	scanf("%s", Add_student_number);
	strcpy(p->Awards_student_number, Add_student_number);
	printf("                                                       2.竞赛项目名称:");
	char Add_project_name[50];
	scanf("%s", Add_project_name);
	strcpy(p->Award_project_name, Add_project_name);
	char Add_Paper_name[50];
	printf("                                                       3.主办单位:");
	scanf("%s", Add_Paper_name);
	strcpy(p->Award_unit, Add_Paper_name);
	printf("                                                       4.获奖人:");
	char Add_Paper_time[50];
	scanf("%s", Add_Paper_time);
	strcpy(p->Award_name, Add_Paper_time);
	printf("                                                       5.获奖等级:");
	char Add_student_page[50];
	scanf("%s", Add_student_page);
	strcpy(p->Award_level, Add_student_page);
	printf("                                                       6.获奖时间:");
	char Add_student_level[50];
	scanf("%s", Add_student_level);
	strcpy(p->Award_time, Add_student_level);

	int page2;
page2:
	printf("                                        请确认您添加的信息全部正确\n");
	printf("                                        信息正确请输入1\n");
	printf("                                        信息存在错误请输入0\n");
	printf("                              ******************************************************\n");
	char b[error_test];
	scanf("%s", b);
	if (strcmp(b,"0") == 0)
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                   请重新输入\n");
		printf("                              ******************************************************\n");
		Add_Awards();
	}
	else if (strcmp(b, "1") == 0)
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                      添加成功\n");
		printf("                              ******************************************************\n");
		p->next = NULL;
		FILE* fpp;
		fpp = fopen("award.txt", "a");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		fprintf(fpp, "%s\t%s\t%s\t%s\t%s\t%s\t\n", Add_student_number, Add_project_name, Add_Paper_name, Add_Paper_time, Add_student_page, Add_student_level);
		p = p->next;
		fclose(fpp);

	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                             选项输入错误，请重新输入\n");
		printf("                              ******************************************************\n");
		goto page2;
	}
	After_Add_awards();

}


//函数---教务处端功能12-2-3
void Add_Project(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                              请输入要增加的项目信息\n");
	Project* head = Project_build();
	Project* p = head;
	while (p != NULL)                                                     //找到尾节点
	{
		p = p->next;
	}
	p = (Project*)malloc(sizeof(Project));     //为节点申请空间
	printf("                                             请输入共有几位项目成员:");
	int m;
	scanf("%d", &m);
	if (m == 1)
	{
		printf("                                          1.学号:");
		char Add_student_number[50];
		scanf("%s", Add_student_number);
		strcpy(p->Project_student_number, Add_student_number);
		printf("                                          2.项目成员:");
		char Add_student_name[50];
		scanf("%s", Add_student_name);
		strcpy(p->Project_writer, Add_student_name);
		char Add_Paper_name[50];
		printf("                                          3.指导教师: ");
		scanf("%s", Add_Paper_name);
		strcpy(p->Project_teacher_name, Add_Paper_name);
		printf("                                          4.项目名称:");
		char Add_Paper_time[50];
		scanf("%s", Add_Paper_time);
		strcpy(p->Project_name, Add_Paper_time);
		printf("                                          5.项目编号: ");
		char Add_student_page[50];
		scanf("%s", Add_student_page);
		strcpy(p->Project_number, Add_student_page);
		printf("                                          6.立项时间: ");
		char Add_student_level[50];
		scanf("%s", Add_student_level);
		strcpy(p->Project_start_time, Add_student_level);
		printf("                                          7.结项时间: ");
		char Add_student_point[50];
		scanf("%s", Add_student_point);
		strcpy(p->Project_end_time, Add_student_point);
		printf("                                          8.是否为责任人或第二名：");
		char Add_Project_status[50];
		scanf("%s", Add_Project_status);
		strcpy(p->Project_status, Add_Project_status);
		int page3;
	page3:
		printf("                                        请确认您添加的信息全部正确\n");
		printf("                                        信息正确请输入1\n");
		printf("                                        信息存在错误请输入0\n");
		printf("                              ******************************************************\n");
		char b[error_test];
		scanf("%s", b);
		if (strcmp(b,"0") == 0)
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                                   请重新输入\n");
			printf("                              ******************************************************\n");
			Add_Project();
		}
		else if (strcmp(b, "1") == 0)
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                                      添加成功\n");
			printf("                              ******************************************************\n");
			p->next = NULL;
			FILE* fpp;
			fpp = fopen("project.txt", "a");
			if (fpp == NULL)
			{
				printf("FILE NOT FOUND");                   //未找到文件则退出
				exit(0);
			}
			fprintf(fpp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", Add_student_number, Add_student_name, Add_Paper_name, Add_Paper_time, Add_student_page, Add_student_level, Add_student_point, Add_Project_status);
			p = p->next;
			fclose(fpp);
		}
		else
		{
			system("cls");
			printf("                              ******************************************************\n");
			printf("                                              选项输入错误，请重新输入\n");
			printf("                              ******************************************************\n");
			goto page3;
		}
		
	}
	else
	{
			printf("                              ******************************************************\n");
			printf("                                                       1.项目成员名字:\n");
			char Add_student_name[50];
			scanf("%s", Add_student_name);
			strcpy(p->Project_writer, Add_student_name);
			char Add_Paper_name[50];
			printf("                                                       2.指导教师:\n");
			scanf("%s", Add_Paper_name);
			strcpy(p->Project_teacher_name, Add_Paper_name);
			printf("                                                       3.项目名称:\n");
			char Add_Paper_time[50];
			scanf("%s", Add_Paper_time);
			strcpy(p->Project_name, Add_Paper_time);
			printf("                                                       4.项目编号:\n");
			char Add_student_page[50];
			scanf("%s", Add_student_page);
			strcpy(p->Project_number, Add_student_page);
			printf("                                                       5.立项时间:\n");
			char Add_student_level[50];
			scanf("%s", Add_student_level);
			strcpy(p->Project_start_time, Add_student_level);
			printf("                                                       6.结项时间:\n");
			char Add_student_point[50];
			scanf("%s", Add_student_point);
			strcpy(p->Project_end_time, Add_student_point);
			printf("                                                       请输入第1位项目成员学号:\n");
			char Add_student_number[50];
			scanf("%s", Add_student_number);
			strcpy(p->Project_student_number, Add_student_number);
			printf("                                                       请输入此同学在项目中的职务:\n");
			char Add_Project_status[50];
			scanf("%s", Add_Project_status);
			strcpy(p->Project_status, Add_Project_status);
			p->next = NULL;
			FILE* fpp;
			fpp = fopen("project.txt", "a");
			if (fpp == NULL)
			{
				printf("FILE NOT FOUND");                   //未找到文件则退出
				exit(0);
			}
			fprintf(fpp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", Add_student_number, Add_student_name, Add_Paper_name, Add_Paper_time, Add_student_page, Add_student_level, Add_student_point, Add_Project_status);
			p = p->next;
			p = (Project*)malloc(sizeof(Project));
			fclose(fpp);
			int n = 2;
			for (n = 2; n <= m; n++)
			{
				printf("                                                     请输入第%d位项目成员学号:\n", n);
				char Add_student_number[50];
				scanf("%s", Add_student_number);
				strcpy(p->Project_student_number, Add_student_number);
				printf("                                                     请输入此同学在项目中的职务:\n");
				char Add_Project_status[50];
				scanf("%s", Add_Project_status);
				strcpy(p->Project_status, Add_Project_status);
				strcpy(p->Project_writer, Add_student_name);
				strcpy(p->Project_teacher_name, Add_Paper_name);
				strcpy(p->Project_name, Add_Paper_time);
				strcpy(p->Project_number, Add_student_page);
				strcpy(p->Project_start_time, Add_student_level);
				strcpy(p->Project_end_time, Add_student_point);
				p->next = NULL;
				FILE* fpp;
				fpp = fopen("project.txt", "a");
				if (fpp == NULL)
				{
					printf("FILE NOT FOUND");                   //未找到文件则退出
					exit(0);
				}
				fprintf(fpp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n", Add_student_number, Add_student_name, Add_Paper_name, Add_Paper_time, Add_student_page, Add_student_level, Add_student_point, Add_Project_status);
				p = p->next;
				p = (Project*)malloc(sizeof(Project));
				fclose(fpp);


			}
			printf("                                                            添加成功\n");
			printf("                              ******************************************************\n");
		After_Add_project();
	}
}


//函数---教务处端功能12-3-1
void Modify_Paper(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  请输入论文名称：                  \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char name[20];
	scanf("%s", name);
	system("cls");
	Paper* head = Paper_build();
	Paper* p = head->next;
	Paper* tmp = head->next;
	int m = strcmp(p->Paper_name, name);
	while (m != 0 && p != NULL)
	{
		p = p->next;
		if (p == NULL)
		{
			break;
		}
		m = strcmp(p->Paper_name, name);
	}
	if (p == NULL)
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                      查无此论文                        \n");
		printf("                                                    按1重新输入                       \n");
		printf("                                                    按2回到上一界面                   \n");
		printf("                                                    请输入：                          \n");
		printf("                              ******************************************************\n");
		printf("                              ");
		char o[error_test];
		scanf("%s", o);
		if (strcmp(o,"1") == 0)
		{
			system("cls");
			Modify_Paper();
		}
		else if (strcmp(o, "2") == 0)
		{
			system("cls");
			Modify();
		}
		else
		{
			system("cls");
			
			Error_student_number_paper();

		}
	}
	printf("                              ******************************************************\n");
	printf("                                                  1.论文名称 / 期刊名称 / 会议名称\n");
	printf("                                                  2.发表时间\n");
	printf("                                                  3.卷 / 期 / 论文号 / 页码范围\n");
	printf("                                                  4.论文级别信息（A，B,C,D,E,F)\n");
	printf("                                                  5.加分信息\n");
	printf("                                                  请选择您要修改的信息:\n");
	printf("                              ******************************************************\n");
	printf("                      ");
	char i[error_test];
	getchar();
	scanf("%s", i);
	system("cls");
	if (strcmp(i,"1") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                        当前论文名称 / 期刊名称 / 会议名称为：%s\n", p->Paper_name);
		printf("                                        请输入论文名称 / 期刊名称 / 会议名称:");
		char Add_paper_name[50];
		scanf("%s", Add_paper_name);
		strcpy(p->Paper_name, Add_paper_name);
		printf("                                        修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("paper.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s  \n", tmp->Paper_student_number, tmp->Paper_writer, tmp->Paper_name, tmp->Paper_time, tmp->Paper_page, tmp->Paper_level, tmp->Paper_points);
			tmp = tmp->next;
		}


		fclose(fpp);
	}
	else if (strcmp(i, "2") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                            当前发表时间为：%s\n", p->Paper_time);
		printf("                                            请输入发表时间:");
		char Add_paper_time[50];
		scanf("%s", Add_paper_time);
		strcpy(p->Paper_time, Add_paper_time);
		printf("                                            修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("paper.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s  \n", tmp->Paper_student_number, tmp->Paper_writer, tmp->Paper_name, tmp->Paper_time, tmp->Paper_page, tmp->Paper_level, tmp->Paper_points);
			tmp = tmp->next;
		}


		fclose(fpp);
	}
	else if (strcmp(i, "3") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                    当前卷 / 期 / 论文号 / 页码范围为：%s\n", p->Paper_page);
		printf("                                    请输入卷 / 期 / 论文号 / 页码范围:");
		char Add_paper_page[50];
		scanf("%s", Add_paper_page);
		strcpy(p->Paper_page, Add_paper_page);
		printf("                                    修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("paper.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s  \n", tmp->Paper_student_number, tmp->Paper_writer, tmp->Paper_name, tmp->Paper_time, tmp->Paper_page, tmp->Paper_level, tmp->Paper_points);
			tmp = tmp->next;
		}


		fclose(fpp);
	}
	else if (strcmp(i, "4") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                          当前论文级别信息为：%s\n", p->Paper_level);
		printf("                                          请输入论文级别信息（A，B,C,D,E,F): ");
		char Add_paper_level[50];
		scanf("%s", Add_paper_level);
		strcpy(p->Paper_level, Add_paper_level);
		printf("                                          修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("paper.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s  \n", tmp->Paper_student_number, tmp->Paper_writer, tmp->Paper_name, tmp->Paper_time, tmp->Paper_page, tmp->Paper_level, tmp->Paper_points);
			tmp = tmp->next;
		}


		fclose(fpp);
	}
	else if (strcmp(i, "5") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                           当前加分信息为：%s\n", p->Paper_points);
		printf("                                           请输入加分信息: ");
		char Add_paper_points[50];
		scanf("%s", Add_paper_points);
		strcpy(p->Paper_points, Add_paper_points);
		printf("                                           修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("paper.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s  \n", tmp->Paper_student_number, tmp->Paper_writer, tmp->Paper_name, tmp->Paper_time, tmp->Paper_page, tmp->Paper_level, tmp->Paper_points);
			tmp = tmp->next;
		}


		fclose(fpp);
	}
	else
	{
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：         \n");
		printf("                              ******************************************************\n");
		Modify_Paper();
	}
	After_Modify_Paper();

}


//函数---教务处端功能12-3-2
void Modify_Awards(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  请输入学生学号：\n");
	printf("                              ******************************************************\n");
	printf("                      ");
	char number[20];
	scanf("%s", number);
	printf("                              ******************************************************\n");
	printf("                                                  请输入获奖时间：\n");
	printf("                              ******************************************************\n");
	printf("                      ");
	char time[50];
	scanf("%s", time);
	Awards* head = Awards_build();
	Awards* p = head->next;
	Awards* tmp = head->next;
	int m = strcmp(p->Awards_student_number, number);
	int n = strcmp(p->Award_time, time);
	while (m != 0 && n != 0 && p != NULL)
	{
		p = p->next;
		if (p == NULL)
		{
			break;
		}
		m = strcmp(p->Awards_student_number, number);
		n = strcmp(p->Award_time, time);

	}

	if (p == NULL)
	{
		while (1)
		{

			printf("                              ******************************************************\n");
			printf("                                                      查无此奖项                        \n");
			printf("                                                    按1重新输入                       \n");
			printf("                                                    按2回到上一界面                   \n");
			printf("                                                    请输入：                          \n");
			printf("                              ******************************************************\n");
			printf("                              ");
			char o[error_test];
			scanf("%s", o);
			if (strcmp(o,"1") == 0)
			{
				system("cls");
				Modify_Awards();
				break;
			}
			else if (strcmp(o, "2") == 0)
			{
				system("cls");
				Modify();
				break;
			}
			else
			{
				system("cls");
				printf("                              ******************************************************\n");
				printf("                                                  输入错误，请重新输入\n");
				printf("                              ******************************************************\n");
			}
		}
	}
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                 1.竞赛项目名称\n");
	printf("                                                 2.主办单位\n");
	printf("                                                 3.获奖人\n");
	printf("                                                 4.获奖等级\n");
	printf("                                                 5.获奖时间\n");
	printf("                                                 请选择您要修改的信息:\n");
	printf("                              ******************************************************\n");
	printf("                      ");
	char i[error_test];
	getchar();
	scanf("%s", i);
	system("cls");
	if (strcmp(i,"1") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                         当前竞赛项目名称为:%s\n", p->Award_project_name);
		printf("                                         请输入竞赛项目名称:");
		char Add_project_name[50];
		scanf("%s", Add_project_name);
		strcpy(p->Award_project_name, Add_project_name);
		printf("                                         修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("award.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s\n", tmp->Awards_student_number, tmp->Award_project_name, tmp->Award_unit, tmp->Award_name, tmp->Award_level, tmp->Award_time);
			tmp = tmp->next;
		}


		fclose(fpp);

	}
	else if (strcmp(i, "2") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                                当前主办单位为:%s\n", p->Award_unit);
		printf("                                                请输入主办单位:");
		char Add_award_unit[50];
		scanf("%s", Add_award_unit);
		strcpy(p->Award_unit, Add_award_unit);
		printf("                                                修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("award.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s\n", tmp->Awards_student_number, tmp->Award_project_name, tmp->Award_unit, tmp->Award_name, tmp->Award_level, tmp->Award_time);
			tmp = tmp->next;
		}


		fclose(fpp);

	}
	else if (strcmp(i, "3") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                               当前获奖人为:%s\n", p->Award_name);
		printf("                                               请输入获奖人:");
		char Add_award_name[50];
		scanf("%s", Add_award_name);
		strcpy(p->Award_name, Add_award_name);
		printf("                                               修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("award.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s\n", tmp->Awards_student_number, tmp->Award_project_name, tmp->Award_unit, tmp->Award_name, tmp->Award_level, tmp->Award_time);
			tmp = tmp->next;
		}


		fclose(fpp);

	}
	else if (strcmp(i, "4") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                             当前获奖等级为:%s\n", p->Award_level);
		printf("                                             请输入获奖等级:");
		char Add_award_level[50];
		scanf("%s", Add_award_level);
		strcpy(p->Award_level, Add_award_level);
		printf("                                             修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("award.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s\n", tmp->Awards_student_number, tmp->Award_project_name, tmp->Award_unit, tmp->Award_name, tmp->Award_level, tmp->Award_time);
			tmp = tmp->next;
		}


		fclose(fpp);

	}
	else if (strcmp(i, "5") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                                  当前获奖时间为:%s\n", p->Award_time);
		printf("                                                  请输入获奖时间:");
		char Add_award_time[50];
		scanf("%s", Add_award_time);
		strcpy(p->Award_time, Add_award_time);
		printf("                                                  修改成功\n");
		printf("                              ******************************************************\n");
		FILE* fpp;
		fpp = fopen("award.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s\n", tmp->Awards_student_number, tmp->Award_project_name, tmp->Award_unit, tmp->Award_name, tmp->Award_level, tmp->Award_time);
			tmp = tmp->next;
		}


		fclose(fpp);

	}
	else
	{
		printf("                              ******************************************************\n");
		printf("                                              输入错误，请重新输入：         \n");
		printf("                              ******************************************************\n");
		Modify_Awards();
	}
	After_Modify_Awards();
}


//函数---教务处端功能12-3-3
void Modify_Project(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  请输入项目编号：                         \n");
	printf("                              ******************************************************\n");
	printf("                                    ");
	char number[20];
	scanf("%s", number);
	system("cls");
	Project* head = Project_build();
	Project* p = head->next;
	Project* tmp = head->next;
	int m = strcmp(p->Project_number, number);
	while (m != 0 && p != NULL)
	{
		p = p->next;
		if (p == NULL)
		{
			break;
		}
		m = strcmp(p->Project_number, number);
	}
	if (p == NULL)
	{
		while (1)
		{

			printf("                              ******************************************************\n");
			printf("                                                    查无此项目                        \n");
			printf("                                                    按1重新输入                       \n");
			printf("                                                    按2回到上一界面                   \n");
			printf("                                                    请输入：                          \n");
			printf("                              ******************************************************\n");
			printf("                              ");
			char o[error_test];
			scanf("%s", o);
			if (strcmp(o,"1") == 0)
			{
				system("cls");
				Modify_Project();
				break;
			}
			else if (strcmp(o, "2") == 0)
			{
				system("cls");
				Modify();
				break;
			}
			else
			{
				system("cls");
				printf("                              ******************************************************\n");
				printf("                                                  输入错误，请重新输入\n");
				printf("                              ******************************************************\n");
			}
		}
	}
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                    1.指导教师                             \n");
	printf("                                                    2.项目名称                             \n");
	printf("                                                    3.项目编号                             \n");
	printf("                                                    4.立项时间                             \n");
	printf("                                                    5.结项时间                             \n");
	printf("                                                    请选择您要修改的信息:                  \n");
	printf("                              ******************************************************\n");
	printf("                                      ");
	char i[error_test];
	getchar();
	scanf("%s", i);
	system("cls");
	if (strcmp(i,"1") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                                当前指导教师为:%s                               \n", p->Project_teacher_name);
		printf("                                                请输入指导教师:                                 \n");
		printf("                              ******************************************************\n");
		printf("                                    ");
		char Add_project_teacher[50];
		scanf("%s", Add_project_teacher);
		system("cls");
		strcpy(p->Project_teacher_name, Add_project_teacher);
		FILE* fpp;
		fpp = fopen("project.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
			tmp = tmp->next;
		}
		fclose(fpp);
		while (p->next != NULL)
		{
			p = p->next;
			m = strcmp(p->Project_number, number);
			if (m == 0)
			{
				strcpy(p->Project_teacher_name, Add_project_teacher);
				FILE* pp;
				pp = fopen("project.txt", "w");
				if (pp == NULL)
				{
					printf("FILE NOT FOUND");
					exit(0);
				}
				tmp = head->next;
				while (tmp != 0)
				{
					fprintf(pp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
					tmp = tmp->next;
				}
				fclose(fpp);
			}
		}


	}
	else if (strcmp(i, "2") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                               当前项目名称为:%s               \n", p->Project_name);
		printf("                                               请输入项目名称:                                 \n");
		printf("                              ******************************************************\n");
		printf("                                    ");
		char Add_project_name[50];
		scanf("%s", Add_project_name);
		strcpy(p->Project_name, Add_project_name);
		FILE* fpp;
		fpp = fopen("project.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
			tmp = tmp->next;
		}
		while (p->next != NULL)
		{
			p = p->next;
			m = strcmp(p->Project_number, number);
			if (m == 0)
			{
				strcpy(p->Project_name, Add_project_name);
				FILE* pp;
				pp = fopen("project.txt", "w");
				if (pp == NULL)
				{
					printf("FILE NOT FOUND");
					exit(0);
				}
				tmp = head->next;
				while (tmp != 0)
				{
					fprintf(pp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
					tmp = tmp->next;
				}
				fclose(fpp);
			}
		}



		fclose(fpp);
	}
	else if (strcmp(i, "3") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                               当前项目编号为:%s                             \n", p->Project_number);
		printf("                                               请输入项目编号:                                 \n");
		printf("                              ******************************************************\n");
		printf("                                    ");
		char Add_project_number[50];
		scanf("%s", Add_project_number);
		strcpy(p->Project_number, Add_project_number);
		FILE* fpp;
		fpp = fopen("project.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
			tmp = tmp->next;
		}
		while (p->next != NULL)
		{
			p = p->next;
			m = strcmp(p->Project_number, number);
			if (m == 0)
			{
				strcpy(p->Project_number, Add_project_number);
				FILE* pp;
				pp = fopen("project.txt", "w");
				if (pp == NULL)
				{
					printf("FILE NOT FOUND");
					exit(0);
				}
				tmp = head->next;
				while (tmp != 0)
				{
					fprintf(pp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
					tmp = tmp->next;
				}
				fclose(fpp);
			}
		}


		fclose(fpp);
	}
	else if (strcmp(i, "4") == 0)
	{
		printf("                              ******************************************************\n");
		printf("                                                当前立项时间为:%s                             \n", p->Project_start_time);
		printf("                                                请输入立项时间:                                 \n");
		printf("                              ******************************************************\n");
		printf("                                    ");
		char Add_project_start_time[50];
		scanf("%s", Add_project_start_time);
		strcpy(p->Project_start_time, Add_project_start_time);
		FILE* fpp;
		fpp = fopen("project.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
			tmp = tmp->next;
		}
		while (p->next != NULL)
		{
			p = p->next;
			m = strcmp(p->Project_number, number);
			if (m == 0)
			{
				strcpy(p->Project_start_time, Add_project_start_time);
				FILE* pp;
				pp = fopen("project.txt", "w");
				if (pp == NULL)
				{
					printf("FILE NOT FOUND");
					exit(0);
				}
				tmp = head->next;
				while (tmp != 0)
				{
					fprintf(pp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
					tmp = tmp->next;
				}
				fclose(fpp);
			}
		}


		fclose(fpp);
	}
	else if (strcmp(i, "5") == 0)
	{
		printf("                                    ************************************************************\n");
		printf("                                                        当前结项时间为:%s                             \n", p->Project_end_time);
		printf("                                                        请输入结项时间:                                 \n");
		printf("                                    ************************************************************\n");
		printf("                                    ");
		char Add_project_end_time[50];
		scanf("%s", Add_project_end_time);
		strcpy(p->Project_end_time, Add_project_end_time);
		FILE* fpp;
		fpp = fopen("project.txt", "w");
		if (fpp == NULL)
		{
			printf("FILE NOT FOUND");
			exit(0);
		}
		tmp = head->next;
		while (tmp != NULL)
		{
			fprintf(fpp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
			tmp = tmp->next;
		}
		while (p->next != NULL)
		{
			p = p->next;
			m = strcmp(p->Project_number, number);
			if (m == 0)
			{
				strcpy(p->Project_end_time, Add_project_end_time);
				FILE* pp;
				pp = fopen("project.txt", "w");
				if (pp == NULL)
				{
					printf("FILE NOT FOUND");
					exit(0);
				}
				tmp = head->next;
				while (tmp != 0)
				{
					fprintf(pp, "%s  %s  %s  %s  %s  %s  %s %s \n", tmp->Project_student_number, tmp->Project_writer, tmp->Project_teacher_name, tmp->Project_name, tmp->Project_number, tmp->Project_start_time, tmp->Project_end_time, tmp->Project_status);
					tmp = tmp->next;
				}
				fclose(fpp);
			}
		}


		fclose(fpp);
	}

	else
	{
		printf("                              ******************************************************\n");
		printf("                                                输入错误，请重新输入：        \n");
		printf("                              ******************************************************\n");
		Modify_Project();
	}
	printf("                              ******************************************************\n");
	printf("                                                                                       \n");
	printf("                                                     修改成功                          \n");
	printf("                                                                                       \n");
	printf("                                                                                       \n");
	printf("                              ******************************************************\n");
	After_Modify_project();
}


//函数---查询错误输入时
void error_find(void)
{
	printf("                              ******************************************************\n");
	printf("                                                回到上一页面请输入1             \n");
	printf("                                                回到素质类首页请输入2           \n");
	printf("                                                回到教务处端首页请输入3         \n");
	printf("                                                退出系统请输入4                 \n");
	printf("                                                请输入：                        \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	while (1)
	{
		scanf("%s", i);
		if (strcmp(i,"1") == 0)
		{
			single_find();
			break;
		}
		else if (strcmp(i, "2") == 0)
		{
			Service();
			break;
		}
		else if (strcmp(i, "3") == 0)
		{
			dean_office_interface();
			break;
		}
		else if (strcmp(i, "4") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("                              ******************************************************\n");
			printf("                                                输入错误，请重新输入:           \n");
			printf("                              ******************************************************\n");
			printf("                              ");
		}
	}
}


//函数---查找时输入错误
void Find_error(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                输入错误，请重新输入：                  \n");
	printf("                              ******************************************************\n");
	printf("                              ******************************************************\n");
	printf("                                     请选择查看所有素质类成绩或单独查看某位同学成绩     \n");
	printf("                                             查看全部素质类成绩请输入1                  \n");
	printf("                                            单独查看某位同学成绩请输入2                 \n");
	printf("                                                  返回上一层请按0                       \n");
	printf("                                                        请输入：                        \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char n[error_test];
	scanf("%s", n);
	if (strcmp(n,"1") == 0)
	{
		system("cls");
		Student_find();
	}
	else if (strcmp(n, "2") == 0)
	{
		system("cls");
		single_find();
	}
	else if (strcmp(n, "0") == 0)
	{
		Service();
	}
	else
	{
		Find_error();

	}
}


//函数---查询结束后下一步骤
void After_student_find(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  返回上一页面请输入1                    \n");
	printf("                                                  返回素质类首页请输入2                  \n");
	printf("                                                  返回教务处端首页请输入3                \n");
	printf("                                                  退出系统请输入4                        \n");
	printf("                                                     请输入：                            \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"1") == 0)
	{
		system("cls");
		Student_find();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                  输入错误，请重新输入：                  \n");
		printf("                              ******************************************************\n");
		After_student_find();
	}
}


//函数---单独查询某位学生后下一步骤
void After_single_find(void)
{
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                              ******************************************************\n");
	printf("                                                  返回上一页面请输入1                    \n");
	printf("                                                  返回素质类首页请输入2                  \n");
	printf("                                                  返回教务处端首页请输入3                \n");
	printf("                                                  退出系统请输入4                        \n");
	printf("                                                     请输入：                            \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"1") == 0)
	{
		system("cls");
		Find();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                  输入错误，请重新输入：                  \n");
		printf("                              ******************************************************\n");
		After_single_find();
	}
}


//函数---增加论文类项目后下一步骤
void After_Add_Paper(void)
{
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                              ******************************************************\n");
	printf("                                                  继续添加请输入0                        \n");
	printf("                                                  返回上一页面请输入1                    \n");
	printf("                                                  返回素质类首页请输入2                  \n");
	printf("                                                  返回教务处端首页请输入3                \n");
	printf("                                                  退出系统请输入4                        \n");
	printf("                                                     请输入：                            \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"0") == 0)
	{
		system("cls");
		Add_Paper();
	}
	else if (strcmp(i, "1") == 0)
	{
		system("cls");
		Add();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：                   \n");
		printf("                              ******************************************************\n");
		After_Add_Paper();
	}
}


//函数---增加项目类后下一步骤
void After_Add_project(void)
{
	printf("                              ******************************************************\n");
	printf("                                                   继续添加请输入0                       \n");
	printf("                                                   返回上一页面请输入1                   \n");
	printf("                                                   返回素质类首页请输入2                 \n");
	printf("                                                   返回教务处端首页请输入3               \n");
	printf("                                                   退出系统请输入4                       \n");
	printf("                                                   请输入：                              \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"0") == 0)
	{
		system("cls");
		Add_Project();
	}
	else if (strcmp(i, "1") == 0)
	{
		system("cls");
		Add();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                  输入错误，请重新输入：                  \n");
		printf("                              ******************************************************\n");
		After_Add_project();
	}
}


//函数---增加完奖项类项目后下一步骤
void After_Add_awards(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  继续添加请输入0                        \n");
	printf("                                                  返回上一页面请输入1                    \n");
	printf("                                                  返回素质类首页请输入2                  \n");
	printf("                                                  返回教务处端首页请输入3                \n");
	printf("                                                  退出系统请输入4                        \n");
	printf("                                                  请输入：                               \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"0") == 0)
	{
		system("cls");
		Add_Awards();
	}
	else if (strcmp(i, "1") == 0)
	{
		system("cls");
		Add();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：                   \n");
		printf("                              ******************************************************\n");
		After_Add_awards();
	}
}


//函数---修改完论文类项目后下一步骤
void After_Modify_Paper(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  继续修改请输入0                        \n");
	printf("                                                  返回上一页面请输入1                    \n");
	printf("                                                  返回素质类首页请输入2                  \n");
	printf("                                                  返回教务处端首页请输入3                \n");
	printf("                                                  退出系统请输入4                        \n");
	printf("                                                  请输入：                               \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"0") == 0)
	{
		system("cls");
		Modify_Paper();
	}
	else if (strcmp(i, "1") == 0)
	{
		system("cls");
		Modify();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：                   \n");
		printf("                              ******************************************************\n");
		After_Modify_Paper();
	}
}


//函数---修改完项目类后下一步骤
void After_Modify_project(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  继续修改请输入0                        \n");
	printf("                                                  返回上一页面请输入1                    \n");
	printf("                                                  返回素质类首页请输入2                  \n");
	printf("                                                  返回教务处端首页请输入3                \n");
	printf("                                                  退出系统请输入4                        \n");
	printf("                                                  请输入：                               \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"0") == 0)
	{
		system("cls");
		Modify_Project();
	}
	else if (strcmp(i, "1") == 0)
	{
		system("cls");
		Modify_Project();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：                   \n");
		printf("                              ******************************************************\n");
		After_Modify_project();
	}
}


//函数---修改完奖项类后下一步骤
void After_Modify_Awards(void)
{
	printf("                              ******************************************************\n");
	printf("                                                  继续修改请输入0                        \n");
	printf("                                                  返回上一页面请输入1                    \n");
	printf("                                                  返回素质类首页请输入2                  \n");
	printf("                                                  返回教务处端首页请输入3                \n");
	printf("                                                  退出系统请输入4                        \n");
	printf("                                                  请输入：                               \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char i[error_test];
	scanf("%s", i);
	if (strcmp(i,"0") == 0)
	{
		system("cls");
		Modify_Awards();
	}
	else if (strcmp(i, "1") == 0)
	{
		system("cls");
		Modify();
	}
	else if (strcmp(i, "2") == 0)
	{
		system("cls");
		Service();
	}
	else if (strcmp(i, "3") == 0)
	{
		dean_office_interface();
	}
	else if (strcmp(i, "4") == 0)
	{
		withdraw();
	}
	else
	{
		system("cls");
		printf("                              ******************************************************\n");
		printf("                                                 输入错误，请重新输入：                   \n");
		printf("                              ******************************************************\n");
		After_Modify_Awards();
	}
}


//函数---修改论文信息时学号输入错误
void Error_student_number_paper(void)
{
	system("cls");
	printf("                              ******************************************************\n");
	printf("                                                   输入错误                           \n");
	printf("                                                   按1重新输入学号                    \n");
	printf("                                                   按2回到上一界面                    \n");
	printf("                                                   请输入：                           \n");
	printf("                              ******************************************************\n");
	printf("                              ");
	char o[error_test];
	scanf("%s", o);
	if (strcmp(o,"1") == 0)
		Modify_Paper;
	else if (strcmp(o, "2") == 0)
		Modify();
	else
	{
		Error_student_number_paper();

	}
}


//函数---学生端功能1（成绩查询）
void student_inquiry(Student* head, Student* tmp)
{

	system("cls");

	printf("                              ******************************************************\n");
	printf("                              **                     成绩查询                     **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                  1.综合成绩查询                  ||\n");
	printf("                              ||                  2.具体成绩查询                  ||\n");
	printf("                              ||                  返回上一层请按0                 ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");                             //界面

	char ch[error_test];         //选项

	while (1)
	{
		scanf("%s", ch);

		if (strcmp(ch,"1") == 0)
		{
			student_inquiry_total(head, tmp);
			break;

		}
		else if (strcmp(ch, "2") == 0)
		{
			student_inquiry_detail(head, tmp);
			break;
		}
		else if (strcmp(ch, "0") == 0)
		{
			student_interface(head, tmp);
			break;
		}
		else
		{
			printf("\033[31m                              您输入的选项不正确，请重新输入：\033[0m");
		}
	}

}


//函数---学生端功能1-1（综合成绩查询）
void student_inquiry_total(Student* head, Student* tmp)
{
	system("cls");

	printf("                              查询成功！\n\n");
	printf("                              ============================================\n");
	printf("                                                                          \n");
	printf("                                                  姓名：%s                \n", tmp->name);
	printf("                                                  学号：%s                \n", tmp->num);
	printf("                                                  专业：%s                \n", tmp->major);
	printf("                                                  平均成绩：%.1f          \n", tmp->grade);
	printf("                                                  综合绩点：%.2f          \n", tmp->GPA);
	printf("                                                  排名：%d                \n", tmp->ranking);
	printf("                                                                          \n");
	printf("                              ============================================\n\n");

	printf("                              ******************************************************\n");
	printf("                              ||                  继续查询请输入1                 ||\n");
	printf("                              ||                  返回首页请输入2                 ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_inquiry(head, tmp);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_interface(head, tmp);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
		}
	}
}


//函数---学生端功能1-2（具体成绩查询）
void student_inquiry_detail(Student* head, Student* tmp)
{
	system("cls");

	printf("                              ******************************************************\n");
	printf("                              **                   具体成绩查询                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                    1.大一学年                    ||\n");
	printf("                              ||                    2.大二学年                    ||\n");
	printf("                              ||                    3.大三学年                    ||\n");
	printf("                              ||                 返回上一层请按0                  ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您想查看的学年（输入1/2/3）：");

	int m = 0;
	int cho;

	chengji* top = tmp->head->next;

	while (1)
	{
		scanf("%d", &cho);
		top = tmp->head->next;
		if (cho == 1 || cho == 2 || cho == 3)
		{

			system("cls");
			printf("                              查询成功！\n\n");
			printf("                              ======================================================\n");
			printf("                              学科             学分             成绩            绩点\n");
			printf("                              ======================================================\n");


			while (top != NULL)
			{
				if (top->xueqi == cho)
				{
					if (top->chengji < 60)
					{
						printf("\033[31m                              %-10s\t%-10d\t%-10.1f\t%-10.2f\033[0m\n", top->xueke, top->xuefen, top->chengji, top->jidian);
					}
					else
					{
						printf("                              %-10s\t%-10d\t%-10.1f\t%-10.2f\n", top->xueke, top->xuefen, top->chengji, top->jidian);
					}

				}
				else
				{
					m++;
				}
				top = top->next;
			}
			if (cknotNumber(tmp->head) == m)
			{
				printf("\033[31m                              未找到该学年的成绩，请您重新输入学年：\033[0m");
			}
			else
			{
				break;
			}
		}
		else if (cho == 0)
		{
			student_inquiry(head, tmp);
			break;
		}
		else
		{
			printf("\033[31m                              您输入的学年不正确，请重新输入：\033[0m");
			m = 0;
			top = tmp->head->next;
		}

	}
	printf("\n\n                              ******************************************************\n");
	printf("                              ||                  继续查询请输入1                 ||\n");
	printf("                              ||                  返回首页请输入2                 ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_inquiry(head, tmp);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_interface(head, tmp);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
		}
	}
}


//函数---学生端功能2（学生学习态度评估及保研预测）
void student_single_prediction(Student* head, Student* p)
{
	system("cls");
	printf("                              *****************************************************************\n");
	printf("                              **                 学生学习态度评估及保研预测                  **\n");
	printf("                              *****************************************************************\n\n");
	double x[10];
	double y[10];
	//x[]数组中存放学期数，相当于横坐标
	chengji* q = p->head->next;//q指向该学生的成绩的头节点
	float sum_xuefen = 0.0;
	float GPA_every_year = 0.0;
	if ((p->semester == 2) || (p->semester == 3)) {
		for (int i = 0; i < p->semester; i++) {
			x[i] = i + 1;
		}

		//y[]数组中存放每学期的绩点，相当于纵坐标
		for (int j = 0; j < (p->semester); j++) {
			while (q != NULL) {
				if (q->xueqi == j + 1) {
					sum_xuefen += q->xuefen;
					GPA_every_year += (q->xuefen) * (q->jidian);
					q = q->next;
				}
				else
				{
					q = q->next;
				}
			}
			y[j] = GPA_every_year / sum_xuefen;
			sum_xuefen = 0;
			GPA_every_year = 0.0;
			q = p->head->next;
		}

		//调用训练模型
		LinearRegression lr;
		gradient(x, y, (p->semester), &lr);
		int want_pre;
		int start_pre1;
	start_pre1:
		printf("                              请输入你想查询的学年数：(输入1至4的数字代表学年数)");
		scanf("%d", &want_pre);
		//调用预测函数返回值即为预测成绩
		if ((want_pre > p->semester) && (want_pre <= 4)) {
			printf("                              \033[44m系统预测该学年绩点为：%.2f\033[0m", predict(want_pre, lr));
			printf("\n                              ****************继续预测请按1，返回学生端首页请按2,退出系统请按3****************\n");
			printf("                              ");
			char going[error_test];
			while (1)
			{
				scanf("%s", going);
				if (strcmp(going, "1") == 0)
				{
					student_single_prediction(head, p);
					break;
				}
				else if (strcmp(going, "2") == 0)
				{
					student_interface(head, p);
					break;
				}
				else if (strcmp(going, "3") == 0)
				{
					withdraw();
					break;
				}
				else
				{
					printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
				}
			}
		}
		else {
			printf("\033[31m                              该学年成绩不可预测，请重新输入！\033[0m\n");
			goto start_pre1;
		}
	}
	else {
		printf("\033[31m                              对不起，您所在年级不可预测！\033[0m\n");
		printf("\n                              ****************返回学生端首页请按1,退出系统请按2****************\n");
		printf("                              ");
		
		char going[error_test];
		while (1)
		{
			scanf("%s", going);
			if (strcmp(going, "1") == 0)
			{
				student_interface(head, p);
				break;
			}
			else if (strcmp(going, "2") == 0)
			{
				withdraw();
				break;
			}
			else
			{
				printf("\033[31m                              选项输入不正确，请重新输入：\033[0m");
			}
		}
	}
}


//函数---学生端功能3（学生密码修改）
void student_modifyKey(Student* head, Student* p)
{
	Student* copy = p;
	system("cls");                                          //清屏

	printf("                              ******************************************************\n");
	printf("                              **                   学生密码修改                   **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");

	char ch;
	int ikeyII = 0, ikeyIII = 0, ikeyIV = 0;                            //计数器

	FILE* fpp = NULL;                                             //为之后修改文件做准备

	char originalKey[20], newKeyI[20], newKeyII[20];            //输入的原密码、新密码、重复的新密码

	printf("\n                              请输入您的原密码：");
	getchar();

	while (1)
	{
		while (1)                                 //实现隐藏密码，使密码输出为*
		{
			ch = getch();
			if (ch == '\r')
			{
				break;
			}
			if (ch == '\b')
			{
				if (ikeyII > 0)
				{
					originalKey[ikeyII - 1] = '\0';
					ikeyII--;
				}
				printf("\b");
				printf(" \b");
				continue;
			}

			originalKey[ikeyII++] = ch;
			printf("*");
		}
		originalKey[ikeyII] = '\0';


		if (strcmp(p->role_code, originalKey) == 0)                 //验证原密码是否正确
		{
			printf("\n\n                              请输入您的新密码（8位）：");
			while (1)
			{
				while (1)                                 //实现隐藏密码，使密码输出为*
				{
					ch = getch();
					if (ch == '\r')
					{
						break;
					}
					if (ch == '\b')
					{
						if (ikeyIII > 0)
						{
							newKeyI[ikeyIII - 1] = '\0';
							ikeyIII--;
						}
						printf("\b");
						printf(" \b");
						continue;
					}
					newKeyI[ikeyIII++] = ch;
					printf("*");
				}
				newKeyI[ikeyIII] = '\0';


				if (strlen(newKeyI) != 8)                        //验证新密码的长度
				{
					printf("\033[31m\n\n                              密码设置必须为8位，请您重新设置：\033[0m");
					ikeyII = 0;
					ikeyIII = 0;
					ikeyIV = 0;
				}
				else
				{
					printf("\n\n                              请再次输入您的新密码：");

					while (1)                                    //实现隐藏密码，使密码输出为*
					{
						ch = getch();
						if (ch == '\r')
						{
							break;
						}
						if (ch == '\b')
						{
							if (ikeyIV > 0)
							{
								newKeyII[ikeyIV - 1] = '\0';
								ikeyIV--;
							}
							printf("\b");
							printf(" \b");
							continue;
						}
						newKeyII[ikeyIV++] = ch;
						printf("*");
					}
					newKeyII[ikeyIV] = '\0';


					if (strcmp(newKeyI, newKeyII) == 0)                      //验证两次输入的新密码是否一致
					{
						strcpy(p->role_code, newKeyI);                           //更新链表中密码部分
						strcpy(copy->role_code, newKeyI);
						printf("\n\n                              修改密码成功！\n\n");

						Student* pp = head->next;
						chengji* qq;

						FILE* fp = NULL;
						fp = fopen("student_information.txt", "w");

						if (fp == NULL)
						{
							printf("FILE NOT FOUND");
							exit(0);
						}

						while (pp != NULL)
						{
							fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%s\t%.1f\t%.2f\t%d\t%s\t%d\t", pp->name, pp->sex, pp->num, pp->major, pp->semester, pp->school_district, pp->grade, pp->GPA, pp->ranking, pp->role_code, pp->credit);      //打开文件并进行复写
							qq = pp->head->next;
							while (qq != NULL)
							{
								fprintf(fp, "%d\t%d\t%s\t%.1f\t%.2f\t", qq->xueqi, qq->xuefen, qq->xueke, qq->chengji, qq->jidian);
								qq = qq->next;
							}
							fprintf(fp, "\n");
							pp = pp->next;
						}
						fclose(fp);
						break;
					}
					else
					{
						printf("\033[31m\n\n                              密码输入不一致，请重新设置,请输入您的新密码：\033[0m");
						ikeyII = 0;
						ikeyIII = 0;
						ikeyIV = 0;
					}
				}
			}
			break;
		}
		else
		{
			printf("\033[31m\n                              密码错误！请重新输入您的原密码：\033[0m");
			ikeyII = 0;
			ikeyIII = 0;
			ikeyIV = 0;
		}
	}
	printf("                              ******************************************************\n");
	printf("                              ||                  返回首页请输入1                 ||\n");
	printf("                              ||                  退出系统请输入2                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_interface(head, copy);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
	
}


//函数---学生端功能4（素质类项目查询）
void student_quality_education(Student* head, Student* tmp)
{
	system("cls");

	printf("                              ******************************************************\n");
	printf("                              **                  素质类项目查询                  **\n");
	printf("                              ******************************************************\n");
	printf("                                                                                    \n");
	printf("                              ======================================================\n");
	printf("                              ||                                                  ||\n");
	printf("                              ||                     1.论文类                     ||\n");
	printf("                              ||                     2.项目类                     ||\n");
	printf("                              ||                   3.竞赛获奖类                   ||\n");
	printf("                              ||                  返回上一层请按0                 ||\n");
	printf("                              ||                                                  ||\n");
	printf("                              ======================================================\n\n");
	printf("                              请输入您所需的服务（输入前方的序号）：");

	char ch[error_test];
	while (1)
	{
		scanf("%s", ch);
		if (strcmp(ch,"1") == 0)
		{
			student_paper(head, tmp);
			break;
		}
		else if (strcmp(ch, "2") == 0)
		{
			student_project(head, tmp);
			break;
		}
		else if (strcmp(ch, "3") == 0)
		{
			student_awards(head, tmp);
			break;
		}
		else if (strcmp(ch, "0") == 0)
		{
			student_interface(head, tmp);
			break;
		}
		else
		{
			printf("\033[31m                              输入选项错误，请重新输入：\033[0m");
		}

	}
}


//函数---学生端功能4-1（论文类）
void student_paper(Student* top, Student* tmp)
{
	system("cls");
	int i = 1;
	Paper* head = Paper_build();
	Paper* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Paper_student_number, tmp->num) == 0)
		{
			printf("编号  论文作者       论文名称/期刊名称/会议名称        发表时间   卷/期/论文号/页码范围    论文级别信息  加分信息 GPA\n");
			printf("%-7d", i++);
			printf("%-16s%-30s%-20s%-20s%-10s%-9s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);

			if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
				printf("0.4\n");
			else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
				printf("0.2\n");
			else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
				printf("0.1\n");
			else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
				printf("0.05\n");
			else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
				printf("0.02\n");
			else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
				printf("0.01\n");
			else
				printf("0\n");
			p = p->next;
			break;
		}
		else
		{
			p = p->next;
			if (p == NULL)
			{
				system("cls");
				printf("                              ******************************************************\n");
				printf("                                                没有找到您的论文类信息              \n");
				printf("                              ******************************************************\n");
			}
		}
	}
	while (p != NULL)
	{

		if (strcmp(p->Paper_student_number, tmp->num) == 0)
		{
			printf("%-7d", i++);
			printf("%-16s%-30%-20s%-20s%-10s%-9s", p->Paper_writer, p->Paper_name, p->Paper_time, p->Paper_page, p->Paper_level, p->Paper_points);

			if (strcmp(p->Paper_level, "A") == 0)                    //A类论文绩点加0.4
				printf("0.4\n");
			else if (strcmp(p->Paper_level, "B") == 0)                     //B类论文绩点加0.2
				printf("0.2\n");
			else if (strcmp(p->Paper_level, "C") == 0)                         //C类论文绩点加0.1
				printf("0.1\n");
			else if (strcmp(p->Paper_level, "D") == 0)                           //D类论文绩点加0.05
				printf("0.05\n");
			else if (strcmp(p->Paper_level, "E") == 0)                              //E类论文绩点加0.02
				printf("0.02\n");
			else if (strcmp(p->Paper_level, "F") == 0)                                       //F类论文绩点加0.01
				printf("0.01\n");
			else
				printf("0\n");
			p = p->next;

		}
		else
		{
			p = p->next;
		}
	}
	printf("\n\n                              ******************************************************\n");
	printf("                              ||             返回素质类项目首页请输入1            ||\n");
	printf("                              ||               返回学生端首页请输入2              ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_quality_education(top, tmp);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_interface(top, tmp);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---学生端功能4-2（项目类）
void student_project(Student* top, Student* tmp)
{
	system("cls");
	int i = 1;
	Project* head = Project_build();
	Project* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Project_student_number, tmp->num) == 0)               //比对学号，找到学生
		{
			printf("编号    项目成员        指导教师       项目名称         项目编号      立项时间        结项时间   在项目中职务  GPA\n");
			printf("%d     ", i++);
			printf("%-20s%-10s%-22s%-12s%-16s%-15s%-10s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);
			if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
				printf("0.4\n");
			else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
				printf("0.2\n");
			else
				printf("0\n");                                     //其他人不加GPA
			p = p->next;
			break;
		}
		else
		{
			p = p->next;
			if (p == NULL)                           //如果匹配不到此同学则输出查无此人
			{
				printf("                              ******************************************************\n");
				printf("                                                没有找到您的项目类信息              \n");
				printf("                              ******************************************************\n");
			}
		}
	}
	while (p != NULL)
	{
		if (strcmp(p->Project_student_number, tmp->num) == 0)               //比对学号，找到学生
		{
			printf("%d     ", i++);
			printf("%-20s%-10s%-22s%-12s%-16s%-15s%-10s", p->Project_writer, p->Project_teacher_name, p->Project_name, p->Project_number, p->Project_start_time, p->Project_end_time, p->Project_status);
			if (strcmp(p->Project_status, "负责人") == 0)                      //项目负责人GPA加0.4
				printf("0.4\n");
			else if (strcmp(p->Project_status, "第二名") == 0)                 //项目第二名GPA加0.2
				printf("0.2\n");
			else
				printf("0\n");                                     //其他人不加GPA
			p = p->next;

		}
		else
			p = p->next;
	}
	printf("\n\n                              ******************************************************\n");
	printf("                              ||             返回素质类项目首页请输入1            ||\n");
	printf("                              ||               返回学生端首页请输入2              ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");

	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_quality_education(top, tmp);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_interface(top, tmp);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---学生端功能4-3（竞赛获奖类）
void student_awards(Student* top, Student* tmp)
{
	system("cls");
	int i = 1;
	Awards* head = Awards_build();
	Awards* p;
	p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->Awards_student_number, tmp->num) == 0)
		{
			printf("编号    竞赛项目名称                主办单位            获奖人             获奖等级           获奖时间     GPA\n");
			printf("%-4d", i++);
			printf("%-30s%-21s%-20s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
			if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
				printf("0.4\n");
			else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
				printf("0.2\n");
			else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
				printf("0.1\n");
			else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
				printf("0.05\n");
			else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
				printf("0.02\n");
			p = p->next;
			break;
		}
		else
		{
			p = p->next;
			if (p == NULL)
			{
				printf("                              ******************************************************\n");
				printf("                                                没有找到您的获奖类信息              \n");
				printf("                              ******************************************************\n");
			}
		}
	}
	while (p != NULL)
	{
		if (strcmp(p->Awards_student_number, tmp->num) == 0)
		{
			printf("%-4d", i++);
			printf("%-30s%-21s%-20s%-18s%-14s", p->Award_project_name, p->Award_unit, p->Award_name, p->Award_level, p->Award_time);
			if (strcmp(p->Award_level, "A类竞赛金奖") == 0)
				printf("0.4\n");
			else if ((strcmp(p->Award_level, "A类竞赛银奖") == 0) || (strcmp(p->Award_level, "B类竞赛金奖") == 0))
				printf("0.2\n");
			else if ((strcmp(p->Award_level, "A类竞赛铜奖") == 0) || (strcmp(p->Award_level, "B类竞赛银奖") == 0) || (strcmp(p->Award_level, "C类竞赛金奖") == 0))
				printf("0.1\n");
			else if ((strcmp(p->Award_level, "B类竞赛铜奖") == 0) || (strcmp(p->Award_level, "C类竞赛银奖") == 0))
				printf("0.05\n");
			else if (strcmp(p->Award_level, "C类竞赛铜奖") == 0)
				printf("0.02\n");
			p = p->next;
		}
		else
		{
			p = p->next;
		}
	}
	printf("\n\n                              ******************************************************\n");
	printf("                              ||             返回素质类项目首页请输入1            ||\n");
	printf("                              ||               返回学生端首页请输入2              ||\n");
	printf("                              ||                  退出系统请输入3                 ||\n");
	printf("                              ******************************************************\n");
	printf("                              请输入：");
	char shift[error_test];
	while (1)
	{
		scanf("%s", shift);
		if (strcmp(shift, "1") == 0)
		{
			student_quality_education(top, tmp);
			break;
		}
		else if (strcmp(shift, "2") == 0)
		{
			student_interface(top, tmp);
			break;
		}
		else if (strcmp(shift, "3") == 0)
		{
			withdraw();
			break;
		}
		else
		{
			printf("\033[31m                              输入选项不正确，请重新输入：\033[0m");
		}
	}
}


//函数---退出系统
void withdraw(void)
{
	printf("\n\n\n\033[44m欢迎您再次使用成绩管理系统！\033[0m\n");
	exit(0);
}


int main()
{
	login();
	return 0;
}




