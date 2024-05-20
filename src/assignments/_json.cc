#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_json_tool.hpp"

#include <iostream>

#if (_RAPIDJSON == 1)

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#endif // _RAPIDJSON == 1

__DEF_NS__(Alan::Tool::JSON::RapidJSON)

void TestRapidJSON()
{   
    // #define _RAPIDJSON 1
    // #if (_RAPIDJSON == 1)
    __USE_NS__(rapidjson);
    
    


    // #endif
}

__END_NS__ // Alan::Tool::JSON::RapidJSON