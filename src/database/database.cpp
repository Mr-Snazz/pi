#include <stdexcept>

#include <sqlite3.h>

#include "database/database.hpp"

constexpr const char* CreateEventTableQuery =
    "CREATE TABLE IF NOT EXISTS EVENTS ("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "NAME TEXT NOT NULL, "
    "PINS_TO_TRIGGER TEXT NOT NULL);";

constexpr const char* FailedToOpenDatabaseError = "Failed to open or create database file\n";

constexpr const char* FailedToExecuteCreationQueryError = "Failed to execute creation query when creating table\n";

sqlite3* DB;

void SPI::Database::Initialize()
{
    if (sqlite3_open("databases/test.db", &DB) != SQLITE_OK) throw std::runtime_error(FailedToOpenDatabaseError);

    char* ErrorMessage{nullptr};
    if (sqlite3_exec(DB, CreateEventTableQuery, nullptr, 0, &ErrorMessage) != SQLITE_OK) {
        sqlite3_free(ErrorMessage);
        throw std::runtime_error(FailedToExecuteCreationQueryError);
    }

    const char* Query =
    "INSERT INTO EVENTS (NAME, PINS_TO_TRIGGER) "
    "VALUES ('Test', '[1,2,3]');";
    sqlite3_exec(DB, Query, [](void* NotUsed, int argc, char** argv, char** azColName){ return 0; }, 0, &ErrorMessage);
}

void SPI::Database::FreeResources()
{
    sqlite3_close(DB);
}


