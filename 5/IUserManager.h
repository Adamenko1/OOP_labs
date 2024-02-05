#pragma once
#include "User.h"

__interface IUserManager
{
public:
    void Registration(User& user);
    void Authorization(User& user);
    void signIn(User& user);
    void signOut(User& user);
    bool isAuthorized();
};