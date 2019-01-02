#include "CApp.h"
#include <sys/stat.h>

// HELPER FUNCTIONS

bool fileExists(const std::string& filename)
{
    struct stat buf;
    return stat(filename.c_str(), &buf) != -1;
}

// settings does not include sections at the moment, it's just simple key=value pairs on each line

bool CApp::SettingsInit()
{
    std::cout << "Checking for existing settings file..." << std::endl;
    if (fileExists(SettingsFileName))
    {
        std::cout << "Settings file exists, parsing..." << std::endl;
        SettingsFileStream.open(SettingsFileName);
    }
    else
    {
        std::cout << "Settings file does not exist, creating new one with default settings." << std::endl;
        CurrentSettings = DefaultSettings;
        SettingsSave();
    }

    return true;
}

bool CApp::SettingsSave()
{
    if (!SettingsFileStream.is_open())
        SettingsFileStream.open(SettingsFileName);
    // loop through current settings, essentially a foreach
    for (auto const& [key, val] : CurrentSettings)
    {
        SettingsFileStream << key << ':' << val << std::endl;
        std::cout << "WRITING: " << key << ':' << val << std::endl;
    }
    return true;
}
