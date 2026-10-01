// 1001b0a0 FUN_1001b0a0 [Global]
// program: rwdlmd21.dll

void FUN_1001b0a0(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0xf];
  param_1[1] = *(int *)(iVar1 + 0x58);
  param_1[2] = *(int *)(iVar1 + 0x5c);
  param_1[3] = *(int *)(iVar1 + 0x60);
  FUN_1001af40(param_1);
  return;
}


