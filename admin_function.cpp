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
        return;
    }
    cout << "�û������������" << endl;

}