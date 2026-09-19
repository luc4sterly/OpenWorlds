// 10019370 FUN_10019370 [Global]
// programa: RWDL6D21.DLL

void FUN_10019370(int param_1,int param_2,int param_3,int *param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  short sVar9;
  int iVar10;
  ushort *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  
  iVar5 = DAT_10079218;
  uVar12 = *(uint *)(param_3 + 8);
  bVar1 = *(byte *)((param_4[1] >> 0x10) * 0x20 + ((uVar12 & 0x7c0) >> 6) + 0x400 + DAT_10079220);
  bVar2 = *(byte *)((param_4[2] >> 0x10) * 0x20 + (uVar12 & 0x1f) + 0x800 + DAT_10079220);
  bVar3 = *(byte *)((*param_4 >> 0x10) * 0x20 + ((uVar12 & 0xf800) >> 0xb) + DAT_10079220);
  uVar12 = *(uint *)(param_1 + 0x1c) & 0xffff0000;
  local_1c = *(uint *)(param_1 + 0x18) & 0xffff0000;
  local_18 = *(int *)(param_1 + 0x20);
  bVar6 = *(byte *)(param_3 + 0x30) & 0x40;
  if (bVar6 != 0) {
    local_18 = local_18 + 0xff0000;
  }
  uVar7 = *(uint *)(param_2 + 0x18) & 0xffff0000;
  uVar14 = *(uint *)(param_2 + 0x1c) & 0xffff0000;
  iVar10 = *(int *)(param_2 + 0x20);
  if (bVar6 != 0) {
    iVar10 = iVar10 + 0xff0000;
  }
  uVar8 = uVar7;
  local_14 = iVar10;
  uVar13 = uVar12;
  if ((int)uVar7 < (int)local_1c) {
    uVar8 = local_1c;
    local_14 = local_18;
    uVar13 = uVar14;
    uVar14 = uVar12;
    local_1c = uVar7;
    local_18 = iVar10;
  }
  if (uVar8 == DAT_1007c0c4) {
    if (local_1c == DAT_1007c0c4) {
      return;
    }
    uVar12 = (int)(uVar14 - uVar13) >> 0x1f;
    if ((int)(uVar8 - local_1c) < (int)((uVar14 - uVar13 ^ uVar12) - uVar12)) {
      uVar8 = uVar8 - 1;
    }
  }
  if ((uVar13 == DAT_1007c0c0) || (uVar14 == DAT_1007c0c0)) {
    if (uVar14 == uVar13) {
      return;
    }
    if (uVar13 == DAT_1007c0c0) {
      uVar13 = uVar13 - 1;
    }
    else if ((int)(uVar14 - uVar13) < (int)(uVar8 - local_1c)) {
      uVar14 = uVar14 - 1;
    }
  }
  iVar15 = uVar14 - uVar13;
  iVar10 = uVar8 - local_1c;
  local_14 = local_14 - local_18;
  sVar9 = (short)((uint)iVar15 >> 0x10);
  if (iVar15 < 0) {
    sVar9 = -sVar9;
  }
  local_20 = (int)(short)((uint)iVar10 >> 0x10);
  if (local_20 < sVar9) {
    local_20 = (int)sVar9;
  }
  if (local_20 == 0) {
    local_20 = 1;
  }
  else {
    iVar10 = iVar10 / local_20;
    iVar15 = iVar15 / local_20;
    local_14 = local_14 / local_20;
  }
  while (local_20 != 0) {
    local_20 = local_20 + -1;
    iVar4 = ((int)local_1c >> 0x10) * 2;
    puVar11 = (ushort *)(((int)uVar13 >> 0x10) * DAT_1007beb0 + iVar4 + DAT_10079210);
    local_10 = (uint)*puVar11;
    if ((int)local_10 <= local_18 >> 0x10) {
      *puVar11 = (ushort)((uint)local_18 >> 0x10);
      *(ushort *)(*(int *)(iVar5 + ((int)uVar13 >> 0x10) * 4) + iVar4) =
           (ushort)bVar1 << 6 | (ushort)bVar2 | (ushort)bVar3 << 0xb;
    }
    uVar13 = uVar13 + iVar15;
    local_1c = local_1c + iVar10;
    local_18 = local_18 + local_14;
  }
  return;
}


