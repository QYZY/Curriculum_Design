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

void PostCommodity(string user_id)         // ������Ʒ
{
    system("cls");
    Commodity commodity;
    commodity.id = 'C' + to_string(C_id);
    commodity.seller = user_id;
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

    C_id++;
    UpdateConfig();
    v1.push_back(commodity);
    UpdateCommodity();
    return;
}

void ShowMyCommodity(string user_id)       // �鿴�ҵ���Ʒ
{
    system("cls");
    cout << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(10) << "��Ʒid" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ�۸�" << setw(20) << "����ʱ��"  << setw(10) << "��Ʒ״̬" << endl;
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

void ModifyCommodity(string user_id)       // �޸���Ʒ��Ϣ
{
    system("cls");
    string id;
    cout << "������Ҫ�޸ĵ���Ʒid��";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == user_id)
        {
            while(true)
            {
                system("cls");
                cout << endl;
                cout << "**************��Ʒ��Ϣ**************" << endl;
                cout << left << setw(20) << "��Ʒid��" << setw(20) << it->id << endl;
                cout << left << setw(20) << "��Ʒ���ƣ�" << setw(20) << it->name << endl;
                cout << left << setw(20) << "��Ʒ�۸�" << setw(20) << fixed << setprecision(2) << it->price << endl;
                cout << left << setw(20) << "��Ʒ������" << setw(20) << it->description << endl;
                cout << "************************************" << endl;
                cout << "������Ҫ�޸ĵ���Ϣ��1.��Ʒ���� 2.��Ʒ�۸� 3.��Ʒ���� 4.�˳�" << endl;
                int option;
                cin >> option;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout << "�����������������" << endl;
                    continue;
                }
                switch (option)
                {
                    case 1:
                        cout << "��������Ʒ���ƣ�";
                        cin >> it->name;
                        break;
                    case 2:
                        cout << "��������Ʒ�۸�";
                        cin >> it->price;
                        break;
                    case 3:
                        cout << "��������Ʒ������";
                        cin >> it->description;
                        break;
                    case 4:
                        cout << "�޸ĳɹ�" << endl;
                        return;
                    default:
                        cout << "�����������������" << endl;
                        break;

                }
                UpdateCommodity();
                system("pause");
            }

        }
    }
    cout << "��Ʒ�����ڻ�����Ȩ�޸�" << endl;
    return;

}

void RemoveCommodity(string user_id)       // �¼���Ʒ
{
system("cls");
    string id;
    cout << "������Ҫ�¼ܵ���Ʒid��";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == user_id)
        {
            it->status = "���¼�";
            cout << "�¼ܳɹ�" << endl;
            UpdateCommodity();
            return;
        }
    }
    cout << "��Ʒ�����ڻ�����Ȩ����" << endl;
    return;

}

void ShowBuyCommodity(string user_id)      // �鿴�ɹ�����Ʒ
{
    system("cls");
    cout << endl;
    cout << "========================�ɹ�����Ʒ========================" << endl;
    cout << left << setw(10) << "��Ʒid" << setw(10) << "��Ʒ����" << setw(10)   << "��Ʒ�۸�" << setw(20) << "����ʱ��"  << setw(10) << "��Ʒ״̬" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->status == "����" && it->seller != user_id)
        {
            cout << left << setw(10) << it->id << setw(10) << it->name << setw(10) << fixed << setprecision(2)<< it->price << setw(20) << it->added_time << setw(10) << it->status << endl;
        }
    }
    cout << "===========================================================" << endl;
    return;
}

void BuyCommodity(string user_id)      // ������Ʒ
{
    system("cls");
    string id;
    cout << "������Ҫ�������Ʒid��";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->status == "����" && it->seller != user_id)
        {
            // ֧��
            for (vector<User>::iterator it1 = v.begin(); it1 != v.end(); it1++)
            {
                if (it1->id == user_id)
                {
                    if (it1->balance < it->price)
                    {
                        cout << "���㣬����ʧ��" << endl;
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
            it->status = "���۳�";
            cout << "����ɹ�" << endl;
            UpdateCommodity();
            return;
        }
    }
    cout << "��Ʒ�����ڻ����¼�" << endl;
    return;
}

void SearchCommodity()      // ������Ʒ
{
    system("cls");
    string name;
    cout << "������Ҫ��������Ʒ���ƣ�";
    cin >> name;

    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if ( (it->name).find(name) != string::npos )
        {
            cout << endl;
            cout << "**************��Ʒ��Ϣ**************" << endl;
            cout << left << setw(10) <<"����" << setw(10) << it -> name << endl;
            cout << left << setw(10) <<"�۸�" << setw(10) << fixed << setprecision(2) <<it -> price << endl;
            cout << left << setw(10) <<"����" << setw(10) << it -> description << endl;
            cout << left << setw(10) <<"����ʱ��" << setw(10) << it -> added_time << endl;
            cout << left << setw(10) <<"״̬" << setw(10) << it -> status << endl;
            cout << left << setw(10) <<"����" << setw(10) << it -> seller << endl;
            cout << "************************************" << endl;
        }
    }

    return;
}