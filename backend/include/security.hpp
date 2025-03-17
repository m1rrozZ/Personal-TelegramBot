#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <string>

class ISecurity
{
public:
    virtual ~ISecurity() = default;

    virtual bool checkAuthToken(const std::string& token) = 0;
    virtual bool isAdmin(const std::string& token) = 0;
    virtual std::string generateAuthToken(long userID) = 0;
};

#endif // SECURITY_HPP
