#ifndef WEBSITE_FILTER_H
#define WEBSITE_FILTER_H
#include <string>
#include <unordered_set>

class WebsiteFilter {
private:
    std::unordered_set<std::string> blockedSites;

public:
    void loadSites(const std::string& filename);
    bool isAllowed(const std::string& domain);
};
#endif