#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"
//ͨѶ¼-��̬�汾
// 1��ͨѶ¼���ܴ��1000���˵���Ϣ
//ÿ���˵���Ϣ��
//����+����+�Ա�+�绰+��ַ
//2������ָ���˵���Ϣ
//3��ɾ��ָ���˵���Ϣ
//4���޸�ָ���˵���Ϣ
//5������ָ���˵���Ϣ
//6������ͨѶ¼����Ϣ
//
//�汾2��
// 1��ͨѶ¼��ʼ�����ܴ��3���˵���Ϣ
// 2�������ǵĿռ�������ʱ����������������Ϣ��
// 3+2+2+2+2+...
//



void menu() {
	printf("***************************************************\n");
	printf("**********    1��add        2��del     ************\n");
	printf("**********    3��search     3��modify  ************\n");
	printf("**********    5��sort       6��print  *************\n");
	printf("**********    0��exit                  ************\n");
	printf("***************************************************\n");
}

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,

};

int main() {
	int input = 0;
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	
	//��date����һ�������Ŀռ��ڶ�����
	// sz=0
	// capacity ��ʼ��Ϊ��ǰ���������
	
	InitContact(&con);

	do {
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input) {
			case ADD:
				//������ϵ�˵���Ϣ
				AddContact(&con);   //��̬����ʱ��Ҫ����
				break;
			case DEL:
				//ɾ����ϵ�˵���Ϣ
				DelContact(&con);
				break;
			case SEARCH:
				//����ָ����ϵ��
				SearchContact(&con);
				break;
			case MODIFY:
				//�޸�ָ����ϵ��
				ModifyContact(&con);
				break;
			case SORT:
				//����ûд
				break;
			case PRINT:
				//��ӡ��ϵ����Ϣ
				PrintfContact(&con);
				break;
			case EXIT:
				//��̬����ʱ��Ҫ����ͨѶ¼
				DestoryContact(&con);
				printf("�˳�");
				break;
			default:
				printf("ѡ�����������ѡ��");
				break;
			}
	} while (input);
	return 0;
}