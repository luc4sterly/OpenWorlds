// 0044d600 FUN_0044d600 [Global]
// program: gamma.dll

void __cdecl FUN_0044d600(int param_1,byte *param_2,char *param_3,uint *param_4)

{
  byte *pbVar1;
  int local_14;
  byte *local_10;
  undefined4 local_c;
  
  local_14 = param_1;
  local_10 = param_2;
  local_c = 0;
  pbVar1 = FUN_0044ce70(&LAB_0044d550,&local_14,param_3,param_4);
  if (param_1 != 0) {
    if (param_2 <= pbVar1) {
      pbVar1 = param_2 + -1;
    }
    pbVar1[param_1] = 0;
  }
  return;
}


