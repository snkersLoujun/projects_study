#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>
#include "rapidjson/pointer.h"
#include "rapidjson/filereadstream.h"
#include <iostream>

using namespace rapidjson;
using namespace std;

Value FromJsonPathGetVaule(Document &d, string path , string key) {
    Value * e = Pointer(path.c_str()).Get(d);
    for(int i = 0; i < e->Size(); ++i)
    {
         Value * et = Pointer(key.c_str()).Get((*e)[i]);
         if(et && et->IsString()){
             cout << et->GetString() << endl;
         }
         else if(et && et->IsNumber()){
             cout << et->GetDouble() << endl;
         }
         else if(et && et->IsNull()){
             cout << et->IsNull() << endl;
         }
         else if(et && et->IsBool()){
             cout << et->IsBool() << endl;
         }
         else break;
     }
}

int main(){
    FILE* fp = fopen("/home/junluo01/AIproject/framework/src/utils/store.json", "rb");
    char readBuffer[65536];
    FileReadStream bis(fp, readBuffer, sizeof(readBuffer));
    AutoUTFInputStream<unsigned, FileReadStream> eis(bis);  // wraps bis into eis
    Document d;
    d.ParseStream(eis);
    FromJsonPathGetVaule( d , "/store/book" , "/category" );
    return 0 ;
}
