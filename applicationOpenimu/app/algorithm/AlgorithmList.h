#ifndef ALGORITHMLIST_H
#define ALGORITHMLIST_H

#include <string>
#include<vector>
#include "../acquisition/IJsonSerializable.h"

struct ParametersInfo
{
    std::string name;
};

struct AlgorithmInfo
{
    std::string name;
    std::string id;
    std::vector<ParametersInfo> parameters;
};

class AlgorithmList : public IJsonSerializable
{
public:
   AlgorithmList();
   virtual ~AlgorithmList(void);

   virtual void Serialize( Json::Value& root, RecordInfo infos,  std::string date,std::string& output);
   virtual void Deserialize( Json::Value& root);

   std::vector<AlgorithmInfo> m_algorithmList;
};
#endif
