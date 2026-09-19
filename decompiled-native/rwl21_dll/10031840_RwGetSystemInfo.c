// 10031840 RwGetSystemInfo [Global]
// programa: RWL21.DLL

undefined4 RwGetSystemInfo(undefined4 param_1,char *param_2,size_t param_3)

{
  char local_100 [256];
  
                    /* 0x31840  251  RwGetSystemInfo */
  if (param_2 == (char *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((int)param_3 < 1) {
    FUN_1000cba0(0x47);
    return 0;
  }
  switch(param_1) {
  case 1:
    _sprintf(local_100,s__d__d__02d__s_1005aeec,2,1,6,&DAT_1005aefc);
    _strncpy(param_2,local_100,param_3);
    param_2[param_3 - 1] = '\0';
    break;
  case 2:
    if ((int)param_3 < 4) {
      FUN_1000cba0(0x47);
      return 0;
    }
    param_2[0] = '\x02';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
    break;
  case 3:
    if ((int)param_3 < 4) {
      FUN_1000cba0(0x47);
      return 0;
    }
    param_2[0] = '\x01';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
    break;
  case 4:
    _strncpy(param_2,&DAT_1005aefc,param_3);
    param_2[param_3 - 1] = '\0';
    break;
  case 5:
    goto joined_r0x10031955;
  case 6:
joined_r0x10031955:
    if ((int)param_3 < 4) {
      FUN_1000cba0(0x47);
      return 0;
    }
    param_2[0] = '\0';
    param_2[1] = '\0';
    param_2[2] = '\0';
    param_2[3] = '\0';
    break;
  default:
    FUN_1000cba0(0x38);
    return 0;
  }
  return 1;
}


