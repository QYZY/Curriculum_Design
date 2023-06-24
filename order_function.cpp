//
// Created by wangh on 2023/6/24.
//
# include <iostream>
# include <string>
# include <fstream>
# include <vector>
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
    cout <<"订单编号\t商品编号\t商品名称\t商品价格\t卖家\t\t订单时间" << endl;
    for (vector<Order>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        if (it->buyer == user_id)
        {
            for (vector<Commodity>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
            {
                if (it->commodity_id == it1->id)
                {
                    cout << it->order_id << "\t\t" << it->commodity_id << "\t\t" << it1->name << "\t\t" << it->price << "\t\t" << it->seller << "\t\t" << it->order_time << endl;
                }
            }
        }
    }
    cout << "=======================================================================================================" << endl;
    system("pause");
    return;

}

void ShowMySellOrder(string user_id)
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             我的出售订单                                          ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << "订单编号\t商品编号\t商品名称\t商品价格\t买家\t\t订单时间" << endl;
    for (vector<Order>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        if (it->seller == user_id)
        {
            for (vector<Commodity>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
            {
                if (it->commodity_id == it1->id)
                {
                    cout << it->order_id << "\t\t" << it->commodity_id << "\t\t" << it1->name << "\t\t" << it->price << "\t\t" << it->buyer << "\t\t" << it->order_time << endl;
                }
            }
        }
    }
    cout << "=======================================================================================================" << endl;
    system("pause");
    return;
}

