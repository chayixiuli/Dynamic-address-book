#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


////静态版本-初始化
//void InitContact(Contact* pc) {
//	pc->sz = 0;
//	//memset();函数  -内存设置
//	memset(pc->date,0,sizeof(pc->date));
//}

//动态版本-初始化
void InitContact(Contact* pc) {
	pc->date = (PeopInfo*)malloc(DEEAULT_SZ *sizeof(PeopInfo));
	if (pc->date == NULL) {
		perror("InitContact");
		return;
	}
	pc->sz = 0;
	pc->capacity = DEEAULT_SZ;
}

//动态开辟时需要销毁通讯录
void DestoryContact(Contact* pc) {
	free(pc->date);
	pc->date = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


////静态版本的增加联系人
//void AddContact(Contact* pc) {
//	if (pc->sz == MAX) {
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	//增加一个人的信息
//	printf("请输入名字：");
//	scanf("%s", pc->date[pc->sz].name);//因为是数组所以不用取地址符号
//	printf("请输入年龄:");
//	scanf("%d", &(pc->date[pc->sz].age));//age是int型需要取地址
//	printf("请输入性别：");
//	scanf("%s", pc->date[pc->sz].sex);
//	printf("请输入电话：");
//	scanf("%s", pc->date[pc->sz].tele);
//	printf("请输入地址：");
//	scanf("%s", pc->date[pc->sz].addr);
//	pc->sz++;
//	printf("添加成功\n");
//}

//动态版本的增加联系人
void AddContact(Contact* pc) {
	//考虑增容
	if (pc->sz == pc->capacity) {
		PeopInfo* ptr=(PeopInfo*)realloc(pc->date, (pc->capacity + INC_SZ) * sizeof(PeopInfo));
		if (ptr != NULL) {
			pc->date = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else {
			perror("AddContact");
			printf("增加联系人失败");
			return;
		}
	}
	//增加一个人的信息
	printf("请输入名字：");
	scanf("%s", pc->date[pc->sz].name);//因为是数组所以不用取地址符号
	printf("请输入年龄:");
	scanf("%d", &(pc->date[pc->sz].age));//age是int型需要取地址
	printf("请输入性别：");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入电话：");
	scanf("%s", pc->date[pc->sz].tele);
	printf("请输入地址：");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}

void PrintfContact(const Contact* pc) {
	//打印标题
	if (pc->sz == 0) {
		printf("通讯录为空\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (int i=0; i < pc->sz; i++) {
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[i].name, 
													pc->date[i].age, 
													pc->date[i].sex, 
													pc->date[i].tele, 
													pc->date[i].addr);

	}

}
static int FindByName(Contact* pc,char name[Max_Name]) { //static 修饰函数只能在当前文件查看
	
	for (int i = 0; i < pc->sz; i++) {
		if (strcmp(pc->date[i].name ,name)==0) {
			return i;
		}
	}
	return -1;//找不到
}

void DelContact(Contact* pc) {
	char name[Max_Name] = { 0 };
	if (pc->sz == 0) {
		printf("通讯录已空。\n");
		return;
	}
	printf("请输入要删除联系人的名字：");
	scanf("%s", name);
	//1、查找要删除的人
	//有/没有
	int pos=FindByName(pc, name);
	if (pos == -1) {
		printf("联系人不存在。\n");
		return;
	}

	//2、删除
	for (int i = pos; i < pc->sz-1; i++) {
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(Contact* pc) {
	char name[Max_Name] = { 0 };
	printf("请输入要查找联系人的名字：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("联系人不存在。\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[pos].name,
			pc->date[pos].age,
			pc->date[pos].sex,
			pc->date[pos].tele,
			pc->date[pos].addr);
}

void ModifyContact(Contact* pc) {
	char name[Max_Name] = { 0 };
	printf("请输入要修改联系人的名字：");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1) {
		printf("联系人不存在。\n");
		return;
	}
	printf("请输入名字：");
	scanf("%s", pc->date[pos].name);//因为是数组所以不用取地址符号
	printf("请输入年龄:");
	scanf("%d", &(pc->date[pos].age));//age是int型需要取地址
	printf("请输入性别：");
	scanf("%s", pc->date[pos].sex);
	printf("请输入电话：");
	scanf("%s", pc->date[pos].tele);
	printf("请输入地址：");
	scanf("%s", pc->date[pos].addr);
	printf("修改成功\n");
}




