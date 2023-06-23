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
void SellerMenu(std::string username);
void BuyerMenu(std::string username);
void PersonalInfo(std::string username);

// commodity menu function
std::string GetcurTime();
void PostCommodity(std::string username);
void ShowMyCommodity(std::string username);
void ModifyCommodity(std::string username);
void RemoveCommodity(std::string username);

#endif //CURRICULUM_DESIGN_MENU_H
