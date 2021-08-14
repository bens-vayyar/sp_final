#include "spkmeansmodule.h"
#include <math.h>

int testWAM()
{
    double** matrix;
    double observ1[3] = {1,2,3};
    double observ2[3] = {2,3,4};
    double observ3[3] = {4,5,6};
    double* observations[3] = {observ1, observ2, observ3};
    matrix = CreateWeightedAdjacencyMatrix(observations,3,3);
    return 0;
}
int testLaplacian()
{
    double WAMLine0[3] = {0, 4, 3}, WAMLine1[3] = {4,0,5}, WAMLine2[3] = {3,5,0};
    double DDMLine0[3] = {1/pow(5,0.5),0,0}, DDMLine1[3] = {0,1/pow(6,0.5),0}, DDMLine2[3] = {0,0,1/pow(8,0.5)}; 
    double *matrixWAM[3] = {WAMLine0,WAMLine1,WAMLine2}, *matrixDDM[3] = {DDMLine0, DDMLine1, DDMLine2}, **Laplacian;
    Laplacian = ComputeNormalizedGraphLaplacian(matrixWAM,matrixDDM,3);
}

int testJacobi()
{
    double line1[3] = {1,pow(2,0.5),2}, line2[3] = {pow(2,0.5),3,pow(2,0.5)}, line3[3] = {2,pow(2,0.5),1};

    double* matrixS[3] = {line1,line2, line3};
    //JacobiAlgorithm(matrixS,3);

}
int testJacobi2()
{
    double test2Line1[2] = {1,2}, test2Line2[2] = {2,4};
    double *matrixS2[2] = {test2Line1, test2Line2};
    //JacobiAlgorithm(matrixS2,2);
}
int testJacobi3()
{
    double test3Line1[4] = {4,-30,60,-35}, test3Line2[4] = {-30,300,-675,420}, test3Line3 [4] ={60,-675,1620,-1050}, test3Line4[4] ={-35,420,-1050,700};
    double* matrixS3[4] = {test3Line1,test3Line2,test3Line3,test3Line4};
    double matrixVLine1[4]={0,0,0,0}, matrixVLine2[4]={0,0,0,0}, matrixVLine3[4]={0,0,0,0}, matrixVLine4[4]={0,0,0,0};
    double* matrixV4[4]={matrixVLine1,matrixVLine2,matrixVLine3,matrixVLine4};  
    JacobiAlgorithm(matrixS3,matrixV4,4);
}