#ifndef ARETE_H
#define ARETE_H
#include "noeud.h"
#include <Qstring>

class arete
{
private:
    noeud* debut;
    noeud* fin;
    QString id;   // ID de l'ar�te provenant de OSM
    QString type; // Type de route (autoroute, nationale, etc.)

public:
    arete(noeud* debut=nullptr, noeud* fin=nullptr);

    noeud* getDebut() const;
    void setDebut(noeud* newDebut);

    noeud* getFin() const;
    void setFin(noeud* newFin);

    double getDistance() const;

    //void calculerDistance();// M�thode pour calculer la distance entre les n�uds
    double getDistanceLambert93() const;

    QString getId() const;
    void setId(const QString& newId);

    QString getType() const;
    void setType(const QString& newType);


};

#endif // ARETE_H
