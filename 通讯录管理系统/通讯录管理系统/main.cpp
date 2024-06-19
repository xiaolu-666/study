#include<iostream>
#include<string>
using namespace std;

#define MAXPERSON 1000// 通讯录极限人数
int select;// 您的选择

struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct AddressBooks {
	Person personArray[MAXPERSON];
	int m_Size;
};

// 通讯录界面
void showMenu() {
	cout << " ****************************************" << endl;
	cout << " ****************************************" << endl;
	cout << " ******        1. 添加联系人        ******" << endl;
	cout << " ******        2. 显示联系人        ******" << endl;
	cout << " ******        3. 删除联系人        ******" << endl;
	cout << " ******        4. 查找联系人        ******" << endl;
	cout << " ******        5. 修改联系人        ******" << endl;
	cout << " ******        6. 清空联系人        ******" << endl;
	cout << " ******        0. 退出通讯录        ******" << endl;
	cout << " ****************************************" << endl;
	cout << " ****************************************" << endl;
}
// 用户选择
void yourSelect() {
	cout << "请输入您的选择：";
	cin >> select;
}

// 显示一个人
void showOnePerson(Person person) {
	cout << "姓名：" << person.m_Name << "，"
		<< "性别：" << (person.m_Sex == 1 ? "男" : "女") << "，"
		<< "年龄：" << person.m_Age << "，"
		<< "电话：" << person.m_Phone << "，"
		<< "地址：" << person.m_Addr << endl;
}
// 显示一条消息
void showMessage(string message) {
	cout << message << endl;
}


// 添加一个人
void addPerson(AddressBooks* abs) {
	if (abs->m_Size == MAXPERSON) {
		showMessage("通讯录已满，无法添加！");
		return;
	}
	else {
		Person newPerson;
		int mySex;
		cout << "请输入姓名：";
		cin >> newPerson.m_Name;
		cout << "请输入性别：";
		while (true) {
			cin >> mySex;
			if (mySex == 1 || mySex == 2) {
				newPerson.m_Sex = mySex;
				break;
			}
			else {
				showMessage("输入错误，请重新输入");
			}
		}
		cout << "请输入年龄：";
		cin >> newPerson.m_Age;
		cout << "请输入电话：";
		cin >> newPerson.m_Phone;
		cout << "请输入家庭地址：";
		cin >> newPerson.m_Addr;

		abs->personArray[abs->m_Size] = newPerson;
		(abs->m_Size)++;
		showMessage("添加成功");
		system("pause");
		system("cls");
	}
}
void showPerson(AddressBooks* abs) {
	if (abs->m_Size == 0) {
		showMessage("通讯录为空。");
	}
	else {
		for (int i = 0; i < abs->m_Size; i++)
		{
			showOnePerson(abs->personArray[i]);
		}
	}
	system("pause");
	system("cls");
}
// 查找一个人并返回其位置
int selectOnePerson(AddressBooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}
// 删除指定姓名的人
void deletePerson(AddressBooks* abs) {
	string name;
	showMessage("请选择您要删除的姓名：");
	cin >> name;
	int ret = selectOnePerson(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i].m_Name = abs->personArray[i + 1].m_Name;
			abs->personArray[i].m_Sex = abs->personArray[i + 1].m_Sex;
			abs->personArray[i].m_Age = abs->personArray[i + 1].m_Age;
			abs->personArray[i].m_Phone = abs->personArray[i + 1].m_Phone;
			abs->personArray[i].m_Addr = abs->personArray[i + 1].m_Addr;
		}
		abs->m_Size--;
		showMessage("删除成功！");
	}
	else {
		showMessage("查无此人！");
	}
	system("pause");
	system("cls");
}
// 查找指定姓名的人
void findPerson(AddressBooks* abs) {
	showMessage("请输入您要查询的联系人：");
	string name;
	cin >> name;
	int ret = selectOnePerson(abs, name);
	if (ret != -1) {
		showOnePerson(abs->personArray[ret]);
	}
	else {
		showMessage("查无此人");
	}
	system("pause");
	system("cls");
}
// 修改联系人
void modifyPerson(AddressBooks* abs) {
	showMessage("请输入您要修改的联系人：");
	Person person;
	cin >> person.m_Name;
	int ret = selectOnePerson(abs, person.m_Name);
	if (ret != -1) {
		showMessage("姓名，性别，年龄，联系电话，家庭住址");
		showMessage("请输入您的选择：1. 修改        0. 不修改");
		string yesModify;
		cin >> yesModify;
		if (yesModify[0])
		{
			showMessage("请输入新的姓名：");
			cin >> person.m_Name;
		}
		if (yesModify[1])
		{
			showMessage("请输入新的性别：");
			cin >> person.m_Sex;
		}
		if (yesModify[2]) {
			showMessage("请输入新的年龄：");
			cin >> person.m_Age;
		}
		if (yesModify[3]) {
			showMessage("请输入新的联系电话：");
			cin >> person.m_Phone;
		}
		if (yesModify[4]) {
			showMessage("请输入新的家庭住址：");
			cin >> person.m_Addr;
		}
		abs->personArray[ret] = person;
	}
	else {
		showMessage("查无此人");
	}
	system("pause");
	system("cls");
}
// 清空所有联系人
void cleanPerson(AddressBooks* abs) {
	showMessage("是否要清空所有联系人：");
	int judge = NULL;
	cin >> judge;
	if (judge == 1) {
		abs->m_Size = 0;
		showMessage("通讯录已清空。");
	}
	system("pause");
	system("cls");
}
int main() {
	AddressBooks abs;
	abs.m_Size = 0;

	while (true) {
		showMenu();
		yourSelect();
		switch (select) {
		case 1:// 1. 添加联系人
			addPerson(&abs);
			break;
		case 2:// 2. 显示联系人
			showPerson(&abs);
			break;
		case 3:// 3. 删除联系人
			deletePerson(&abs);
			break;
		case 4:// 4. 查找联系人
			findPerson(&abs);
			break;
		case 5:// 5. 修改联系人
			modifyPerson(&abs);
			break;
		case 6:// 6. 清空联系人
			cleanPerson(&abs);
			break;
		case 0:// 0. 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}






	system("pause");
	return 0;
}