#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


////��̬�汾-��ʼ��
//void InitContact(Contact* pc) {
//	pc->sz = 0;
//	//memset();����  -�ڴ�����
//	memset(pc->date,0,sizeof(pc->date));
//}

//��̬�汾-��ʼ��
void InitContact(Contact* pc) {
	pc->date = (PeopInfo*)malloc(DEEAULT_SZ *sizeof(PeopInfo));
	if (pc->date == NULL) {
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEEAULT_SZ;
}

//��̬����ʱ��Ҫ����ͨѶ¼
void DestoryContact(Contact* pc) {
	free(pc->date);
	pc->date = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


////��̬�汾��������ϵ��
//void AddContact(Contact* pc) {
//	if (pc->sz == MAX) {
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	//����һ���˵���Ϣ
//	printf("���������֣�");
//	scanf("%s", pc->date[pc->sz].name);//��Ϊ���������Բ���ȡ��ַ����
//	printf("����������:");
//	scanf("%d", &(pc->date[pc->sz].age));//age��int����Ҫȡ��ַ
//	printf("�������Ա�");
//	scanf("%s", pc->date[pc->sz].sex);
//	printf("������绰��");
//	scanf("%s", pc->date[pc->sz].tele);
//	printf("�������ַ��");
//	scanf("%s", pc->date[pc->sz].addr);
//	pc->sz++;
//	printf("��ӳɹ�\n");
//}

//��̬�汾��������ϵ��
void AddContact(Contact* pc) {
	//��������
	if (pc->sz == pc->capacity) {
		PeopInfo* ptr=(PeopInfo*)realloc(pc->date, (pc->capacity + INC_SZ) * sizeof(PeopInfo));
		if (ptr != NULL) {
			pc->date = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else {
			perror("AddContact");
			printf("������ϵ��ʧ��");
			return;
		}
	}
	//����һ���˵���Ϣ
	printf("���������֣�");
	scanf("%s", pc->date[pc->sz].name);//��Ϊ���������Բ���ȡ��ַ����
	printf("����������:");
	scanf("%d", &(pc->date[pc->sz].age));//age��int����Ҫȡ��ַ
	printf("�������Ա�");
	scanf("%s", pc->date[pc->sz].sex);
	printf("������绰��");
	scanf("%s", pc->date[pc->sz].tele);
	printf("�������ַ��");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}

void PrintfContact(const Contact* pc) {
	//��ӡ����
	if (pc->sz == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i=0; i < pc->sz; i++) {
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[i].name, 
													pc->date[i].age, 
													pc->date[i].sex, 
													pc->date[i].tele, 
													pc->date[i].addr);

	}

}
static int FindByName(Contact* pc,char name[Max_Name]) { //static ���κ���ֻ���ڵ�ǰ�ļ��鿴
	
	for (int i = 0; i < pc->sz; i++) {
		if (strcmp(pc->date[i].name ,name)==0) {
			return i;
		}
	}
	return -1;//�Ҳ���
}

void DelContact(Contact* pc) {
	char name[Max_Name] = { 0 };
	if (pc->sz == 0) {
		printf("ͨѶ¼�ѿա�\n");
		return;
	}
	printf("������Ҫɾ����ϵ�˵����֣�");
	scanf("%s", name);
	//1������Ҫɾ������
	//��/û��
	int pos=FindByName(pc, name);
	if (pos == -1) {
		printf("��ϵ�˲����ڡ�\n");
		return;
	}

	//2��ɾ��
	for (int i = pos; i < pc->sz-1; i++) {
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(Contact* pc) {
	char name[Max_Name] = { 0 };
	printf("������Ҫ������ϵ�˵����֣�");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("��ϵ�˲����ڡ�\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[pos].name,
			pc->date[pos].age,
			pc->date[pos].sex,
			pc->date[pos].tele,
			pc->date[pos].addr);
}

void ModifyContact(Contact* pc) {
	char name[Max_Name] = { 0 };
	printf("������Ҫ�޸���ϵ�˵����֣�");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("��ϵ�˲����ڡ�\n");
		return;
	}
	printf("���������֣�");
	scanf("%s", pc->date[pos].name);//��Ϊ���������Բ���ȡ��ַ����
	printf("����������:");
	scanf("%d", &(pc->date[pos].age));//age��int����Ҫȡ��ַ
	printf("�������Ա�");
	scanf("%s", pc->date[pos].sex);
	printf("������绰��");
	scanf("%s", pc->date[pos].tele);
	printf("�������ַ��");
	scanf("%s", pc->date[pos].addr);
	printf("�޸ĳɹ�\n");
}




