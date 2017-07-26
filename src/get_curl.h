#ifndef GET_CURL_H_   
#define GET_CURL_H_

struct url_data;
size_t write_data(void *ptr, size_t size, size_t nmemb, struct url_data *data);
char *handle_url(char* url); 

#endif 