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
void UserMenu(std::string id);
void SellerMenu(std::string id);
void BuyerMenu(std::string id);
void PersonalInfo(std::string id);

// commodity menu function
std::string GetcurTime();
void PostCommodity(std::string id);
void ShowMyCommodity(std::string id);
void ModifyCommodity(std::string id);
void RemoveCommodity(std::string id);
void ShowBuyCommodity(std::string id);
void BuyCommodity(std::string id);


// simplify function
void UpdateConfig();
void UpdateUser();
void UpdateOrder();
void UpdateCommodity();



#endif //CURRICULUM_DESIGN_MENU_H
