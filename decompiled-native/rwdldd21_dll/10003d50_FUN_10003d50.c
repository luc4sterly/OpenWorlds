// 10003d50 FUN_10003d50 [Global]
// program: RWDLDD21.DLL

void FUN_10003d50(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xc] = 0;
  param_1[5] = 200;
  param_1[6] = 10;
  param_1[9] = 0x14;
  for (; 0 < param_2; param_2 = param_2 / 2) {
    iVar1 = iVar1 + 1;
  }
  param_1[10] = iVar1;
  return;
}


