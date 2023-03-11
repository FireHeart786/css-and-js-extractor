#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <libxml/HTMLparser.h>
#include "extract_files.h"

using namespace std;

size_t write_callback(char* ptr, size_t size, size_t nmemb, string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <URL>" << endl;
        return 1;
    }
    
    string url = argv[1];

    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        string html;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            cerr << "Error retrieving URL: " << curl_easy_strerror(res) << endl;
            return 1;
        }

        vector<string> scriptFiles;
        vector<string> cssFiles;
        extract_files(html, scriptFiles, cssFiles);

        cout << "Total script files in the page: " << scriptFiles.size() << endl;
        cout << "Total CSS files in the page: " << cssFiles.size() << endl;

        ofstream jsFile("javascript_files.txt");
        for (const string& file : scriptFiles) {
            jsFile << file << endl;
        }
        jsFile.close();

        ofstream cssFile("css_files.txt");
        for (const string& file : cssFiles) {
            cssFile << file << endl;
        }
        cssFile.close();
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <libxml/HTMLparser.h>
#include "extract_files.h"

using namespace std;

size_t write_callback(char* ptr, size_t size, size_t nmemb, string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <URL>" << endl;
        return 1;
    }
    
    string url = argv[1];

    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        string html;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            cerr << "Error retrieving URL: " << curl_easy_strerror(res) << endl;
            return 1;
        }

        vector<string> scriptFiles;
        vector<string> cssFiles;
        extract_files(html, scriptFiles, cssFiles);

        cout << "Total script files in the page: " << scriptFiles.size() << endl;
        cout << "Total CSS files in the page: " << cssFiles.size() << endl;

        ofstream jsFile("javascript_files.txt");
        for (const string& file : scriptFiles) {
            jsFile << file << endl;
        }
        jsFile.close();

        ofstream cssFile("css_files.txt");
        for (const string& file : cssFiles) {
            cssFile << file << endl;
        }
        cssFile.close();
    }

    return 0;
}
