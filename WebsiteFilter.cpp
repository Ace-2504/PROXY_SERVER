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
        if (domain == site)
            return false;

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