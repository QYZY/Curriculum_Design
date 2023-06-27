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

void PostCommodity(string user_id)         // 发布商品
{
    system("cls");
    Commodity commodity;
    commodity.id = 'C' + to_string(C_id);
    commodity.seller = user_id;
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

    C_id++;
    UpdateConfig();
    v1.push_back(commodity);
    UpdateCommodity();
    return;
}

void ShowMyCommodity(string user_id)       // 查看我的商品
{
    system("cls");
    cout << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(10) << "商品id" << setw(10) << "商品名称" << setw(10) << "商品价格" << setw(20) << "发布时间"  << setw(10) << "商品状态" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->seller == user_id)
        {
            cout << left << setw(10) << it->id << setw(10) << it->name << setw(10) << fixed << setprecision(2) << it->price << setw(20) << it->added_time << setw(10) << it->status << endl;
        }
    }
    cout << "=======================================================================================================" << endl;
    return;
}

void ModifyCommodity(string user_id)       // 修改商品信息
{
    system("cls");
    string id;
    cout << "请输入要修改的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == user_id)
        {
            while(true)
            {
                system("cls");
                cout << endl;
                cout << "**************商品信息**************" << endl;
                cout << left << setw(20) << "商品id：" << setw(20) << it->id << endl;
                cout << left << setw(20) << "商品名称：" << setw(20) << it->name << endl;
                cout << left << setw(20) << "商品价格：" << setw(20) << fixed << setprecision(2) << it->price << endl;
                cout << left << setw(20) << "商品描述：" << setw(20) << it->description << endl;
                cout << "************************************" << endl;
                cout << "请输入要修改的信息：1.商品名称 2.商品价格 3.商品描述 4.退出" << endl;
                int option;
                cin >> option;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout << "输入错误，请重新输入" << endl;
                    continue;
                }
                switch (option)
                {
                    case 1:
                        cout << "请输入商品名称：";
                        cin >> it->name;
                        break;
                    case 2:
                        cout << "请输入商品价格：";
                        cin >> it->price;
                        break;
                    case 3:
                        cout << "请输入商品描述：";
                        cin >> it->description;
                        break;
                    case 4:
                        cout << "修改成功" << endl;
                        return;
                    default:
                        cout << "输入错误，请重新输入" << endl;
                        break;

                }
                UpdateCommodity();
                system("pause");
            }

        }
    }
    cout << "商品不存在或您无权修改" << endl;
    return;

}

void RemoveCommodity(string user_id)       // 下架商品
{
system("cls");
    string id;
    cout << "请输入要下架的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == user_id)
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

void ShowBuyCommodity(string user_id)      // 查看可购买商品
{
    system("cls");
    cout << endl;
    cout << "========================可购买商品========================" << endl;
    cout << left << setw(10) << "商品id" << setw(10) << "商品名称" << setw(10)   << "商品价格" << setw(20) << "发布时间"  << setw(10) << "商品状态" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->status == "在售" && it->seller != user_id)
        {
            cout << left << setw(10) << it->id << setw(10) << it->name << setw(10) << fixed << setprecision(2)<< it->price << setw(20) << it->added_time << setw(10) << it->status << endl;
        }
    }
    cout << "===========================================================" << endl;
    return;
}

void BuyCommodity(string user_id)      // 购买商品
{
    system("cls");
    string id;
    cout << "请输入要购买的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->status == "在售" && it->seller != user_id)
        {
            // 支付
            for (vector<User>::iterator it1 = v.begin(); it1 != v.end(); it1++)
            {
                if (it1->id == user_id)
                {
                    if (it1->balance < it->price)
                    {
                        cout << "余额不足，购买失败" << endl;
                        return;
                    }
                    else
                    {
                        for(vector<User>::iterator it2 = v.begin(); it2 != v.end(); it2++)
                        {
                            if (it2->id == it->seller)
                            {
                                it2->balance += it->price;
                                it1->balance -= it->price;
                                break;
                            }
                        }
                        UpdateUser();

                        Order order;
                        order.order_id = 'O' + to_string(O_id);
                        order.commodity_id = it->id;
                        order.price = it->price;
                        order.seller= it->seller;
                        order.buyer = it1->id;
                        order.order_time = GetcurTime();


                        v2.push_back(order);
                        UpdateOrder();
                        O_id++;
                        UpdateConfig();
                        break;
                    }
                }
            }

            it->buyer = user_id;
            it->status = "已售出";
            cout << "购买成功" << endl;
            UpdateCommodity();
            return;
        }
    }
    cout << "商品不存在或已下架" << endl;
    return;
}

void SearchCommodity()      // 搜索商品
{
    system("cls");
    string name;
    cout << "请输入要搜索的商品名称：";
    cin >> name;

    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if ( (it->name).find(name) != string::npos )
        {
            cout << endl;
            cout << "**************商品信息**************" << endl;
            cout << left << setw(10) <<"名称" << setw(10) << it -> name << endl;
            cout << left << setw(10) <<"价格" << setw(10) << fixed << setprecision(2) <<it -> price << endl;
            cout << left << setw(10) <<"描述" << setw(10) << it -> description << endl;
            cout << left << setw(10) <<"发布时间" << setw(10) << it -> added_time << endl;
            cout << left << setw(10) <<"状态" << setw(10) << it -> status << endl;
            cout << left << setw(10) <<"卖家" << setw(10) << it -> seller << endl;
            cout << "************************************" << endl;
        }
    }

    return;
}