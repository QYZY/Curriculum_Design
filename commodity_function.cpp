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

extern vector<User> v;     // �û���Ϣ
extern vector<Commodity> v1;   // ��Ʒ��Ϣ
extern vector<Order> v2;   // ������Ϣ

extern int U_id;    // �û�id
extern int C_id;    // ��Ʒid
extern int O_id;    // ����id

string GetcurTime()    // ��ȡ��ǰʱ��
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

void PostCommodity(string username)         // ������Ʒ
{
    system("cls");
    Commodity commodity;
    commodity.id = 'C' + to_string(C_id);
    commodity.seller = username;
    commodity.buyer = "";
    commodity.status = "����";
    cout << "��������Ʒ���ƣ�";
    cin >> commodity.name;
    cout << "��������Ʒ�۸�";
    cin >> commodity.price;
    cout << "��������Ʒ������";
    cin >> commodity.description;
    commodity.added_time = GetcurTime();
    cout << "�����ɹ�" << endl;
    UpdateConfig();
    C_id++;
    v1.push_back(commodity);
    UpdateCommodity();
    system("pause");
    return;
}

void ShowMyCommodity(string username)       // �鿴�ҵ���Ʒ
{
    system("cls");
    cout << left << setw(10) << "��Ʒid" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ�۸�" << setw(20) << "����ʱ��"  << setw(10) << "��Ʒ״̬" << endl;
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

void ModifyCommodity(string username)       // �޸���Ʒ��Ϣ
{
    system("cls");
    string id;
    cout << "������Ҫ�޸ĵ���Ʒid��";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == username)
        {
            cout << "**************��Ʒ��Ϣ**************" << endl;
            cout << "��Ʒid��" << it->id << endl;
            cout << "��Ʒ���ƣ�" << it->name << endl;
            cout << "��Ʒ�۸�" << it->price << endl;
            cout << "��Ʒ������" << it->description << endl;
            cout << "************************************" << endl;
            cout << "�������µ���Ʒ���ƣ�";
            cin >> it->name;
            cout << "�������µ���Ʒ�۸�";
            cin >> it->price;
            cout << "�������µ���Ʒ������";
            cin >> it->description;
            cout << "�޸ĳɹ�" << endl;
            UpdateCommodity();
            system("pause");
            return;
        }
    }
    cout << "��Ʒ�����ڻ�����Ȩ�޸�" << endl;
    system("pause");
    return;

}

void RemoveCommodity(string username)       // �¼���Ʒ
{
system("cls");
    string id;
    cout << "������Ҫ�¼ܵ���Ʒid��";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == username)
        {
            it->status = "���¼�";
            cout << "�¼ܳɹ�" << endl;
            UpdateCommodity();
            system("pause");
            return;
        }
    }
    cout << "��Ʒ�����ڻ�����Ȩ����" << endl;
    system("pause");
    return;

}

void ShowBuyCommodity(string username)      // �鿴�ɹ�����Ʒ
{
    system("cls");
    cout << left << setw(10) << "��Ʒid" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ�۸�" << setw(20) << "����ʱ��"  << setw(10) << "��Ʒ״̬" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->status == "����" && it->seller != username)
        {
            cout << left << setw(10) << it->id << setw(10) << it->name << setw(10) << it->price << setw(20) << it->added_time << setw(10) << it->status << endl;
        }
    }
    system("pause");
    return;
}

void BuyCommodity(string username)      // ������Ʒ
{
    system("cls");
    string id;
    cout << "������Ҫ�������Ʒid��";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->status == "����" && it->seller != username)
        {
            // ֧��
            for (vector<User>::iterator it1 = v.begin(); it1 != v.end(); it1++)
            {
                if (it1->username == username)
                {
                    if (it1->balance < it->price)
                    {
                        cout << "���㣬����ʧ��" << endl;
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
            it->status = "���۳�";
            cout << "����ɹ�" << endl;
            UpdateCommodity();
            system("pause");
            return;
        }
    }
    cout << "��Ʒ�����ڻ����¼�" << endl;
    system("pause");
    return;
}