#include "PairwiseAligner.hpp"

void PairwiseAligner::launchNeedlemanWunsh(){

    int N = _seq1.size();
    int M = _seq2.size();
    int left = 0, up = 0, diagonal = 0;

    for (int i = 1; i < N + 1; i++){
        for (int j = 1; i < M + 1; j++){

            left = _penaltyMatrix.at(i).at(j - 1) + _gapPenalty;
            up = _penaltyMatrix.at(i - 1).at(j) + _gapPenalty;
            diagonal = _penaltyMatrix.at(i - 1).at(j - 1) + _seq1.at(i - 1) == _seq2.at(j - 1) ? _match : _mismatch;

            _penaltyMatrix.at(i).at(j) = std::max(std::max(left, up), diagonal);
        }
    }


}

PairwiseAligner::PairwiseAligner(std::string &s1, std::string &s2) : _seq1(s1), _seq2(s2), _penaltyMatrix(std::vector <std::vector <int>>(s1.size() + 1, std::vector<int>(s2.size() + 1, 0))){

    int N = _seq1.size();
    int M = _seq2.size();
    
    _penaltyMatrix.at(0).at(0) = 0;
    for (int i; i < N + 1; i++) _penaltyMatrix.at(i).at(0) = _gapPenalty * i;
    for (int j; j < M + 1; j++) _penaltyMatrix.at(0).at(j) = _gapPenalty * j;
}