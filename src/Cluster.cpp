#include "Cluster.h"

Cluster::Cluster(int id)
    : clusterID(id), centerX(0.0), centerY(0.0), prevCenterX(0.0), prevCenterY(0.0) {
}

int Cluster::getClusterID() const {
    return clusterID;
}

double Cluster::getCenterX() const {
    return centerX;
}

double Cluster::getCenterY() const {
    return centerY;
}


double Cluster::getPrevCenterX() const {
    return prevCenterX;
}

double Cluster::getPrevCenterY() const {
    return prevCenterY;
}

void Cluster::updateCenter(double newCenterX, double newCenterY) {
    centerX = newCenterX;
    centerY = newCenterY;
}
