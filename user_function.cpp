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
    int flag = 0;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username && it->password == passwd)
        {
            flag = 1;
            cout << "登录成功" << endl;
            cout << "欢迎您，" << username << endl;
            UserMenu(username);
            return;
        }

    }
    cout << "用户名或密码错误" << endl;
    return;
}

void UserMenu(string username)
{
    while(true) {
        system("cls");
        cout << "======================================================" << endl;
        cout << "1.我是买家  2.我是卖家  3.个人信息  4.退出登录" << endl;
        cout << "======================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "我是买家" << endl;
                break;
            case 2:
                cout << "我是卖家" << endl;
                SellerMenu(username);
                break;
            case 3:
                cout << "个人信息" << endl;
                break;
            case 4:
                cout << "退出登录" << endl;
                return;
            default:
                cout << "输入错误" << endl;
                break;
        }
        system("pause");
    }


}

void SellerMenu(string username)
{
    while(true) {
        system("cls");
        cout << "==============================================================================" << endl;
        cout << "1.商品上架  2.查看发布商品  3.修改商品信息  4.商品下架  5.查看历史订单  6. 返回" << endl;
        cout << "==============================================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "商品上架" << endl;
                PostCommodity(username);
                break;
            case 2:
                cout << "查看发布商品" << endl;
                ShowMyCommodity(username);
                break;
            case 3:
                cout << "修改商品信息" << endl;
                ModifyCommodity(username);
                break;
            case 4:
                cout << "商品下架" << endl;
                RemoveCommodity(username);
                break;
            case 5:
                cout << "查看历史订单" << endl;
                break;
            case 6:
                cout << "返回" << endl;
                return;
            default:
                cout << "输入错误" << endl;
                break;
        }
    }
}