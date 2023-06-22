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

extern int U_id;    // 用户id
extern int C_id;    // 商品id
extern int O_id;    // 订单id

extern vector<User> v;     // 用户信息

void Register()     // 用户注册
{
    system("cls");
    User user;
    user.id= 'U' + to_string(U_id);
    cout << "请输入您的用户名：";
    cin >> user.username;
    cout << "请输入您的密码：";
    cin >> user.password;
    cout << "注册成功" << endl;
    ofstream ofs;
    ofs.open("../data/User.txt", ios::out | ios::app);
    ofs << user.id << " " << user.username << " " << user.password << endl;
    ofs.close();
    ofstream ofs1;
    ofs1.open("../data/Config.txt", ios::out);

    ofs1 << U_id + 1 << endl << C_id <<endl << O_id << endl;
    ofs1.close();
    v.push_back(user);
    return;
}

void Login()
{
    system("cls");
    string username;
    string passwd;
    cout << "请输入您的用户名：";
    cin >> username;
    cout << "请输入您的密码：";
    cin >> passwd;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username && it->password == passwd)
        {
            cout << "登录成功" << endl;
            cout << "欢迎您，" << username << endl;
            return;
        }

    }
    cout << "用户名或密码错误" << endl;
    return;
}