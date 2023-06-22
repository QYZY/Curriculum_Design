//
// Created by wangh on 2023/6/20.
//
#include <iostream>
#include <fstream>
#include "menu.h"
#include "config.h"
using namespace std;

vector<User> v;     // 用户信息

int U_id = 1000;    // 用户id
int C_id = 1000;    // 商品id
int O_id = 1000;    // 订单id

void ShowMenu()     // 显示菜单
{
    cout << "====================================" << endl;
    cout << "==       欢迎使用学生管理系统     ==" << endl;
    cout << "==         请选择您的操作         ==" << endl;
    cout << "====================================" << endl;
    cout << "********** 1.用户登录 **************" << endl;
    cout << "********** 2.用户注册 **************" << endl;
    cout << "********** 3.管理员登录 ************" << endl;
    cout << "********** 4.退出系统 **************" << endl;
    cout << "====================================" << endl;
}

void init()     // 初始化
{
    ifstream ifs("../data/Config.txt");
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    ifs >> U_id >> C_id >> O_id;
    ifs.close();

    ifstream ifs1("../data/User.txt");
    if (!ifs1.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    User user;
    while (ifs1 >> user.id && ifs1 >> user.username && ifs1 >> user.password)
    {
        v.push_back(user);
    }
    ifs1.close();
}


void MakeChoice()       // 选择操作
{
    while(true) {
        system("cls");
        ShowMenu();
        int option = 0;
        cout << "请输入您的选择：";
        cin >> option;
        if (cin.fail()) {
            cout << "输入错误，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            system("pause");
            continue;
        }
        switch (option) {
            case 1:
                cout << "用户登录" << endl;
                Login();
                break;
            case 2:
                cout << "用户注册" << endl;
                Register();
                break;
            case 3:
                cout << "管理员登录" << endl;
                AdminLogin();
                break;
            case 4:
                cout << "退出系统" << endl;
                Exit();
                break;
            default:
                cout << "输入错误，请重新输入" << endl;
                break;
        }
        system("pause");
    }

}


void Exit()     // 退出系统
{
    system("cls");
    cout << "-------------------------------------" << endl;
    cout << "          感谢您的使用，再见    " << endl;
    cout << "-------------------------------------" << endl;
    system("pause");
    exit(0);
}

