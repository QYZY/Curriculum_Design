//
// Created by wangh on 2023/6/22.
//
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <iomanip>
#include "menu.h"
#include "config.h"
using namespace std;

extern vector<User> v;     // 用户信息
extern vector<Commodity> v1;   // 商品信息
extern vector<Order> v2;   // 订单信息

extern int U_id;    // 用户id
extern int C_id;    // 商品id
extern int O_id;    // 订单id

string GetcurTime()    // 获取当前时间
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string curTime = to_string(1900 + ltm->tm_year) + "-" +
                        to_string(1 + ltm->tm_mon) + "-" +
                        to_string(ltm->tm_mday) +" " +
                        to_string(ltm->tm_hour) + ":" +
                        to_string(ltm->tm_min) + ":" +
                        to_string(ltm->tm_sec);
    return curTime;
}

void PostCommodity(string username)         // 发布商品
{
    system("cls");
    Commodity commodity;
    commodity.id = 'C' + to_string(C_id);
    commodity.seller = username;
    commodity.buyer = "";
    commodity.status = "在售";
    cout << "请输入商品名称：";
    cin >> commodity.name;
    cout << "请输入商品价格：";
    cin >> commodity.price;
    cout << "请输入商品描述：";
    cin >> commodity.description;
    commodity.added_time = GetcurTime();
    cout << "发布成功" << endl;
    UpdateConfig();
    C_id++;
    v1.push_back(commodity);
    UpdateCommodity();
    system("pause");
    return;
}

void ShowMyCommodity(string username)       // 查看我的商品
{
    system("cls");
    cout << left << setw(10) << "商品id" << setw(10) << "商品名称" << setw(10) << "商品价格" << setw(20) << "发布时间"  << setw(10) << "商品状态" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->seller == username)
        {
            cout << left << setw(10) << it->id << setw(10) << it->name << setw(10) << it->price << setw(20) << it->added_time << setw(10) << it->status << endl;
        }
    }
    system("pause");
    return;
}

void ModifyCommodity(string username)       // 修改商品信息
{
    system("cls");
    string id;
    cout << "请输入要修改的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == username)
        {
            cout << "**************商品信息**************" << endl;
            cout << "商品id：" << it->id << endl;
            cout << "商品名称：" << it->name << endl;
            cout << "商品价格：" << it->price << endl;
            cout << "商品描述：" << it->description << endl;
            cout << "************************************" << endl;
            cout << "请输入新的商品名称：";
            cin >> it->name;
            cout << "请输入新的商品价格：";
            cin >> it->price;
            cout << "请输入新的商品描述：";
            cin >> it->description;
            cout << "修改成功" << endl;
            UpdateCommodity();
            system("pause");
            return;
        }
    }
    cout << "商品不存在或您无权修改" << endl;
    system("pause");
    return;

}

void RemoveCommodity(string username)       // 下架商品
{
system("cls");
    string id;
    cout << "请输入要下架的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == username)
        {
            it->status = "已下架";
            cout << "下架成功" << endl;
            UpdateCommodity();
            system("pause");
            return;
        }
    }
    cout << "商品不存在或您无权操作" << endl;
    system("pause");
    return;

}

void ShowBuyCommodity(string username)      // 查看可购买商品
{
    system("cls");
    cout << left << setw(10) << "商品id" << setw(10) << "商品名称" << setw(10) << "商品价格" << setw(20) << "发布时间"  << setw(10) << "商品状态" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->status == "在售" && it->seller != username)
        {
            cout << left << setw(10) << it->id << setw(10) << it->name << setw(10) << it->price << setw(20) << it->added_time << setw(10) << it->status << endl;
        }
    }
    system("pause");
    return;
}

void BuyCommodity(string username)      // 购买商品
{
    system("cls");
    string id;
    cout << "请输入要购买的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->status == "在售" && it->seller != username)
        {
            // 支付
            for (vector<User>::iterator it1 = v.begin(); it1 != v.end(); it1++)
            {
                if (it1->username == username)
                {
                    if (it1->balance < it->price)
                    {
                        cout << "余额不足，购买失败" << endl;
                        system("pause");
                        return;
                    }
                    else
                    {
                        it1->balance -= it->price;

                        UpdateUser();
                        Order order;
                        order.order_id = 'O' + to_string(O_id);
                        order.commodity_id = it->id;
                        order.price = it->price;
                        order.seller_id= it->seller;
                        order.buyer_id = it1->id;
                        order.order_time = GetcurTime();

                        O_id++;
                        v2.push_back(order);
                        UpdateOrder();
                        break;
                    }
                }
            }

            it->buyer = username;
            it->status = "已售出";
            cout << "购买成功" << endl;
            UpdateCommodity();
            system("pause");
            return;
        }
    }
    cout << "商品不存在或已下架" << endl;
    system("pause");
    return;
}