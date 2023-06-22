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


// commodity menu function
std::string GetcurTime();
#endif //CURRICULUM_DESIGN_MENU_H
