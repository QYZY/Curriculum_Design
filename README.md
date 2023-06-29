# Curriculum_Design
C语言课程设计

# 实验名称：基于C++的简易二手交易平台设计与实现
## 一、实验目的
程序设计语言课程注重边学边练，但由于课堂教学和实验的学时有限，练习的深度受到一定的限制。课程设计比教学实验复杂，涉及的深度广，更加接近实用。
本课程设计是大学阶段的第一次课程设计，通过本次实习，对C语言程序设计进行一次全面的综合训练，加强学生的动手力和程序设计能力，培养学生运用所学知识来解决实际问题的能力。最终目标是通过这种形式，帮助学生系统地掌握该门程的主要内容，更好地完成教学任务，为学习后续课程和进行毕业设计作好准备。

## 二、实验环境
操作系统：Windows 11
编程语言：C++
集成开发环境：CLion 2023.1.4
## 三、实验内容
1. 系统需求分析
   本系统是一个二手交易平台，主要包括以下功能：

* 用户注册和登录
* 商品发布和购买
* 订单管理
* 用户信息管理
* 系统配置管理
2. 系统设计

本项目中采用了结构体来存储用户、商品和订单等关键信息。具体结构体包括：

User结构体：包括用户的id、用户名、密码、地址、电话和账户余额等信息；
```c++
struct User     // 用户信息
{
    string id;
    string username;
    string password;
    string address;
    string phone;
    double balance;
};
```
Commodity结构体：包括商品的id、名称、价格、添加时间、卖家信息、买家信息、状态和描述等信息；
```c++
struct Commodity     // 商品信息
{
    string id;
    string name;
    double price;
    string added_time;
    string seller;
    string buyer;
    string status;
    string description;
};
```
Order结构体：包括订单号、商品信息、价格、卖家信息、买家信息和下单时间等信息。
```c++
struct Order     // 订单信息
{
    string order_id;
    string commodity_id;
    double price;
    string seller;
    string buyer;
    string order_time;
};
```


3. 系统实现
   本系统主要采用了C++语言进行开发，使用了STL容器和文件存储技术来管理数据。具体实现过程如下：

1) 系统初始化
   在程序开始运行时，会调用init()函数对系统进行初始化，包括读取配置文件（Config.txt）、加载用户数据（User.txt）、商品数据（Commodity.txt）和订单数据（Order.txt）等。其中，配置文件中保存了管理员账号和密码等重要信息。
```c++
void init()     // 初始化
{
    // 读取配置文件
    ifstream ifs("../data/Config.txt");
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    ifs >> U_id >> C_id >> O_id;
    ifs.close();

    // 读取用户信息
    ifstream ifs1("../data/User.txt");
    if (!ifs1.is_open())
    {
        cout << "文件打开失败" << endl;
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
        user.address = str;
        getline(ss, str, ',');
        user.phone = str;
        getline(ss, str, ',');
        user.balance = stod(str);
        v.push_back(user);
    }
    ifs1.close();
    ...
}
```
2) 用户注册和登录
   当用户打开程序后，首先需要选择登录或注册功能。如果是注册，则需要输入用户名、密码信息，并将其保存在User.txt文件中。如果是登录，则需要输入用户名和密码进行验证，验证通过后则进入用户菜单界面。
```c++
void Register()     // 用户注册
{
    system("cls");
    User user;
    user.id= 'U' + to_string(U_id);
    user.address = "";
    user.phone = "";
    user.balance = 0;
    cout << "请输入您的用户名：";
    cin >> user.username;
    while (check(user.username))
    {
        cout << "该用户名已存在，请重新输入：";
        cin >> user.username;
    }
    cout << "请输入您的密码：";
    cin >> user.password;
    cout << "注册成功" << endl;

    // 更新User.txt
    v.push_back(user);
    UpdateUser();


    // 更新Config.txt
    U_id++;
    UpdateConfig();
    return;
}

```

3) 商品发布和购买
   在商品发布功能中，用户可以输入商品名称、价格、描述等信息，并将其保存在commodity.txt文件中。在购买商品功能中，用户可以搜索并浏览其他用户发布的商品，并选择购买。购买后，系统会自动生成订单并将其保存在order.txt文件中。
```c++
void BuyCommodity(string user_id)      // 购买商品
{
    system("cls");
    string id;
    cout << "请输入要购买的商品id：";
    cin >> id;
    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        if (it->id == id && it->status == "在售" && it->seller != user_id)
        {
            // 支付
            for (auto it1 = v.begin(); it1 != v.end(); it1++)
            {
                if (it1->id == user_id)
                {
                    if (it1->balance < it->price)
                    {
                        cout << "余额不足，购买失败" << endl;
                        return;
                    }
                    else
                    {
                        for(auto it2 = v.begin(); it2 != v.end(); it2++)
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
            it->status = "已售出";
            cout << "购买成功" << endl;
            UpdateCommodity();
            return;
        }
    }
    cout << "商品不存在或已下架" << endl;
    return;
}
```
4) 用户信息管理
   在用户信息管理功能中，用户可以查看和修改个人信息，包括用户名、密码、地址、电话和账户余额等。同时，还可以进行充值操作以增加账户余额。
```c++
void ShowPersonalInfo(string user_id)   // 查看个人信息
{
    system("cls");
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            cout << endl;
            cout << "***************个人信息***************" << endl;
            cout << left << setw(10) << "用户名：" << it->username << endl;
            cout << left << setw(10) << "地址：" << it->address << endl;
            cout << left << setw(10) << "电话：" << it->phone << endl;
            cout << left << setw(10) << fixed << setprecision(2) << "余额：" << it->balance << endl;
            cout << "**************************************" << endl;
            return;
        }
    }
}

void ModifyPassword(string user_id)     // 修改密码
{
    string new_password,old_password;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it->id == user_id)
        {
            cout << "请输入旧密码：";
            cin >> old_password;
            if (old_password != it->password)
            {
                cout << "密码错误" << endl;
                return;
            }
            cout << "请输入新密码：";
            cin >> new_password;
            it->password = new_password;
            cout << "修改成功" << endl;
            UpdateUser();
            return;
        }
    }

}
```

5) 系统配置管理
   在系统配置管理功能中，管理员可以登录系统并展示所有用户、删除用户、展示所有商品、展示所有订单和删除商品等操作。

4. 实验结果与分析

通过本次实验，我们成功地完成了基于C++的简易二手交易平台的设计和实现。该系统具有以下优点：

* 采用面向对象编程思想，结构清晰，易于维护和扩展；
* 采用了STL容器和文件存储技术，方便数据管理和持久化存储；

通过对程序的优化和算法的改进，提升了程序的性能表现和响应速度。
然而，该系统也存在一些不足之处，例如：

* 没有引入图形界面，用户体验较差；
* 对于大规模数据的管理，性能可能存在瓶颈；
* 未考虑安全性问题，如数据明文存储、输入。

针对以上不足之处，可以考虑引入图形界面、优化算法和数据结构、加强安全性措施等方式来进一步完善系统。

## 四、实验总结
本次实验通过设计一个基于C++的简易二手交易平台，让学生深入掌握了C++语言的特点和使用方法，同时培养了良好的软件开发思想和实践经验。

在实验过程中，我们掌握了面向对象编程思想、STL容器和文件存储技术、算法优化和数据结构设计等重要技能。通过不断尝试和实践，我们成功地完成了二手交易平台的设计和实现，并深入探讨了如何优化程序性能和提高用户体验等问题。

在今后的学习和工作中，我们将继续加强对C++语言的理解和运用，并不断探索更加高效、安全和可靠的软件开发方法和技术，为实现更加优秀的软件产品而努力奋斗。

> 管理员默认账号：admin   
密码：12345

> 管理员默认账号：admin 密码：12345
