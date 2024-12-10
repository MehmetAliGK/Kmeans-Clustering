# **K-Means Clustering Implementation**
## **Overview**
This project implements the K-Means clustering algorithm in C++ using a class hierarchy design. The algorithm groups 40 samples, each with two features (x and y coordinates), into K clusters, where K is a user-defined parameter. The goal is to assign each sample to the appropriate cluster and compute the cluster centers as the average of the features of the samples within that cluster.

## **Features**
  - Implements K-Means clustering for two-dimensional data.
  - Supports visualization of clusters (K=2 and K=5 examples included).
  - Calculates and displays cluster centers after each iteration.
  - Includes a sample data file (40.txt) for clustering.

## **Input Format**
The input file (40.txt) contains 40 samples, each with:

  - An index (identity number between 0 and 39).
  - Cluster ID (updated dynamically during clustering).
  - Two features: x and y coordinates.

Example Outputs
  - K=2: Two clusters with distinct cluster centers.
  - K=5: Five clusters with distinct cluster centers.

Red crosses in visualizations depict cluster centers.
