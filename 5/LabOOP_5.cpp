#include "FileUserRepository.h"
#include "UserManager.h"
#include <windows.h>

/*
Реализация IUserManager и UserRepository с сохранением данных в файл
Приложение должно автоматически авторизовать пользователя, добавлять пользователя, поменять текущего пользователя
*/

int main()
{
    SetConsoleOutputCP(1251);
    std::string filePath = "users.txt";

    std::unique_ptr<IUserRepository> userRepository(new FileUserRepository(filePath));

    std::unique_ptr<UserManager> userManager(new UserManager(userRepository.get()));

    User user(1, "Sasha", "password12345", "Test_for_lab");

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

    // Sign out the user
    userManager->signOut(user);

    return 0;

}