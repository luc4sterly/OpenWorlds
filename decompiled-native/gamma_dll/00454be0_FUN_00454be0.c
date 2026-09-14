// 00454be0 FUN_00454be0 [Global]
// programa: gamma.dll

void __cdecl FUN_00454be0(undefined4 *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int iVar1;
  
  *param_1 = 0;
  param_1[1] = param_2;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf7;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  param_1[7] = 0;
  if (param_4 == 0) {
    param_4 = 0;
    iVar1 = 0;
    param_3 = (uint *)0x0;
  }
  else {
    iVar1 = 2;
  }
  FUN_00459440(param_1,param_3,iVar1,param_4);
  param_1[10] = param_1[8];
  param_1[0xb] = 0;
  if ((*(ushort *)(param_1 + 1) >> 7 & 7) == 1) {
    param_1[0xf] = &LAB_00459230;
    param_1[0x10] = &LAB_004591c0;
    param_1[0x11] = &LAB_00459200;
    param_1[0x12] = &LAB_00459260;
  }
  param_1[0x13] = 0;
  return;
}


