//
// Created by wangh on 2023/6/22.
//

#include <iostream>
#include <fstream>
#include "menu.h"
#include "config.h"
using namespace std;


extern vector<User> v;     // 用户信息

void AdminLogin() {
    system("cls");
    ifstream ifs("../data/AdminAccount.txt");
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    string username;
    string passwd;
    cout << "请输入管理员用户名：";
    cin >> username;
    cout << "请输入管理员密码：";
    cin >> passwd;
    string username1;
    string passwd1;
    ifs >> username1;
    ifs >> passwd1;
    if (username == username1 && passwd == passwd1) {
        cout << "登录成功" << endl;
        cout << "欢迎您，" << username << endl;
        AdminMenu();
        return;
    }
    else
        cout << "用户名或密码错误" << endl;
    ifs.close();
    return;

}

void ShowAdminMenu()
{
    system("cls");
    cout << "***** 欢迎进入管理员界面 *****" << endl;
    cout << "\t1. 查看所有商品" << endl;
    cout << "\t2. 搜索商品" << endl;
    cout << "\t3. 查看所有订单" << endl;
    cout << "\t4. 查看所有用户" << endl;
    cout << "\t5. 删除用户" << endl;
    cout << "\t6. 下架商品" << endl;
    cout << "\t7. 退出登录" << endl;
}


void AdminMenu()
{
    while(true) {
        ShowAdminMenu();
        int option = 0;
        cout << "请输入您的选择：";
        cin >> option;
        while (cin.fail()) {
            cout << "输入错误，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            system("pause");
            system("cls");
            ShowAdminMenu();
            cout << "请输入您的选择：";
            cin >> option;

        }
        switch (option) {
            case 1:
                cout << "查看所有商品" << endl;
                break;
            case 2:
                cout << "搜索商品" << endl;
                break;
            case 3:
                cout << "查看所有订单" << endl;
                break;
            case 4:
                cout << "查看所有用户" << endl;
                ShowAllUser();
                break;
            case 5:
                cout << "删除用户" << endl;
                DeleteUser();
                break;
            case 6:
                cout << "下架商品" << endl;
                break;
            case 7:
                cout << "退出登录" << endl;
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
                system("pause");
                system("cls");
                break;
        }
    }

}

void ShowAllUser()
{
    system("cls");
    cout << "***** 所有用户信息 *****" << endl;
    cout << "用户ID\t\t用户名\t\t密码" << endl;
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
    cout << "***** 删除用户 *****" << endl;
    cout << "请输入要删除的用户ID：";
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
    cout << "删除成功" << endl;
    system("pause");
    return;
}