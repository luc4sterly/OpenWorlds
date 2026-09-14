// 004593d0 FUN_004593d0 [Global]
// programa: gamma.dll

int __cdecl FUN_004593d0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1[10] - param_1[8] != 0) {
    param_1[0xb] = param_1[10] - param_1[8];
    if ((*(byte *)((int)param_1 + 5) >> 4 & 1) == 0) {
      FUN_004592e0();
    }
    iVar1 = (*(code *)param_1[0x11])(*param_1,param_1[8],param_1 + 0xb,param_1[0x13]);
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1[0xb];
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    param_1[7] = param_1[7] + param_1[0xb];
  }
  FUN_00459300((int)param_1);
  return 0;
}


