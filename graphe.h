#ifndef GRAPHE_H
#define GRAPHE_H
#include "noeud.h"
#include "arete.h"
#include <QMap>
#include <Qvector>
class graphe
{
private :
    QMap<long long, noeud*> listeNoeuds;
    QVector<arete*> listeAretes;
public:
    graphe();

    QMap<long long, noeud*> getListeNoeuds() const;
    QVector<arete*> getListeAretes() const;

    void ajouteNoeud(noeud* node);
    void ajouteArete(arete* edge);

};

#endif // GRAPHE_H
