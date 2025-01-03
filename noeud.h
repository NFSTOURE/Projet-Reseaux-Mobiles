#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

#include <QVector>
#include "point.h"

class noeud {
private:
    long long id;
    double latitude;
    double longitude;

public:
    noeud(long long id, double lat, double lon);

    // Getters
    long long getId() const;
    double getLatitude() const;
    double getLongitude() const;
    point getCoordonnees() const;

    // Projection en Lambert 93
    double X_lambert93() const;
    double Y_lambert93() const;
};

#endif // NOEUD_H_INCLUDED
