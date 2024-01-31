#include "solution.hpp"

HttpCode ApiClient::httpPost(const std::string &route,
                             const rapidjson::Document &json) {
  // START YOUR IMPLEMENTATION HERE
  // Remember to call save() method with validated data before returning correct
  // http code
    // Check if the route is correct
    if (route != "/users") {
        return HttpCode::BAD_REQUEST;
    }

    // Check if both name and age are present
    if (!json.HasMember("name") || !json.HasMember("age")) {
        return HttpCode::BAD_REQUEST;
    }

    // Check if name is a string and age is a number
    if (!json["name"].IsString() || !json["age"].IsNumber()) {
        return HttpCode::BAD_REQUEST;
    }

    std::string name = json["name"].GetString();
    int age = json["age"].GetInt();

    // Validate name length and age value
    if (name.length() > 32 || age < 16) {
        return HttpCode::BAD_REQUEST;
    }

    // Create User object
    User newUser;
    newUser.age = age;
    newUser.name = name;

    // Save the User object
    save(newUser);

    return HttpCode::CREATED;
}
