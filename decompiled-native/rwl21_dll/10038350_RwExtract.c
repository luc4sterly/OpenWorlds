// 10038350 RwExtract [Global]
// programa: RWL21.DLL

bool RwExtract(char *param_1,int param_2,char *param_3,int param_4)

{
  char *local_8;
  
                    /* 0x38350  84  RwExtract */
  local_8 = param_1;
  while( true ) {
    if (param_2 < 2) {
      for (; ((1 < param_4 && (*local_8 != '\0')) && (*local_8 != ';')); local_8 = local_8 + 1) {
        *param_3 = *local_8;
        param_3 = param_3 + 1;
        param_4 = param_4 + -1;
      }
      if (param_4 != 0) {
        *param_3 = '\0';
      }
      return param_4 != 0;
    }
    for (; (*local_8 != ';' && (*local_8 != '\0')); local_8 = local_8 + 1) {
    }
    if (*local_8 == '\0') break;
    local_8 = local_8 + 1;
    param_2 = param_2 + -1;
  }
  return false;
}


