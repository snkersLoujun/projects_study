#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/pointer.h"
#include <cstdio>
#include <iostream>
#include <vector>

using namespace rapidjson;
using namespace std;

rapidjson::Value *getValue(const char *inputJson, const std::string &path)
{
    Document d;
    d.Parse(inputJson);
    Value *res;
    res = Pointer(path.c_str()).Get(d);
    return res;
}

int main()
{
    // const char *json = "{\"store\":{\"book\":[{\"category\":\"reference\",\"author\":\"Nigel Rees\",\"title\":\"Sayings of the Century\",\"price\":8.95},{\"category\":\"fiction\",\"author\":\"Evelyn Waugh\",\"title\":\"Sword of Honour\",\"price\":12.99},{\"category\":\"fiction\",\"author\":\"Herman Melville\",\"title\":\"Moby Dick\",\"isbn\":\"0-553-21311-3\",\"price\":8.99},{\"category\":\"fiction\",\"author\":\"J. R. R. Tolkien\",\"title\":\"The Lord of the Rings\",\"isbn\":\"0-395-19395-8\",\"price\":22.99}],\"bicycle\":{\"color\":\"red\",\"price\":19.95}},\"expensive\":10}";
     const char *json = "{\"glossary\":{\"title\":\"example glossary\",\"GlossDiv\":{\"title\":\"S\",\"GlossList\":{\"GlossEntry\":{\"ID\":\"SGML\",\"SortAs\":\"SGML\",\"GlossTerm\":\"Standard Generalized Markup Language\",\"Acronym\":\"SGML\",\"Abbrev\":\"ISO 8879:1986\",\"GlossDef\":{\"para\":\"A meta-markup language, used to create markup languages such as DocBook.\",\"GlossSeeAlso\":[\"GML\",\"XML\"]},\"GlossSee\":\"markup\"}}}}}";
    //  const char *json = "{\"type\":\"object\",\"properties\":{\"encoding\":{\"type\":\"string\",\"enum\":[\"opus\",\"speex\"]},\"seq\":{\"type\":\"integer\",\"maximum\":99},\"vcn\":{\"type\":\"number\",\"data\":[{\"value\":48000,\"desc\":\"111\",\"resource\":\"$resourceKey，指用户设置了参数vcn的值为48000时，必须加载的资源\"},{\"value\":16000,\"desc\":\"222\"}]}}";

    Value *vaule = getValue(json, "/glossary/GlossDiv/title");
    // cout << vaule->GetString() << endl;
    switch (vaule->GetType())
    {
    case kStringType:
        cout << vaule->GetString() << endl;
        break;
    case kNumberType:
        cout << vaule->GetDouble() << endl;
        break;
    default:
        break;
    }
}