#include<iostream>
#include<string>
using namespace std;

#define MAXPERSON 1000// ͨѶ¼��������
int select;// ����ѡ��

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

// ͨѶ¼����
void showMenu() {
	cout << " ****************************************" << endl;
	cout << " ****************************************" << endl;
	cout << " ******        1. �����ϵ��        ******" << endl;
	cout << " ******        2. ��ʾ��ϵ��        ******" << endl;
	cout << " ******        3. ɾ����ϵ��        ******" << endl;
	cout << " ******        4. ������ϵ��        ******" << endl;
	cout << " ******        5. �޸���ϵ��        ******" << endl;
	cout << " ******        6. �����ϵ��        ******" << endl;
	cout << " ******        0. �˳�ͨѶ¼        ******" << endl;
	cout << " ****************************************" << endl;
	cout << " ****************************************" << endl;
}
// �û�ѡ��
void yourSelect() {
	cout << "����������ѡ��";
	cin >> select;
}

// ��ʾһ����
void showOnePerson(Person person) {
	cout << "������" << person.m_Name << "��"
		<< "�Ա�" << (person.m_Sex == 1 ? "��" : "Ů") << "��"
		<< "���䣺" << person.m_Age << "��"
		<< "�绰��" << person.m_Phone << "��"
		<< "��ַ��" << person.m_Addr << endl;
}
// ��ʾһ����Ϣ
void showMessage(string message) {
	cout << message << endl;
}


// ���һ����
void addPerson(AddressBooks* abs) {
	if (abs->m_Size == MAXPERSON) {
		showMessage("ͨѶ¼�������޷���ӣ�");
		return;
	}
	else {
		Person newPerson;
		int mySex;
		cout << "������������";
		cin >> newPerson.m_Name;
		cout << "�������Ա�";
		while (true) {
			cin >> mySex;
			if (mySex == 1 || mySex == 2) {
				newPerson.m_Sex = mySex;
				break;
			}
			else {
				showMessage("�����������������");
			}
		}
		cout << "���������䣺";
		cin >> newPerson.m_Age;
		cout << "������绰��";
		cin >> newPerson.m_Phone;
		cout << "�������ͥ��ַ��";
		cin >> newPerson.m_Addr;

		abs->personArray[abs->m_Size] = newPerson;
		(abs->m_Size)++;
		showMessage("��ӳɹ�");
		system("pause");
		system("cls");
	}
}
void showPerson(AddressBooks* abs) {
	if (abs->m_Size == 0) {
		showMessage("ͨѶ¼Ϊ�ա�");
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
// ����һ���˲�������λ��
int selectOnePerson(AddressBooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}
// ɾ��ָ����������
void deletePerson(AddressBooks* abs) {
	string name;
	showMessage("��ѡ����Ҫɾ����������");
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
		showMessage("ɾ���ɹ���");
	}
	else {
		showMessage("���޴��ˣ�");
	}
	system("pause");
	system("cls");
}
// ����ָ����������
void findPerson(AddressBooks* abs) {
	showMessage("��������Ҫ��ѯ����ϵ�ˣ�");
	string name;
	cin >> name;
	int ret = selectOnePerson(abs, name);
	if (ret != -1) {
		showOnePerson(abs->personArray[ret]);
	}
	else {
		showMessage("���޴���");
	}
	system("pause");
	system("cls");
}
// �޸���ϵ��
void modifyPerson(AddressBooks* abs) {
	showMessage("��������Ҫ�޸ĵ���ϵ�ˣ�");
	Person person;
	cin >> person.m_Name;
	int ret = selectOnePerson(abs, person.m_Name);
	if (ret != -1) {
		showMessage("�������Ա����䣬��ϵ�绰����ͥסַ");
		showMessage("����������ѡ��1. �޸�        0. ���޸�");
		string yesModify;
		cin >> yesModify;
		if (yesModify[0])
		{
			showMessage("�������µ�������");
			cin >> person.m_Name;
		}
		if (yesModify[1])
		{
			showMessage("�������µ��Ա�");
			cin >> person.m_Sex;
		}
		if (yesModify[2]) {
			showMessage("�������µ����䣺");
			cin >> person.m_Age;
		}
		if (yesModify[3]) {
			showMessage("�������µ���ϵ�绰��");
			cin >> person.m_Phone;
		}
		if (yesModify[4]) {
			showMessage("�������µļ�ͥסַ��");
			cin >> person.m_Addr;
		}
		abs->personArray[ret] = person;
	}
	else {
		showMessage("���޴���");
	}
	system("pause");
	system("cls");
}
// ���������ϵ��
void cleanPerson(AddressBooks* abs) {
	showMessage("�Ƿ�Ҫ���������ϵ�ˣ�");
	int judge = NULL;
	cin >> judge;
	if (judge == 1) {
		abs->m_Size = 0;
		showMessage("ͨѶ¼����ա�");
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
		case 1:// 1. �����ϵ��
			addPerson(&abs);
			break;
		case 2:// 2. ��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:// 3. ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:// 4. ������ϵ��
			findPerson(&abs);
			break;
		case 5:// 5. �޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:// 6. �����ϵ��
			cleanPerson(&abs);
			break;
		case 0:// 0. �˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}






	system("pause");
	return 0;
}