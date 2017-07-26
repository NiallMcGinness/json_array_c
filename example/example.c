#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <jansson.h>
#include <sys/stat.h>
#include "../src/get_curl.h"
#include "../src/parse_json.h"


int main(int argc, char* argv[]) {
    
    char* data;
    
    if(argc < 2) {
        fprintf(stderr, "please pass in a url to get json response from \n");
        return 1;
    }

    data = handle_url(argv[1]);

    if(data) {
        
        parse_json_array(data);
        free(data);
    }
    
    return 0;
}