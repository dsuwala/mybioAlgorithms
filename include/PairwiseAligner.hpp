#ifndef __pariwise_alignment_hpp__
#define __pariwise_alignment_hpp__

#include <string>
#include <vector>
#include <utility>

class PairwiseAligner{

    public: 
        PairwiseAligner(std::string &s1, std::string &s2);
        
        void launchNeedlemanWunsh();
        
        // std::pair <std::string, std::string> getSeq(){};
        std::vector <std::vector <int>> getPenaltyMatrix() const {return _penaltyMatrix;}

    private:
        std::string _seq1, _seq2;
        std::string alignment;
        std::vector <std::vector <int>> _penaltyMatrix;
        
        int _gapPenalty = -2;
        int _match = 1;
        int _mismatch = -1;

};

#endif