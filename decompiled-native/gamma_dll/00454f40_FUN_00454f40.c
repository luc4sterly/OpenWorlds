// 00454f40 FUN_00454f40 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00454f40(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = FUN_00454d00();
    return uVar1;
  }
  if ((*(char *)((int)param_1 + 0xd) != '\0') || ((*(ushort *)(param_1 + 1) >> 7 & 7) == 0)) {
    return 0xffffffff;
  }
  if ((*(byte *)(param_1 + 1) >> 2 & 7) == 1) {
    return 0;
  }
  if (2 < (*(byte *)(param_1 + 2) & 7)) {
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8 | 2;
  }
  if ((*(byte *)(param_1 + 2) & 7) == 2) {
    param_1[0xb] = 0;
  }
  if ((*(byte *)(param_1 + 2) & 7) != 1) {
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8;
    return 0;
  }
  if ((*(ushort *)(param_1 + 1) >> 7 & 7) == 1) {
    uVar1 = FUN_004552c0((int)param_1);
  }
  else {
    uVar1 = 0;
  }
  iVar2 = FUN_004593d0(param_1,(undefined4 *)0x0);
  if (iVar2 != 0) {
    *(undefined1 *)((int)param_1 + 0xd) = 1;
    param_1[0xb] = 0;
    return 0xffffffff;
  }
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8;
  param_1[7] = uVar1;
  param_1[0xb] = 0;
  return 0;
}


