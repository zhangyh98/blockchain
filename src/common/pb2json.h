

#ifndef __JSON_PROTOBUF_H__
#define __JSON_PROTOBUF_H__

#include <json/json.h>
#include <google/protobuf/message.h>

namespace chain {
	bool Json2Proto(const Json::Value& root, google::protobuf::Message& msg, std::string& errorMsg);
	Json::Value Proto2Json(const google::protobuf::Message& message);
} // namespace json_protobuf

#endif // __JSON_PROTOBUF_H__
