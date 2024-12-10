#include "KMeans.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <cmath>

KMeans::KMeans(int k) : K(k) {
    // Initialize clusters
    for (int i = 1; i <= K; ++i) {
        clusters.push_back(Cluster(i));
    }
}
    //Read samples form text file
void KMeans::readSamplesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file");
    }

    int idx = 0;
    double x, y;

    while (file >> x >> y) {
        samples.push_back(Sample(idx, x, y));
        idx++;
    }

    file.close();
}
    // Initialize cluster centroids with random samples
void KMeans::initializeRandomCentroids() {
    
    random_shuffle(samples.begin(), samples.end());
    for (int i = 0; i < K; ++i) {
        clusters[i].updateCenter(samples[i].getX(), samples[i].getY());
    }
}
    // Calculate Euclidean distance between sample and cluster centroid
double KMeans::calculateDistance(const Sample& sample, const Cluster& cluster) const {
    
    double dx = sample.getX() - cluster.getCenterX();
    double dy = sample.getY() - cluster.getCenterY();
    return std::sqrt(dx * dx + dy * dy);
}

void KMeans::performKMeansClustering() {
    int maxIterations = 100; // Maximum number of iterations
    double epsilon = 0.001;  // Convergence threshold

    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        // 1. Assign each sample to the nearest cluster
        for (Sample& sample : samples) {
            int closestClusterID = -1;
            double minDistance = std::numeric_limits<double>::max();

            for (const Cluster& cluster : clusters) {
                double distance = calculateDistance(sample, cluster);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestClusterID = cluster.getClusterID();
                }
            }

            sample.setClusterID(closestClusterID);
        }

        // 2. Update cluster centroids
        bool converged = true;

        for (Cluster& cluster : clusters) {
            int clusterID = cluster.getClusterID();
            double totalX = 0.0;
            double totalY = 0.0;
            int clusterSize = 0;

            for (const Sample& sample : samples) {
                if (sample.getClusterID() == clusterID) {
                    totalX += sample.getX();
                    totalY += sample.getY();
                    clusterSize++;
                }
            }

            double newCenterX = (clusterSize > 0) ? totalX / clusterSize : 0.0;
            double newCenterY = (clusterSize > 0) ? totalY / clusterSize : 0.0;

            if (abs(newCenterX - cluster.getCenterX()) > epsilon ||
                abs(newCenterY - cluster.getCenterY()) > epsilon) {
                converged = false;
            }

            cluster.updateCenter(newCenterX, newCenterY);
        }

        // Check for convergence
        if (converged) {
            cout << "Converged after " << iteration + 1 << " iterations." << endl;
            break;
        }
    }
}

bool KMeans::hasConverged(double epsilon) const {
    // Check for convergence based on epsilon
    for (const Cluster& cluster : clusters) {
        double deltaX = cluster.getCenterX() - cluster.getPrevCenterX();
        double deltaY = cluster.getCenterY() - cluster.getPrevCenterY();
        if (sqrt(deltaX * deltaX + deltaY * deltaY) > epsilon) {
            return false;
        }
    }
    return true;
}

// Print the clusters
void KMeans::printClusters() const {
    for (const Cluster& cluster : clusters) {
        cout << "Cluster " << cluster.getClusterID() << " Center: (" << cluster.getCenterX() << ", "
                  << cluster.getCenterY() << ")" << endl;
        for (const Sample& sample : samples) {
            if (sample.getClusterID() == cluster.getClusterID()) {
                cout << "Sample " << sample.getIndex() << ": Cluster " << sample.getClusterID() << " ("
                          << sample.getX() << ", " << sample.getY() << ")" << endl;
            }
        }
    }
}
