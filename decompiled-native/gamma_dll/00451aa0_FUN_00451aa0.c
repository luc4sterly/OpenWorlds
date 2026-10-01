// 00451aa0 FUN_00451aa0 [Global]
// program: gamma.dll

undefined4 FUN_00451aa0(ushort param_1)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  
  if (param_1 < 0x100) {
    uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 8;
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    return 8;
  }
  if (param_1 < 0x100) {
    uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 3;
  }
  else {
    uVar1 = 0;
  }
  bVar2 = uVar1 != 0;
  if (param_1 < 0x100) {
    uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 6;
  }
  else {
    uVar1 = 0;
  }
  bVar3 = uVar1 != 0;
  if (!bVar3 && bVar2) {
    return 1;
  }
  if (bVar2 && bVar3) {
    return 2;
  }
  if (!bVar2 && bVar3) {
    return 4;
  }
  if (param_1 < 0x100) {
    uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 0x20;
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    if (param_1 < 0x100) {
      uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 0x10;
    }
    else {
      uVar1 = 0;
    }
    if (uVar1 == 0) {
      if (param_1 < 0x100) {
        uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 0x40;
      }
      else {
        uVar1 = 0;
      }
      if (uVar1 == 0) {
        return 0xa0;
      }
      return 0x60;
    }
    return 0x30;
  }
  if (param_1 < 0x100) {
    uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 0x40;
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 != 0) {
    return 0x40;
  }
  if (param_1 < 0x100) {
    uVar1 = *(ushort *)(&DAT_004830e0 + (uint)param_1 * 2) & 0x80;
  }
  else {
    uVar1 = 0;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return 0x80;
}


