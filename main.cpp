#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

static std::string data;
static char errdata[CURL_ERROR_SIZE];

static size_t curl_ipify_writer(char *data, size_t size, size_t nmemb, std::string *writer_data) {
    if (writer_data == NULL) {
        return 0;
    }

    writer_data->append(data, size*nmemb);

    return size * nmemb;
}

bool curl_ipify_init(CURL *&conn) {
    CURLcode code;

    conn = curl_easy_init();

    if (!conn) {
        fprintf(stderr, "Failed to initialize CURL connection");
        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errdata);
    if(code != CURLE_OK) {
        fprintf(stderr, "Failed to set error buffer [%d]\n", code);
        return false;
    }
    
    code = curl_easy_setopt(conn, CURLOPT_URL, "https://api.ipify.org/?format=json");
    if(code != CURLE_OK) {
        fprintf(stderr, "Failed to set URL [%s]\n", errdata);
        return false;
    }
    
    code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
    if(code != CURLE_OK) {
        fprintf(stderr, "Failed to set redirect option [%s]\n", errdata);
        return false;
    }
    
    code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, curl_ipify_writer);
    if(code != CURLE_OK) {
        fprintf(stderr, "Failed to set writer [%s]\n", errdata);
        return false;
    }
    
    code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &data);
    if(code != CURLE_OK) {
        fprintf(stderr, "Failed to set write data [%s]\n", errdata);
        return false;
    }

    return true;
}

int main() {
    CURL *conn = NULL;
    CURLcode code;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    if (!curl_ipify_init(conn)) {
        fprintf(stderr, "Connection intialization failed");
        return 1;
    }

    code = curl_easy_perform(conn);
    curl_easy_cleanup(conn);

    if (code != CURLE_OK) {
        fprintf(stderr, "Failed to query to ipify [%s]\n", errdata);
        return 1;
    }

    json result = json::parse(data);

    std::cout << "Your ip address was " << result["ip"] << std::endl;

    curl_global_cleanup();

    return 0;
}
