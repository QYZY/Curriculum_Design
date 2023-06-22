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

int check(string username)
{
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username)
            return 1;
    }
    return 0;
}

void Register()     // 用户注册
{
    system("cls");
    User user;
    user.id= 'U' + to_string(U_id);
    user.adderss = "";
    user.phone = "";
    user.balance = 0;
    cout << "请输入您的用户名：";
    cin >> user.username;
    while (check(user.username))
    {
        cout << "该用户名已存在，请重新输入：";
        cin >> user.username;
    }
    cout << "请输入您的密码：";
    cin >> user.password;
    cout << "注册成功" << endl;
    ofstream ofs;
    ofs.open("../data/User.txt", ios::out | ios::app);
    ofs << user.id << "," << user.username << "," << user.password << "," << user.adderss << "," << user.phone << "," << user.balance << endl;
    ofs.close();
    U_id++;

    // 更新Config.txt
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