 #include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>
#include <boost/program_options.hpp> // si tu utilises cette bibliothèque
    // si tu utilises cette bibliothèque

#include <iostream>
#include <osmium/io/reader.hpp>
//#include <osmium/io/area.hpp>
#include "graphe.h"
#include "MyHandler.h" // Assurez-vous que votre fichier de header s'appelle MyHandler.h

int main() {

    // Chemin vers le fichier OSM
    const std::string fichier_osm = "votre_fichier.osm";

    // Créer un objet GrapheRoutier
    GrapheRoutier graphe;

    // Lire le fichier OSM et traiter les données
    osmium::io::Reader reader(fichier_osm);
    OSMHandler handler(graphe);
    osmium::apply(reader, handler);
    reader.close();

    // Afficher le graphe
    graphe.afficherGraphe();



    return 0;
}
