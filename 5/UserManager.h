#pragma once

#include "IUserManager.h"
#include "IUserRepository.h"
#include "iostream"
class UserManager : public IUserManager
{
private:
    User* currentUser;
    IUserRepository* userRepository;
public:

    UserManager(IUserRepository* userRepository) : userRepository(userRepository), currentUser(nullptr)
    {
    }

    void signIn(User& user) override
    {
        currentUser = &user;
    }

    void signOut(User& user) override
    {

        currentUser = nullptr;
        std::cout << "User has been signed out" << std::endl; // Пользователь вышел из системы

    }

    bool isAuthorized() override
    {
        return currentUser != nullptr;
    }
};