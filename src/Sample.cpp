#include "Sample.h"

Sample::Sample(int idx, double x_coord, double y_coord)
    : index(idx), clusterID(-1), x(x_coord), y(y_coord) {
}

int Sample::getIndex() const {
    return index;
}

int Sample::getClusterID() const {
    return clusterID;
}

double Sample::getX() const {
    return x;
}

double Sample::getY() const {
    return y;
}

void Sample::setClusterID(int newClusterID) {
    clusterID = newClusterID;
}
