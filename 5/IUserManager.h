#pragma once
#include "User.h"

__interface IUserManager
{
public:
    void signIn(User& user);
    void signOut(User& user);
    bool isAuthorized();
};