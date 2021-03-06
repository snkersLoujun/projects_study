#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/pointer.h"
#include <cstdio>
#include <iostream>
#include<vector>

using namespace rapidjson;
using namespace std;

vector<string> GetValue(const char *inputJson, string path, string key)
{
    Document d;
    d.Parse(inputJson);
    Value *e = Pointer(path.c_str()).Get(d);
    vector<string>res;
    if (e->IsArray())
    {
        for (int i = 0; i < e->Size(); ++i)
        {
            Value *et = Pointer(key.c_str()).Get((*e)[i]);
            if (et && et->IsString())
            {
                res.push_back(et->GetString());          
            }
            else if (et && et->IsNumber())
            {
                res.push_back(to_string(et->GetDouble()));
            }
            else if (et && et->IsNull())
            {
                res.push_back(to_string(et->IsNull()));
            }
            else if (et && et->IsBool())
            {
                res.push_back(to_string(et->GetBool()));
            }
            else break;
        }
    }
    else
    {
        Value *et = Pointer(key.c_str()).Get(*e);
        if (et && et->IsString())
        {
            res.push_back(et->GetString());
        }
        else if (et && et->IsNumber())
        {
            res.push_back(to_string(et->GetDouble()));
        }
        else if (et && et->IsNull())
        {
            res.push_back(to_string(et->IsNull()));
        }
        else if (et && et->IsBool())
        {
            res.push_back(to_string(et->GetBool()));
        }
       return res;
    }
}

void test01(){
    const char *json = "{\"store\":{\"book\":[{\"category\":\"reference\",\"author\":\"Nigel Rees\",\"title\":\"Sayings of the Century\",\"price\":8.95},{\"category\":\"fiction\",\"author\":\"Evelyn Waugh\",\"title\":\"Sword of Honour\",\"price\":12.99},{\"category\":\"fiction\",\"author\":\"Herman Melville\",\"title\":\"Moby Dick\",\"isbn\":\"0-553-21311-3\",\"price\":8.99},{\"category\":\"fiction\",\"author\":\"J. R. R. Tolkien\",\"title\":\"The Lord of the Rings\",\"isbn\":\"0-395-19395-8\",\"price\":22.99}],\"bicycle\":{\"color\":\"red\",\"price\":19.95}},\"expensive\":10}";
    // const char *json = "{\"glossary\":{\"title\":\"example glossary\",\"GlossDiv\":{\"title\":\"S\",\"GlossList\":{\"GlossEntry\":{\"ID\":\"SGML\",\"SortAs\":\"SGML\",\"GlossTerm\":\"Standard Generalized Markup Language\",\"Acronym\":\"SGML\",\"Abbrev\":\"ISO 8879:1986\",\"GlossDef\":{\"para\":\"A meta-markup language, used to create markup languages such as DocBook.\",\"GlossSeeAlso\":[\"GML\",\"XML\"]},\"GlossSee\":\"markup\"}}}}}";
    // const char *json = "{\"type\":\"object\",\"properties\":{\"encoding\":{\"type\":\"string\",\"enum\":[\"opus\",\"speex\"]},\"seq\":{\"type\":\"integer\",\"maximum\":99},\"vcn\":{\"type\":\"number\",\"data\":[{\"value\":48000,\"desc\":\"111\",\"resource\":\"$resourceKey???????????????????????????vcn?????????48000???????????????????????????\"},{\"value\":16000,\"desc\":\"222\"}]}}";
    vector<string>ans;
    ans = GetValue(json, "/type", "");
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << endl;
    }
}
int main()
{
    test01();
    return 0 ;
}