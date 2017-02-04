#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<vector>
using namespace std;

void check_file_open(char * fn, FILE * f){
  if(!f){
    printf("Error: failed to open file: [%s]\n"); 
    exit(1);
  }
}

size_t get_file_size(char * fn){
  FILE * f = fopen(fn, "rb");
  check_file_open(fn, f);
  fseek(f, 0L, SEEK_END);
  size_t sz = ftell(f);
  fclose(f);
  return(sz);
}

void * allocate(size_t number_of_bytes){
  void * buffer = malloc(number_of_bytes);
  memset(buffer, '\0', number_of_bytes);
  return(buffer); 
}
void read_file(void * buf, char * fn, size_t number_of_bytes){
  FILE * f = fopen(fn, "rb");
  check_file_open(fn, f);
  size_t bytes_read = fread(buf, 1, number_of_bytes, f);
  if(bytes_read != number_of_bytes){
    printf("Error: expected (%ld) bytes; (%ld) bytes read.\n", 
      (long int)number_of_bytes, (long int)bytes_read); 
    exit(1);
  }
  fclose(f);
}

void write_file(void * buf, char * fn, size_t number_of_bytes){
  FILE * f = fopen(fn, "wb");
  check_file_open(fn, f);
  size_t bytes_written = fwrite(buf, 1, number_of_bytes, f);
  if(bytes_written != number_of_bytes){
    printf("Error: expected (%ld) bytes written; wrote (%ld) bytes.\n", 
      (long int)number_of_bytes, (long int)bytes_written); 
    exit(1);
  }
  fclose(f);
}

