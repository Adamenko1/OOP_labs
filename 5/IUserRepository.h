#pragma once

#include "IRepository.h"
#include "User.h"

class IUserRepository : public IRepository<User>
{
public:
    virtual User* getById(int id) = 0;
    virtual User* getByLogin(const std::string& login) = 0;
};
