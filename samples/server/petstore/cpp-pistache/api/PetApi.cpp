/**
* OpenAPI Petstore
* This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
*
* The version of the OpenAPI document: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/

#include "PetApi.h"
#include "Helpers.h"

namespace org::openapitools::server::api
{

using namespace org::openapitools::server::helpers;
using namespace org::openapitools::server::model;

const std::string PetApi::base = "/v2";

PetApi::PetApi(const std::shared_ptr<Pistache::Rest::Router>& rtr)
    : router(rtr)
{
}

void PetApi::init() {
    setupRoutes();
}

void PetApi::setupRoutes() {
    using namespace Pistache::Rest;

    Routes::Post(*router, base + "/pet", Routes::bind(&PetApi::add_pet_handler, this));
    Routes::Delete(*router, base + "/pet/:petId", Routes::bind(&PetApi::delete_pet_handler, this));
    Routes::Get(*router, base + "/pet/findByStatus", Routes::bind(&PetApi::find_pets_by_status_handler, this));
    Routes::Get(*router, base + "/pet/findByTags", Routes::bind(&PetApi::find_pets_by_tags_handler, this));
    Routes::Get(*router, base + "/pet/:petId", Routes::bind(&PetApi::get_pet_by_id_handler, this));
    Routes::Put(*router, base + "/pet", Routes::bind(&PetApi::update_pet_handler, this));
    Routes::Post(*router, base + "/pet/:petId", Routes::bind(&PetApi::update_pet_with_form_handler, this));
    Routes::Post(*router, base + "/pet/:petId/uploadImage", Routes::bind(&PetApi::upload_file_handler, this));

    // Default handler, called when a route is not found
    router->addCustomHandler(Routes::bind(&PetApi::pet_api_default_handler, this));
}

std::pair<Pistache::Http::Code, std::string> PetApi::handleParsingException(const std::exception& ex) const noexcept
{
    try {
        throw;
    } catch (nlohmann::detail::exception &e) {
        return std::make_pair(Pistache::Http::Code::Bad_Request, e.what());
    } catch (org::openapitools::server::helpers::ValidationException &e) {
        return std::make_pair(Pistache::Http::Code::Bad_Request, e.what());
    } catch (std::exception &e) {
        return std::make_pair(Pistache::Http::Code::Internal_Server_Error, e.what());
    }
}

std::pair<Pistache::Http::Code, std::string> PetApi::handleOperationException(const std::exception& ex) const noexcept
{
    return std::make_pair(Pistache::Http::Code::Internal_Server_Error, ex.what());
}

void PetApi::add_pet_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the body param
    
    Pet body;
    
    try {
        nlohmann::json::parse(request.body()).get_to(body);
        body.validate();
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleParsingException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    try {
        this->add_pet(body, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void PetApi::delete_pet_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    // Getting the path params
    auto petId = request.param(":petId").as<int64_t>();
    
    // Getting the header params
    auto apiKey = request.headers().tryGetRaw("api_key");

    try {
        this->delete_pet(petId, apiKey, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void PetApi::find_pets_by_status_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the query params
    auto statusQuery = request.query().get("status");
    std::optional<std::vector<std::string>> status;
    if(statusQuery.has_value()){
        std::vector<std::string> valueQuery_instance;
        if(fromStringValue(statusQuery.value(), valueQuery_instance)){
            status = valueQuery_instance;
        }
    }
    
    try {
        this->find_pets_by_status(status, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void PetApi::find_pets_by_tags_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the query params
    auto tagsQuery = request.query().get("tags");
    std::optional<std::vector<std::string>> tags;
    if(tagsQuery.has_value()){
        std::vector<std::string> valueQuery_instance;
        if(fromStringValue(tagsQuery.value(), valueQuery_instance)){
            tags = valueQuery_instance;
        }
    }
    
    try {
        this->find_pets_by_tags(tags, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void PetApi::get_pet_by_id_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    // Getting the path params
    auto petId = request.param(":petId").as<int64_t>();
    
    try {
        this->get_pet_by_id(petId, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void PetApi::update_pet_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {


    // Getting the body param
    
    Pet body;
    
    try {
        nlohmann::json::parse(request.body()).get_to(body);
        body.validate();
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleParsingException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    try {
        this->update_pet(body, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void PetApi::update_pet_with_form_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    try {
      this->update_pet_with_form(request, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void PetApi::upload_file_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    try {
      this->upload_file(request, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}

void PetApi::pet_api_default_handler(const Pistache::Rest::Request &, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

} // namespace org::openapitools::server::api

