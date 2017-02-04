// 20170203 richardson.ashlin@gmail.com
#include"util.h"

int main(int argc, char ** argv){
  if(argc != 3){
    printf("hex2bin [input filename] [output filename]\n"); 
    exit(1);
  }
  char * in_file_name = argv[1];
  char * file_name    = argv[2];
  FILE * in_file = fopen(in_file_name, "rb");
  if(!in_file){
    printf("Error: could not open input file [%s] for reading.\n", in_file_name);
    exit(1);
  }
  vector<unsigned char> my_data;
  unsigned char x;
  long int z=0;
  while(fscanf(in_file, "%02hhX", &x) != EOF){
    my_data.push_back(x);
  }
  fclose(in_file);
  size_t file_size = my_data.size();
  void * buf = allocate(file_size); 
  long int i=0;
  vector<unsigned char>::iterator it;
  for(it = my_data.begin(); it != my_data.end(); it++){
    ((unsigned char * )buf)[i++] = *it; 
  }
  write_file(buf, file_name, file_size);
  return 0;
}
