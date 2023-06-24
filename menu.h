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
void DeleteUser();
void ShowAllCommodity();
void ShowAllOrder();
void DeleteCommodity();



// user menu function
void UserMenu(std::string username);
void SellerMenu(std::string user_id);
void BuyerMenu(std::string user_id);
void PersonalInfo(std::string user_id);
void ShowPersonalInfo(std::string user_id);
void ModifyPersonalInfo(std::string user_id);
void ModifyUsername(std::string user_id);
void ModifyPassword(std::string user_id);
void ModifyAddress(std::string user_id);
void ModifyPhone(std::string user_id);
void Recharge(std::string user_id);


// commodity menu function
std::string GetcurTime();
void PostCommodity(std::string user_id);
void ShowMyCommodity(std::string user_id);
void ModifyCommodity(std::string user_id);
void RemoveCommodity(std::string user_id);
void ShowBuyCommodity(std::string user_id);
void BuyCommodity(std::string user_id);

// order menu function
void ShowMyBuyOrder(std::string user_id);
void ShowMySellOrder(std::string user_id);


// simplify function
void UpdateConfig();
void UpdateUser();
void UpdateOrder();
void UpdateCommodity();



#endif //CURRICULUM_DESIGN_MENU_H
