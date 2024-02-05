#pragma once

#include "IUserManager.h"
#include "IUserRepository.h"
#include "FileUserRepository.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
class UserManager : public IUserManager
{
private:
    User* currentUser;
    IUserRepository* userRepository;
public:

    UserManager(IUserRepository* userRepository) : userRepository(userRepository), currentUser(nullptr)
    {
    }

    void Registration(User& user) override
    {
        int id = 0;
        std::string login, password, name;

        std::cout << "Добро пожаловать в систему регистрации\n";
        std::cout << "Введите логин: ";
        std::cin >> login;
        if (userRepository->loginVerification(login) == 1) {
            std::cout << "Данный логин уже занят, попробуйте другой\n\n";
            Registration(user);
        }

        std::cout << "Введите пароль: ";
        std::cin >> password;
        if (userRepository->passwordVerification(password) == 1) {
            std::cout << "Данный пароль уже занят, попробуйте другой\n\n";
            Registration(user);
        }

        std::cout << "Введите имя пользователя: ";
        std::cin >> name;

        id = userRepository->createId();
        user.setId(id);
        user.setLogin(login);
        user.setPassword(password);
        user.setName(name);
        userRepository->add(user);
        std::cout << "Регистрация прошла успешно!\n\n";
        return;
    }

    void Authorization(User& user) override
    {
        std::string login, password, name;

        std::cout << "Введите логин: ";
        std::cin >> login;

        std::cout << "Введите пароль: ";
        std::cin >> password;
        if (userRepository->AllVerification(login, password) == 1) {
            std::cout << "Авторизация прошла успешно!\n\n";
            user.setLogin(login);
            user.setPassword(password);
            return;
        }
        else {
            std::cout << "неправильные логин или пароль\n";
            Authorization(user);
        }
    }

    void signIn(User& user) override
    {
        currentUser = &user;
        user = userRepository->userData(user.getLogin(), user.getPassword());
        std::ofstream outfile("authorized Users.txt");
        if (outfile.is_open()) outfile << user.getId() << '\n';
        outfile.close();
    }

    void signOut(User& user) override
    {

        currentUser = nullptr;
        int id_to_delete = user.getId();
        std::string file = "authorized Users.txt";
        std::ifstream inputFile(file);
        std::string line;
        std::stringstream tempFile;

        // Чтение содержимого файла и запись во временный буфер, исключая строчку с указанным индексом
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string token;

            std::getline(ss, token, ',');
            int currentIndex = std::stoi(token);

            if (currentIndex != id_to_delete) {
                tempFile << line << std::endl;
            }
        }
        inputFile.close();

        // Запись обновленного содержимого обратно в файл
        std::ofstream outputFile(file);
        outputFile << tempFile.rdbuf();
        outputFile.close();

        std::cout << "User has been signed out" << std::endl; // Пользователь вышел из системы
    }

    bool isAuthorized() override
    {
        return currentUser != nullptr;
    }
};