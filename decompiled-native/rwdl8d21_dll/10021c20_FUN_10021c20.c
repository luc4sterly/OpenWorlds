// 10021c20 FUN_10021c20 [Global]
// program: RWDL8D21.DLL

void FUN_10021c20(int param_1,int param_2,int param_3,int *param_4)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if ((*(uint *)(param_3 + 8) & 0x20) == 0) {
    iVar4 = *param_4;
  }
  else {
    iVar4 = 0x1f0000 - *param_4;
  }
  uVar1 = *(undefined1 *)((*(uint *)(param_3 + 8) & 0xffe0) + (iVar4 >> 0x10) + DAT_1007521c);
  local_10 = *(uint *)(param_1 + 0x18) & 0xffff0000;
  uVar5 = *(uint *)(param_1 + 0x1c) & 0xffff0000;
  local_8 = *(int *)(param_1 + 0x20);
  bVar2 = *(byte *)(param_3 + 0x30) & 0x40;
  if (bVar2 != 0) {
    local_8 = local_8 + 0xff0000;
  }
  iVar4 = local_8;
  uVar9 = *(uint *)(param_2 + 0x18) & 0xffff0000;
  uVar11 = *(uint *)(param_2 + 0x1c) & 0xffff0000;
  local_c = *(int *)(param_2 + 0x20);
  if (bVar2 != 0) {
    local_c = local_c + 0xff0000;
  }
  uVar6 = uVar5;
  uVar10 = uVar9;
  if ((int)uVar9 < (int)local_10) {
    local_8 = local_c;
    local_c = iVar4;
    uVar6 = uVar11;
    uVar10 = local_10;
    uVar11 = uVar5;
    local_10 = uVar9;
  }
  if (uVar10 == DAT_100780c4) {
    if (local_10 == DAT_100780c4) {
      return;
    }
    uVar5 = (int)(uVar11 - uVar6) >> 0x1f;
    if ((int)(uVar10 - local_10) < (int)((uVar11 - uVar6 ^ uVar5) - uVar5)) {
      uVar10 = uVar10 - 1;
    }
  }
  if ((uVar6 == DAT_100780c0) || (uVar11 == DAT_100780c0)) {
    if (uVar11 == uVar6) {
      return;
    }
    if (uVar6 == DAT_100780c0) {
      uVar6 = uVar6 - 1;
    }
    else if ((int)(uVar11 - uVar6) < (int)(uVar10 - local_10)) {
      uVar11 = uVar11 - 1;
    }
  }
  iVar12 = uVar11 - uVar6;
  iVar4 = uVar10 - local_10;
  local_c = local_c - local_8;
  sVar7 = (short)((uint)iVar12 >> 0x10);
  if (iVar12 < 0) {
    sVar7 = -sVar7;
  }
  local_14 = (int)(short)((uint)iVar4 >> 0x10);
  if (local_14 < sVar7) {
    local_14 = (int)sVar7;
  }
  if (local_14 == 0) {
    local_14 = 1;
  }
  else {
    iVar4 = iVar4 / local_14;
    iVar12 = iVar12 / local_14;
    local_c = local_c / local_14;
  }
  while (local_14 != 0) {
    local_14 = local_14 + -1;
    puVar8 = (ushort *)
             (((int)uVar6 >> 0x10) * DAT_10077eb0 + ((int)local_10 >> 0x10) * 2 + DAT_10075210);
    uVar3 = (ushort)((uint)local_8 >> 0x10);
    if (*puVar8 <= uVar3) {
      *puVar8 = uVar3;
      *(undefined1 *)(*(int *)(DAT_10075218 + ((int)uVar6 >> 0x10) * 4) + ((int)local_10 >> 0x10)) =
           uVar1;
    }
    uVar6 = uVar6 + iVar12;
    local_10 = local_10 + iVar4;
    local_8 = local_8 + local_c;
  }
  return;
}


