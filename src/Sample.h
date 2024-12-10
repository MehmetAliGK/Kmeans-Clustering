#ifndef SAMPLE_H
#define SAMPLE_H

class Sample {
private:
    int index;
    int clusterID;
    double x;
    double y;

public:
    Sample(int idx, double x_coord, double y_coord);
    int getIndex() const;
    int getClusterID() const;
    double getX() const;
    double getY() const;
    void setClusterID(int newClusterID);
};

#endif // SAMPLE_H
