#include <vector>
#include <libxml/HTMLparser.h>
#include "extract_files.h"

using namespace std;

void extract_files(const string& html, vector<string>& scriptFiles, vector<string>& cssFiles) {
    htmlNodePtr rootNode = htmlReadDoc((xmlChar*)html.c_str(), NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE
