#include "PairwiseAligner.hpp"

void PairwiseAligner::init(){
    int N = _seq1.size();
    int M = _seq2.size();
    
    std::vector <int> row;

    for (int i; i < N + 1; i++){
        for (int j; j < M + 1; j++){

            row.push_back(0);
        }
        _penaltyMatrix.emplace_back(row);
    }
    _penaltyMatrix.at(0).at(0) = 0;

    for (int i; i < N + 1; i++) _penaltyMatrix.at(i).at(0) = _gapPenalty * i;
    for (int j; j < M + 1; j++) _penaltyMatrix.at(0).at(j) = _gapPenalty * j;
}
void PairwiseAligner::launchNeedlemanWunsh(){


}