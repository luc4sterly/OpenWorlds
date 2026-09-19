// 10019120 FUN_10019120 [Global]
// programa: RWDL6D21.DLL

void FUN_10019120(int param_1,int param_2,int param_3,int *param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint local_10;
  
  iVar4 = DAT_10079218;
  uVar6 = *(uint *)(param_3 + 8);
  bVar1 = *(byte *)((param_4[1] >> 0x10) * 0x20 + ((uVar6 & 0x7c0) >> 6) + 0x400 + DAT_10079220);
  bVar2 = *(byte *)((param_4[2] >> 0x10) * 0x20 + (uVar6 & 0x1f) + 0x800 + DAT_10079220);
  bVar3 = *(byte *)((*param_4 >> 0x10) * 0x20 + ((uVar6 & 0xf800) >> 0xb) + DAT_10079220);
  local_10 = *(uint *)(param_1 + 0x18) & 0xffff0000;
  uVar5 = *(uint *)(param_1 + 0x1c) & 0xffff0000;
  uVar10 = *(uint *)(param_2 + 0x18) & 0xffff0000;
  uVar13 = *(uint *)(param_2 + 0x1c) & 0xffff0000;
  uVar6 = uVar5;
  uVar11 = uVar10;
  if ((int)uVar10 < (int)local_10) {
    uVar6 = uVar13;
    uVar11 = local_10;
    uVar13 = uVar5;
    local_10 = uVar10;
  }
  if (uVar11 == DAT_1007c0c4) {
    if (local_10 == DAT_1007c0c4) {
      return;
    }
    uVar5 = (int)(uVar13 - uVar6) >> 0x1f;
    if ((int)(uVar11 - local_10) < (int)((uVar13 - uVar6 ^ uVar5) - uVar5)) {
      uVar11 = uVar11 - 1;
    }
  }
  if ((uVar6 == DAT_1007c0c0) || (uVar13 == DAT_1007c0c0)) {
    if (uVar13 == uVar6) {
      return;
    }
    if (uVar6 == DAT_1007c0c0) {
      uVar6 = uVar6 - 1;
    }
    else if ((int)(uVar13 - uVar6) < (int)(uVar11 - local_10)) {
      uVar13 = uVar13 - 1;
    }
  }
  iVar14 = uVar13 - uVar6;
  iVar12 = uVar11 - local_10;
  sVar7 = (short)((uint)iVar14 >> 0x10);
  if (iVar14 < 0) {
    sVar7 = -sVar7;
  }
  iVar9 = (int)(short)((uint)iVar12 >> 0x10);
  if (iVar9 < sVar7) {
    iVar9 = (int)sVar7;
  }
  if (iVar9 == 0) {
    iVar9 = 1;
  }
  else {
    iVar12 = iVar12 / iVar9;
    iVar14 = iVar14 / iVar9;
  }
  for (; iVar9 != 0; iVar9 = iVar9 + -1) {
    iVar8 = (int)uVar6 >> 0x10;
    uVar6 = uVar6 + iVar14;
    *(ushort *)(*(int *)(iVar4 + iVar8 * 4) + ((int)local_10 >> 0x10) * 2) =
         (ushort)bVar1 << 6 | (ushort)bVar2 | (ushort)bVar3 << 0xb;
    local_10 = local_10 + iVar12;
  }
  return;
}


