//
// Created by wangh on 2023/6/20.
//
# include <iostream>
# include <string>
# include <fstream>
# include <algorithm>
# include "menu.h"
# include "config.h"
using namespace std;

extern int U_id;    // �û�id
extern int C_id;    // ��Ʒid
extern int O_id;    // ����id

extern vector<User> v;     // �û���Ϣ

int check(string username)
{
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username)
            return 1;
    }
    return 0;
}

void Register()     // �û�ע��
{
    system("cls");
    User user;
    user.id= 'U' + to_string(U_id);
    user.adderss = "";
    user.phone = "";
    user.balance = 0;
    cout << "�����������û�����";
    cin >> user.username;
    while (check(user.username))
    {
        cout << "���û����Ѵ��ڣ����������룺";
        cin >> user.username;
    }
    cout << "�������������룺";
    cin >> user.password;
    cout << "ע��ɹ�" << endl;
    ofstream ofs;
    ofs.open("../data/User.txt", ios::out | ios::app);
    ofs << user.id << "," << user.username << "," << user.password << "," << user.adderss << "," << user.phone << "," << user.balance << endl;
    ofs.close();
    U_id++;

    // ����Config.txt
    ofstream ofs1;
    ofs1.open("../data/Config.txt", ios::out);

    ofs1 << U_id << endl << C_id <<endl << O_id << endl;
    ofs1.close();
    v.push_back(user);
    return;
}

void Login()
{
    system("cls");
    string username;
    string passwd;
    cout << "�����������û�����";
    cin >> username;
    cout << "�������������룺";
    cin >> passwd;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username && it->password == passwd)
        {
            cout << "��¼�ɹ�" << endl;
            cout << "��ӭ����" << username << endl;
            return;
        }

    }
    cout << "�û������������" << endl;
    return;
}