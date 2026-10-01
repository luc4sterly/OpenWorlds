// 00455650 FUN_00455650 [Global]
// program: gamma.dll

uint __cdecl FUN_00455650(uint param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  
  uVar4 = *(ushort *)(param_2 + 1) >> 7 & 7;
  param_2[0xb] = 0;
  if ((*(char *)((int)param_2 + 0xd) != '\0') || (uVar4 == 0)) {
    return 0xffffffff;
  }
  if (uVar4 == 2) {
    FUN_00459570();
  }
  if (((*(byte *)(param_2 + 2) & 7) == 0) && ((*(byte *)(param_2 + 1) >> 2 & 2) != 0)) {
    if ((*(byte *)(param_2 + 1) >> 2 & 4) != 0) {
      iVar3 = FUN_004553b0(param_2,0,2);
      if (iVar3 != 0) {
        return 0;
      }
    }
    *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0xf8 | 1;
    FUN_00459300((int)param_2);
  }
  if ((*(byte *)(param_2 + 2) & 7) != 1) {
    *(undefined1 *)((int)param_2 + 0xd) = 1;
    param_2[0xb] = 0;
    return 0xffffffff;
  }
  if (((*(byte *)(param_2 + 1) >> 5 & 3) == 2) || (param_2[9] == param_2[10] - param_2[8])) {
    iVar3 = FUN_004593d0(param_2,(undefined4 *)0x0);
    if (iVar3 != 0) {
      *(undefined1 *)((int)param_2 + 0xd) = 1;
      param_2[0xb] = 0;
      return 0xffffffff;
    }
  }
  param_2[0xb] = param_2[0xb] + -1;
  puVar1 = (undefined1 *)param_2[10];
  param_2[10] = param_2[10] + 1;
  *puVar1 = (char)param_1;
  bVar2 = *(byte *)(param_2 + 1) >> 5 & 3;
  if (bVar2 != 2) {
    if ((bVar2 == 0) || (param_1 == 10)) {
      iVar3 = FUN_004593d0(param_2,(undefined4 *)0x0);
      if (iVar3 != 0) {
        *(undefined1 *)((int)param_2 + 0xd) = 1;
        param_2[0xb] = 0;
        return 0xffffffff;
      }
    }
    param_2[0xb] = 0;
  }
  return param_1 & 0xff;
}


