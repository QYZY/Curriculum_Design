//
// Created by wangh on 2023/6/22.
//

#include <iostream>
#include <fstream>
#include "menu.h"
#include "config.h"
using namespace std;


extern vector<User> v;     // �û���Ϣ

void AdminLogin() {
    system("cls");
    ifstream ifs("../data/AdminAccount.txt");
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string username;
    string passwd;
    cout << "���������Ա�û�����";
    cin >> username;
    cout << "���������Ա���룺";
    cin >> passwd;
    string username1;
    string passwd1;
    ifs >> username1;
    ifs >> passwd1;
    if (username == username1 && passwd == passwd1) {
        cout << "��¼�ɹ�" << endl;
        cout << "��ӭ����" << username << endl;
        AdminMenu();
        return;
    }
    else
        cout << "�û������������" << endl;
    ifs.close();
    return;

}

void ShowAdminMenu()
{
    system("cls");
    cout << "***** ��ӭ�������Ա���� *****" << endl;
    cout << "\t1. �鿴������Ʒ" << endl;
    cout << "\t2. ������Ʒ" << endl;
    cout << "\t3. �鿴���ж���" << endl;
    cout << "\t4. �鿴�����û�" << endl;
    cout << "\t5. ɾ���û�" << endl;
    cout << "\t6. �¼���Ʒ" << endl;
    cout << "\t7. �˳���¼" << endl;
}


void AdminMenu()
{
    while(true) {
        ShowAdminMenu();
        int option = 0;
        cout << "����������ѡ��";
        cin >> option;
        while (cin.fail()) {
            cout << "�����������������" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            system("pause");
            system("cls");
            ShowAdminMenu();
            cout << "����������ѡ��";
            cin >> option;

        }
        switch (option) {
            case 1:
                cout << "�鿴������Ʒ" << endl;
                break;
            case 2:
                cout << "������Ʒ" << endl;
                break;
            case 3:
                cout << "�鿴���ж���" << endl;
                break;
            case 4:
                cout << "�鿴�����û�" << endl;
                ShowAllUser();
                break;
            case 5:
                cout << "ɾ���û�" << endl;
                DeleteUser();
                break;
            case 6:
                cout << "�¼���Ʒ" << endl;
                break;
            case 7:
                cout << "�˳���¼" << endl;
                return;
            default:
                cout << "�����������������" << endl;
                system("pause");
                system("cls");
                break;
        }
    }

}

void ShowAllUser()
{
    system("cls");
    cout << "***** �����û���Ϣ *****" << endl;
    cout << "�û�ID\t\t�û���\t\t����" << endl;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->id << "\t\t" << it->username << "\t\t" << it->password << endl;
    }
    system("pause");
    return;
}

void DeleteUser()
{
    system("cls");
    cout << "***** ɾ���û� *****" << endl;
    cout << "������Ҫɾ�����û�ID��";
    string del_id;
    cin >> del_id;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == del_id)
        {
            v.erase(it);
        }
    }
    ofstream ofs("../data/User.txt");
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        ofs << it->id << " " << it->username << " " << it->password << endl;
    }
    ofs.close();
    cout << "ɾ���ɹ�" << endl;
    system("pause");
    return;
}