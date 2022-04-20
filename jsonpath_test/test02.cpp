#include "rapidjson/document.h"     
#include "rapidjson/prettywriter.h" 
#include "rapidjson/pointer.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <iostream>


using namespace rapidjson;
using namespace std;

void PrintJsonPath(Value& js_value,  int d = 0 )
{ 
    if(js_value.IsNull() ||js_value.IsBool() ||js_value.IsNumber() ||js_value.IsString()){
        for(int i = 0; i < d+1; i++){
            cout << "  ";
        }
    }

    if(js_value.IsNull())
    {
        cout << "(null)";
    }

    else if(js_value.IsBool())
    {
        cout << (js_value.GetBool()) ;
        cout << "(bool)";
    }
    else if(js_value.IsObject())
    {

        for(auto iter = js_value.MemberBegin(); iter != js_value.MemberEnd(); ++iter){
            auto key = (iter->name).GetString();
            for(int i = 0; i < d; i++){
                cout << "  ";
            }
            cout << "- "<< key << "(object): ";
            cout << endl;
            PrintJsonPath(js_value[key],d + 1);
            if(js_value[key].IsArray()) continue;
            if(iter+1 == js_value.MemberEnd()) continue;
            cout <<endl;
        }
    }
    else if(js_value.IsArray())
    {
        for(auto i = 0; i < js_value.Size(); ++i){
           PrintJsonPath(js_value[i], d);
            cout <<endl;
        }
    }
    else if(js_value.IsNumber())
    {
        cout << (js_value.GetDouble()) ;
        cout << "(number)";
    }
    else if(js_value.IsString())
    {
        cout << (js_value.GetString()) ;
        cout << "(string)";
    }
    else {
        cout << "(error)";
    }
    return ;
}
int main(){

    FILE* fp = fopen("/home/junluo01/AIproject/framework/src/utils/glossarytest.json", "rb");
    char readBuffer[65536];
    FileReadStream bis(fp, readBuffer, sizeof(readBuffer));
    AutoUTFInputStream<unsigned, FileReadStream> eis(bis);  // wraps bis into eis
    Document d;
    d.ParseStream(eis);
    if(d.HasParseError())
    {
        cout << "GetParseError" << endl;;
    }
    PrintJsonPath(d, 0);
    return 0 ;
     
}