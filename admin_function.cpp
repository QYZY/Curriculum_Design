//
// Created by wangh on 2023/6/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "menu.h"
#include "config.h"
using namespace std;

extern int U_id;    // �û�id
extern int C_id;    // ��Ʒid
extern int O_id;    // ����id

extern vector<User> v;     // �û���Ϣ
extern vector<Commodity> v1;   // ��Ʒ��Ϣ
extern vector<Order> v2;   // ������Ϣ


void AdminLogin() {
    system("cls");
    ifstream ifs("../data/AdminAccount.txt");
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string username;
    string passwd;
    cout << "���������Ա�û�����";
    cin >> username;
    cout << "���������Ա���룺";
    cin >> passwd;
    string username1;
    string passwd1;
    ifs >> username1;
    ifs >> passwd1;
    if (username == username1 && passwd == passwd1) {
        cout << "��¼�ɹ�" << endl;
        cout << "��ӭ����" << username << endl;
        AdminMenu();
        return;
    }
    else
        cout << "�û������������" << endl;
    ifs.close();
    return;

}

void ShowAdminMenu()
{
    system("cls");
    cout << "***** ��ӭ�������Ա���� *****" << endl;
    cout << "\t1. �鿴������Ʒ" << endl;
    cout << "\t2. ������Ʒ" << endl;
    cout << "\t3. �鿴���ж���" << endl;
    cout << "\t4. �鿴�����û�" << endl;
    cout << "\t5. ɾ���û�" << endl;
    cout << "\t6. �¼���Ʒ" << endl;
    cout << "\t7. �˳���¼" << endl;
}


void AdminMenu()
{
    while(true) {
        ShowAdminMenu();
        int option = 0;
        cout << "����������ѡ��";
        cin >> option;
        while (cin.fail()) {
            cout << "�����������������" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            system("pause");
            system("cls");
            ShowAdminMenu();
            cout << "����������ѡ��";
            cin >> option;

        }
        switch (option) {
            case 1:
                cout << "�鿴������Ʒ" << endl;
                ShowAllCommodity();
                break;
            case 2:
                cout << "������Ʒ" << endl;
                break;
            case 3:
                cout << "�鿴���ж���" << endl;
                ShowAllOrder();
                break;
            case 4:
                cout << "�鿴�����û�" << endl;
                ShowAllUser();
                break;
            case 5:
                cout << "ɾ���û�" << endl;
                DeleteUser();
                break;
            case 6:
                cout << "�¼���Ʒ" << endl;
                DeleteCommodity();
                break;
            case 7:
                cout << "�˳���¼" << endl;
                return;
            default:
                cout << "�����������������" << endl;
                break;
        }
        system("pause");
    }


}

void ShowAllUser()      // ��ʾ�����û���Ϣ
{
    system("cls");
    cout << "==================================================================================================" << endl;
    cout << "==                                        �����û���Ϣ                                          ==" << endl;
    cout << "==================================================================================================" << endl;
    cout << left << setw(15) << "�û�ID" << setw(15) << "�û���" << setw(15) << "����" <<setw(20) << "�û���ַ" << setw(20) << "�û��绰" << setw(15) << "���" << endl;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << left << setw(15) << it->id << setw(15) << it->username << setw(15) << it->password << setw(20) << it->adderss << setw(20) << it->phone << setw(15) << it->balance << endl;
    }
    return;
}

void DeleteUser()
{
    system("cls");
    cout << "***** ɾ���û� *****" << endl;
    cout << "������Ҫɾ�����û�ID��";
    string del_id;
    cin >> del_id;
    int flag = 0;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {

        if (it->id == del_id)
        {
            flag = 1;
            cout << "ɾ���ɹ�" << endl;
            v.erase(it);
        }
    }
    if (flag == 0)
        cout << "�û�������" << endl;

    ofstream ofs("../data/User.txt");
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        ofs << it->id << "," << it->username << "," << it->password << "," << it->adderss << "," << it->phone << "," << it->balance << endl;

    }
    ofs.close();

    return;
}

void ShowAllOrder()
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             ���ж���                                              ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(20) << "����ID" << setw(20) << "��ƷID" << setw(20) << "��Ʒ����" << setw(20) << "��Ʒ�۸�" << setw(10) << "���ID" << setw(10) << "����ID" << setw(20) << "����ʱ��" << endl;
    for (vector<Order>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        for (vector<Commodity>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
        {
            if (it->commodity_id == it1->id)
            {
                cout << left << setw(20) << it->order_id << setw(20) << it->commodity_id << setw(20) << it1->name << setw(20) << it->price << setw(10) << it->buyer << setw(10) << it->seller << setw(20) << it->order_time << endl;
            }
        }
    }
    cout << "=======================================================================================================" << endl;
    return;
}

void ShowAllCommodity()
{
    system("cls");
    cout << "=======================================================================================================" << endl;
    cout << "==                                             ������Ʒ                                              ==" << endl;
    cout << "=======================================================================================================" << endl;
    cout << left << setw(20) << "��Ʒid" << setw(20) << "��Ʒ����" << setw(20) << "��Ʒ�۸�" << setw(30) << "����ʱ��"  << setw(20) << "��Ʒ״̬" << endl;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << left << setw(20) << it->id << setw(20) << it->name << setw(20) << it->price << setw(30) << it->added_time << setw(20) << it->status << endl;
    }
    cout << "=======================================================================================================" << endl;
    return;
}

void DeleteCommodity()       // �¼���Ʒ
{
    system("cls");
    string id;
    cout << "������Ҫ�¼ܵ���Ʒid��";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id)
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