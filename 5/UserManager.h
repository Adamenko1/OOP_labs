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

        std::cout << "����� ���������� � ������� �����������\n";
        std::cout << "������� �����: ";
        std::cin >> login;
        if (userRepository->loginVerification(login) == 1) {
            std::cout << "������ ����� ��� �����, ���������� ������\n\n";
            Registration(user);
        }

        std::cout << "������� ������: ";
        std::cin >> password;
        if (userRepository->passwordVerification(password) == 1) {
            std::cout << "������ ������ ��� �����, ���������� ������\n\n";
            Registration(user);
        }

        std::cout << "������� ��� ������������: ";
        std::cin >> name;

        id = userRepository->createId();
        user.setId(id);
        user.setLogin(login);
        user.setPassword(password);
        user.setName(name);
        userRepository->add(user);
        std::cout << "����������� ������ �������!\n\n";
        return;
    }

    void Authorization(User& user) override
    {
        std::string login, password, name;

        std::cout << "������� �����: ";
        std::cin >> login;

        std::cout << "������� ������: ";
        std::cin >> password;
        if (userRepository->AllVerification(login, password) == 1) {
            std::cout << "����������� ������ �������!\n\n";
            user.setLogin(login);
            user.setPassword(password);
            return;
        }
        else {
            std::cout << "������������ ����� ��� ������\n";
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

        // ������ ����������� ����� � ������ �� ��������� �����, �������� ������� � ��������� ��������
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

        // ������ ������������ ����������� ������� � ����
        std::ofstream outputFile(file);
        outputFile << tempFile.rdbuf();
        outputFile.close();

        std::cout << "User has been signed out" << std::endl; // ������������ ����� �� �������
    }

    bool isAuthorized() override
    {
        return currentUser != nullptr;
    }
};