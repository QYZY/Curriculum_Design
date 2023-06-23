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

extern vector<Commodity> v1;   // ��Ʒ��Ϣ

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

void PostCommodity(string username)
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
    ofstream ofs;
    ofs.open("../data/Commodity.txt", ios::out | ios::app);
    ofs << commodity.id << "," << commodity.name << "," << commodity.price << "," << commodity.added_time << "," << commodity.seller << "," << commodity.buyer << "," << commodity.status << "," << commodity.description << endl;
    ofs.close();
    C_id++;
    ofstream ofs1;
    ofs1.open("../data/Config.txt", ios::out);
    ofs1 << U_id << endl << C_id <<endl << O_id << endl;
    ofs1.close();
    v1.push_back(commodity);
    system("pause");
    return;
}

void ShowMyCommodity(string username)
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

void ModifyCommodity(string username)
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
            ofstream ofs;
            ofs.open("../data/Commodity.txt", ios::out);
            for (vector<Commodity>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
            {
                ofs << it1->id << "," << it1->name << "," << it1->price << "," << it1->added_time << "," << it1->seller << "," << it1->buyer << "," << it1->status << "," << it1->description << endl;
            }
            ofs.close();
            system("pause");
            return;
        }
    }
    cout << "��Ʒ�����ڻ�����Ȩ�޸�" << endl;
    system("pause");
    return;

}

void RemoveCommodity(string username)
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
            ofstream ofs;
            ofs.open("../data/Commodity.txt", ios::out);
            for (vector<Commodity>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
            {
                ofs << it1->id << "," << it1->name << "," << it1->price << "," << it1->added_time << "," << it1->seller << "," << it1->buyer << "," << it1->status << "," << it1->description << endl;
            }
            ofs.close();
            system("pause");
            return;
        }
    }
    cout << "��Ʒ�����ڻ�����Ȩ����" << endl;
    system("pause");
    return;

}