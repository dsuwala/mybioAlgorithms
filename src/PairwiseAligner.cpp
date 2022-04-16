#include "PairwiseAligner.hpp"

void PairwiseAligner::launchNeedlemanWunsh(){

    int N = _seq2.size();
    int M = _seq1.size();
    int left = 0, up = 0, diagonal = 0;

    // matrix filling
    // seq1 --> j, seq2 --> i
    for (int i = 1; i < N + 1; i++){
        for (int j = 1; j < M + 1; j++){

            left = _penaltyMatrix.at(i).at(j - 1) + _gapPenalty;
            up = _penaltyMatrix.at(i - 1).at(j) + _gapPenalty;
            diagonal = _penaltyMatrix.at(i - 1).at(j - 1) + (_seq1.at(j - 1) == _seq2.at(i - 1) ? _match : _mismatch);

            _penaltyMatrix.at(i).at(j) = std::max(std::max(left, up), diagonal);
        }
    }
    
    // tracing back
    int i = N; int j = M;
    while (i != 0 && j != 0){

        if (_seq1.at(j - 1) != _seq2.at(i - 1)){
            

            left = _penaltyMatrix.at(i).at(j - 1);
            up = _penaltyMatrix.at(i - 1).at(j);
            diagonal = _penaltyMatrix.at(i - 1).at(j - 1);

            int maxNeighbor = std::max(std::max(left, up), diagonal);

            if (maxNeighbor == left) {
                
                _alignment2.append("-");
                _alignment1.append(std::string(1, _seq1.at(j - 1)));
                j--;
            }

            if (maxNeighbor == up) {

                _alignment1.append("-");
                _alignment2.append(std::string(1, _seq2.at(i - 1)));
                i--;
            }

            if (maxNeighbor == diagonal) {

                _alignment1.append(std::string(1, _seq1.at(j - 1)));
                _alignment2.append(std::string(1, _seq2.at(i - 1)));
                i--;
                j--;
            }
                
        }else{

            _alignment1.append(std::string(1, _seq1.at(j - 1)));
            _alignment2.append(std::string(1, _seq2.at(i - 1)));

            i--;
            j--;
        }

    }
    
    while(true){

        if (j != 0){

            _alignment2.append("-");
            _alignment1.append(std::string(1, _seq1.at(j - 1)));
            j--;
        }

        if (i != 0){
            _alignment1.append("-");
            _alignment2.append(std::string(1, _seq2.at(i - 1)));
            i--;
        }
        if (i == 0 && j == 0 ) break;

    }

    std::reverse(_alignment1.begin(), _alignment1.end());
    std::reverse(_alignment2.begin(), _alignment2.end());

}

PairwiseAligner::PairwiseAligner(std::string &s1, std::string &s2) : _seq1(s1), _seq2(s2), _penaltyMatrix(std::vector <std::vector <int>>(s2.size() + 1, std::vector<int>(s1.size() + 1, 0))){

    int N = _seq2.size();
    int M = _seq1.size();
    
    _penaltyMatrix.at(0).at(0) = 0;
    for (int i = 0; i < N + 1; i++) _penaltyMatrix.at(i).at(0) = _gapPenalty * i;
    for (int j = 0; j < M + 1; j++) _penaltyMatrix.at(0).at(j) = _gapPenalty * j;
}