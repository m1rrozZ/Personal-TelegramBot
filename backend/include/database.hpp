#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>
#include <optional>
#include <ctime>

struct BanInfo
{
    long userID;
    std::string reason;
    std::time_t banTime;
};

struct WarnInfo
{
    long userID;
    std::string reason;
    std::time_t warnTime;
};

struct LogInfo
{
    long adminInfo;
    std::string action;
    std::time_t timestamp;
};

class IDatabase
{
public:
    virtual ~IDatabase() = default;

    // --- Bans ---
    virtual bool banUser(long userID, const std::string& reason) = 0;
    virtual bool unbanUser(long userID) = 0;
    virtual bool isUserBanned(long userID) = 0;
    virtual std::vector<BanInfo> getBanList() = 0;

    // --- Warns ---
    virtual bool warnUser(long userID, const std::string& reason) = 0;
    virtual bool unwarnUser(long userID) = 0;
    virtual bool cleanWarns(long userID) = 0;

    // --- Muts ---
    virtual bool muteUser(long userID) = 0;
    virtual bool unmuteUser(long userID) = 0;
    virtual bool isUserMuted(long userID) = 0;

    // --- Others ---
    virtual bool incrementActivity(long userID) = 0;
    virtual int getActivityPoints(long userID) = 0;
    virtual bool setRole(long userID, const std::string& role) = 0;
    virtual std::string getRole(long userID) = 0;

    // --- Logs ---
    virtual bool addLog(long adminID, const std::string& action) = 0;
    virtual std::vector<LogInfo> getLogs() = 0;
};

#endif // DATABASE_HPPфъъъхыфвщщал=  ффыф