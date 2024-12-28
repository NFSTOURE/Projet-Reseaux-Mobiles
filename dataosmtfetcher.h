#ifndef DATAOSMTFETCHER_H
#define DATAOSMTFETCHER_H
#include "graphe.h"

class dataOSMTFetcher
{
private:
    graphe graphe;
public:
    dataOSMTFetcher();

    void parseNode(const QString namefile);
    void parseWay(const QString namefile);

};

#endif // DATAOSMTFETCHER_H
