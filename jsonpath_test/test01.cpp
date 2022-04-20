#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/pointer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;
using namespace std;

void PrintNotLeftPath(const Value& v, const Pointer& p) {
    StringBuffer sb;
    p.Stringify(sb);
    std::cout << sb.GetString() << std::endl;
    switch (v.GetType()) {
    case kArrayType:
        for (SizeType i = 0; i != v.Size(); ++i)
            PrintNotLeftPath(v[i], p.Append(i));
        break;
    case kObjectType:
        for (Value::ConstMemberIterator m = v.MemberBegin(); m != v.MemberEnd(); ++m) 
            PrintNotLeftPath(m->value, p.Append(m->name.GetString(), m->name.GetStringLength()));
        break;
    default:
        break;
    }
}

int main() {
    FILE* fp = fopen("/home/junluo01/AIproject/framework/src/utils/store.json", "rb");
    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    AutoUTFInputStream<unsigned, FileReadStream> eis(is);
    Document d;
    d.ParseStream(eis);
    Pointer root;
    PrintNotLeftPath(d, root);
    return 0;
}