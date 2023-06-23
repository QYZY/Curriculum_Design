//
// Created by wangh on 2023/6/20.
//


#ifndef CURRICULUM_DESIGN_MENU_H
#define CURRICULUM_DESIGN_MENU_H


// main menu function
void ShowMenu();
void MakeChoice();
void init();
void Login();
void Register();
void AdminLogin();
void Exit();


// admin menu function
void AdminMenu();
void ShowAllUser();
void AddUser();
void DeleteUser();
void ModifyUser();


// user menu function
void UserMenu(std::string username);
void SellerMenu(std::string user_id);
void BuyerMenu(std::string user_id);
void PersonalInfo(std::string user_id);

// commodity menu function
std::string GetcurTime();
void PostCommodity(std::string user_id);
void ShowMyCommodity(std::string user_id);
void ModifyCommodity(std::string user_id);
void RemoveCommodity(std::string user_id);
void ShowBuyCommodity(std::string user_id);
void BuyCommodity(std::string user_id);


// simplify function
void UpdateConfig();
void UpdateUser();
void UpdateOrder();
void UpdateCommodity();



#endif //CURRICULUM_DESIGN_MENU_H
