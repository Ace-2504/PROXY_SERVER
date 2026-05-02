#include "WebsiteFilter.h"
#include <fstream>
using namespace std;
void WebsiteFilter::loadSites(const string& filename)
{
    ifstream file(filename);
    string site;

    while (file >> site)
    {
        blockedSites.insert(site);
    }

    file.close();
}

bool WebsiteFilter::isAllowed(const string& domain)
{
    for (const auto& site : blockedSites)
    {
        // Case 1: domain name exact match
        if (domain == site)
            return false;

        // Case 2: subdomain match (e.g., www.facebook.com)
        if (domain.size() > site.size())
        {
            size_t pos = domain.size() - site.size();

            if (domain.compare(pos, site.size(), site) == 0 &&
                domain[pos - 1] == '.')
            {
                return false;
            }
        }
    }

    return true;
}