#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <jansson.h>

int parse_json_array(char* json_string){
    long size;
    int array_size;
    size_t i,j;
    char *text;
    json_t *json, *array, *element, *array_entry;
    json_error_t error;
    float value;

    size = strlen(json_string);

    printf("%ld\n",size);
    json = json_loads(json_string, 0, &error);
    printf("%s\n", json_string);

    if(!json)
    {
            fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
            return 1;
    }

    int json_type = json_typeof(json);
    printf("json type %i\n", json_type);

    json_t *data_array = json_object_get(json, "data");
    json_type = json_typeof(data_array);
    printf("json data token %i\n", json_type);    

        
    array_size = json_array_size(data_array);
    printf("array size %i\n", array_size);
    for(i = 0; i < json_array_size(data_array); i++){
            
        array_entry = json_array_get(data_array, i);

        for(j = 0; j < json_array_size(array_entry); j++){
               
            element = json_array_get(array_entry, j);
            value = json_real_value(element);
            printf(" value %f\n", value);

        }
    }
        
    json_decref(json);
    return 0;
}