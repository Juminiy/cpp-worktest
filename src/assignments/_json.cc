#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_json_tool.hpp"

#include <iostream>

// #define _RAPIDJSON 1
#if (_RAPIDJSON == 1)

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#endif // _RAPIDJSON == 1

__DEF_NS__(Alan::Tool::JSON::RapidJSON)

void TestRapidJSON()
{   
    // #define _RAPIDJSON 1
    #if (_RAPIDJSON == 1)
    
    __USE_NS__(rapidjson);
    
    const char * domCC = "{\"key\":1}";
    Document dom = Document();
    dom.Parse(domCC);

    // modify different type of value
    dom["key"] = "vvi";

    StringBuffer sb;
    Writer<StringBuffer> wr(sb);
    dom.Accept(wr);

    PRINTLN(sb.GetString());
    

    #endif
}

__END_NS__ // Alan::Tool::JSON::RapidJSON