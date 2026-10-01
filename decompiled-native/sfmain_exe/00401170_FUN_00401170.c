// 00401170 FUN_00401170 [Global]
// program: sfmain.exe

void __fastcall FUN_00401170(short *param_1,undefined1 *param_2)

{
  uint uVar1;
  bool bVar2;
  char *in_EAX;
  uint uVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int iVar6;
  uint local_18;
  char *local_10;
  
  uVar3 = (uint)*param_1;
  iVar4 = (int)(char)param_1[1];
  bVar2 = false;
  iVar6 = (&DAT_00437df4)[iVar4];
  local_10 = in_EAX;
  for (; 0 < unaff_EBX; unaff_EBX = unaff_EBX + -1) {
    uVar1 = local_18;
    if (!bVar2) {
      local_18 = (uint)*local_10;
      local_10 = local_10 + 1;
      uVar1 = (int)local_18 >> 4;
    }
    bVar2 = !bVar2;
    iVar4 = iVar4 + *(int *)(&DAT_00437db4 + (uVar1 & 0xf) * 4);
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    if (0x58 < iVar4) {
      iVar4 = 0x58;
    }
    iVar5 = iVar6 >> 3;
    if ((uVar1 & 4) != 0) {
      iVar5 = iVar5 + iVar6;
    }
    if ((uVar1 & 2) != 0) {
      iVar5 = iVar5 + (iVar6 >> 1);
    }
    if ((uVar1 & 1) != 0) {
      iVar5 = iVar5 + (iVar6 >> 2);
    }
    if ((uVar1 & 8) != 0) {
      iVar5 = -iVar5;
    }
    uVar3 = uVar3 + iVar5;
    if ((int)uVar3 < 0x8000) {
      if ((int)uVar3 < -0x8000) {
        uVar3 = 0xffff8000;
      }
    }
    else {
      uVar3 = 0x7fff;
    }
    iVar6 = (&DAT_00437df4)[iVar4];
    *param_2 = (&DAT_00427192)[(int)(uVar3 & 0xffff) >> 3];
    param_2 = param_2 + 1;
  }
  *param_1 = (short)uVar3;
  *(char *)(param_1 + 1) = (char)iVar4;
  return;
}


