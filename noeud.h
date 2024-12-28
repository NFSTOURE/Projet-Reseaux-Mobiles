#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED
#include "point.h"
#include <Qvector>

class noeud {
private:
    long long id;
    double latitude;
    double longitude;
    QVector<noeud> noeudsVoisins;

public:
    noeud(long long id, double lat, double lon);

    // Getters
    long long getId() const;
    double getLatitude() const;
    double getLongitude() const;
    point getCoordonnees() const;

    double X_lambert93() const;
    double Y_lambert93() const;
    QVector<noeud> getNoeudsVoisins() const;


};



#endif // NOEUD_H_INCLUDED
