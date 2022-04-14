#ifndef __pariwise_alignment_hpp__
#define __pariwise_alignment_hpp__

#include <string>
#include <vector>
#include <utility>

class PairwiseAligner{

    public: 
        PairwiseAligner(std::string &s1, std::string &s2) : _seq1(s1), _seq2(s2) {};
        
        void launchNeedlemanWunsh();
        
        // creates (N + 1)x(M  + 1) matrix filled with zeros with M,N - seq1, seq2 sizes
        void init();

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