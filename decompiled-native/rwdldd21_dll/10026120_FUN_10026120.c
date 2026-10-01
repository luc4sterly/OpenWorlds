// 10026120 FUN_10026120 [Global]
// program: RWDLDD21.DLL

/* WARNING: Removing unreachable block (ram,0x10026131) */
/* WARNING: Removing unreachable block (ram,0x100261c1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10026120(void)

{
  int iVar1;
  byte bVar2;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  
  log2((float10)_DAT_100346a0);
  iVar1 = 0x100;
  do {
    iVar5 = iVar1 + 1;
    log2(((float10)_DAT_1003462c + (float10)iVar1) * (float10)_DAT_100346a8);
    log2((float10)iVar1 * (float10)_DAT_100346a8);
    lVar7 = __ftol();
    (&DAT_100455e0)[iVar1] = (char)lVar7;
    iVar1 = iVar5;
  } while (iVar5 < 0x200);
  DAT_100362b8 = &DAT_100455e0;
  iVar1 = (**(code **)(DAT_100394fc + 0x34c))(0x10000);
  if (iVar1 == 0) {
    DAT_100362bc = 0;
  }
  else {
    iVar3 = -0x1f;
    iVar4 = -0x1f00;
    iVar5 = extraout_ECX;
    do {
      iVar6 = -0x100;
      do {
        FUN_10029bc2(iVar5);
        FUN_10029bc2(extraout_ECX_00);
        lVar7 = __ftol();
        if (iVar4 < 1) {
          bVar2 = -(byte)iVar3;
          iVar5 = CONCAT31((int3)((uint)iVar3 >> 8),bVar2);
          *(int *)(iVar1 + 0x8000 + (iVar6 + iVar4) * 4) = (int)lVar7 << (bVar2 & 0x1f);
        }
        else {
          iVar5 = iVar6 + iVar4;
          *(int *)(iVar1 + 0x8000 + iVar5 * 4) = (int)lVar7 >> ((byte)iVar3 & 0x1f);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0);
      iVar4 = iVar4 + 0x100;
      iVar3 = iVar3 + 1;
    } while (iVar4 < 0x2000);
    DAT_100362bc = iVar1 + 0x8000;
  }
  if (DAT_100362bc == 0) {
    return 0;
  }
  _DAT_100457e0 = DAT_100362bc;
  return 1;
}


