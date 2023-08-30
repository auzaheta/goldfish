#include <omp.h>
#include <RcppArmadillo.h>
#include <RcppEigen.h>
// [[Rcpp::depends(RcppArmadillo, RcppEigen)]]
// [[Rcpp::plugins(openmp)]]

// [[Rcpp::export]]
SEXP MapMatMult(
    const Eigen::Map<Eigen::MatrixXd> A,
    const Eigen::Map<Eigen::MatrixXd> B,
    int nCores
) {
    Eigen::setNbThreads(nCores);
    Eigen::MatrixXd C = A * B;

    return Rcpp::wrap(C);
}

// [[Rcpp::export]]
SEXP MapMatMultI(
    const Eigen::Map<Eigen::MatrixXi> A,
    const Eigen::Map<Eigen::MatrixXi> B,
    int nCores
) {
    Eigen::setNbThreads(nCores);
    Eigen::MatrixXi C = A * B;

    return Rcpp::wrap(C);
}
