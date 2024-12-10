#ifndef CLUSTER_H
#define CLUSTER_H

class Cluster {
private:
    int clusterID;
    double centerX;
    double centerY;
	double prevCenterX;
    double prevCenterY;
public:
    Cluster(int id);
    int getClusterID() const;
    double getCenterX() const;
    double getCenterY() const;
    void updateCenter(double newCenterX, double newCenterY);
    double getPrevCenterX() const;
    double getPrevCenterY() const;
};

#endif // CLUSTER_H
