// 1002d680 FUN_1002d680 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __fastcall FUN_1002d680(undefined4 param_1,undefined4 param_2,float *param_3,uint *param_4)

{
  char cVar1;
  float local_8;
  float local_4;
  
  FUN_1002d750(&local_8,param_2,&local_8,param_4,param_3);
  local_8 = param_3[3] + local_8;
  local_4 = param_3[4] + local_4;
  cVar1 = '\x01';
  if (_DAT_1005223c <= local_4) {
    cVar1 = (0 < (int)local_8) + '\x02';
  }
  if (cVar1 == '\x02') {
    if (_DAT_1005223c <= local_4 + local_8) {
      if (-local_8 < param_3[4] - param_3[3]) {
        cVar1 = '\x03';
        param_3[3] = param_3[3] + -local_8;
      }
    }
    else if (local_4 < param_3[4] - param_3[3]) {
      param_3[4] = param_3[4] - local_4;
      return '\x01';
    }
  }
  return cVar1;
}


