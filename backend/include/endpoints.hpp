#ifndef ENDPOINTS_HPP
#define ENDPOINTS_HPP

#include <string>
#include <optional>
#include "database.hpp"

/*
 * Интерфейс, который описывает HTTP-эндпоинты, к которым будет обращаться Telegram-бот. (/banUser, /warnUser, other..)
 */

class Endpoints
{
public:
    virtual ~Endpoints() = default;

    // --- Ban ---
    virtual std::string banUser(const std::string& adminToken, long targerUserID, const std::string& reason) = 0;
    virtual std::string unBanUser(const std::string& adminToken, long targerUserID) = 0;

    // --- Warn ---
    virtual std::string warnUser(const std::string& adminToken, long targetUserID) = 0;
    virtual std::string unWarnUser(const::std::string& adminToken, long targetUserID) = 0;

    // --- Mute ---
    virtual std::string muteUser(const std::string& adminToken, long targetUserID, int minutes) = 0;
    virtual std::string unMuteUser(const std::string& adminToken, long targetUserID) = 0;

    // --- Activity ---
    virtual std::string incrementActivity(long userID) = 0;
    virtual std::string getActivityPoints(long userID) = 0;

    // --- Role ---
    virtual std::string setRole(const std::string& adminToken, long targetUserID, const std::string& role) = 0;
    virtual std::string getRole(long userID) = 0;

    // --- Announce ---
    virtual std::string announce(const std::string& adminToken, const std::string& message) = 0;

    // --- Vote ---
    virtual std::string createVote(const std::string& adminToken, const std::string& question, const std::vector<std::string>& options) = 0;
    virtual std::string vote(const std::string& adminToken, long userID, int option) = 0;

    // --- Logs ---
    virtual std::string getLogs(const std::string& adminToken) = 0;
};

#endif // ENDPOINTS_HPP