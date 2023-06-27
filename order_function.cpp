//
// Created by wangh on 2023/6/24.
//
# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <iomanip>
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

void ShowMyBuyOrder(string user_id)
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             我的购买订单                                          ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(15) << "订单编号" << setw(15) << "商品编号" << setw(20) << "商品名称" << setw(15) << "商品价格" << setw(15) << "卖家" << setw(20) << "订单时间" << endl;
    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        if (it->buyer == user_id)
        {
            for (auto it1 = v1.begin(); it1 != v1.end(); it1++)
            {
                if (it->commodity_id == it1->id)
                {
                    cout << left << setw(15) << it->order_id << setw(15) << it->commodity_id << setw(20) << it1->name << setw(15) << fixed << setprecision(2) << it->price << setw(15) << it->seller << setw(20) << it->order_time << endl;
                }
            }
        }
    }
    cout << "=======================================================================================================" << endl;
    return;

}

void ShowMySellOrder(string user_id)
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             我的出售订单                                          ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(15) << "订单编号" << setw(15) << "商品编号" << setw(20) << "商品名称" << setw(15) << "商品价格" << setw(15) << "买家" << setw(20) << "订单时间" << endl;
    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        if (it->seller == user_id)
        {
            for (auto it1 = v1.begin(); it1 != v1.end(); it1++)
            {
                if (it->commodity_id == it1->id)
                {
                    cout << left << setw(15) << it->order_id << setw(15) << it->commodity_id << setw(20) << it1->name << setw(15) << fixed << setprecision(2) <<it->price << setw(15) << it->buyer << setw(20) << it->order_time << endl;
                }
            }
        }
    }
    cout << "=======================================================================================================" << endl;
    return;
}

