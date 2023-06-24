//
// Created by wangh on 2023/6/20.
//
# include <iostream>
# include <string>
# include <fstream>
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



int check(string username)      // ����û����Ƿ����
{
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username)
            return 1;
    }
    return 0;
}

void Register()     // �û�ע��
{
    system("cls");
    User user;
    user.id= 'U' + to_string(U_id);
    user.adderss = "";
    user.phone = "";
    user.balance = 0;
    cout << "�����������û�����";
    cin >> user.username;
    while (check(user.username))
    {
        cout << "���û����Ѵ��ڣ����������룺";
        cin >> user.username;
    }
    cout << "�������������룺";
    cin >> user.password;
    cout << "ע��ɹ�" << endl;

    // ����User.txt
    v.push_back(user);
    UpdateUser();


    // ����Config.txt
    U_id++;
    UpdateConfig();
    return;
}

void Login()        // �û���¼
{
    system("cls");
    string username;
    string passwd;
    cout << "�����������û�����";
    cin >> username;
    cout << "�������������룺";
    cin >> passwd;
    int flag = 0;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username && it->password == passwd)
        {
            flag = 1;
            cout << "��¼�ɹ�" << endl;
            cout << "��ӭ����" << username << endl;
            UserMenu(username);
            return;
        }

    }
    cout << "�û������������" << endl;
    return;
}

void UserMenu(string username)      // �û��˵�
{
    string user_id;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->username == username)
        {
            user_id = it->id;
            break;
        }
    }
    while(true) {
        system("cls");
        cout << "======================================================" << endl;
        cout << "1.�������  2.��������  3.������Ϣ  4.�˳���¼" << endl;
        cout << "======================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "�������" << endl;
                BuyerMenu(user_id);
                break;
            case 2:
                cout << "��������" << endl;
                SellerMenu(user_id);
                break;
            case 3:
                cout << "������Ϣ" << endl;
                PersonalInfo(user_id);
                break;
            case 4:
                cout << "�˳���¼" << endl;
                return;
            default:
                cout << "�������" << endl;
                break;
        }
        system("pause");
    }


}

void SellerMenu(string user_id)        // ���Ҳ˵�
{
    while(true) {
        system("cls");
        cout << "==============================================================================" << endl;
        cout << "1.��Ʒ�ϼ�  2.�鿴������Ʒ  3.�޸���Ʒ��Ϣ  4.��Ʒ�¼�  5.�鿴��ʷ����  6. ����" << endl;
        cout << "==============================================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "��Ʒ�ϼ�" << endl;
                PostCommodity(user_id);
                break;
            case 2:
                cout << "�鿴������Ʒ" << endl;
                ShowMyCommodity(user_id);
                break;
            case 3:
                cout << "�޸���Ʒ��Ϣ" << endl;
                ModifyCommodity(user_id);
                break;
            case 4:
                cout << "��Ʒ�¼�" << endl;
                RemoveCommodity(user_id);
                break;
            case 5:
                cout << "�鿴��ʷ����" << endl;
                break;
            case 6:
                cout << "����" << endl;
                return;
            default:
                cout << "�������" << endl;
                break;
        }
    }
}

void BuyerMenu(string user_id)     // ��Ҳ˵�
{
    while(true)
    {
        system("cls");
        cout << "==============================================================================" << endl;
        cout << "1.�鿴��Ʒ�б� 2.������Ʒ 3.������Ʒ 4.�鿴��ʷ���� 5.����" << endl;
        cout << "==============================================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "�鿴��Ʒ�б�" << endl;
                ShowBuyCommodity(user_id);
                break;
            case 2:
                cout << "������Ʒ" << endl;
                BuyCommodity(user_id);
                break;
            case 3:
                cout << "������Ʒ" << endl;
                break;
            case 4:
                cout << "�鿴��ʷ����" << endl;
                break;
            case 5:
                cout << "����" << endl;
                return;
            default:
                cout << "�������" << endl;
                break;
        }
    }
}

void PersonalInfo(string user_id)    // ������Ϣ
{
    while(true)
    {
        system("cls");
        cout << "==============================================================================" << endl;
        cout << "1.�鿴������Ϣ 2.�޸ĸ�����Ϣ 3.��ֵ 4.����" << endl;
        cout << "==============================================================================" << endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "�鿴������Ϣ" << endl;
                ShowPersonalInfo(user_id);
                break;
            case 2:
                cout << "�޸ĸ�����Ϣ" << endl;
                ModifyPersonalInfo(user_id);
                break;
            case 3:
                cout << "��ֵ" << endl;
                Recharge(user_id);
                break;
            case 4:
                cout << "����" << endl;
                return;
            default:
                cout << "�������" << endl;
                break;
        }
        system("pause");
    }
}

void ShowPersonalInfo(string user_id)   // �鿴������Ϣ
{
    system("cls");
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            cout << "�û�����" << it->username << endl;
            cout << "���룺" << it->password << endl;
            cout << "��ַ��" << it->adderss << endl;
            cout << "�绰��" << it->phone << endl;
            cout << "��" << it->balance << endl;
            return;
        }
    }
}

void ModifyPersonalInfo(string user_id)     // �޸ĸ�����Ϣ
{
    while (true) {
        system("cls");
        int option;
        cout << "1.�޸��û��� 2.�޸����� 3.�޸ĵ�ַ 4.�޸ĵ绰 5.����" << endl;
        cin >> option;
        switch (option) {
            case 1:
                cout << "�޸��û���" << endl;
                ModifyUsername(user_id);
                break;
            case 2:
                cout << "�޸�����" << endl;
                ModifyPassword(user_id);
                break;
            case 3:
                cout << "�޸ĵ�ַ" << endl;
                ModifyAddress(user_id);
                break;
            case 4:
                cout << "�޸ĵ绰" << endl;
                ModifyPhone(user_id);
                break;
            case 5:
                cout << "����" << endl;
                return;
            default:
                cout << "�������" << endl;
                break;
        }
        system("pause");
    }
}
void ModifyUsername(string user_id)     // �޸��û���
{
    string username;
    cout << "�������µ��û�����";
    cin >> username;
    if (check(username))
    {
        cout << "�û����Ѵ���" << endl;
        return;
    }
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->username = username;
            cout << "�޸ĳɹ�" << endl;
            UpdateUser();
            return;
        }
    }
}

void ModifyPassword(string user_id)     // �޸�����
{
    string password;
    cout << "�������µ����룺";
    cin >> password;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->password = password;
            cout << "�޸ĳɹ�" << endl;
            UpdateUser();
            return;
        }
    }
}

void ModifyAddress(string user_id)      // �޸ĵ�ַ
{
    string address;
    cout << "�������µĵ�ַ��";
    cin >> address;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->adderss = address;
            cout << "�޸ĳɹ�" << endl;
            UpdateUser();
            return;
        }
    }
}

void ModifyPhone(string user_id)        // �޸ĵ绰
{
    string phone;
    cout << "�������µĵ绰��";
    cin >> phone;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->phone = phone;
            cout << "�޸ĳɹ�" << endl;
            UpdateUser();
            return;
        }
    }
}

void Recharge(string user_id)
{
    system("cls");
    int money;
    cout << "�������ֵ��";
    cin >> money;
    for (vector<User>::iterator it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            it->balance += money;
            cout << "��ֵ�ɹ�" << endl;
            UpdateUser();
            return;
        }
    }
}