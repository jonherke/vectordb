#pragma once

#include <memory>
#include <string>

#include "thirdparty/rapidjson/document.h"

namespace vectordb {

class Json {
 public:
  Json();
  Json(rapidjson::Value* value);  // Constructor for nested objects

  bool LoadFromString(const std::string& json_string);
  std::string DumpToString();
  std::string GetString(const std::string& key);
  int64_t GetInt(const std::string& key);
  double GetDouble(const std::string& key);
  bool GetBool(const std::string& key);
  std::string GetString();
  int64_t GetInt();
  double GetDouble();
  bool GetBool();
  Json GetObject(const std::string& key);                      // Get nested object
  Json GetArrayElement(const std::string& key, size_t index);  // Get specific element from array

 private:
  std::unique_ptr<rapidjson::Document> doc_;
  rapidjson::Value* val_;  // Pointer to a value within the document (for nested objects)
};

}  // namespace vectordb

/**
 * Usage example:
 * 
  std::string json_string = R"({
        "name": "John Doe",
        "age": 30,
        "isMarried": true,
        "spouse": {
            "name": "Jane Doe",
            "age": 28
        },
        "childrenNames": ["Alice", "Bob"]
    })";

    vectordb::Json json;
    bool load_success = json.LoadFromString(json_string);
    if (!load_success) {
        std::cout << "Failed to load JSON\n";
        return 1;
    }

    std::string name = json.GetString("name");
    int64_t age = json.GetInt("age");
    bool is_married = json.GetBool("isMarried");
    std::string spouse_name = json.GetObject("spouse").GetString("name");
    int spouse_age = json.GetObject("spouse").GetInt("age");
    std::string first_child_name = json.GetArrayElement("childrenNames", 0).GetString();

    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Is Married: " << (is_married ? "Yes" : "No") << "\n";
    std::cout << "Spouse's Name: " << spouse_name << "\n";
    std::cout << "Spouse's Age: " << spouse_age << "\n";
    std::cout << "First Child's Name: " << first_child_name << "\n";
*/
