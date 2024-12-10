#ifndef KMEANS_H
#define KMEANS_H

#include "Sample.h"
#include "Cluster.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class KMeans {
private:
    int K;
    vector<Sample> samples;
    vector<Cluster> clusters;

public:
    KMeans(int k);
    void readSamplesFromFile(const string& filename);
    void initializeRandomCentroids();
    double calculateDistance(const Sample& sample, const Cluster& cluster) const;
    void performKMeansClustering();
    bool hasConverged(double epsilon) const;
    void printClusters() const;
};

#endif // KMEANS_H
