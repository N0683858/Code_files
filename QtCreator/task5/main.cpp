#include <fstream>
#include "gridworld_route.h"

const std::string filepath = "../logs/GPX/routes/";

using namespace GPS;

int main()
{
    //Creating AllBelowSeaLevel.gpx
    GridWorld worldNorthSea(Position(53.5757, 1.2951, -20),1000, 50);

    GridWorldRoute routeAllBelowSeaLevel("MNO", worldNorthSea);

    std::ofstream AllBelowSeaLevel( filepath + "N0719715-AllBelowSeaLevel.gpx");

    AllBelowSeaLevel << routeAllBelowSeaLevel.toGPX();

    AllBelowSeaLevel.close();


    //Creating AboveBelowSeaLevel.gpx
    GridWorld worldStokeSea(Position(53.0233, -2.19936, 120),1000, 120);

    GridWorldRoute routeAboveBelowSeaLevel("KLMNO", worldStokeSea);

    std::ofstream AboveBelowSeaLevel( filepath + "N0719715-AboveBelowSeaLevel.gpx");

    AboveBelowSeaLevel << routeAboveBelowSeaLevel.toGPX();

    AboveBelowSeaLevel.close();

    //Creating DeepestElev.gpx
    GridWorld worldDeepEarth(Position(17.89980916421568, 142.6513461487682, -11000),1000, 1000);

    GridWorldRoute routeDeepestElev("MSY", worldDeepEarth);

    std::ofstream DeepestElev( filepath + "N0719715-DeepestElev.gpx");

    DeepestElev << routeDeepestElev.toGPX();

    DeepestElev.close();

    return 0;
}
