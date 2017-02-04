// 20170203 richardson.ashlin@gmail.com
#include<stdio.h>
#include<stdlib.h>
void check_file_open(char * fn, FILE * f){
  if(!f){
    printf("Error: could not open file: [%s]\n"); 
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


void * allocate(size_t n_bytes){
  void * buffer = malloc(n_bytes);
  memset(buffer, '\0', n_bytes);
  return(buffer); 
}

void read_file(void * buf, char * fn, size_t n_bytes){
  FILE * f = fopen(fn, "rb");
  check_file_open(fn, f);
  size_t bytes_read = fread(buf, 1, n_bytes, f);
  if(bytes_read != n_bytes){
    printf("Error: expected (%ld) bytes; read (%ld).\n", 
      (long int)n_bytes, (long int)bytes_read); 
    exit(1);
  }
  fclose(f);
}

int main(int argc, char ** argv){
  if(argc!= 2){
    printf("Error: bin2hex:\n\tbin2hex [input binary file name].\n"); 
    exit(1);
  }
  char * file_name = argv[1];
  size_t file_size = get_file_size(file_name); 
  void * buf = allocate(file_size); 
  read_file(buf, file_name, file_size); 
  long long int i; long long int nb = (long long int)file_size;
  for(i = 0;i < nb; i++){
    printf("%02hhX",((unsigned char *)buf)[i]);
  }
  return 0;
}


