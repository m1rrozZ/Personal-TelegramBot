#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <unordered_map>
#include <ctime>

namespace Utils
{
    std::unordered_map<std::string, std::string> parseUrlParams(const std::string& url);

    void Loginfo(const std::string& message);
    void LogError(const std::string& message);

    std::string formatTimestamp(time_t timestamp);
}

#endif // UTILS_HPP