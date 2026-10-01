// 10021a20 FUN_10021a20 [Global]
// program: RWDL8D21.DLL

void FUN_10021a20(int param_1,int param_2,int param_3,int *param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint local_c;
  
  if ((*(uint *)(param_3 + 8) & 0x20) == 0) {
    iVar2 = *param_4;
  }
  else {
    iVar2 = 0x1f0000 - *param_4;
  }
  uVar1 = *(undefined1 *)((*(uint *)(param_3 + 8) & 0xffe0) + (iVar2 >> 0x10) + DAT_1007521c);
  local_c = *(uint *)(param_1 + 0x18) & 0xffff0000;
  uVar4 = *(uint *)(param_1 + 0x1c) & 0xffff0000;
  uVar8 = *(uint *)(param_2 + 0x18) & 0xffff0000;
  uVar10 = *(uint *)(param_2 + 0x1c) & 0xffff0000;
  uVar5 = uVar4;
  uVar9 = uVar8;
  if ((int)uVar8 < (int)local_c) {
    uVar5 = uVar10;
    uVar9 = local_c;
    uVar10 = uVar4;
    local_c = uVar8;
  }
  if (uVar9 == DAT_100780c4) {
    if (local_c == DAT_100780c4) {
      return;
    }
    uVar4 = (int)(uVar10 - uVar5) >> 0x1f;
    if ((int)(uVar9 - local_c) < (int)((uVar10 - uVar5 ^ uVar4) - uVar4)) {
      uVar9 = uVar9 - 1;
    }
  }
  if ((uVar5 == DAT_100780c0) || (uVar10 == DAT_100780c0)) {
    if (uVar10 == uVar5) {
      return;
    }
    if (uVar5 == DAT_100780c0) {
      uVar5 = uVar5 - 1;
    }
    else if ((int)(uVar10 - uVar5) < (int)(uVar9 - local_c)) {
      uVar10 = uVar10 - 1;
    }
  }
  iVar11 = uVar10 - uVar5;
  iVar2 = uVar9 - local_c;
  sVar6 = (short)((uint)iVar11 >> 0x10);
  if (iVar11 < 0) {
    sVar6 = -sVar6;
  }
  iVar7 = (int)(short)((uint)iVar2 >> 0x10);
  if (iVar7 < sVar6) {
    iVar7 = (int)sVar6;
  }
  if (iVar7 == 0) {
    iVar7 = 1;
  }
  else {
    iVar2 = iVar2 / iVar7;
    iVar11 = iVar11 / iVar7;
  }
  for (; iVar7 != 0; iVar7 = iVar7 + -1) {
    iVar3 = (int)uVar5 >> 0x10;
    uVar5 = uVar5 + iVar11;
    *(undefined1 *)(*(int *)(DAT_10075218 + iVar3 * 4) + ((int)local_c >> 0x10)) = uVar1;
    local_c = local_c + iVar2;
  }
  return;
}


