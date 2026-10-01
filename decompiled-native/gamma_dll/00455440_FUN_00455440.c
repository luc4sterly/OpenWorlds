// 00455440 FUN_00455440 [Global]
// program: gamma.dll

uint __cdecl FUN_00455440(undefined4 *param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  
  param_1[0xb] = 0;
  if ((*(char *)((int)param_1 + 0xd) != '\0') || ((*(ushort *)(param_1 + 1) >> 7 & 7) == 0)) {
    return 0xffffffff;
  }
  uVar2 = (uint)(*(byte *)(param_1 + 2) & 7);
  if ((uVar2 != 1) && ((*(byte *)(param_1 + 1) >> 2 & 1) != 0)) {
    if (2 < uVar2) {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8 | (*(byte *)(param_1 + 2) & 7) - 1 & 7;
      if (uVar2 == 3) {
        param_1[0xb] = param_1[0xd];
      }
      return (uint)*(byte *)((int)param_1 + uVar2 + 0x10);
    }
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8 | 2;
    iVar3 = FUN_00459330(param_1,(undefined4 *)0x0,0);
    if ((iVar3 == 0) && (param_1[0xb] != 0)) {
      param_1[0xb] = param_1[0xb] + -1;
      pbVar1 = (byte *)param_1[10];
      param_1[10] = param_1[10] + 1;
      return (uint)*pbVar1;
    }
    if (iVar3 == 1) {
      *(undefined1 *)((int)param_1 + 0xd) = 1;
    }
    else {
      *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0xf8;
      *(undefined1 *)(param_1 + 3) = 1;
    }
    param_1[0xb] = 0;
    return 0xffffffff;
  }
  *(undefined1 *)((int)param_1 + 0xd) = 1;
  param_1[0xb] = 0;
  return 0xffffffff;
}


