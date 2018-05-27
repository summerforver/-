#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define MALLOC (STU *)malloc(sizeof( STU ))

//学生信息 
typedef struct student {
	
	char stuName[30];//学生姓名 
	char stuSex[30];//学生性别 
	char stuClass[30];//学生班级
	int  stuAge ; //学生年龄 
	char stuNumber[30] ;//学生学号
	double stuScore;//学生成绩  
	struct student *next ;//指向本结构体的指针 
	 
}STU;

//账户登录信息 
typedef struct scert {
	char user[20]; //用户名 
	char code[20];//密码 
}Users;


Users per;
int count;
STU *pHead = NULL;
FILE *fp;


void show( ) ;//主页面学生教师管理员选择
void show_Student( ) ;//学生登录界面
void show_Teacher( ) ;//教师登录界面
void show_Manager( ) ;//管理员登录界面 
void show_Find( ) ;//查找界面
void show_Count( ) ;//统计界面
void show_Sort( ) ;//排序界面 
void stu_InputMessage( ) ;//手动输入学生信息 
STU *stu_Input( ) ;//链表创建输入学生信息 
void stu_FileInput( ) ;//将学生信息保存在文件中
void stu_Output( ) ;//输出学生信息
void stu_NameFind( ) ;//根据姓名查找信息
void stu_NumberFind( ) ;//根据学号查找信息
void stu_ClassSexFind( ) ;//根据班级和性别组合查询
void stu_Delete( ) ;//根据学号删除
void stu_Increase( ) ;//增加学生信息
void stu_NumberCorrect( ) ;//根据学号修改学生信息
void stu_NameCorrect( ) ;//根据姓名修改学生信息
void stu_ScoreCount( ) ;//根据成绩统计学生信息
void stu_SexCount( ) ;//根据性别统计学生信息
void stu_ClassAgeCount( ) ;//根据班级和年龄综合统计
void stu_UpSort( ) ;//按成绩升序
void stu_DownSort( ) ;//按成绩降序 
void find_Book( ) ;//查询端
void count_Book( ) ;//统计端
void sort_Book( ) ;//排序端 
void student_Book( ) ;//学生端
void teacher_Book( ) ;//教师端 
void manager_Book( ) ;//管理员端
void remark( ) ;//主菜单 


void stu_TeacherSign ( );//教师注册 
void stu_StuSubmit( ) ; //学生登录 
void stu_TeacherSubmit( );//教师登录 
void stu_ManagerSubmit( );// 管理员登录 


//主界面 
void show() {
	printf("\n\n\t\t\t  =====================================================================\n");
	printf("\t\t\t  ---------------------------学生管理系统------------------------------\n");
	printf("\t\t\t  -                        -1-     学生登录                           -\n");
	printf("\t\t\t  -                        -2-     教师登录                           -\n");
	printf("\t\t\t  -                        -3-     管理员登录                         -\n");
	printf("\t\t\t  -                        -0-     退出                               -\n");
	printf("\t\t\t  ---------------------------学生管理系统------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
}

//学生登录页面 
show_StuSubmit( ) {
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t  |                    欢迎进入学生管理系统！                     |\n"); 
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t               ---1.登录---                  ---2.注册---\n "); 
	printf("\t\t\t               ---3.返回上一层---            ---0.退出---\n "); 
}

//教师登录页面 
show_TeacherSubmit( ) {
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t  |                    欢迎进入学生管理系统！                     |\n"); 
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t               ---1.登录---                  ---2.注册---\n "); 
	printf("\t\t\t               ---3.返回上一层---            ---0.退出---\n "); 
}

//管理员登录页面 
show_ManagerSubmit( ) {
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t  |                    欢迎进入学生管理系统！                     |\n"); 
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t               ---1.登录---                  ---2.注册---\n "); 
	printf("\t\t\t               ---3.返回上一层---            ---0.退出---\n "); 
}

//学生登录界面 
void show_Student () {
	printf("\n\n\t\t\t  ---------------------------恭喜你登陆成功！--------------------------\n");
	printf("\t\t\t  =====================================================================\n");
	printf("\t\t\t  -----------------------------学生登录--------------------------------\n");
	printf("\t\t\t  -                        -1-     查询学生信息                       -\n");
	printf("\t\t\t  -                        -2-     返回上一层                         -\n");
	printf("\t\t\t  -                        -0-     退出                               -\n");
	printf("\t\t\t  -----------------------------学生登录--------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
}

//教师登录界面
void show_Teacher () {
	printf("\n\n\t\t\t  ---------------------------恭喜你登陆成功！----------------------------\n");
	printf("\t\t\t  =====================================================================\n");
	printf("\t\t\t  -----------------------------教师登录--------------------------------\n");
	printf("\t\t\t  -                       -1-     输入学生信息                        -\n");
	printf("\t\t\t  -                       -2-     将学生信息保存在文件中              -\n");
	printf("\t\t\t  -                       -3-     输出学生信息                        -\n");
	printf("\t\t\t  -                       -4-     修改学生信息                        -\n");
	printf("\t\t\t  -                       -5-     增加学生信息                        -\n");
	printf("\t\t\t  -                       -6-     删除学生信息                        -\n");
	printf("\t\t\t  -                       -7-     查询学生信息                        -\n");
	printf("\t\t\t  -                       -8-     学生信息统计                        -\n");
	printf("\t\t\t  -                       -9-     对学生信息排序                      -\n");
	printf("\t\t\t  -                       -a-     返回上一层                          -\n");
	printf("\t\t\t  -                       -0-     退出                                -\n");
	printf("\t\t\t  -----------------------------教师登录--------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
} 

// 管理员理员登录界面 
void show_Manager() {
	printf("\n\n\t\t\t  ---------------------------恭喜你登陆成功！--------------------------\n");
	printf("\t\t\t  =====================================================================\n");
	printf("\t\t\t  ---------------------------管理员登录--------------------------------\n");
	printf("\t\t\t  -                       -1-     输入学生信息                        -\n");
	printf("\t\t\t  -                       -2-     将学生信息保存在文件中              -\n");
	printf("\t\t\t  -                       -3-     输出学生信息                        -\n");
	printf("\t\t\t  -                       -4-     修改学生信息                        -\n");
	printf("\t\t\t  -                       -5-     增加学生信息                        -\n");
	printf("\t\t\t  -                       -6-     删除学生信息                        -\n");
	printf("\t\t\t  -                       -7-     查询学生信息                        -\n");
	printf("\t\t\t  -                       -8-     学生信息统计                        -\n");
	printf("\t\t\t  -                       -9-     对学生信息排序                      -\n");
	printf("\t\t\t  -                       -a-     返回上一层                          -\n");
	printf("\t\t\t  -                       -0-     退出                                -\n");
	printf("\t\t\t  ---------------------------管理员登录--------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
}

//查找界面 
void show_Find ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------信息查询----------------------------------\n");
	printf("\t\t\t  -                          -1-     学号查询                             -\n");
	printf("\t\t\t  -                          -2-     姓名查询                             -\n");
	printf("\t\t\t  -                          -3-     性别和班级查询                       -\n");
	printf("\t\t\t  -                          -4-     返回上一层                           -\n");
	printf("\t\t\t  -                          -0-     退出                                 -\n");
	printf("\t\t\t  -------------------------------信息查询----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//统计界面 
void show_Count ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------信息统计----------------------------------\n");
	printf("\t\t\t  -                          -1-     成绩统计                             -\n");
	printf("\t\t\t  -                          -2-     性别统计                             -\n");
	printf("\t\t\t  -                          -3-     班级和年龄统计                       -\n");
	printf("\t\t\t  -                          -4-     返回上一层                           -\n");
	printf("\t\t\t  -                          -0-     退出                                 -\n");
	printf("\t\t\t  -------------------------------信息统计----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//修改界面 
void show_Correct ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------信息修改----------------------------------\n");
	printf("\t\t\t  -                          -1-     学号修改                             -\n");
	printf("\t\t\t  -                          -2-     姓名修改                             -\n");
	printf("\t\t\t  -                          -3-     返回上一层                           -\n");
	printf("\t\t\t  -                          -0-     退出                                 -\n");
	printf("\t\t\t  -------------------------------信息修改----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}
//增加界面 
void show_Increase ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------信息增加----------------------------------\n");
	printf("\t\t\t  -                          -1-     从头部增加                           -\n");
	printf("\t\t\t  -                          -2-     从中间增加                           -\n");
	printf("\t\t\t  -                          -3-     从尾部增加                           -\n");
	printf("\t\t\t  -                          -4-     返回上一层                           -\n");
	printf("\t\t\t  -                          -0-     退出                                 -\n");
	printf("\t\t\t  -------------------------------信息增加----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//删除界面 
void show_Delete ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------信息删除----------------------------------\n");
	printf("\t\t\t  -                          -1-     学号删除                             -\n");
	printf("\t\t\t  -                          -2-     姓名姓名                             -\n");
	printf("\t\t\t  -                          -3-     返回上一层                           -\n");
	printf("\t\t\t  -                          -0-     退出                                 -\n");
	printf("\t\t\t  -------------------------------信息删除----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//排序界面
void show_Sort ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------信息排序----------------------------------\n");
	printf("\t\t\t  -                          -1-     按成绩升序                           -\n");
	printf("\t\t\t  -                          -2-     按成绩降序                           -\n");
	printf("\t\t\t  -                          -3-     按学号升序                           -\n");
	printf("\t\t\t  -                          -4-     按学号降序                           -\n");
	printf("\t\t\t  -                          -5-     返回上一层                           -\n");
	printf("\t\t\t  -                          -0-     退出                                 -\n");
	printf("\t\t\t  -------------------------------信息排序----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
} 


//将学生注册信息写入文件 
void stu_StuFileSign() {
	fp = fopen ("学生登录.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  写文件出错，请按任意键退出！");
		getch();
		exit(1);
	} 
	fprintf(fp,"%s %s\r\n",per.user,per.code); 
	printf("\n\t\t\t  你注册的用户名和密码保存成功,请按任意键继续！");
	getch();
	fclose(fp);
} 



//学生注册 
void stu_StuSign ( ) {
	char temp1[30],temp2[30];
	printf("\n\t\t\t  -----------用户注册-----------");
	printf("\n\t\t\t  请输入用户名(5-20位，包含5和20)：") ;
	scanf("%s",per.user);
	
	if(  strlen(per.user) < 5 || strlen(per.user) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的用户名！"); 
		return stu_StuSign();
	} 
	
	printf("\n\t\t\t  请输入密码(6-20位，包含6和20)：");
	
	int j;
	for ( j = 0 ; per.code[j-1]!='\r';j++) {
		per.code[j]=getch();
		if ( per.code[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && per.code[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	per.code[j-1]='\0';
	//scanf("%s",per.code);
	
	if(  strlen(per.code) < 6 || strlen(per.code) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_StuSign();
	} 
	
	printf("\n\t\t\t  请确认密码(6-20位，包含6和20)：");
	
	for ( j = 0 ; temp1[j-1]!='\r';j++) {
		temp1[j]=getch();
		if ( temp1[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && temp1[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	temp1[j-1]='\0';
	
	//scanf("%s",temp1);
	
	if(  strlen(temp1) < 6 || strlen(temp1) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_StuSign();
	} 
	
	if ( strcmp ( per.code , temp1) == 0 ) {
		printf("\n\t\t\t  注册成功！");
		stu_StuFileSign( );
		printf("\n\t\t\t  --------------------------------");
		stu_StuSubmit( );
	} else {
		printf("\n\t\t\t  请再次确认密码(6-20位，包含6和20)：");
		
		//int j;
	for ( j = 0 ; temp2[j-1]!='\r';j++) {
		temp2[j]=getch();
		if (temp2[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && temp2[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	temp2[j-1]='\0';
		//scanf("%s",temp2);
		
		if(  strlen(temp2) < 6 || strlen(temp2) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_StuSign();
	} 
	
		
		if ( strcmp ( per.code , temp2) == 0 ) {
			printf("\n\t\t\t  注册成功！") ;
			stu_StuFileSign( );
			printf("\n\t\t\t  --------------------------------");
			stu_StuSubmit( );
			
		} else {
			printf("\n\t\t\t  注册失败！");
			printf("\n\t\t\t  请输入任意键退出！");
			getch();
			exit(0);
		}
	}
} 

//学生登录 
void stu_StuSubmit( ) {
	Users person; 
	char temp[30];
	printf("\n\t\t\t  ----------用户登录-------------");
	printf("\n\t\t\t  请输入用户名(5-20位，包含5和20)：") ;
	scanf("%s",person.user);
	
	if(  strlen(person.user) < 5 || strlen(person.user) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的用户名！"); 
		return stu_StuSubmit( );
	} 
	
	printf("\n\t\t\t  请输入密码(6-20位，包含6和20)：");
	int j;
	for ( j = 0 ; person.code[j-1]!='\r';j++) {
		person.code[j]=getch();
		if ( person.code[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && person.code[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	person.code[j-1]='\0';
	
	if(  strlen(person.code) < 6 || strlen(person.code) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_StuSubmit( );
	} 
	
	//scanf("%s",person.code);
	fp = fopen ("学生登录.txt","rb");
	if ( fp == NULL ) {
		printf("\t\t\t  没有此用户名，请前往注册！");
		stu_StuSign ( );
		/*printf("\n\t\t\t  写文件出错，请按任意键退出！");
		getch();
		exit(1);*/
	} 
	while ( fscanf(fp,"%s %s\r\n",per.user,per.code) != 0 ) {
		if( strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) == 0  ){
			printf("\n\t\t\t  登录成功！");
			break;
		} 
		if (strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) != 0) {
			printf("\n\t\t\t  用户名正确，密码错误！");
			printf("\n\t\t\t  请重新输入密码(6-20位，包含6和20)：");
			
			for ( j = 0 ; temp[j-1]!='\r';j++) {
			temp[j]=getch();
			if ( temp[j] == 8 && j >0 ) {
				printf("\b \b",j-=2);
			} else if ( j >= 0 && temp[j]!=13) {
				printf("*");
			} else {
				printf(" ");
			}
		}
			printf("\n");
			temp[j-1]='\0';
			
			if(  strlen(temp) < 6 || strlen(temp) > 20 ) {
				printf("\n\t\t\t  请输入在范围内的密码！"); 
				return stu_StuSubmit( );
			} 
			//scanf("%s",temp) ;
			if (strcmp ( per.code,temp) == 0) {
				printf("\n\t\t\t  登录成功！");
			} else {
				printf("\n\t\t\t  登录失败 ，请按任意键退出！");
				getch( ) ;
				exit (0);
			}
			break; 
		} 
		if (strcmp ( per.user,person.user) != 0 ) { 
			printf("\n\t\t\t  此用户未注册！请完成注册！");
			stu_StuSign ( );
			break; 
		} 
	}
} 

//将教师注册信息写入文件 
void stu_TeacherFileSign() {
	fp = fopen ("教师登录.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  写文件出错，请按任意键退出！");
		getch();
		exit(1);
	
	} 
	fprintf(fp,"%s %s\r\n",per.user,per.code); 
	printf("\n\t\t\t  你注册的用户名和密码保存成功,请按任意键继续！");
	getch();
	fclose(fp);
} 
//教师注册 
void stu_TeacherSign ( ) {
	char temp1[30],temp2[30];
	printf("\n\t\t\t  -----------用户注册-----------");
	printf("\n\t\t\t  请输入用户名(5-20位，包含5和20)：") ;
	
	scanf("%s",per.user);
	if(  strlen(per.user) < 5 || strlen(per.user) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的用户名！"); 
		return stu_TeacherSign();
	} 
	
	printf("\n\t\t\t  请输入密码(6-20位，包含6和20)：");
	
	int j;
	for ( j = 0 ; per.code[j-1]!='\r';j++) {
		per.code[j]=getch();
		if ( per.code[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && per.code[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	per.code[j-1]='\0';
	
	//scanf("%s",per.code);
	
	if(  strlen(per.code) < 6 || strlen(per.code) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_TeacherSign();
	} 
	
	printf("\n\t\t\t  请确认密码(6-20位，包含6和20)：");

	for ( j = 0 ; temp1[j-1]!='\r';j++) {
		temp1[j]=getch();
		if ( temp1[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && temp1[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	temp1[j-1]='\0';
	//scanf("%s",temp1);
	
	if(  strlen(temp1) < 6 || strlen(temp1) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_TeacherSign();
	} 
	if ( strcmp ( per.code , temp1) == 0 ) {
		printf("\n\t\t\t  注册成功！");
		stu_TeacherFileSign( );
		printf("\n\t\t\t  --------------------------------");
		stu_TeacherSubmit( );
	} else {
		printf("\n\t\t\t  密码错误，请再次确认密码：");
		for ( j = 0 ; temp2[j-1]!='\r';j++) {
		temp2[j]=getch();
		if ( temp2[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && temp2[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	temp2[j-1]='\0';
		
		//scanf("%s",temp2);
		
			if(  strlen(temp2) < 6 || strlen(temp2) > 20 ) {
				printf("\n\t\t\t  请输入在范围内的密码！"); 
				return stu_StuSign();
			} 
		if ( strcmp ( per.code , temp2) == 0 ) {
			printf("\n\t\t\t  注册成功！") ;
			stu_TeacherFileSign( );
			printf("\n\t\t\t  --------------------------------");
			stu_TeacherSubmit( );
			
		} else {
			printf("\n\t\t\t  注册失败！");
			printf("\n\t\t\t  请输入任意键退出！");
			getch();
			exit(0);
		}
	}
	
} 
//教师登录 
void stu_TeacherSubmit( ) {
	Users person; 
	char temp[30];
	printf("\n\t\t\t  ----------用户登录-------------");
	printf("\n\t\t\t  请输入用户名(5-20位，包含5和20)：") ; 
	scanf("%s",person.user);
	
	if(  strlen(person.user) < 5 || strlen(person.user) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的用户名！"); 
		return stu_TeacherSubmit( );
	} 
	
	printf("\n\t\t\t  请输入密码(6-20位，包含6和20)：");
	
	int j;
	for ( j = 0 ; person.code[j-1]!='\r';j++) {
		person.code[j]=getch();
		if ( person.code[j] == 8 && j > 0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && person.code[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	person.code[j-1]='\0';
	
	if(  strlen(person.code) < 6 || strlen(person.code) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_TeacherSubmit( );
	} 
	
	//scanf("%s",person.code);
	fp = fopen ("教师登录.txt","rb");
	if ( fp == NULL ) {
		printf("\t\t\t  没有此用户名，请前往注册！");
		stu_TeacherSign ( );
	//	printf("\n\t\t\t  写文件出错，请按任意键退出！");
	//	getch();
	//	exit(1);
	} 
	while ( fscanf(fp,"%s %s\r\n",per.user,per.code) != 0 ) {
		if( strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) == 0  ){
			printf("\n\t\t\t  登录成功！");
			break;
		} 
		if (strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) != 0) {
			printf("\n\t\t\t  用户名正确，密码错误！");
			printf("\n\t\t\t  请重新输入密码(6-20位，包含6和20)：");
			
			
			for ( j = 0 ; temp[j-1]!='\r';j++) {
				temp[j]=getch();
				if ( temp[j] == 8 && j >0 ) {
					printf("\b \b",j-=2);
				} else if ( j >= 0 && temp[j]!=13) {
					printf("*");
				} else {
					printf(" ");
		}
			}
			printf("\n");
			temp[j-1]='\0';
				
				if(  strlen(temp) < 6 || strlen(temp) > 20 ) {
				printf("\n\t\t\t  请输入在范围内的密码！"); 
				return stu_TeacherSubmit( );
			} 
		//	scanf("%s",temp) ;
			if (strcmp ( per.code,temp) == 0) {
				printf("\n\t\t\t  登录成功！");
			} else {
				printf("\n\t\t\t  登录失败 ，请按任意键退出！");
				getch( ) ;
				exit (0);
			}
			break; 
		} 
		if (strcmp ( per.user,person.user) != 0 ) { 
			printf("\n\t\t\t  此用户未注册！请完成注册！");
			stu_TeacherSign ( );
			break; 
		} 
	}
} 

//将管理员注册信息写入文件 
void stu_ManagerFileSign() {
	fp = fopen ("管理员登录.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  写文件出错，请按任意键退出！");
		getch();
		exit(1);
	} 
	fprintf(fp,"%s %s\r\n",per.user,per.code); 
	printf("\n\t\t\t  你注册的用户名和密码保存成功,请按任意键继续！");
	getch();
	fclose(fp);
} 
//管理员注册 
void stu_ManagerSign ( ) {
	char temp1[30],temp2[30];
	printf("\n\t\t\t  -----------用户注册-----------");
	printf("\n\t\t\t  请输入用户名(5-20位，包含5和20)：") ;
	scanf("%s",per.user);
	if(  strlen(per.user) < 5 || strlen(per.user) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的用户名！"); 
		return stu_ManagerSign();
	} 
	
	printf("\n\t\t\t  请输入密码(6-20位，包含6和20)：");
	int j;
	for ( j = 0 ; per.code[j-1]!='\r';j++) {
		per.code[j]=getch();
		if ( per.code[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && per.code[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	per.code[j-1]='\0';
	
	//scanf("%s",per.code);
	
	if(  strlen(per.code) < 6 || strlen(per.code) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_ManagerSign();
	} 
	
	printf("\n\t\t\t  请确认密码(6-20位，包含6和20)：");

	for ( j = 0 ; temp1[j-1]!='\r';j++) {
		temp1[j]=getch();
		if ( temp1[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && temp1[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	temp1[j-1]='\0';
	
	//scanf("%s",temp1);
	
	if(  strlen(temp1) < 6 || strlen(temp1) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_ManagerSign();
	} 
	if ( strcmp ( per.code , temp1) == 0 ) {
		printf("\n\t\t\t  注册成功！");
		stu_ManagerFileSign( );
		printf("\n\t\t\t  --------------------------------");
		stu_ManagerSubmit( );
	} else {
		printf("\n\t\t\t  请再次确认密码(6-20位，包含6和20)：");
		
		for ( j = 0 ; temp2[j-1]!='\r';j++) {
		temp2[j]=getch();
		if ( temp2[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && temp2[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	temp2[j-1]='\0';
		//scanf("%s",temp2);
		if(  strlen(temp2) < 6 || strlen(temp2) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_ManagerSign();
	} 
		
		if ( strcmp ( per.code , temp2) == 0 ) {
			printf("\n\t\t\t  注册成功！") ;
			stu_ManagerFileSign( );
			printf("\n\t\t\t  --------------------------------");
			stu_ManagerSubmit( );
		} else {
			printf("\n\t\t\t  注册失败！");
			printf("\n\t\t\t  请输入任意键退出！");
			getch();
			exit(0);
		}
	}
} 
//管理员登录 
void stu_ManagerSubmit( ) {
	Users person; 
	char temp[30];
	printf("\n\t\t\t  ----------用户登录-------------");
	printf("\n\t\t\t  请输入用户名(5-20位，包含5和20)：") ;
	scanf("%s",person.user);
	
	if(  strlen(person.user) < 5 || strlen(person.user) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的用户名！"); 
		return stu_ManagerSubmit( );
	} 
	printf("\n\t\t\t  请输入密码(6-20位，包含6和20)：");
		int j;
	for ( j = 0 ; person.code[j-1]!='\r';j++) {
		person.code[j]=getch();
		if ( person.code[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && person.code[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
	}
	printf("\n");
	person.code[j-1]='\0';
	
	if(  strlen(person.code) < 6 || strlen(person.code) > 20 ) {
		printf("\n\t\t\t  请输入在范围内的密码！"); 
		return stu_ManagerSubmit( );
	} 
	//scanf("%s",person.code);
	fp = fopen ("管理员登录.txt","rb");
	if ( fp == NULL ) {
		printf("\t\t\t  没有此用户名，请前往注册！");
		stu_ManagerSign ( );
	/*	printf("\n\t\t\t  写文件出错，请按任意键退出！");
		getch();
		exit(1);*/
	} 
	while ( fscanf(fp,"%s %s\r\n",per.user,per.code) != 0 ) {
		if( strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) == 0  ){
			printf("\n\t\t\t  登录成功！");
			break;
		} 
		if (strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) != 0) {
			printf("\n\t\t\t  用户名正确，密码错误！");
			printf("\n\t\t\t  请重新输入密码(6-20位，包含6和20)：");
			
			for ( j = 0 ; temp[j-1]!='\r';j++) {
			temp[j]=getch();
			if ( temp[j] == 8 && j >0 ) {
			printf("\b \b",j-=2);
		} else if ( j >= 0 && temp[j]!=13) {
			printf("*");
		} else {
			printf(" ");
		}
		}
		printf("\n");
		temp[j-1]='\0';
		
			if(  strlen(temp) < 6 || strlen(temp) > 20 ) {
				printf("\n\t\t\t  请输入在范围内的密码！"); 
				return stu_ManagerSubmit( );
			} 
			//scanf("%s",temp) ;
			if (strcmp ( per.code,temp) == 0) {
				printf("\n\t\t\t  登录成功！");
			} else {
				printf("\n\t\t\t  登录失败 ，请按任意键退出！");
				getch( ) ;
				exit (0);
			}
			break; 
		} 
		if (strcmp ( per.user,person.user) != 0 ) { 
			printf("\n\t\t\t  此用户未注册！请完成注册！");
			stu_ManagerSign ( );
			break; 
		} 
	}
}

//输入信息 
STU *stu_Input () {
	STU *pNew , *pEnd ;
	count = 0 ;
	pEnd = pNew = MALLOC ;
	printf("\t\t\t  请输入学生的信息(当成绩为0时结束输入)：\n");
	printf("\n\t\t\t  请输入的姓名在2-10位汉字,性别(男/女),年龄(0-30),学号(8位),成绩(0-100)");
	printf("\n\t\t\t  请输入姓名，性别，班级，年龄，学号，成绩：");
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  pHead = stu_Input( );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 1 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  pHead = stu_Input( );
	}
	if ( pNew->stuAge  < 0 || pNew->stuAge  > 30 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  pHead = stu_Input( );
	}
	while ( pNew->stuScore != 0 ) {
		count ++ ;
		if ( count == 1 ) {
			pNew->next = pHead;
			pEnd = pNew;
			pHead = pNew;
		} else {
			pNew->next = NULL ;
			pEnd->next = pNew ;
			pEnd = pNew ; 
		}
		pNew = MALLOC ;
	//	printf("\n\t\t\t  请输入姓名，性别，班级，年龄，学号，成绩：\n");
		printf("\t\t\t  ");
		scanf("%s %s %s %d %s %lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
		if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return  pHead = stu_Input( );
		}
		if ( strlen(pNew->stuName) % 2 < 2 || strlen(pNew->stuName) % 2 > 10 || strlen(pNew->stuSex) != 1 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  pHead = stu_Input( );
	}
		if ( pNew->stuAge  < 0 || pNew->stuAge  > 30 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return  pHead = stu_Input( );
		}
	}
	free(pNew);
	return pHead ; 
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录界面选择模式2！\n");
}


//将链表中的信息保存在文件中 
void stu_FileInput() {
	STU *p ;
	p = pHead;
	fp = fopen ("学生信息.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  写文件出错，请按任意键退出！");
		getch();
		exit(1);
	} 
	p = p->next;
	while ( p != NULL ) {
		fprintf(fp,"%s %s %s %d %s %lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		p = p->next;
	} 
	
	fclose(fp);
	printf("\n\t\t\t  文件已成功保存,请按任意键继续");
	getch();
	printf("\n"); 
} 
//将文件中的信息保存在链表中 
void stu_FileRead( ) {
	count = 0 ;
	STU *pNew,*p;
	FILE *fp = NULL;
	fp = fopen("学生信息.txt","rb");
	if ( fp ==  NULL ){
		printf("\n\t\t\t  不存在该文件，请按任意键退出！");
		getch( );
		exit ( 0 );
	}
	pHead = MALLOC ;
	p = pHead ;
	while ( !feof ( fp ) ) {
		count ++ ;
		pNew = MALLOC ;
		fscanf(fp,"%s %s %s %d %s %lf\n",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore) ;
		p->next = pNew;
		p = pNew;
	}

	p->next = NULL;
	fclose(fp);
//	printf("\n\t\t\t  文件中信息已正确读出，请按任意键继续！");
//	getch();
//	printf("\n");
	
} 

//输出信息 
void stu_Output(  ) {
	STU *p;
	p = pHead->next;//pHead 头结点有指针域 有数据域 数据域占据了内存 
	printf("\t\t\t  ----------------------------------本名单中共有%d个学生--------------------------------\n",count); 
	printf("\t\t\t  姓名\t\t\t性别\t\t班级\t\t年龄\t\t学号\t\t成绩\n");
	while ( p != NULL ) {
		printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		p = p->next ; 	
	}
}
 
//姓名查询
void stu_NameFind ( ) {
	STU *p  ;
	p = pHead ;
	char name[30];
	printf("\n\t\t\t  请输入的姓名在2-10位汉字");
	printf("\n\t\t\t  请输入要查询的学生姓名：");
	scanf("%s",name);
	if ( strlen(name) / 2 < 2 || strlen(name) / 2 > 10 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_NameFind ( ) ;
	}
	
	while ( p && strcmp ( p->stuName , name ) != 0 ) {
		p = p->next ;
	}
	if ( p == NULL ) {
		printf("\t\t\t  没有找到此人！\n");
	} else {
		printf("\t\t\t  姓名\t\t\t性别\t\t班级\t\t年龄\t\t学号\t\t成绩\t\t\n");
		printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
	}
} 


//学号查询 


void stu_NumberFind(  ) {
	STU *p = pHead ;
	char num[30];
	printf("\n\t\t\t  请输入的学生学号为8位");
	printf("\n\t\t\t  请输入要查询的学生学号：");
//	getchar();
	scanf("%s",num);
	if( strlen(num) != 8 ) {
		printf("\n\t\t\t  信息输入有误，请重新输入！\n");
		return  stu_NumberFind(  );
	}
	
	while ( p && strcmp ( p->stuNumber , num ) != 0 ) {
		p = p->next ;
	}
	if ( p == NULL ) {
		printf("\t\t\t  没有找到此人！\n");
	} else {
		printf("\t\t\t  姓名\t\t\t性别\t\t班级\t\t年龄\t\t学号\t\t成绩\t\t\n");
		printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
	}
	
}

//班级和性别组合查询 
void stu_ClassSexFind( ) {
	STU *p = pHead->next ;
	char sex[30];
	char clas_s[30];
	printf("\n\t\t\t  请输入的性别为(男/女)");
	printf("\n\t\t\t  请输入要查询的性别和班级：") ;
	scanf("%s",sex);
	scanf("%s",clas_s);
	if( strlen(sex) != 2 ) {
		printf("\n\t\t\t  信息输入有误，请重新输入！\n");
		return  stu_ClassSexFind( );
	}
	printf("\n\t\t\t  姓名\t\t\t性别\t\t班级\t\t年龄\t\t学号\t\t成绩\t\t\n");
	
	if ( p == NULL ) {
		printf("\t\t\t  没有找到此人！"); 
	}
	
	while ( p != NULL  ) {
		if (  strcmp ( p->stuSex , sex ) == 0  && strcmp ( p->stuClass , clas_s ) == 0 ) {
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next ;
	}
} 


//根据学号删除学生信息 
void stu_NumberDelete(  ) {
	char num[30];
	STU *p,*t;//p为要删除的结点，t为删除结点后面的结点
	p = pHead;
	printf("\n\t\t\t  请输入的学生学号为8位");
	printf("\n\t\t\t  请输入你要删除的学生学号：");
	scanf("%s",num);
	if( strlen(num) != 8 ) {
		printf("\n\t\t\t  信息输入有误，请重新输入！");
		return  stu_NumberDelete(  );
	}
	
	if ( pHead && strcmp ( pHead->stuNumber , num ) == 0 ) {
		pHead = pHead->next ;
	} else {
		while ( strcmp ( p->stuNumber , num ) != 0 && p->next != NULL ) {
			t = p ;
			p = p->next ;
		} 
		t->next = p->next ;
		free(p);
		count -- ;
	}
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录成功界面选择模式2！\n");
}

//根据姓名删除学生信息 
void stu_NameDelete(  ) {
	char name[30];
	STU *p,*t;//p为要删除的结点，t为删除结点后面的结点
	p = pHead;
	printf("\n\t\t\t  请输入的学生姓名为2-10位汉字"); 
	printf("\n\t\t\t  请输入你要删除的学生姓名：");

	scanf("%s",name);
	if ( strlen(name) / 2 < 2 || strlen(name) / 2 > 10 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_NameDelete(  );
	}
	if ( pHead && strcmp ( pHead->stuName , name ) == 0 ) {
		pHead = pHead->next ;
	} else {
		while ( strcmp ( p->stuName , name ) != 0 && p->next != NULL ) {
			t = p ;
			p = p->next ;
		} 
		t->next = p->next ;
		free(p);
		count -- ;
	}
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录成功界面选择模式2！\n");
	
}

//头部增加学生信息 

void stu_HeadIncrease (  ) {
	STU *pNew;
	printf("\t\t\t  请输入头插的学生信息：\n");
	pNew = MALLOC ;
	printf("\n\t\t\t  请输入的姓名在2-10位汉字,性别(男/女),年龄(0-30),学号(8位),成绩(0-100)");
	printf("\n\t\t\t  请输入姓名，性别，班级，年龄，学号(8位)，成绩(0-100)：\n");
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_HeadIncrease (  );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 2 ) {
		printf("\n\t\t\t  -------------------\n");
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_HeadIncrease (  );
	}
	if ( pNew->stuAge < 0 || pNew->stuAge  > 30 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_HeadIncrease (  );
	}
	
	pNew->next = pHead->next;
	pHead->next = pNew ;
	count ++ ;
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录成功界面选择模式2！\n");
}
//中间插入学生信息

void stu_MiddleIncrease (  ) {
	STU *p,*pNew;
	p = pHead ;
	char s[30];
	printf("\n\t\t\t  请输入的学生学号为8位");
	printf("\n\t\t\t  请输入你要插入的学生后(根据学号插入)："); 
	scanf("%s",s);
	
	if ( strlen ( s ) != 8 ) {
		printf("\n\t\t\t  输入信息有误，请重新输入！");
		return stu_MiddleIncrease (  );
	}
	
	while ( p->next && strcmp( p->stuNumber,s ) != 0 ) {
		p = p->next ;
	}
	printf("\t\t\t  请输入中间插入的学生信息：");
	pNew = MALLOC ;
	printf("\n\t\t\t  请输入的姓名在2-10位汉字,性别(男/女),年龄(0-30),学号(8位),成绩(0-100)");
	printf("\n\t\t\t  请输入姓名，性别，班级，年龄，学号(8位)，成绩(0-100)：\n");
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
	
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_MiddleIncrease (  );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 2 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_MiddleIncrease (  );
	}
	if ( pNew->stuAge < 0 || pNew->stuAge > 30 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_MiddleIncrease (  );
	}
	
	//stu_InputMessage( pNew ) ;
	pNew->next = p->next ;
	p->next = pNew ;
	count ++ ;
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录成功界面选择模式2！\n");
}

//尾部插入学生信息 

void stu_TailIncrease (  ) {
	STU *p,*pNew;
	p = pHead ;

	while ( p && p->next != NULL ) {
		p = p->next ;
	}
		
	printf("\t\t\t  请输入尾插的学生信息：\n");
	pNew = MALLOC ;
	printf("\n\t\t\t  请输入的姓名在2-10位汉字,性别(男/女),年龄(0-30),学号(8位),成绩(0-100)");
	printf("\n\t\t\t  请输入姓名，性别，班级，年龄，学号(8位)，成绩(0-100)：\n");
	
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
//	stu_InputMessage( pNew ) ;
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_TailIncrease (  );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 2 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_TailIncrease (  );
	}
	if ( pNew->stuAge  < 0 || pNew->stuAge > 30 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_TailIncrease (  );
	}
	p->next = pNew;
	pNew->next = NULL ;
	count ++ ;
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录成功界面选择模式2！\n");
} 

//学号修改函数 

void stu_NumberCorrect (  ) {
	STU *p = pHead ;
	char s[30];
	printf("\n\t\t\t  请输入的学生学号为8位"); 
	printf("\n\t\t\t  请输入你要修改学生学号：");
	
	scanf("%s",s);
	
	if( strlen(s) != 8 ) {
		printf("\n\t\t\t  信息输入有误，请重新输入！");
		return  stu_NumberCorrect (  );
	}
	while ( p && strcmp ( p->stuNumber , s ) ) {
		p = p->next;
	}
	if ( p==NULL ) {
		printf("\t\t\t  没有找到此人！");
	} else {
		printf("\n\t\t\t  请输入的姓名在2-10位汉字,性别(男/女),年龄(0-30),学号(8位),成绩(0-100)");
		printf("\n\t\t\t  请输入姓名，性别，班级，年龄，学号，成绩：\n");
		
		printf("\t\t\t  ");
		scanf("%s%s%s%d%s%lf",p->stuName,p->stuSex,p->stuClass,&p->stuAge,p->stuNumber,&p->stuScore);
		
		if ( p->stuScore > 100 || p->stuScore < 0  || strlen(p->stuNumber) != 8 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return  stu_NumberCorrect (  );
		}
		
		if ( strlen(p->stuName) / 2 < 2 || strlen(p->stuName) / 2 > 10|| strlen(p->stuSex) != 2 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return  stu_NumberCorrect (  );
		}
		if ( p->stuAge  < 0 || p->stuAge  > 30 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return  stu_NumberCorrect (  );
		}
			//stu_InputMessage( p ) ;	
	}	
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录成功界面选择模式2！\n");
}

//姓名修改函数

void  stu_NameCorrect ( ) {
	STU *p = pHead ;
	char name[30];
	printf("\n\t\t\t  请输入的学生姓名为2-10位汉字"); 
	printf("\n\t\t\t  请输入你要修改的学生姓名：");
	
	scanf("%s",name);
	if ( strlen(name) / 2 < 1 || strlen(name) / 2 > 10 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_NameCorrect ( );
	}
	while ( p && strcmp ( p->stuName , name ) ) {
		p = p->next ;
	} 
	if ( p == NULL ) {
		printf ("\t\t\t  没有找到此人！"); 
	} else {
		printf("\n\t\t\t  请输入的姓名在2-10位汉字,性别(男/女),年龄(0-30),学号(8位),成绩(0-100)");
		printf("\n\t\t\t  请输入姓名，性别，班级，年龄，学号，成绩：\n");
		
		printf("\t\t\t  ");
		scanf("%s%s%s%d%s%lf",p->stuName,p->stuSex,p->stuClass,&p->stuAge,p->stuNumber,&p->stuScore);
	
		if ( p->stuScore > 100 || p->stuScore < 0  || strlen(p->stuNumber) != 8 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return stu_NameCorrect (  );
		}
		if ( strlen(name) / 2 < 2 || strlen(name) / 2 > 10 || strlen(p->stuSex) != 2 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return  stu_NameCorrect (  );
		}
		if ( p->stuAge < 0 || p->stuAge > 30 ) {
			printf("\n\t\t\t  输入信息有误请重输入！\n");
			return  stu_NameCorrect (  );
		}
	//	stu_InputMessage( p ) ;	
	}
	printf("\n\t\t\t  如果要将信息保存在文件中，请在登录成功界面选择模式2！\n");
	
}

//成绩统计函数 
void stu_ScoreCount( ) { 
	STU *p = pHead ;
	int sumScore = 0;
	double score1 ,score2 ,t;
	printf("\n\t\t\t  请输入的成绩范围在0-100之间");
	printf("\n\t\t\t  请输入你要输出的成绩范围："); 
	
	scanf("%lf%lf",&score1,&score2);
	if ( score1 > 100 || score1 < 0 || score2 > 100 || score2 < 0 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_ScoreCount( );
	}
	
	if (score1 > score2 ) {
		t = score1;
		score1 = score2;
		score2 = t ;
	} 
	printf("\t\t\t  姓名\t\t\t性别\t\t班级\t\t年龄\t\t学号\t\t成绩\t\t\n");
	while ( p != NULL ) {
		
		if ( p->stuScore >= score1 && p->stuScore <= score2 ) {
			sumScore ++ ;
			
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next ;
	} 
	printf("\t\t\t  成绩在%d和%d之间的共有：%d人\n",score1,score2,sumScore);
}

//按性别统计 
void  stu_SexCount(  ) {
	STU *p = pHead ;
	char sex[30];
	int sumSex = 0 ;
	printf("\n\t\t\t  请输入的性别为(男/女)");
	printf("\n\t\t\t  请输入你要统计的性别(男,女)：");
 	scanf("%s",sex);
 	if ( strlen(sex) != 2 ) {
 		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_SexCount(  );
	}
	while ( p != NULL ) {
		if ( strcmp ( p->stuSex , sex ) == 0 ) {
			sumSex ++ ;
			printf("\t\t\t  姓名\t\t\t性别\t\t班级\t\t年龄\t\t学号\t\t成绩\t\t\n");
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next ;
	}
	printf("\t\t\t  性别为%s的人共有%d个！\n",sex,sumSex);
} 

//班级和年龄综合统计 
void stu_ClassAgeCount( ) {
	STU *p = pHead ;
	char clas_s[30];
	int age ;
	int sumClassAge = 0 ;
	printf("\n\t\t\t  请输入的年龄在(0-30)");
	printf("\n\t\t\t  请输入你要统计的班级和年龄：");
	scanf("%s",clas_s); 
	scanf("%d",&age);
	if ( age < 0 || age > 30 ) {
		printf("\n\t\t\t  输入信息有误请重输入！\n");
		return  stu_ClassAgeCount( );
	}
	printf("\t\t\t  姓名\t\t\t性别\t\t班级\t\t年龄\t\t学号\t\t成绩\t\t\n");
	while ( p != NULL ) {
		if ( strcmp ( p->stuClass , clas_s) == 0 && p->stuAge == age ) {
			sumClassAge ++ ; 
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next; 
	}
}
//排序函数 成绩按升序排序 
void stu_UpSort(  ) {
	STU *pEnd = NULL ;
	STU *p,*pLast,*pNext;
	while ( pEnd != pHead->next ) {
		for ( pLast = pHead , p = pLast->next ; p->next != pEnd ; p = p->next , pLast = pLast->next ) {
			pNext = p->next;
			if ( p->stuScore < pNext->stuScore ) {
				pLast->next = pNext ;
				p->next = pNext->next;
				pNext->next = p ;
				p = pLast->next;
			}
		}
		pEnd = p ;
	}
	
	stu_Output( );
} 


		
//排序函数 成绩按降序排序 
void stu_DownSort(  ) {
	STU *pEnd = NULL ;
	STU *p,*pLast,*pNext;
	while ( pEnd != pHead->next ) {
		for ( pLast = pHead , p = pLast->next ; p->next != pEnd ; p = p->next , pLast = pLast->next ) {
			pNext = p->next;
			if ( p->stuScore > pNext->stuScore ) {
				pLast->next = pNext ;
				p->next = pNext->next;
				pNext->next = p ;
				p = pLast->next;
			}
		}
		pEnd = p ;
	}
	
	stu_Output( );
} 

//排序函数 学号按降序排序 
void stu_NumberDownSort(  ) {
	STU *pEnd = NULL ;
	STU *p,*pLast,*pNext;
	while ( pEnd != pHead->next ) {
		for ( pLast = pHead , p = pLast->next ; p->next != pEnd ; p = p->next , pLast = pLast->next ) {
			pNext = p->next;
			if ( strcmp ( p->stuNumber , pNext->stuNumber ) < 0   ) {
				pLast->next = pNext ;
				p->next = pNext->next;
				pNext->next = p ;
				p = pLast->next;
			}
			
		}
			pEnd = p ;
	}
	stu_Output( );
	//return pHead;
} 

//排序函数 学号升序排序 
void stu_NumberUpSort(  ) {
	STU *pEnd = NULL ;
	STU *p,*pLast,*pNext;
	while ( pEnd != pHead->next ) {
		for ( pLast = pHead , p = pLast->next ; p->next != pEnd ; p = p->next , pLast = pLast->next ) {
			pNext = p->next;
			if ( strcmp ( p->stuNumber , pNext->stuNumber ) > 0   ) {
				pLast->next = pNext ;
				p->next = pNext->next;
				pNext->next = p ;
				p = pLast->next;
			}
			
		}
			pEnd = p ;
	}
	stu_Output( );
	//return pHead;
} 


//查询端

void find_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Find ( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-4)：");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_NumberFind ( ) ; break;
			case '2' : stu_NameFind( ) ; break ; 
			case '3' : stu_ClassSexFind( ) ;break ;
 			case '4' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//修改端

void correct_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Correct ( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-3)：");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_NumberCorrect ( ) ; break;
			case '2' : stu_NameCorrect ( ) ; break ;
 			case '3' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//插入端

void increase_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Increase ( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-4)：");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_HeadIncrease ( ) ; break;
			case '2' : stu_MiddleIncrease ( ) ; break ;
			case '3' : stu_TailIncrease ( ) ; break ;
 			case '4' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//删除端

void delete_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Delete ( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-3)：");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_NumberDelete ( ) ; break;
			case '2' : stu_NameDelete ( ) ; break ;
 			case '3' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//统计端 
void count_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Count ( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-4)：");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_ScoreCount ( ) ; break;
			case '2' : stu_SexCount ( ) ; break ;
			case '3' : stu_ClassAgeCount( ) ;break ;
 			case '4' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//排序端

void sort_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Sort ( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-5)：");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_UpSort( ); break;
			case '2' : stu_DownSort( ); break ; 
			case '3' : stu_NumberUpSort( ); break;
			case '4' : stu_NumberDownSort( ); break ;
 			case '5' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//学生注册登录端 
void submit_StuBook() {
	char flag ;
	system("cls");
	show_StuSubmit(); 
	printf("\n\t\t\t  请选择模式(0-3)：");
	fflush(stdin);
	scanf("%c",&flag);
	switch( flag ) {
		case '1' : stu_StuSubmit( ) ; break;
		case '2' : stu_StuSign ( ) ; break;
 		case '3' : remark() ; break; 
		case '0' : exit(0) ; break;
		default : printf("\t\t\t  输入有误请重新输入\n") ; break;
	}
	printf("\n\t\t\t  按任意键进行下一步操作");
	getch( );  	
}

//教师注册登录端 
void submit_TeacherBook() {
	char flag ;
	system("cls");
	show_TeacherSubmit(); 
	printf("\n\t\t\t  请选择模式(0-3)：");
	fflush(stdin);
	scanf("%c",&flag);
	switch( flag ) {
		case '1' : stu_TeacherSubmit( ) ; break;
		case '2' : stu_TeacherSign ( ) ; break;
 		case '3' : remark() ; break; 
		case '0' : exit(0) ; break;
		default : printf("\t\t\t  输入有误请重新输入\n") ; break;
	}
	printf("\n\t\t\t  按任意键进行下一步操作");
	getch( ); 
}

//管理员注册登录端 
void submit_ManagerBook() {
	char flag ;
	system("cls");
	show_ManagerSubmit();
	printf("\n\t\t\t  请选择模式(0-3)：");
	fflush(stdin);
	scanf("%c",&flag);
	switch( flag ) {
		case '1' : stu_ManagerSubmit( ) ; break;
		case '2' : stu_ManagerSign ( ) ; break;
 		case '3' : remark() ; break; 
		case '0' : exit(0) ; break;
		default : printf("\t\t\t  输入有误请重新输入\n") ; break;
	}
	printf("\n\t\t\t  按任意键进行下一步操作");
	getch( ); 
}

//学生端 
void student_Book ( ) {
	char flag ;
	submit_StuBook ( );
	while ( 1 ) {
		system ( "cls" );
		show_Student ( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-2)：");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : find_Book ( ) ; break;
 			case '2' : submit_StuBook() ; break; 
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//教师端 
void teacher_Book ( ) {
	char flag ;
	submit_TeacherBook ( ); 
	while ( 1 ) {
		system("cls");
		show_Teacher( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-a)："); 
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : pHead = stu_Input ( ) ; break ;
			case '2' : stu_FileInput ( ) ; break ;  
			case '3' : stu_Output( ) ;break ;
			case '4' : correct_Book ( ) ; break ;
			case '5' : increase_Book( ) ; break ;
			case '6' : delete_Book ( ) ; break;
			case '7' : find_Book ( ) ; break ;
			case '8' : count_Book ( ) ;break;
			case '9' : sort_Book( ) ; break;
			case 'a' : submit_TeacherBook() ; break;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

//管理员端 
void manager_Book ( ) {
	char flag ;
	submit_ManagerBook( );
	while ( 1 ) {
		system( " cls " );
		show_Manager( ) ;
		printf("\n\t\t\t  请输入选择的模式(0-a)："); 
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : pHead = stu_Input ( ) ; break ;
			case '2' : stu_FileInput ( ) ; break ;  
			case '3' : stu_Output( ) ; break ;
			case '4' : correct_Book ( ) ; break ;
			case '5' : increase_Book ( ) ; break ;
			case '6' : delete_Book ( ) ; break;
			case '7' : find_Book ( ) ; break ;
			case '8' : count_Book ( ) ;break;
			case '9' : sort_Book( ) ; break;
			case 'a' : submit_ManagerBook() ; break ; 
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  输入有误请重新输入\n") ; break;
		}
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
	}
} 

void remark () {
	system("color 0A");
	stu_FileRead( );
	char flag ;
	while ( 1 ) {
		system ( "cls" );	
		show ( ); 
		printf("\n\t\t\t  请输入选择的模式(0-3)："); 
		fflush(stdin);
		scanf("%c",&flag);
		switch( flag ) {
		case '1' : student_Book ( ) ; break ;
		case '2' : teacher_Book ( ) ; break ;
		case '3' : manager_Book ( ) ; break ;
		case '0' : exit(0) ; break;
		default : printf("\n\t\t\t  输入有误请重新输入") ; break;
	}
	} 
	printf("\t\t\t  按任意键进行下一步操作");
	getch( ); 
}

int main ( ) {
	remark ( ) ;
} 

