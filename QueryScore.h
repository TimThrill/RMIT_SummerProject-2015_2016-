/*
 * QueryScore.h
 *
 *  Created on: Jan 16, 2016
 *      Author: cheetah
 */

#ifndef QUERYSCORE_H_
#define QUERYSCORE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "QueryReply_m.h"
#include "Query_m.h"
#include "ExtractDataset.h"
#include "MyApplicationLayer.h"
#include "Coord.h"
#include "json/json.h"
#include "Lexicon.h"
#include "Document.h"

class QueryScore {
public:

    std::map<std::string, Lexicon> lexiconMap;
    std::map<unsigned int, Document> docMap;
    std::ifstream ivsFile;
    std::ifstream lexiconfile;
    std::ifstream mapFile;

    QueryScore()
    {
        initialise();
    }

    void initialise();


    void getRankingResult(QueryReply* queryReplyMessage,
            Query* queryMessage);

    void rankingScore(std::vector<std::pair<unsigned int, double> >* reviewsScore, Query* queryMessage);

    Json::Value readReviewJson(long line_number);

    double getDistanceScore(Coord& a, Coord&b);

    double getTextScore(const std::vector<std::pair<unsigned int, double> >::iterator& it, Query* queryMessage);

    void setRankingResult(int, QueryReply*, std::vector<std::pair<unsigned int, double> >*);
};


#endif /* QUERYSCORE_H_ */
