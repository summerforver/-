#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define MALLOC (STU *)malloc(sizeof( STU ))

//ѧ����Ϣ 
typedef struct student {
	
	char stuName[30];//ѧ������ 
	char stuSex[30];//ѧ���Ա� 
	char stuClass[30];//ѧ���༶
	int  stuAge ; //ѧ������ 
	char stuNumber[30] ;//ѧ��ѧ��
	double stuScore;//ѧ���ɼ�  
	struct student *next ;//ָ�򱾽ṹ���ָ�� 
	 
}STU;

//�˻���¼��Ϣ 
typedef struct scert {
	char user[20]; //�û��� 
	char code[20];//���� 
}Users;


Users per;
int count;
STU *pHead = NULL;
FILE *fp;


void show( ) ;//��ҳ��ѧ����ʦ����Աѡ��
void show_Student( ) ;//ѧ����¼����
void show_Teacher( ) ;//��ʦ��¼����
void show_Manager( ) ;//����Ա��¼���� 
void show_Find( ) ;//���ҽ���
void show_Count( ) ;//ͳ�ƽ���
void show_Sort( ) ;//������� 
void stu_InputMessage( ) ;//�ֶ�����ѧ����Ϣ 
STU *stu_Input( ) ;//����������ѧ����Ϣ 
void stu_FileInput( ) ;//��ѧ����Ϣ�������ļ���
void stu_Output( ) ;//���ѧ����Ϣ
void stu_NameFind( ) ;//��������������Ϣ
void stu_NumberFind( ) ;//����ѧ�Ų�����Ϣ
void stu_ClassSexFind( ) ;//���ݰ༶���Ա���ϲ�ѯ
void stu_Delete( ) ;//����ѧ��ɾ��
void stu_Increase( ) ;//����ѧ����Ϣ
void stu_NumberCorrect( ) ;//����ѧ���޸�ѧ����Ϣ
void stu_NameCorrect( ) ;//���������޸�ѧ����Ϣ
void stu_ScoreCount( ) ;//���ݳɼ�ͳ��ѧ����Ϣ
void stu_SexCount( ) ;//�����Ա�ͳ��ѧ����Ϣ
void stu_ClassAgeCount( ) ;//���ݰ༶�������ۺ�ͳ��
void stu_UpSort( ) ;//���ɼ�����
void stu_DownSort( ) ;//���ɼ����� 
void find_Book( ) ;//��ѯ��
void count_Book( ) ;//ͳ�ƶ�
void sort_Book( ) ;//����� 
void student_Book( ) ;//ѧ����
void teacher_Book( ) ;//��ʦ�� 
void manager_Book( ) ;//����Ա��
void remark( ) ;//���˵� 


void stu_TeacherSign ( );//��ʦע�� 
void stu_StuSubmit( ) ; //ѧ����¼ 
void stu_TeacherSubmit( );//��ʦ��¼ 
void stu_ManagerSubmit( );// ����Ա��¼ 


//������ 
void show() {
	printf("\n\n\t\t\t  =====================================================================\n");
	printf("\t\t\t  ---------------------------ѧ������ϵͳ------------------------------\n");
	printf("\t\t\t  -                        -1-     ѧ����¼                           -\n");
	printf("\t\t\t  -                        -2-     ��ʦ��¼                           -\n");
	printf("\t\t\t  -                        -3-     ����Ա��¼                         -\n");
	printf("\t\t\t  -                        -0-     �˳�                               -\n");
	printf("\t\t\t  ---------------------------ѧ������ϵͳ------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
}

//ѧ����¼ҳ�� 
show_StuSubmit( ) {
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t  |                    ��ӭ����ѧ������ϵͳ��                     |\n"); 
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t               ---1.��¼---                  ---2.ע��---\n "); 
	printf("\t\t\t               ---3.������һ��---            ---0.�˳�---\n "); 
}

//��ʦ��¼ҳ�� 
show_TeacherSubmit( ) {
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t  |                    ��ӭ����ѧ������ϵͳ��                     |\n"); 
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t               ---1.��¼---                  ---2.ע��---\n "); 
	printf("\t\t\t               ---3.������һ��---            ---0.�˳�---\n "); 
}

//����Ա��¼ҳ�� 
show_ManagerSubmit( ) {
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t  |                    ��ӭ����ѧ������ϵͳ��                     |\n"); 
	printf("\t\t\t  -----------------------------------------------------------------\n");
	printf("\t\t\t               ---1.��¼---                  ---2.ע��---\n "); 
	printf("\t\t\t               ---3.������һ��---            ---0.�˳�---\n "); 
}

//ѧ����¼���� 
void show_Student () {
	printf("\n\n\t\t\t  ---------------------------��ϲ���½�ɹ���--------------------------\n");
	printf("\t\t\t  =====================================================================\n");
	printf("\t\t\t  -----------------------------ѧ����¼--------------------------------\n");
	printf("\t\t\t  -                        -1-     ��ѯѧ����Ϣ                       -\n");
	printf("\t\t\t  -                        -2-     ������һ��                         -\n");
	printf("\t\t\t  -                        -0-     �˳�                               -\n");
	printf("\t\t\t  -----------------------------ѧ����¼--------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
}

//��ʦ��¼����
void show_Teacher () {
	printf("\n\n\t\t\t  ---------------------------��ϲ���½�ɹ���----------------------------\n");
	printf("\t\t\t  =====================================================================\n");
	printf("\t\t\t  -----------------------------��ʦ��¼--------------------------------\n");
	printf("\t\t\t  -                       -1-     ����ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -2-     ��ѧ����Ϣ�������ļ���              -\n");
	printf("\t\t\t  -                       -3-     ���ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -4-     �޸�ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -5-     ����ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -6-     ɾ��ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -7-     ��ѯѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -8-     ѧ����Ϣͳ��                        -\n");
	printf("\t\t\t  -                       -9-     ��ѧ����Ϣ����                      -\n");
	printf("\t\t\t  -                       -a-     ������һ��                          -\n");
	printf("\t\t\t  -                       -0-     �˳�                                -\n");
	printf("\t\t\t  -----------------------------��ʦ��¼--------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
} 

// ����Ա��Ա��¼���� 
void show_Manager() {
	printf("\n\n\t\t\t  ---------------------------��ϲ���½�ɹ���--------------------------\n");
	printf("\t\t\t  =====================================================================\n");
	printf("\t\t\t  ---------------------------����Ա��¼--------------------------------\n");
	printf("\t\t\t  -                       -1-     ����ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -2-     ��ѧ����Ϣ�������ļ���              -\n");
	printf("\t\t\t  -                       -3-     ���ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -4-     �޸�ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -5-     ����ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -6-     ɾ��ѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -7-     ��ѯѧ����Ϣ                        -\n");
	printf("\t\t\t  -                       -8-     ѧ����Ϣͳ��                        -\n");
	printf("\t\t\t  -                       -9-     ��ѧ����Ϣ����                      -\n");
	printf("\t\t\t  -                       -a-     ������һ��                          -\n");
	printf("\t\t\t  -                       -0-     �˳�                                -\n");
	printf("\t\t\t  ---------------------------����Ա��¼--------------------------------\n");
	printf("\t\t\t  =====================================================================\n");
}

//���ҽ��� 
void show_Find ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------��Ϣ��ѯ----------------------------------\n");
	printf("\t\t\t  -                          -1-     ѧ�Ų�ѯ                             -\n");
	printf("\t\t\t  -                          -2-     ������ѯ                             -\n");
	printf("\t\t\t  -                          -3-     �Ա�Ͱ༶��ѯ                       -\n");
	printf("\t\t\t  -                          -4-     ������һ��                           -\n");
	printf("\t\t\t  -                          -0-     �˳�                                 -\n");
	printf("\t\t\t  -------------------------------��Ϣ��ѯ----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//ͳ�ƽ��� 
void show_Count ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------��Ϣͳ��----------------------------------\n");
	printf("\t\t\t  -                          -1-     �ɼ�ͳ��                             -\n");
	printf("\t\t\t  -                          -2-     �Ա�ͳ��                             -\n");
	printf("\t\t\t  -                          -3-     �༶������ͳ��                       -\n");
	printf("\t\t\t  -                          -4-     ������һ��                           -\n");
	printf("\t\t\t  -                          -0-     �˳�                                 -\n");
	printf("\t\t\t  -------------------------------��Ϣͳ��----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//�޸Ľ��� 
void show_Correct ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------��Ϣ�޸�----------------------------------\n");
	printf("\t\t\t  -                          -1-     ѧ���޸�                             -\n");
	printf("\t\t\t  -                          -2-     �����޸�                             -\n");
	printf("\t\t\t  -                          -3-     ������һ��                           -\n");
	printf("\t\t\t  -                          -0-     �˳�                                 -\n");
	printf("\t\t\t  -------------------------------��Ϣ�޸�----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}
//���ӽ��� 
void show_Increase ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------��Ϣ����----------------------------------\n");
	printf("\t\t\t  -                          -1-     ��ͷ������                           -\n");
	printf("\t\t\t  -                          -2-     ���м�����                           -\n");
	printf("\t\t\t  -                          -3-     ��β������                           -\n");
	printf("\t\t\t  -                          -4-     ������һ��                           -\n");
	printf("\t\t\t  -                          -0-     �˳�                                 -\n");
	printf("\t\t\t  -------------------------------��Ϣ����----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//ɾ������ 
void show_Delete ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------��Ϣɾ��----------------------------------\n");
	printf("\t\t\t  -                          -1-     ѧ��ɾ��                             -\n");
	printf("\t\t\t  -                          -2-     ��������                             -\n");
	printf("\t\t\t  -                          -3-     ������һ��                           -\n");
	printf("\t\t\t  -                          -0-     �˳�                                 -\n");
	printf("\t\t\t  -------------------------------��Ϣɾ��----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
}

//�������
void show_Sort ( ) {
	printf("\n\n\t\t\t  =========================================================================\n");
	printf("\t\t\t  -------------------------------��Ϣ����----------------------------------\n");
	printf("\t\t\t  -                          -1-     ���ɼ�����                           -\n");
	printf("\t\t\t  -                          -2-     ���ɼ�����                           -\n");
	printf("\t\t\t  -                          -3-     ��ѧ������                           -\n");
	printf("\t\t\t  -                          -4-     ��ѧ�Ž���                           -\n");
	printf("\t\t\t  -                          -5-     ������һ��                           -\n");
	printf("\t\t\t  -                          -0-     �˳�                                 -\n");
	printf("\t\t\t  -------------------------------��Ϣ����----------------------------------\n");
	printf("\t\t\t  =========================================================================\n");
} 


//��ѧ��ע����Ϣд���ļ� 
void stu_StuFileSign() {
	fp = fopen ("ѧ����¼.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  д�ļ������밴������˳���");
		getch();
		exit(1);
	} 
	fprintf(fp,"%s %s\r\n",per.user,per.code); 
	printf("\n\t\t\t  ��ע����û��������뱣��ɹ�,�밴�����������");
	getch();
	fclose(fp);
} 



//ѧ��ע�� 
void stu_StuSign ( ) {
	char temp1[30],temp2[30];
	printf("\n\t\t\t  -----------�û�ע��-----------");
	printf("\n\t\t\t  �������û���(5-20λ������5��20)��") ;
	scanf("%s",per.user);
	
	if(  strlen(per.user) < 5 || strlen(per.user) > 20 ) {
		printf("\n\t\t\t  �������ڷ�Χ�ڵ��û�����"); 
		return stu_StuSign();
	} 
	
	printf("\n\t\t\t  ����������(6-20λ������6��20)��");
	
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_StuSign();
	} 
	
	printf("\n\t\t\t  ��ȷ������(6-20λ������6��20)��");
	
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_StuSign();
	} 
	
	if ( strcmp ( per.code , temp1) == 0 ) {
		printf("\n\t\t\t  ע��ɹ���");
		stu_StuFileSign( );
		printf("\n\t\t\t  --------------------------------");
		stu_StuSubmit( );
	} else {
		printf("\n\t\t\t  ���ٴ�ȷ������(6-20λ������6��20)��");
		
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_StuSign();
	} 
	
		
		if ( strcmp ( per.code , temp2) == 0 ) {
			printf("\n\t\t\t  ע��ɹ���") ;
			stu_StuFileSign( );
			printf("\n\t\t\t  --------------------------------");
			stu_StuSubmit( );
			
		} else {
			printf("\n\t\t\t  ע��ʧ�ܣ�");
			printf("\n\t\t\t  ������������˳���");
			getch();
			exit(0);
		}
	}
} 

//ѧ����¼ 
void stu_StuSubmit( ) {
	Users person; 
	char temp[30];
	printf("\n\t\t\t  ----------�û���¼-------------");
	printf("\n\t\t\t  �������û���(5-20λ������5��20)��") ;
	scanf("%s",person.user);
	
	if(  strlen(person.user) < 5 || strlen(person.user) > 20 ) {
		printf("\n\t\t\t  �������ڷ�Χ�ڵ��û�����"); 
		return stu_StuSubmit( );
	} 
	
	printf("\n\t\t\t  ����������(6-20λ������6��20)��");
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_StuSubmit( );
	} 
	
	//scanf("%s",person.code);
	fp = fopen ("ѧ����¼.txt","rb");
	if ( fp == NULL ) {
		printf("\t\t\t  û�д��û�������ǰ��ע�ᣡ");
		stu_StuSign ( );
		/*printf("\n\t\t\t  д�ļ������밴������˳���");
		getch();
		exit(1);*/
	} 
	while ( fscanf(fp,"%s %s\r\n",per.user,per.code) != 0 ) {
		if( strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) == 0  ){
			printf("\n\t\t\t  ��¼�ɹ���");
			break;
		} 
		if (strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) != 0) {
			printf("\n\t\t\t  �û�����ȷ���������");
			printf("\n\t\t\t  ��������������(6-20λ������6��20)��");
			
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
				printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
				return stu_StuSubmit( );
			} 
			//scanf("%s",temp) ;
			if (strcmp ( per.code,temp) == 0) {
				printf("\n\t\t\t  ��¼�ɹ���");
			} else {
				printf("\n\t\t\t  ��¼ʧ�� ���밴������˳���");
				getch( ) ;
				exit (0);
			}
			break; 
		} 
		if (strcmp ( per.user,person.user) != 0 ) { 
			printf("\n\t\t\t  ���û�δע�ᣡ�����ע�ᣡ");
			stu_StuSign ( );
			break; 
		} 
	}
} 

//����ʦע����Ϣд���ļ� 
void stu_TeacherFileSign() {
	fp = fopen ("��ʦ��¼.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  д�ļ������밴������˳���");
		getch();
		exit(1);
	
	} 
	fprintf(fp,"%s %s\r\n",per.user,per.code); 
	printf("\n\t\t\t  ��ע����û��������뱣��ɹ�,�밴�����������");
	getch();
	fclose(fp);
} 
//��ʦע�� 
void stu_TeacherSign ( ) {
	char temp1[30],temp2[30];
	printf("\n\t\t\t  -----------�û�ע��-----------");
	printf("\n\t\t\t  �������û���(5-20λ������5��20)��") ;
	
	scanf("%s",per.user);
	if(  strlen(per.user) < 5 || strlen(per.user) > 20 ) {
		printf("\n\t\t\t  �������ڷ�Χ�ڵ��û�����"); 
		return stu_TeacherSign();
	} 
	
	printf("\n\t\t\t  ����������(6-20λ������6��20)��");
	
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_TeacherSign();
	} 
	
	printf("\n\t\t\t  ��ȷ������(6-20λ������6��20)��");

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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_TeacherSign();
	} 
	if ( strcmp ( per.code , temp1) == 0 ) {
		printf("\n\t\t\t  ע��ɹ���");
		stu_TeacherFileSign( );
		printf("\n\t\t\t  --------------------------------");
		stu_TeacherSubmit( );
	} else {
		printf("\n\t\t\t  ����������ٴ�ȷ�����룺");
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
				printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
				return stu_StuSign();
			} 
		if ( strcmp ( per.code , temp2) == 0 ) {
			printf("\n\t\t\t  ע��ɹ���") ;
			stu_TeacherFileSign( );
			printf("\n\t\t\t  --------------------------------");
			stu_TeacherSubmit( );
			
		} else {
			printf("\n\t\t\t  ע��ʧ�ܣ�");
			printf("\n\t\t\t  ������������˳���");
			getch();
			exit(0);
		}
	}
	
} 
//��ʦ��¼ 
void stu_TeacherSubmit( ) {
	Users person; 
	char temp[30];
	printf("\n\t\t\t  ----------�û���¼-------------");
	printf("\n\t\t\t  �������û���(5-20λ������5��20)��") ; 
	scanf("%s",person.user);
	
	if(  strlen(person.user) < 5 || strlen(person.user) > 20 ) {
		printf("\n\t\t\t  �������ڷ�Χ�ڵ��û�����"); 
		return stu_TeacherSubmit( );
	} 
	
	printf("\n\t\t\t  ����������(6-20λ������6��20)��");
	
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_TeacherSubmit( );
	} 
	
	//scanf("%s",person.code);
	fp = fopen ("��ʦ��¼.txt","rb");
	if ( fp == NULL ) {
		printf("\t\t\t  û�д��û�������ǰ��ע�ᣡ");
		stu_TeacherSign ( );
	//	printf("\n\t\t\t  д�ļ������밴������˳���");
	//	getch();
	//	exit(1);
	} 
	while ( fscanf(fp,"%s %s\r\n",per.user,per.code) != 0 ) {
		if( strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) == 0  ){
			printf("\n\t\t\t  ��¼�ɹ���");
			break;
		} 
		if (strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) != 0) {
			printf("\n\t\t\t  �û�����ȷ���������");
			printf("\n\t\t\t  ��������������(6-20λ������6��20)��");
			
			
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
				printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
				return stu_TeacherSubmit( );
			} 
		//	scanf("%s",temp) ;
			if (strcmp ( per.code,temp) == 0) {
				printf("\n\t\t\t  ��¼�ɹ���");
			} else {
				printf("\n\t\t\t  ��¼ʧ�� ���밴������˳���");
				getch( ) ;
				exit (0);
			}
			break; 
		} 
		if (strcmp ( per.user,person.user) != 0 ) { 
			printf("\n\t\t\t  ���û�δע�ᣡ�����ע�ᣡ");
			stu_TeacherSign ( );
			break; 
		} 
	}
} 

//������Աע����Ϣд���ļ� 
void stu_ManagerFileSign() {
	fp = fopen ("����Ա��¼.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  д�ļ������밴������˳���");
		getch();
		exit(1);
	} 
	fprintf(fp,"%s %s\r\n",per.user,per.code); 
	printf("\n\t\t\t  ��ע����û��������뱣��ɹ�,�밴�����������");
	getch();
	fclose(fp);
} 
//����Աע�� 
void stu_ManagerSign ( ) {
	char temp1[30],temp2[30];
	printf("\n\t\t\t  -----------�û�ע��-----------");
	printf("\n\t\t\t  �������û���(5-20λ������5��20)��") ;
	scanf("%s",per.user);
	if(  strlen(per.user) < 5 || strlen(per.user) > 20 ) {
		printf("\n\t\t\t  �������ڷ�Χ�ڵ��û�����"); 
		return stu_ManagerSign();
	} 
	
	printf("\n\t\t\t  ����������(6-20λ������6��20)��");
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_ManagerSign();
	} 
	
	printf("\n\t\t\t  ��ȷ������(6-20λ������6��20)��");

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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_ManagerSign();
	} 
	if ( strcmp ( per.code , temp1) == 0 ) {
		printf("\n\t\t\t  ע��ɹ���");
		stu_ManagerFileSign( );
		printf("\n\t\t\t  --------------------------------");
		stu_ManagerSubmit( );
	} else {
		printf("\n\t\t\t  ���ٴ�ȷ������(6-20λ������6��20)��");
		
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_ManagerSign();
	} 
		
		if ( strcmp ( per.code , temp2) == 0 ) {
			printf("\n\t\t\t  ע��ɹ���") ;
			stu_ManagerFileSign( );
			printf("\n\t\t\t  --------------------------------");
			stu_ManagerSubmit( );
		} else {
			printf("\n\t\t\t  ע��ʧ�ܣ�");
			printf("\n\t\t\t  ������������˳���");
			getch();
			exit(0);
		}
	}
} 
//����Ա��¼ 
void stu_ManagerSubmit( ) {
	Users person; 
	char temp[30];
	printf("\n\t\t\t  ----------�û���¼-------------");
	printf("\n\t\t\t  �������û���(5-20λ������5��20)��") ;
	scanf("%s",person.user);
	
	if(  strlen(person.user) < 5 || strlen(person.user) > 20 ) {
		printf("\n\t\t\t  �������ڷ�Χ�ڵ��û�����"); 
		return stu_ManagerSubmit( );
	} 
	printf("\n\t\t\t  ����������(6-20λ������6��20)��");
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
		printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
		return stu_ManagerSubmit( );
	} 
	//scanf("%s",person.code);
	fp = fopen ("����Ա��¼.txt","rb");
	if ( fp == NULL ) {
		printf("\t\t\t  û�д��û�������ǰ��ע�ᣡ");
		stu_ManagerSign ( );
	/*	printf("\n\t\t\t  д�ļ������밴������˳���");
		getch();
		exit(1);*/
	} 
	while ( fscanf(fp,"%s %s\r\n",per.user,per.code) != 0 ) {
		if( strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) == 0  ){
			printf("\n\t\t\t  ��¼�ɹ���");
			break;
		} 
		if (strcmp ( per.user,person.user) == 0 && strcmp ( per.code,person.code) != 0) {
			printf("\n\t\t\t  �û�����ȷ���������");
			printf("\n\t\t\t  ��������������(6-20λ������6��20)��");
			
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
				printf("\n\t\t\t  �������ڷ�Χ�ڵ����룡"); 
				return stu_ManagerSubmit( );
			} 
			//scanf("%s",temp) ;
			if (strcmp ( per.code,temp) == 0) {
				printf("\n\t\t\t  ��¼�ɹ���");
			} else {
				printf("\n\t\t\t  ��¼ʧ�� ���밴������˳���");
				getch( ) ;
				exit (0);
			}
			break; 
		} 
		if (strcmp ( per.user,person.user) != 0 ) { 
			printf("\n\t\t\t  ���û�δע�ᣡ�����ע�ᣡ");
			stu_ManagerSign ( );
			break; 
		} 
	}
}

//������Ϣ 
STU *stu_Input () {
	STU *pNew , *pEnd ;
	count = 0 ;
	pEnd = pNew = MALLOC ;
	printf("\t\t\t  ������ѧ������Ϣ(���ɼ�Ϊ0ʱ��������)��\n");
	printf("\n\t\t\t  �������������2-10λ����,�Ա�(��/Ů),����(0-30),ѧ��(8λ),�ɼ�(0-100)");
	printf("\n\t\t\t  �������������Ա𣬰༶�����䣬ѧ�ţ��ɼ���");
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  pHead = stu_Input( );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 1 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  pHead = stu_Input( );
	}
	if ( pNew->stuAge  < 0 || pNew->stuAge  > 30 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
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
	//	printf("\n\t\t\t  �������������Ա𣬰༶�����䣬ѧ�ţ��ɼ���\n");
		printf("\t\t\t  ");
		scanf("%s %s %s %d %s %lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
		if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return  pHead = stu_Input( );
		}
		if ( strlen(pNew->stuName) % 2 < 2 || strlen(pNew->stuName) % 2 > 10 || strlen(pNew->stuSex) != 1 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  pHead = stu_Input( );
	}
		if ( pNew->stuAge  < 0 || pNew->stuAge  > 30 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return  pHead = stu_Input( );
		}
	}
	free(pNew);
	return pHead ; 
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼����ѡ��ģʽ2��\n");
}


//�������е���Ϣ�������ļ��� 
void stu_FileInput() {
	STU *p ;
	p = pHead;
	fp = fopen ("ѧ����Ϣ.txt","wb");
	if ( fp == NULL ) {
		printf("\n\t\t\t  д�ļ������밴������˳���");
		getch();
		exit(1);
	} 
	p = p->next;
	while ( p != NULL ) {
		fprintf(fp,"%s %s %s %d %s %lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		p = p->next;
	} 
	
	fclose(fp);
	printf("\n\t\t\t  �ļ��ѳɹ�����,�밴���������");
	getch();
	printf("\n"); 
} 
//���ļ��е���Ϣ������������ 
void stu_FileRead( ) {
	count = 0 ;
	STU *pNew,*p;
	FILE *fp = NULL;
	fp = fopen("ѧ����Ϣ.txt","rb");
	if ( fp ==  NULL ){
		printf("\n\t\t\t  �����ڸ��ļ����밴������˳���");
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
//	printf("\n\t\t\t  �ļ�����Ϣ����ȷ�������밴�����������");
//	getch();
//	printf("\n");
	
} 

//�����Ϣ 
void stu_Output(  ) {
	STU *p;
	p = pHead->next;//pHead ͷ�����ָ���� �������� ������ռ�����ڴ� 
	printf("\t\t\t  ----------------------------------�������й���%d��ѧ��--------------------------------\n",count); 
	printf("\t\t\t  ����\t\t\t�Ա�\t\t�༶\t\t����\t\tѧ��\t\t�ɼ�\n");
	while ( p != NULL ) {
		printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		p = p->next ; 	
	}
}
 
//������ѯ
void stu_NameFind ( ) {
	STU *p  ;
	p = pHead ;
	char name[30];
	printf("\n\t\t\t  �������������2-10λ����");
	printf("\n\t\t\t  ������Ҫ��ѯ��ѧ��������");
	scanf("%s",name);
	if ( strlen(name) / 2 < 2 || strlen(name) / 2 > 10 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_NameFind ( ) ;
	}
	
	while ( p && strcmp ( p->stuName , name ) != 0 ) {
		p = p->next ;
	}
	if ( p == NULL ) {
		printf("\t\t\t  û���ҵ����ˣ�\n");
	} else {
		printf("\t\t\t  ����\t\t\t�Ա�\t\t�༶\t\t����\t\tѧ��\t\t�ɼ�\t\t\n");
		printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
	}
} 


//ѧ�Ų�ѯ 


void stu_NumberFind(  ) {
	STU *p = pHead ;
	char num[30];
	printf("\n\t\t\t  �������ѧ��ѧ��Ϊ8λ");
	printf("\n\t\t\t  ������Ҫ��ѯ��ѧ��ѧ�ţ�");
//	getchar();
	scanf("%s",num);
	if( strlen(num) != 8 ) {
		printf("\n\t\t\t  ��Ϣ�����������������룡\n");
		return  stu_NumberFind(  );
	}
	
	while ( p && strcmp ( p->stuNumber , num ) != 0 ) {
		p = p->next ;
	}
	if ( p == NULL ) {
		printf("\t\t\t  û���ҵ����ˣ�\n");
	} else {
		printf("\t\t\t  ����\t\t\t�Ա�\t\t�༶\t\t����\t\tѧ��\t\t�ɼ�\t\t\n");
		printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
	}
	
}

//�༶���Ա���ϲ�ѯ 
void stu_ClassSexFind( ) {
	STU *p = pHead->next ;
	char sex[30];
	char clas_s[30];
	printf("\n\t\t\t  ��������Ա�Ϊ(��/Ů)");
	printf("\n\t\t\t  ������Ҫ��ѯ���Ա�Ͱ༶��") ;
	scanf("%s",sex);
	scanf("%s",clas_s);
	if( strlen(sex) != 2 ) {
		printf("\n\t\t\t  ��Ϣ�����������������룡\n");
		return  stu_ClassSexFind( );
	}
	printf("\n\t\t\t  ����\t\t\t�Ա�\t\t�༶\t\t����\t\tѧ��\t\t�ɼ�\t\t\n");
	
	if ( p == NULL ) {
		printf("\t\t\t  û���ҵ����ˣ�"); 
	}
	
	while ( p != NULL  ) {
		if (  strcmp ( p->stuSex , sex ) == 0  && strcmp ( p->stuClass , clas_s ) == 0 ) {
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next ;
	}
} 


//����ѧ��ɾ��ѧ����Ϣ 
void stu_NumberDelete(  ) {
	char num[30];
	STU *p,*t;//pΪҪɾ���Ľ�㣬tΪɾ��������Ľ��
	p = pHead;
	printf("\n\t\t\t  �������ѧ��ѧ��Ϊ8λ");
	printf("\n\t\t\t  ��������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%s",num);
	if( strlen(num) != 8 ) {
		printf("\n\t\t\t  ��Ϣ�����������������룡");
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
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼�ɹ�����ѡ��ģʽ2��\n");
}

//��������ɾ��ѧ����Ϣ 
void stu_NameDelete(  ) {
	char name[30];
	STU *p,*t;//pΪҪɾ���Ľ�㣬tΪɾ��������Ľ��
	p = pHead;
	printf("\n\t\t\t  �������ѧ������Ϊ2-10λ����"); 
	printf("\n\t\t\t  ��������Ҫɾ����ѧ��������");

	scanf("%s",name);
	if ( strlen(name) / 2 < 2 || strlen(name) / 2 > 10 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
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
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼�ɹ�����ѡ��ģʽ2��\n");
	
}

//ͷ������ѧ����Ϣ 

void stu_HeadIncrease (  ) {
	STU *pNew;
	printf("\t\t\t  ������ͷ���ѧ����Ϣ��\n");
	pNew = MALLOC ;
	printf("\n\t\t\t  �������������2-10λ����,�Ա�(��/Ů),����(0-30),ѧ��(8λ),�ɼ�(0-100)");
	printf("\n\t\t\t  �������������Ա𣬰༶�����䣬ѧ��(8λ)���ɼ�(0-100)��\n");
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_HeadIncrease (  );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 2 ) {
		printf("\n\t\t\t  -------------------\n");
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_HeadIncrease (  );
	}
	if ( pNew->stuAge < 0 || pNew->stuAge  > 30 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_HeadIncrease (  );
	}
	
	pNew->next = pHead->next;
	pHead->next = pNew ;
	count ++ ;
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼�ɹ�����ѡ��ģʽ2��\n");
}
//�м����ѧ����Ϣ

void stu_MiddleIncrease (  ) {
	STU *p,*pNew;
	p = pHead ;
	char s[30];
	printf("\n\t\t\t  �������ѧ��ѧ��Ϊ8λ");
	printf("\n\t\t\t  ��������Ҫ�����ѧ����(����ѧ�Ų���)��"); 
	scanf("%s",s);
	
	if ( strlen ( s ) != 8 ) {
		printf("\n\t\t\t  ������Ϣ�������������룡");
		return stu_MiddleIncrease (  );
	}
	
	while ( p->next && strcmp( p->stuNumber,s ) != 0 ) {
		p = p->next ;
	}
	printf("\t\t\t  �������м�����ѧ����Ϣ��");
	pNew = MALLOC ;
	printf("\n\t\t\t  �������������2-10λ����,�Ա�(��/Ů),����(0-30),ѧ��(8λ),�ɼ�(0-100)");
	printf("\n\t\t\t  �������������Ա𣬰༶�����䣬ѧ��(8λ)���ɼ�(0-100)��\n");
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
	
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_MiddleIncrease (  );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 2 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_MiddleIncrease (  );
	}
	if ( pNew->stuAge < 0 || pNew->stuAge > 30 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_MiddleIncrease (  );
	}
	
	//stu_InputMessage( pNew ) ;
	pNew->next = p->next ;
	p->next = pNew ;
	count ++ ;
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼�ɹ�����ѡ��ģʽ2��\n");
}

//β������ѧ����Ϣ 

void stu_TailIncrease (  ) {
	STU *p,*pNew;
	p = pHead ;

	while ( p && p->next != NULL ) {
		p = p->next ;
	}
		
	printf("\t\t\t  ������β���ѧ����Ϣ��\n");
	pNew = MALLOC ;
	printf("\n\t\t\t  �������������2-10λ����,�Ա�(��/Ů),����(0-30),ѧ��(8λ),�ɼ�(0-100)");
	printf("\n\t\t\t  �������������Ա𣬰༶�����䣬ѧ��(8λ)���ɼ�(0-100)��\n");
	
	printf("\t\t\t  ");
	scanf("%s%s%s%d%s%lf",pNew->stuName,pNew->stuSex,pNew->stuClass,&pNew->stuAge,pNew->stuNumber,&pNew->stuScore);
//	stu_InputMessage( pNew ) ;
	if ( pNew->stuScore > 100 || pNew->stuScore < 0  || strlen(pNew->stuNumber) != 8 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_TailIncrease (  );
	}
	if ( strlen(pNew->stuName) / 2 < 2 || strlen(pNew->stuName) / 2 > 10 || strlen(pNew->stuSex) != 2 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_TailIncrease (  );
	}
	if ( pNew->stuAge  < 0 || pNew->stuAge > 30 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_TailIncrease (  );
	}
	p->next = pNew;
	pNew->next = NULL ;
	count ++ ;
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼�ɹ�����ѡ��ģʽ2��\n");
} 

//ѧ���޸ĺ��� 

void stu_NumberCorrect (  ) {
	STU *p = pHead ;
	char s[30];
	printf("\n\t\t\t  �������ѧ��ѧ��Ϊ8λ"); 
	printf("\n\t\t\t  ��������Ҫ�޸�ѧ��ѧ�ţ�");
	
	scanf("%s",s);
	
	if( strlen(s) != 8 ) {
		printf("\n\t\t\t  ��Ϣ�����������������룡");
		return  stu_NumberCorrect (  );
	}
	while ( p && strcmp ( p->stuNumber , s ) ) {
		p = p->next;
	}
	if ( p==NULL ) {
		printf("\t\t\t  û���ҵ����ˣ�");
	} else {
		printf("\n\t\t\t  �������������2-10λ����,�Ա�(��/Ů),����(0-30),ѧ��(8λ),�ɼ�(0-100)");
		printf("\n\t\t\t  �������������Ա𣬰༶�����䣬ѧ�ţ��ɼ���\n");
		
		printf("\t\t\t  ");
		scanf("%s%s%s%d%s%lf",p->stuName,p->stuSex,p->stuClass,&p->stuAge,p->stuNumber,&p->stuScore);
		
		if ( p->stuScore > 100 || p->stuScore < 0  || strlen(p->stuNumber) != 8 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return  stu_NumberCorrect (  );
		}
		
		if ( strlen(p->stuName) / 2 < 2 || strlen(p->stuName) / 2 > 10|| strlen(p->stuSex) != 2 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return  stu_NumberCorrect (  );
		}
		if ( p->stuAge  < 0 || p->stuAge  > 30 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return  stu_NumberCorrect (  );
		}
			//stu_InputMessage( p ) ;	
	}	
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼�ɹ�����ѡ��ģʽ2��\n");
}

//�����޸ĺ���

void  stu_NameCorrect ( ) {
	STU *p = pHead ;
	char name[30];
	printf("\n\t\t\t  �������ѧ������Ϊ2-10λ����"); 
	printf("\n\t\t\t  ��������Ҫ�޸ĵ�ѧ��������");
	
	scanf("%s",name);
	if ( strlen(name) / 2 < 1 || strlen(name) / 2 > 10 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_NameCorrect ( );
	}
	while ( p && strcmp ( p->stuName , name ) ) {
		p = p->next ;
	} 
	if ( p == NULL ) {
		printf ("\t\t\t  û���ҵ����ˣ�"); 
	} else {
		printf("\n\t\t\t  �������������2-10λ����,�Ա�(��/Ů),����(0-30),ѧ��(8λ),�ɼ�(0-100)");
		printf("\n\t\t\t  �������������Ա𣬰༶�����䣬ѧ�ţ��ɼ���\n");
		
		printf("\t\t\t  ");
		scanf("%s%s%s%d%s%lf",p->stuName,p->stuSex,p->stuClass,&p->stuAge,p->stuNumber,&p->stuScore);
	
		if ( p->stuScore > 100 || p->stuScore < 0  || strlen(p->stuNumber) != 8 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return stu_NameCorrect (  );
		}
		if ( strlen(name) / 2 < 2 || strlen(name) / 2 > 10 || strlen(p->stuSex) != 2 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return  stu_NameCorrect (  );
		}
		if ( p->stuAge < 0 || p->stuAge > 30 ) {
			printf("\n\t\t\t  ������Ϣ�����������룡\n");
			return  stu_NameCorrect (  );
		}
	//	stu_InputMessage( p ) ;	
	}
	printf("\n\t\t\t  ���Ҫ����Ϣ�������ļ��У����ڵ�¼�ɹ�����ѡ��ģʽ2��\n");
	
}

//�ɼ�ͳ�ƺ��� 
void stu_ScoreCount( ) { 
	STU *p = pHead ;
	int sumScore = 0;
	double score1 ,score2 ,t;
	printf("\n\t\t\t  ������ĳɼ���Χ��0-100֮��");
	printf("\n\t\t\t  ��������Ҫ����ĳɼ���Χ��"); 
	
	scanf("%lf%lf",&score1,&score2);
	if ( score1 > 100 || score1 < 0 || score2 > 100 || score2 < 0 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_ScoreCount( );
	}
	
	if (score1 > score2 ) {
		t = score1;
		score1 = score2;
		score2 = t ;
	} 
	printf("\t\t\t  ����\t\t\t�Ա�\t\t�༶\t\t����\t\tѧ��\t\t�ɼ�\t\t\n");
	while ( p != NULL ) {
		
		if ( p->stuScore >= score1 && p->stuScore <= score2 ) {
			sumScore ++ ;
			
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next ;
	} 
	printf("\t\t\t  �ɼ���%d��%d֮��Ĺ��У�%d��\n",score1,score2,sumScore);
}

//���Ա�ͳ�� 
void  stu_SexCount(  ) {
	STU *p = pHead ;
	char sex[30];
	int sumSex = 0 ;
	printf("\n\t\t\t  ��������Ա�Ϊ(��/Ů)");
	printf("\n\t\t\t  ��������Ҫͳ�Ƶ��Ա�(��,Ů)��");
 	scanf("%s",sex);
 	if ( strlen(sex) != 2 ) {
 		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_SexCount(  );
	}
	while ( p != NULL ) {
		if ( strcmp ( p->stuSex , sex ) == 0 ) {
			sumSex ++ ;
			printf("\t\t\t  ����\t\t\t�Ա�\t\t�༶\t\t����\t\tѧ��\t\t�ɼ�\t\t\n");
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next ;
	}
	printf("\t\t\t  �Ա�Ϊ%s���˹���%d����\n",sex,sumSex);
} 

//�༶�������ۺ�ͳ�� 
void stu_ClassAgeCount( ) {
	STU *p = pHead ;
	char clas_s[30];
	int age ;
	int sumClassAge = 0 ;
	printf("\n\t\t\t  �������������(0-30)");
	printf("\n\t\t\t  ��������Ҫͳ�Ƶİ༶�����䣺");
	scanf("%s",clas_s); 
	scanf("%d",&age);
	if ( age < 0 || age > 30 ) {
		printf("\n\t\t\t  ������Ϣ�����������룡\n");
		return  stu_ClassAgeCount( );
	}
	printf("\t\t\t  ����\t\t\t�Ա�\t\t�༶\t\t����\t\tѧ��\t\t�ɼ�\t\t\n");
	while ( p != NULL ) {
		if ( strcmp ( p->stuClass , clas_s) == 0 && p->stuAge == age ) {
			sumClassAge ++ ; 
			printf("\t\t\t  %s\t\t%s\t\t%s\t%d\t\t%s\t%.2lf\r\n",p->stuName,p->stuSex,p->stuClass,p->stuAge,p->stuNumber,p->stuScore);
		}
		p = p->next; 
	}
}
//������ �ɼ����������� 
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


		
//������ �ɼ����������� 
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

//������ ѧ�Ű��������� 
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

//������ ѧ���������� 
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


//��ѯ��

void find_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Find ( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-4)��");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_NumberFind ( ) ; break;
			case '2' : stu_NameFind( ) ; break ; 
			case '3' : stu_ClassSexFind( ) ;break ;
 			case '4' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//�޸Ķ�

void correct_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Correct ( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-3)��");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_NumberCorrect ( ) ; break;
			case '2' : stu_NameCorrect ( ) ; break ;
 			case '3' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//�����

void increase_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Increase ( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-4)��");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_HeadIncrease ( ) ; break;
			case '2' : stu_MiddleIncrease ( ) ; break ;
			case '3' : stu_TailIncrease ( ) ; break ;
 			case '4' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//ɾ����

void delete_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Delete ( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-3)��");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_NumberDelete ( ) ; break;
			case '2' : stu_NameDelete ( ) ; break ;
 			case '3' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//ͳ�ƶ� 
void count_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Count ( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-4)��");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_ScoreCount ( ) ; break;
			case '2' : stu_SexCount ( ) ; break ;
			case '3' : stu_ClassAgeCount( ) ;break ;
 			case '4' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//�����

void sort_Book ( ) {
	char flag ;
	while ( 1 ) {
		system ( "cls" );
		show_Sort ( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-5)��");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : stu_UpSort( ); break;
			case '2' : stu_DownSort( ); break ; 
			case '3' : stu_NumberUpSort( ); break;
			case '4' : stu_NumberDownSort( ); break ;
 			case '5' : return ;
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//ѧ��ע���¼�� 
void submit_StuBook() {
	char flag ;
	system("cls");
	show_StuSubmit(); 
	printf("\n\t\t\t  ��ѡ��ģʽ(0-3)��");
	fflush(stdin);
	scanf("%c",&flag);
	switch( flag ) {
		case '1' : stu_StuSubmit( ) ; break;
		case '2' : stu_StuSign ( ) ; break;
 		case '3' : remark() ; break; 
		case '0' : exit(0) ; break;
		default : printf("\t\t\t  ������������������\n") ; break;
	}
	printf("\n\t\t\t  �������������һ������");
	getch( );  	
}

//��ʦע���¼�� 
void submit_TeacherBook() {
	char flag ;
	system("cls");
	show_TeacherSubmit(); 
	printf("\n\t\t\t  ��ѡ��ģʽ(0-3)��");
	fflush(stdin);
	scanf("%c",&flag);
	switch( flag ) {
		case '1' : stu_TeacherSubmit( ) ; break;
		case '2' : stu_TeacherSign ( ) ; break;
 		case '3' : remark() ; break; 
		case '0' : exit(0) ; break;
		default : printf("\t\t\t  ������������������\n") ; break;
	}
	printf("\n\t\t\t  �������������һ������");
	getch( ); 
}

//����Աע���¼�� 
void submit_ManagerBook() {
	char flag ;
	system("cls");
	show_ManagerSubmit();
	printf("\n\t\t\t  ��ѡ��ģʽ(0-3)��");
	fflush(stdin);
	scanf("%c",&flag);
	switch( flag ) {
		case '1' : stu_ManagerSubmit( ) ; break;
		case '2' : stu_ManagerSign ( ) ; break;
 		case '3' : remark() ; break; 
		case '0' : exit(0) ; break;
		default : printf("\t\t\t  ������������������\n") ; break;
	}
	printf("\n\t\t\t  �������������һ������");
	getch( ); 
}

//ѧ���� 
void student_Book ( ) {
	char flag ;
	submit_StuBook ( );
	while ( 1 ) {
		system ( "cls" );
		show_Student ( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-2)��");
		fflush(stdin);
		scanf("%c",&flag);
		switch ( flag ) {
			case '1' : find_Book ( ) ; break;
 			case '2' : submit_StuBook() ; break; 
			case '0' : exit(0) ; break;
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//��ʦ�� 
void teacher_Book ( ) {
	char flag ;
	submit_TeacherBook ( ); 
	while ( 1 ) {
		system("cls");
		show_Teacher( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-a)��"); 
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
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
	getch( ); 
	}
} 

//����Ա�� 
void manager_Book ( ) {
	char flag ;
	submit_ManagerBook( );
	while ( 1 ) {
		system( " cls " );
		show_Manager( ) ;
		printf("\n\t\t\t  ������ѡ���ģʽ(0-a)��"); 
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
			default : printf("\t\t\t  ������������������\n") ; break;
		}
	printf("\t\t\t  �������������һ������");
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
		printf("\n\t\t\t  ������ѡ���ģʽ(0-3)��"); 
		fflush(stdin);
		scanf("%c",&flag);
		switch( flag ) {
		case '1' : student_Book ( ) ; break ;
		case '2' : teacher_Book ( ) ; break ;
		case '3' : manager_Book ( ) ; break ;
		case '0' : exit(0) ; break;
		default : printf("\n\t\t\t  ������������������") ; break;
	}
	} 
	printf("\t\t\t  �������������һ������");
	getch( ); 
}

int main ( ) {
	remark ( ) ;
} 

