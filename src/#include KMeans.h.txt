#include "KMeans.h"
#include <iostream>

int main() {

    // Create a KMeans object
    KMeans kmeans(9);

    // Read samples from a file
    kmeans.readSamplesFromFile("40.txt");

    // Initialize centroids randomly
    kmeans.initializeRandomCentroids();

    // Perform K-means clustering
    kmeans.performKMeansClustering();

    // Print the final cluster centers and sample assignments
    kmeans.printClusters();

    return 0;
}