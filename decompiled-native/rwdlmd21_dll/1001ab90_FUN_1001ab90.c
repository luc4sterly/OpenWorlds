// 1001ab90 FUN_1001ab90 [Global]
// program: rwdlmd21.dll

void FUN_1001ab90(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  
  iVar5 = DAT_10087240;
  uVar8 = *(uint *)(param_3 + 8);
  bVar2 = *(byte *)((param_4[1] >> 0x10) * 0x20 + ((uVar8 & 0x7c0) >> 6) + 0x400 + DAT_10087248);
  bVar3 = *(byte *)((param_4[2] >> 0x10) * 0x20 + (uVar8 & 0x1f) + 0x800 + DAT_10087248);
  bVar4 = *(byte *)((*param_4 >> 0x10) * 0x20 + ((uVar8 & 0xf800) >> 0xb) + DAT_10087248);
  uVar8 = *(uint *)(param_1 + 0x1c) & 0xffff0000;
  local_1c = *(uint *)(param_1 + 0x18) & 0xffff0000;
  local_18 = *(int *)(param_1 + 0x20);
  bVar6 = *(byte *)(param_3 + 0x30) & 0x40;
  if (bVar6 != 0) {
    local_18 = local_18 + 0xff0000;
  }
  uVar12 = *(uint *)(param_2 + 0x18) & 0xffff0000;
  uVar14 = *(uint *)(param_2 + 0x1c) & 0xffff0000;
  iVar11 = *(int *)(param_2 + 0x20);
  if (bVar6 != 0) {
    iVar11 = iVar11 + 0xff0000;
  }
  uVar9 = uVar8;
  local_10 = iVar11;
  uVar13 = uVar12;
  if ((int)uVar12 < (int)local_1c) {
    uVar9 = uVar14;
    local_10 = local_18;
    uVar13 = local_1c;
    uVar14 = uVar8;
    local_1c = uVar12;
    local_18 = iVar11;
  }
  if (uVar13 == DAT_1008a108) {
    if (local_1c == DAT_1008a108) {
      return;
    }
    uVar8 = (int)(uVar14 - uVar9) >> 0x1f;
    if ((int)(uVar13 - local_1c) < (int)((uVar14 - uVar9 ^ uVar8) - uVar8)) {
      uVar13 = uVar13 - 1;
    }
  }
  if ((uVar9 == DAT_1008a104) || (uVar14 == DAT_1008a104)) {
    if (uVar14 == uVar9) {
      return;
    }
    if (uVar9 == DAT_1008a104) {
      uVar9 = uVar9 - 1;
    }
    else if ((int)(uVar14 - uVar9) < (int)(uVar13 - local_1c)) {
      uVar14 = uVar14 - 1;
    }
  }
  local_14 = uVar14 - uVar9;
  iVar11 = uVar13 - local_1c;
  local_10 = local_10 - local_18;
  sVar10 = (short)((uint)local_14 >> 0x10);
  if (local_14 < 0) {
    sVar10 = -sVar10;
  }
  local_20 = (int)(short)((uint)iVar11 >> 0x10);
  if (local_20 < sVar10) {
    local_20 = (int)sVar10;
  }
  if (local_20 == 0) {
    local_20 = 1;
  }
  else {
    iVar11 = iVar11 / local_20;
    local_14 = local_14 / local_20;
    local_10 = local_10 / local_20;
  }
  while (local_20 != 0) {
    local_20 = local_20 + -1;
    iVar1 = ((int)local_1c >> 0x10) * 2;
    iVar7 = DAT_10089ef4 * ((int)uVar9 >> 0x10) + DAT_10087238;
    local_c = (uint)*(ushort *)(iVar7 + iVar1);
    if ((int)local_c <= local_18 >> 0x10) {
      *(short *)(iVar7 + iVar1) = (short)((uint)local_18 >> 0x10);
      *(ushort *)(*(int *)(iVar5 + ((int)uVar9 >> 0x10) * 4) + iVar1) =
           (ushort)bVar2 << 6 | (ushort)bVar3 | (ushort)bVar4 << 0xb;
    }
    local_1c = local_1c + iVar11;
    uVar9 = uVar9 + local_14;
    local_18 = local_18 + local_10;
  }
  return;
}


