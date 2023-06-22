//
// Created by wangh on 2023/6/20.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef CURRICULUM_DESIGN_CONFIG_H
#define CURRICULUM_DESIGN_CONFIG_H

struct User     // 用户信息
{
    string id;
    string username;
    string password;
    string adderss;
    string phone;
    double balance;
};

struct Commodity     // 商品信息
{
    string id;
    string name;
    double price;
    string added_time;
    string seller;
    string status;
    string description;
};

struct Order     // 订单信息
{
    string id;
    string buyer;
    string seller;
    string commodity;
    double price;
    string time;
};


#endif //CURRICULUM_DESIGN_CONFIG_H
