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

extern vector<Commodity> v1;   // 商品信息

extern int U_id;    // 用户id
extern int C_id;    // 商品id
extern int O_id;    // 订单id

string GetcurTime()    // 获取当前时间
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
    commodity.status = "在售";
    cout << "请输入商品名称：";
    cin >> commodity.name;
    cout << "请输入商品价格：";
    cin >> commodity.price;
    cout << "请输入商品描述：";
    cin >> commodity.description;
    commodity.added_time = GetcurTime();
    cout << "发布成功" << endl;
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
    cout << left << setw(10) << "商品id" << setw(10) << "商品名称" << setw(10) << "商品价格" << setw(20) << "发布时间"  << setw(10) << "商品状态" << endl;
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
    cout << "请输入要修改的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == username)
        {
            cout << "**************商品信息**************" << endl;
            cout << "商品id：" << it->id << endl;
            cout << "商品名称：" << it->name << endl;
            cout << "商品价格：" << it->price << endl;
            cout << "商品描述：" << it->description << endl;
            cout << "************************************" << endl;
            cout << "请输入新的商品名称：";
            cin >> it->name;
            cout << "请输入新的商品价格：";
            cin >> it->price;
            cout << "请输入新的商品描述：";
            cin >> it->description;
            cout << "修改成功" << endl;
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
    cout << "商品不存在或您无权修改" << endl;
    system("pause");
    return;

}

void RemoveCommodity(string username)
{
system("cls");
    string id;
    cout << "请输入要下架的商品id：";
    cin >> id;
    for (vector<Commodity>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->seller == username)
        {
            it->status = "已下架";
            cout << "下架成功" << endl;
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
    cout << "商品不存在或您无权操作" << endl;
    system("pause");
    return;

}