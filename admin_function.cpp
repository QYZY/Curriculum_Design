//
// Created by wangh on 2023/6/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "menu.h"
#include "config.h"
using namespace std;

extern int U_id;    // 用户id
extern int C_id;    // 商品id
extern int O_id;    // 订单id

extern vector<User> v;     // 用户信息
extern vector<Commodity> v1;   // 商品信息
extern vector<Order> v2;   // 订单信息


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
                ShowAllCommodity();
                break;
            case 2:
                cout << "搜索商品" << endl;
                break;
            case 3:
                cout << "查看所有订单" << endl;
                ShowAllOrder();
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
                DeleteCommodity();
                break;
            case 7:
                cout << "退出登录" << endl;
                return;
            default:
                cout << "输入错误，请重新输入" << endl;
                break;
        }
        system("pause");
    }


}

void ShowAllUser()      // 显示所有用户信息
{
    system("cls");
    cout << "==================================================================================================" << endl;
    cout << "==                                        所有用户信息                                          ==" << endl;
    cout << "==================================================================================================" << endl;
    cout << left << setw(15) << "用户ID" << setw(15) << "用户名" << setw(15) << "密码" <<setw(20) << "用户地址" << setw(20) << "用户电话" << setw(15) << "余额" << endl;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << left << setw(15) << it->id << setw(15) << it->username << setw(15) << it->password << setw(20) << it->adderss << setw(20) << it->phone << setw(15) << it->balance << endl;
    }
    return;
}

void DeleteUser()
{
    system("cls");
    cout << "***** 删除用户 *****" << endl;
    cout << "请输入要删除的用户ID：";
    string del_id;
    cin >> del_id;
    int flag = 0;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {

        if (it->id == del_id)
        {
            flag = 1;
            cout << "删除成功" << endl;
            v.erase(it);
        }
    }
    if (flag == 0)
        cout << "用户不存在" << endl;

    ofstream ofs("../data/User.txt");
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        ofs << it->id << "," << it->username << "," << it->password << "," << it->adderss << "," << it->phone << "," << it->balance << endl;

    }
    ofs.close();

    return;
}

void ShowAllOrder()
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             所有订单                                              ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(20) << "订单ID" << setw(20) << "商品ID" << setw(20) << "商品名称" << setw(20) << "商品价格" << setw(10) << "买家ID" << setw(10) << "卖家ID" << setw(20) << "订单时间" << endl;
    for (vector<Order>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        for (vector<Commodity>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
        {
            if (it->commodity_id == it1->id)
            {
                cout << left << setw(20) << it->order_id << setw(20) << it->commodity_id << setw(20) << it1->name << setw(20) << it->price << setw(10) << it->buyer << setw(10) << it->seller << setw(20) << it->order_time << endl;
            }
        }
    }
    cout << "=======================================================================================================" << endl;
    return;
}

void ShowAllCommodity()
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             所有商品                                              ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(20) << "商品id" << setw(20) << "商品名称" << setw(20) << "商品价格" << setw(30) << "发布时间"  << setw(20) << "商品状态" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << left << setw(20) << it->id << setw(20) << it->name << setw(20) << it->price << setw(30) << it->added_time << setw(20) << it->status << endl;
    }
    cout << "=======================================================================================================" << endl;
    return;
}

void DeleteCommodity()       // 下架商品
{
    system("cls");
    string id;
    cout << "请输入要下架的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id)
        {
            it->status = "已下架";
            cout << "下架成功" << endl;
            UpdateCommodity();
            return;
        }
    }
    cout << "商品不存在或您无权操作" << endl;
    return;

}