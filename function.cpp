//
// Created by wangh on 2023/6/20.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "menu.h"
#include "config.h"
using namespace std;

vector<User> v;     // 用户信息
vector<Commodity> v1;   // 商品信息
vector<Order> v2;   // 订单信息


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
    // 读取配置文件
    ifstream ifs("../data/Config.txt");
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    ifs >> U_id >> C_id >> O_id;
    ifs.close();

    // 读取用户信息
    ifstream ifs1("../data/User.txt");
    if (!ifs1.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    User user;
    string line;
    while (getline(ifs1, line))
    {
        stringstream ss(line);
        string str;
        getline(ss, str, ',');
        user.id = str;
        getline(ss, str, ',');
        user.username = str;
        getline(ss, str, ',');
        user.password = str;
        getline(ss, str, ',');
        user.adderss = str;
        getline(ss, str, ',');
        user.phone = str;
        getline(ss, str, ',');
        user.balance = stoi(str);
        v.push_back(user);
    }
    ifs1.close();

    // 读取商品信息
    ifstream ifs2("../data/Commodity.txt");
    if (!ifs2.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    Commodity commodity;
    string line1;
    while (getline(ifs2, line1))
    {
        stringstream ss(line1);
        string str;
        getline(ss, str, ',');
        commodity.id = str;
        getline(ss, str, ',');
        commodity.name = str;
        getline(ss, str, ',');
        commodity.price = stod(str);
        getline(ss, str, ',');
        commodity.added_time = str;
        getline(ss, str, ',');
        commodity.seller = str;
        getline(ss, str, ',');
        commodity.buyer = str;
        getline(ss, str, ',');
        commodity.status = str;
        getline(ss, str, ',');
        commodity.description = str;
        v1.push_back(commodity);
    }
    ifs2.close();

    // 读取订单信息
    ifstream ifs3("../data/Order.txt");
    if (!ifs3.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    Order order;
    string line2;
    while (getline(ifs3, line2))
    {
        stringstream ss(line2);
        string str;
        getline(ss, str, ',');
        order.order_id = str;
        getline(ss, str, ',');
        order.commodity_id = str;
        getline(ss, str, ',');
        order.price = stod(str);
        getline(ss, str, ',');
        order.seller_id = str;
        getline(ss, str, ',');
        order.buyer_id = str;
        getline(ss, str, ',');
        order.order_time = str;
        v2.push_back(order);
    }
    ifs3.close();
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

void UpdateUser()       // 更新usr.txt
{
    ofstream ofs("../data/User.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        ofs << v[i].id << "," << v[i].username << "," << v[i].password << "," << v[i].adderss << "," << v[i].phone << "," << v[i].balance << endl;
    }
    ofs.close();
}

void UpdateConfig()     // 更新config.txt
{
    ofstream ofs("../data/Config.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    ofs << U_id << endl << C_id << endl << O_id << endl;
    ofs.close();
}

void UpdateCommodity()      // 更新commodity.txt
{
    ofstream ofs("../data/Commodity.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < v1.size(); ++i)
    {
        ofs << v1[i].id << "," << v1[i].name << "," << v1[i].price << "," << v1[i].added_time << "," << v1[i].seller << "," << v1[i].buyer << "," << v1[i].status << "," << v1[i].description << endl;
    }
    ofs.close();
}
void UpdateOrder()
{
    ofstream ofs("../data/Order.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < v2.size(); ++i)
    {
        ofs << v2[i].order_id << "," << v2[i].commodity_id << "," << v2[i].price <<  v2[i].seller_id << "," << v2[i].buyer_id << "," << v2[i].order_time << endl;
    }
    ofs.close();
}