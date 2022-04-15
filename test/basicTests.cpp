#include <gtest/gtest.h>
#include "PairwiseAligner.hpp"
#include <string>
#include <vector>

TEST(basicTests, initMethodworks){

  std::string s1 = "ACAAG";
  std::string s2 = "UCGUG";
  PairwiseAligner aligner(s1, s2);
  
  std::vector <std::vector <int> > v = {
              { 0, -2, -4, -6, -8, -10}, 
              {-2,  0, 0, 0, 0, 0}, 
              {-4,  0, 0, 0, 0, 0}, 
              {-6,  0, 0, 0, 0, 0}, 
              {-8,  0, 0, 0, 0, 0}, 
              {-10, 0, 0, 0, 0, 0}, 
              };
  

  
  EXPECT_EQ(v, aligner.getPenaltyMatrix());
}