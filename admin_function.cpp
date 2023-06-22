//
// Created by wangh on 2023/6/22.
//

#include <iostream>
#include <fstream>
#include "menu.h"
#include "config.h"
using namespace std;


extern vector<User> v;     // 用户信息

void AdminLogin() {
    ifstream ifs("../data/AdminAccount.txt");
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    string username;
    string passwd;
    cout << "请输入管理员用户名：";
    cin >> username;
    cout << "请输入管理员密码：";
    cin >> passwd;
    string username1;
    string passwd1;
    ifs >> username1;
    ifs >> passwd1;
    if (username == username1 && passwd == passwd1) {
        cout << "登录成功" << endl;
        cout << "欢迎您，" << username << endl;
        return;
    }
    cout << "用户名或密码错误" << endl;

}