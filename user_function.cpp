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
extern vector<User> v;     // �û���Ϣ

void Register()     // �û�ע��
{
    system("cls");
    User user;
    user.id= 'U' + to_string(U_id);
    cout << "�����������û�����";
    cin >> user.username;
    cout << "�������������룺";
    cin >> user.password;
    cout << "ע��ɹ�" << endl;
    ofstream ofs;
    ofs.open("../data/User.txt", ios::out | ios::app);
    ofs << user.id << " " << user.username << " " << user.password << endl;
    ofs.close();
    ofstream ofs1;
    ofs1.open("../data/Config.txt", ios::out | ios::trunc);
    U_id++;
    ofs1 << U_id;
    ofs1.close();

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
            return ;
        }

    }
    cout << "�û������������" << endl;
    system("pause");
}