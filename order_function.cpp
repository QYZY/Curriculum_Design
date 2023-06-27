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
    cout << left << setw(15) << "�������" << setw(15) << "��Ʒ���" << setw(20) << "��Ʒ����" << setw(15) << "��Ʒ�۸�" << setw(15) << "����" << setw(20) << "����ʱ��" << endl;
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
    cout << "==                                             �ҵĳ��۶���                                          ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(15) << "�������" << setw(15) << "��Ʒ���" << setw(20) << "��Ʒ����" << setw(15) << "��Ʒ�۸�" << setw(15) << "���" << setw(20) << "����ʱ��" << endl;
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

