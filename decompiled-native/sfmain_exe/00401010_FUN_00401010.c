// 00401010 FUN_00401010 [Global]
// program: sfmain.exe

void __fastcall FUN_00401010(short *param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  byte *in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EBX;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int local_20;
  int local_1c;
  byte *local_14;
  
  iVar5 = (int)*param_1;
  local_1c = (int)(char)param_1[1];
  bVar2 = true;
  iVar4 = (&DAT_00437df4)[local_1c];
  local_14 = in_EAX;
  for (; 0 < unaff_EBX; unaff_EBX = unaff_EBX + -1) {
    bVar1 = *local_14;
    local_14 = local_14 + 1;
    iVar6 = (*(int *)((uint)bVar1 * 2 + 0x426f90) >> 0x10) - iVar5;
    if (iVar6 < 0) {
      uVar7 = 8;
    }
    else {
      uVar7 = 0;
    }
    if (uVar7 != 0) {
      iVar6 = -iVar6;
    }
    uVar8 = 0;
    iVar9 = iVar4 >> 3;
    if (iVar4 <= iVar6) {
      uVar8 = 4;
      iVar6 = iVar6 - iVar4;
      iVar9 = iVar9 + iVar4;
    }
    iVar3 = iVar4 >> 1;
    if (iVar3 <= iVar6) {
      uVar8 = uVar8 | 2;
      iVar6 = iVar6 - iVar3;
      iVar9 = iVar9 + iVar3;
    }
    if (iVar4 >> 2 <= iVar6) {
      uVar8 = uVar8 | 1;
      iVar9 = iVar9 + (iVar4 >> 2);
    }
    if (uVar7 != 0) {
      iVar9 = -iVar9;
    }
    iVar5 = iVar5 + iVar9;
    if (iVar5 < 0x8000) {
      if (iVar5 < -0x8000) {
        iVar5 = -0x8000;
      }
    }
    else {
      iVar5 = 0x7fff;
    }
    uVar8 = uVar8 | uVar7;
    local_1c = local_1c + *(int *)(&DAT_00437db4 + uVar8 * 4);
    if (local_1c < 0) {
      local_1c = 0;
    }
    if (0x58 < local_1c) {
      local_1c = 0x58;
    }
    iVar4 = (&DAT_00437df4)[local_1c];
    if (bVar2) {
      local_20 = uVar8 << 4;
    }
    else {
      *param_2 = (byte)uVar8 | (byte)local_20;
      param_2 = param_2 + 1;
    }
    bVar2 = !bVar2;
  }
  if (!bVar2) {
    *param_2 = (byte)local_20;
  }
  *param_1 = (short)iVar5;
  *(undefined1 *)(param_1 + 1) = (undefined1)local_1c;
  return;
}


