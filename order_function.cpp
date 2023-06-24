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

extern int U_id;    // �û�id
extern int C_id;    // ��Ʒid
extern int O_id;    // ����id

extern vector<User> v;     // �û���Ϣ
extern vector<Commodity> v1;   // ��Ʒ��Ϣ
extern vector<Order> v2;   // ������Ϣ

void ShowMyBuyOrder(string user_id)
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             �ҵĹ��򶩵�                                          ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout <<"�������\t��Ʒ���\t��Ʒ����\t��Ʒ�۸�\t����\t\t����ʱ��" << endl;
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
    cout << "==                                             �ҵĳ��۶���                                          ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << "�������\t��Ʒ���\t��Ʒ����\t��Ʒ�۸�\t���\t\t����ʱ��" << endl;
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

