#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>

struct Note {
    int id;
    std::string title;
    std::string content;
};

class Database
{
public:
     Database(const std::string& db_name);
    ~Database();

    // Autorisation || Registration
    bool register_user(const std::string& user_id);
    bool userExists(const std::string& user_id);

    // Notes
    bool addNote(const std::string& user_id, const std::string& content);
    std::vector<Note> getNotes(const std::string& user_id);
    bool deleteNote(const std::string& user_id, int note_id);

private:
    void* connection;
};

#endif // DATABASE_HPP