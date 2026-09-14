// 004298b0 FUN_004298b0 [Global]
// programa: gamma.dll

/* WARNING: Removing unreachable block (ram,0x004298e1) */

void FUN_004298b0(void)

{
  undefined **ppuVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined **ppuVar7;
  undefined **local_114 [65];
  
  if (DAT_0049fa80 != 0) {
    return;
  }
  if (DAT_0049fa7c == 0) {
    FUN_00429b40(&DAT_0049fa7c,1);
  }
  iVar3 = DAT_0049fa80;
  DAT_0049fa80 = DAT_0049fa80 + 1;
  *(undefined4 *)(DAT_0049fa84 + iVar3 * 4) = DAT_00473894;
  if (DAT_0049fa80 == DAT_0049fa7c) {
    if (DAT_0049fa7c == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = DAT_0049fa7c * 2;
    }
    FUN_00429b40(&DAT_0049fa7c,uVar6);
  }
  iVar3 = DAT_0049fa80;
  DAT_0049fa80 = DAT_0049fa80 + 1;
  *(undefined4 *)(DAT_0049fa84 + iVar3 * 4) = DAT_00473898;
  if (DAT_0049fa80 == DAT_0049fa7c) {
    if (DAT_0049fa7c == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = DAT_0049fa7c * 2;
    }
    FUN_00429b40(&DAT_0049fa7c,uVar6);
  }
  iVar3 = DAT_0049fa80;
  DAT_0049fa80 = DAT_0049fa80 + 1;
  *(undefined4 *)(DAT_0049fa84 + iVar3 * 4) = DAT_0047389c;
  if (DAT_0049f96c == DAT_0049f968) {
    if (DAT_0049f968 == 0) {
      uVar6 = 1;
    }
    else {
      uVar6 = DAT_0049f968 * 2;
    }
    FUN_00429b40(&DAT_0049f968,uVar6);
  }
  iVar3 = DAT_0049f96c;
  DAT_0049f96c = DAT_0049f96c + 1;
  *(undefined4 *)(DAT_0049f970 + iVar3 * 4) = DAT_004738a0;
  ppuVar7 = &PTR_s_pelvis_00474620;
  uVar6 = 1;
  do {
    pcVar2 = *(char **)(uVar6 * 8 + 0x474618);
    if (*pcVar2 == '\0') {
      return;
    }
    FUN_00427410(local_114,pcVar2,0xff);
    uVar4 = FUN_004296f0((int)local_114);
    local_114[0] = &PTR_LAB_00471ff8;
    if (DAT_0049f96c == DAT_0049f968) {
      if (DAT_0049f968 == 0) {
        uVar5 = 1;
      }
      else {
        uVar5 = DAT_0049f968 * 2;
      }
      FUN_00429b40(&DAT_0049f968,uVar5);
    }
    iVar3 = DAT_0049f96c;
    DAT_0049f96c = DAT_0049f96c + 1;
    *(undefined4 *)(DAT_0049f970 + iVar3 * 4) = uVar4;
    if (DAT_0049fa80 == DAT_0049fa7c) {
      if (DAT_0049fa7c == 0) {
        uVar5 = 1;
      }
      else {
        uVar5 = DAT_0049fa7c * 2;
      }
      FUN_00429b40(&DAT_0049fa7c,uVar5);
    }
    iVar3 = DAT_0049fa80;
    uVar6 = uVar6 + 1;
    DAT_0049fa80 = DAT_0049fa80 + 1;
    ppuVar1 = ppuVar7 + 1;
    ppuVar7 = ppuVar7 + 2;
    *(undefined **)(DAT_0049fa84 + iVar3 * 4) = *ppuVar1;
  } while (uVar6 < 0x1f);
  return;
}


