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
extern vector<Commodity> v1;   // 商品信息
extern vector<Order> v2;   // 订单信息



int check(string username)      // 检查用户名是否存在
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

    // 更新User.txt
    v.push_back(user);
    UpdateUser();


    // 更新Config.txt
    U_id++;
    UpdateConfig();
    return;
}

void Login()        // 用户登录
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

void UserMenu(string username)      // 用户菜单
{
    string user_id;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username)
        {
            user_id = it->id;
            break;
        }
    }
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
                BuyerMenu(user_id);
                break;
            case 2:
                cout << "我是卖家" << endl;
                SellerMenu(user_id);
                break;
            case 3:
                cout << "个人信息" << endl;
                PersonalInfo(user_id);
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

void SellerMenu(string user_id)        // 卖家菜单
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
                PostCommodity(user_id);
                break;
            case 2:
                cout << "查看发布商品" << endl;
                ShowMyCommodity(user_id);
                break;
            case 3:
                cout << "修改商品信息" << endl;
                ModifyCommodity(user_id);
                break;
            case 4:
                cout << "商品下架" << endl;
                RemoveCommodity(user_id);
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

void BuyerMenu(string user_id)     // 买家菜单
{
    while(true)
    {
        system("cls");
        cout << "==============================================================================" << endl;
        cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.返回" << endl;
        cout << "==============================================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "查看商品列表" << endl;
                ShowBuyCommodity(user_id);
                break;
            case 2:
                cout << "购买商品" << endl;
                BuyCommodity(user_id);
                break;
            case 3:
                cout << "搜索商品" << endl;
                break;
            case 4:
                cout << "查看历史订单" << endl;
                break;
            case 5:
                cout << "返回" << endl;
                return;
            default:
                cout << "输入错误" << endl;
                break;
        }
    }
}

void PersonalInfo(string user_id)    // 个人信息
{
    while(true)
    {
        system("cls");
        cout << "==============================================================================" << endl;
        cout << "1.查看个人信息 2.修改个人信息 3.充值 4.返回" << endl;
        cout << "==============================================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "查看个人信息" << endl;
                ShowPersonalInfo(user_id);
                break;
            case 2:
                cout << "修改个人信息" << endl;
                ModifyPersonalInfo(user_id);
                break;
            case 3:
                cout << "充值" << endl;
                Recharge(user_id);
                break;
            case 4:
                cout << "返回" << endl;
                return;
            default:
                cout << "输入错误" << endl;
                break;
        }
        system("pause");
    }
}

void ShowPersonalInfo(string user_id)   // 查看个人信息
{
    system("cls");
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            cout << "用户名：" << it->username << endl;
            cout << "密码：" << it->password << endl;
            cout << "地址：" << it->adderss << endl;
            cout << "电话：" << it->phone << endl;
            cout << "余额：" << it->balance << endl;
            return;
        }
    }
}

void ModifyPersonalInfo(string user_id)     // 修改个人信息
{
    while (true) {
        system("cls");
        int option;
        cout << "1.修改用户名 2.修改密码 3.修改地址 4.修改电话 5.返回" << endl;
        cin >> option;
        switch (option) {
            case 1:
                cout << "修改用户名" << endl;
                ModifyUsername(user_id);
                break;
            case 2:
                cout << "修改密码" << endl;
                ModifyPassword(user_id);
                break;
            case 3:
                cout << "修改地址" << endl;
                ModifyAddress(user_id);
                break;
            case 4:
                cout << "修改电话" << endl;
                ModifyPhone(user_id);
                break;
            case 5:
                cout << "返回" << endl;
                return;
            default:
                cout << "输入错误" << endl;
                break;
        }
        system("pause");
    }
}
void ModifyUsername(string user_id)     // 修改用户名
{
    string username;
    cout << "请输入新的用户名：";
    cin >> username;
    if (check(username))
    {
        cout << "用户名已存在" << endl;
        return;
    }
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->username = username;
            cout << "修改成功" << endl;
            UpdateUser();
            return;
        }
    }
}

void ModifyPassword(string user_id)     // 修改密码
{
    string password;
    cout << "请输入新的密码：";
    cin >> password;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->password = password;
            cout << "修改成功" << endl;
            UpdateUser();
            return;
        }
    }
}

void ModifyAddress(string user_id)      // 修改地址
{
    string address;
    cout << "请输入新的地址：";
    cin >> address;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->adderss = address;
            cout << "修改成功" << endl;
            UpdateUser();
            return;
        }
    }
}

void ModifyPhone(string user_id)        // 修改电话
{
    string phone;
    cout << "请输入新的电话：";
    cin >> phone;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->phone = phone;
            cout << "修改成功" << endl;
            UpdateUser();
            return;
        }
    }
}

void Recharge(string user_id)
{
    system("cls");
    int money;
    cout << "请输入充值金额：";
    cin >> money;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->balance += money;
            cout << "充值成功" << endl;
            UpdateUser();
            return;
        }
    }
}