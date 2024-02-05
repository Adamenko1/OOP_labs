#include "FileUserRepository.h"
#include "UserManager.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <fstream>

int main()
{
    SetConsoleOutputCP(1251);
    std::ifstream file("authorized Users.txt");
    std::string filePath = "Users.txt";
    std::string answer;

    std::string strh;
    std::string str;

    while (!file.eof()) {
        getline(file, strh);
        str += strh;
        if (!file.eof()) {
            str += '\n';
        }
    }

    std::unique_ptr<IUserRepository> userRepository(new FileUserRepository(filePath));

    std::unique_ptr<UserManager> userManager(new UserManager(userRepository.get()));

    if (str == "\0") { // если файл пустой
        User user(0, "login", "password", "name");

        std::cout << "Вы уже зарегестрированы?\n";
        std::cout << "Введите yes или no: ";
        std::cin >> answer;
        if (answer == "yes") {
            userManager->Authorization(user);
        }
        if (answer == "no") {
            userManager->Registration(user);
        }
        if (answer != "yes" && answer != "no") {
            std::cout << "Я сказал только yes или no \n\n";
            main();
        }

        userManager->signIn(user);

        std::cout << user.getLogin() << '\n';

        bool isAuthorized = userManager->isAuthorized();
        if (isAuthorized)
        {
            std::cout << "User is authorized" << std::endl;
        }
        else {
            std::cout << "User is not authorized" << std::endl;
        }

        std::cout << "вы хотите выйти из системы? (yes или no)" << '\n';
        std::cin >> answer;
        if (answer == "yes") {
            // Sign out the user
            userManager->signOut(user);
            std::cout << "вы вышли из системы, если вы захотите зайти повторно, то Вам нужно будет ввести логин и пароль" << '\n';
        }
        if (answer == "no") {
            return 0;
        }

        return 0;
    }
    else {

        int id = stoi(str);

        User user = userRepository->getDataUserById(id);
        std::cout << "вы хотите выйти из системы? (yes или no)" << '\n';
        std::cin >> answer;
        if (answer == "yes") {
            // Sign out the user
            userManager->signOut(user);
            std::cout << "вы вышли из системы, если вы захотите зайти повторно, то Вам нужно будет ввести логин и пароль" << '\n'; \
            return 0;
        }
        if (answer == "no") {
            return 0;
        }
    }
}