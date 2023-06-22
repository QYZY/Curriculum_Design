//
// Created by wangh on 2023/6/20.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "menu.h"
#include "config.h"
using namespace std;

vector<User> v;     // �û���Ϣ

int U_id = 1000;    // �û�id
int C_id = 1000;    // ��Ʒid
int O_id = 1000;    // ����id

void ShowMenu()     // ��ʾ�˵�
{
    cout << "====================================" << endl;
    cout << "==       ��ӭʹ��ѧ������ϵͳ     ==" << endl;
    cout << "==         ��ѡ�����Ĳ���         ==" << endl;
    cout << "====================================" << endl;
    cout << "********** 1.�û���¼ **************" << endl;
    cout << "********** 2.�û�ע�� **************" << endl;
    cout << "********** 3.����Ա��¼ ************" << endl;
    cout << "********** 4.�˳�ϵͳ **************" << endl;
    cout << "====================================" << endl;
}

void init()     // ��ʼ��
{
    // ��ȡ�����ļ�
    ifstream ifs("../data/Config.txt");
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    ifs >> U_id >> C_id >> O_id;
    ifs.close();

    // ��ȡ�û���Ϣ
    ifstream ifs1("../data/User.txt");
    if (!ifs1.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    User user;
    string line;
    while (getline(ifs1, line))
    {
        stringstream ss(line);
        string str;
        getline(ss, str, ',');
        user.id = str;
        getline(ss, str, ',');
        user.username = str;
        getline(ss, str, ',');
        user.password = str;
        getline(ss, str, ',');
        user.adderss = str;
        getline(ss, str, ',');
        user.phone = str;
        getline(ss, str, ',');
        user.balance = stoi(str);
        v.push_back(user);
    }

}


void MakeChoice()       // ѡ�����
{
    while(true) {
        system("cls");
        ShowMenu();
        int option = 0;
        cout << "����������ѡ��";
        cin >> option;
        if (cin.fail()) {
            cout << "�����������������" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            system("pause");
            continue;
        }
        switch (option) {
            case 1:
                cout << "�û���¼" << endl;
                Login();
                break;
            case 2:
                cout << "�û�ע��" << endl;
                Register();
                break;
            case 3:
                cout << "����Ա��¼" << endl;
                AdminLogin();
                break;
            case 4:
                cout << "�˳�ϵͳ" << endl;
                Exit();
                break;
            default:
                cout << "�����������������" << endl;
                break;
        }
        system("pause");
    }

}


void Exit()     // �˳�ϵͳ
{
    system("cls");
    cout << "-------------------------------------" << endl;
    cout << "          ��л����ʹ�ã��ټ�    " << endl;
    cout << "-------------------------------------" << endl;
    system("pause");
    exit(0);
}

