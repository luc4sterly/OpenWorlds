// 1000bc1b FUN_1000bc1b [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __fastcall FUN_1000bc1b(undefined4 param_1,uint param_2)

{
  byte bVar1;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool in_ZF;
  undefined8 uVar8;
  longlong lVar9;
  
  if (in_ZF) {
    DAT_10087230 = (undefined *)0x0;
  }
  else {
    log2((float10)_DAT_100860b0);
    iVar5 = 0x100;
    do {
      iVar6 = iVar5 + 1;
      log2(((float10)_DAT_1008603c + (float10)iVar5) * (float10)_DAT_100860b8);
      log2((float10)iVar5 * (float10)_DAT_100860b8);
      lVar9 = __ftol();
      param_2 = (uint)((ulonglong)lVar9 >> 0x20);
      (&DAT_1008d5c0)[iVar5] = (char)lVar9;
      iVar5 = iVar6;
    } while (iVar6 < 0x200);
    DAT_10087230 = &DAT_1008d5c0;
  }
  if (DAT_10087230 == (undefined *)0x0) {
    return (ulonglong)param_2 << 0x20;
  }
  uVar8 = (**(code **)(DAT_10089de0 + 0x34c))(0x10000);
  uVar2 = (uint)((ulonglong)uVar8 >> 0x20);
  iVar5 = (int)uVar8;
  if (iVar5 == 0) {
    DAT_10087234 = 0;
  }
  else {
    iVar3 = -0x1f;
    iVar4 = -0x1f00;
    iVar6 = extraout_ECX;
    do {
      iVar7 = -0x100;
      do {
        FUN_10060ae2(iVar6);
        FUN_10060ae2(extraout_ECX_00);
        lVar9 = __ftol();
        uVar2 = (uint)((ulonglong)lVar9 >> 0x20);
        if (iVar4 < 1) {
          uVar2 = iVar4 + iVar7;
          bVar1 = -(byte)iVar3;
          iVar6 = CONCAT31((int3)((uint)iVar3 >> 8),bVar1);
          *(int *)(iVar5 + 0x8000 + uVar2 * 4) = (int)lVar9 << (bVar1 & 0x1f);
        }
        else {
          iVar6 = iVar4 + iVar7;
          *(int *)(iVar5 + 0x8000 + iVar6 * 4) = (int)lVar9 >> ((byte)iVar3 & 0x1f);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 0);
      iVar4 = iVar4 + 0x100;
      iVar3 = iVar3 + 1;
    } while (iVar4 < 0x2000);
    DAT_10087234 = iVar5 + 0x8000;
  }
  if (DAT_10087234 == 0) {
    return (ulonglong)uVar2 << 0x20;
  }
  DAT_1008d7c0 = DAT_10087234;
  return CONCAT44(uVar2,1);
}


