//
// Created by wangh on 2023/6/20.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "menu.h"
#include "config.h"
using namespace std;

vector<User> v;     // �û���Ϣ
vector<Commodity> v1;   // ��Ʒ��Ϣ
vector<Order> v2;   // ������Ϣ


int U_id = 1000;    // �û�id
int C_id = 1000;    // ��Ʒid
int O_id = 1000;    // ����id

void ShowMenu()     // ��ʾ�˵�
{
    cout << "====================================" << endl;
    cout << "==       ��ӭʹ��ѧ������ϵͳ     ==" << endl;
    cout << "==         ��ѡ�����Ĳ���         ==" << endl;
    cout << "====================================" << endl;
    cout << "********** 1.�û���¼ **************" << endl;
    cout << "********** 2.�û�ע�� **************" << endl;
    cout << "********** 3.����Ա��¼ ************" << endl;
    cout << "********** 4.�˳�ϵͳ **************" << endl;
    cout << "====================================" << endl;
}

void init()     // ��ʼ��
{
    // ��ȡ�����ļ�
    ifstream ifs("../data/Config.txt");
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    ifs >> U_id >> C_id >> O_id;
    ifs.close();

    // ��ȡ�û���Ϣ
    ifstream ifs1("../data/User.txt");
    if (!ifs1.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
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

    // ��ȡ��Ʒ��Ϣ
    ifstream ifs2("../data/Commodity.txt");
    if (!ifs2.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
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

    // ��ȡ������Ϣ
    ifstream ifs3("../data/Order.txt");
    if (!ifs3.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
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


void MakeChoice()       // ѡ�����
{
    while(true) {
        system("cls");
        ShowMenu();
        int option = 0;
        cout << "����������ѡ��";
        cin >> option;
        if (cin.fail()) {
            cout << "�����������������" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            system("pause");
            continue;
        }
        switch (option) {
            case 1:
                cout << "�û���¼" << endl;
                Login();
                break;
            case 2:
                cout << "�û�ע��" << endl;
                Register();
                break;
            case 3:
                cout << "����Ա��¼" << endl;
                AdminLogin();
                break;
            case 4:
                cout << "�˳�ϵͳ" << endl;
                Exit();
                break;
            default:
                cout << "�����������������" << endl;
                break;
        }
        system("pause");
    }

}


void Exit()     // �˳�ϵͳ
{
    system("cls");
    cout << "-------------------------------------" << endl;
    cout << "          ��л����ʹ�ã��ټ�    " << endl;
    cout << "-------------------------------------" << endl;
    system("pause");
    exit(0);
}

void UpdateUser()       // ����usr.txt
{
    ofstream ofs("../data/User.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        ofs << v[i].id << "," << v[i].username << "," << v[i].password << "," << v[i].adderss << "," << v[i].phone << "," << v[i].balance << endl;
    }
    ofs.close();
}

void UpdateConfig()     // ����config.txt
{
    ofstream ofs("../data/Config.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    ofs << U_id << endl << C_id << endl << O_id << endl;
    ofs.close();
}

void UpdateCommodity()      // ����commodity.txt
{
    ofstream ofs("../data/Commodity.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
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
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    for (int i = 0; i < v2.size(); ++i)
    {
        ofs << v2[i].order_id << "," << v2[i].commodity_id << "," << v2[i].price <<  v2[i].seller_id << "," << v2[i].buyer_id << "," << v2[i].order_time << endl;
    }
    ofs.close();
}