#pragma once

#include "IRepository.h"
#include "User.h"

class IUserRepository : public IRepository<User>
{
public:
    virtual bool AllVerification(std::string login, std::string password) = 0;
    virtual bool loginVerification(std::string login) = 0;
    virtual bool passwordVerification(std::string password) = 0;
    virtual int createId() = 0;
    virtual User userData(std::string login, std::string password) = 0;
    virtual User getDataUserById(int id) = 0;
    virtual User* getById(int id) = 0;
    virtual User* getByLogin(const std::string& login) = 0;
};
