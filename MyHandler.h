#ifndef HANDLER_H_INCLUDED
#define HANDLER_H_INCLUDED

#include <osmium/io/any_input.hpp>
#include <osmium/handler.hpp>
#include <osmium/visitor.hpp>
#include "noeud.h"
#include "arete.h"
#include "graphe.h"
#include <iostream>

class OSMHandler : public osmium::handler::Handler {
private:
    GrapheRoutier& graphe;

public:
    OSMHandler(GrapheRoutier& graphe) : graphe(graphe) {}

    // Méthode appelée pour chaque nœud OSM
    void node(const osmium::Node& osm_node) {
        double lat = osm_node.location().lat();
        double lon = osm_node.location().lon();
        osmium::object_id_type id = osm_node.id();

        // Créer un nœud et l'ajouter au graphe
        Noeud noeud(id, lat, lon);
        graphe.ajouterNoeud(noeud);
    }

    // Méthode appelée pour chaque "way" OSM
    void way(const osmium::Way& osm_way) {
        const auto& nodes = osm_way.nodes();
        if (nodes.size() < 2) return; // Ignorer si le chemin contient moins de 2 nœuds

        // Créer des arêtes entre chaque paire consécutive de nœuds dans le "way"
        for (size_t i = 1; i < nodes.size(); ++i) {
            osmium::object_id_type id_debut = nodes[i - 1].ref();
            osmium::object_id_type id_fin = nodes[i].ref();

            // Récupérer les nœuds du graphe
            Noeud* debut = graphe.getNoeud(id_debut);
            Noeud* fin = graphe.getNoeud(id_fin);

            if (debut && fin) { // Si les nœuds existent
                Arete arete(debut, fin);
                //arete.calculerDistance();
                graphe.ajouterArete(arete);
            }
        }
    }
};





#endif // HANDLER_H_INCLUDED
