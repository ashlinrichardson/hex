// 20170203 richardson.ashlin@gmail.com
#include"util.h"
int main(int argc, char ** argv){
  if(argc!= 2){
    printf("bin2hex [input binary filename]\n"); 
    exit(1);
  }
  char * file_name = argv[1];
  size_t file_size = get_file_size(file_name); 
  void * buf = allocate(file_size); 
  read_file(buf, file_name, file_size); 
  long long int i, nb;
  nb = (long long int)file_size;
  for(i = 0; i < nb; i++){
    printf("%02hhX",((unsigned char *)buf)[i]);
  }
  return 0;
}
