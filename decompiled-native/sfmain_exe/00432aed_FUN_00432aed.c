// 00432aed FUN_00432aed [Global]
// program: sfmain.exe

float10 __fastcall FUN_00432aed(uint param_1,undefined4 *param_2)

{
  byte bVar1;
  byte *in_EAX;
  byte *pbVar2;
  byte *pbVar3;
  byte extraout_CL;
  uint uVar4;
  uint extraout_ECX;
  undefined4 extraout_ECX_00;
  uint extraout_ECX_01;
  byte bVar6;
  uint uVar5;
  undefined4 extraout_EDX;
  int iVar7;
  int iVar8;
  float10 extraout_ST0;
  undefined4 local_40;
  byte local_3c [20];
  undefined8 local_28;
  int local_20;
  byte *local_1c;
  byte *local_18;
  
  for (pbVar2 = in_EAX; (bVar6 = *pbVar2, bVar6 == 0x20 || ((8 < bVar6 && (bVar6 < 0xe))));
      pbVar2 = pbVar2 + 1) {
  }
  uVar4 = param_1 & 0xffffff00;
  pbVar3 = pbVar2 + 1;
  if ((bVar6 != 0x2b) && (pbVar3 = pbVar2, bVar6 == 0x2d)) {
    uVar4 = CONCAT31((int3)(param_1 >> 8),1);
    pbVar3 = pbVar2 + 1;
  }
  iVar7 = 0;
  bVar6 = 0x30;
  local_20 = 0;
  local_18 = in_EAX;
  while( true ) {
    while( true ) {
      bVar1 = *pbVar3;
      uVar4 = CONCAT22((short)(uVar4 >> 0x10),CONCAT11((char)uVar4,(char)uVar4)) & 0xffff08ff;
      pbVar2 = pbVar3 + 1;
      if (bVar1 != 0x2e) break;
      if ((uVar4 >> 8 & 0xff) != 0) goto LAB_00432b7a;
      uVar4 = uVar4 | 8;
      pbVar3 = pbVar2;
    }
    if ((bVar1 < 0x30) || (0x39 < bVar1)) break;
    if ((uVar4 >> 8 & 0xff) != 0) {
      local_20 = local_20 + 1;
    }
    bVar6 = bVar6 | bVar1;
    if (bVar6 != 0x30) {
      if (iVar7 < 0x11) {
        local_3c[iVar7] = bVar1;
      }
      iVar7 = iVar7 + 1;
    }
    uVar4 = uVar4 | 4;
    pbVar3 = pbVar2;
  }
LAB_00432b7a:
  iVar8 = 0;
  if (((CONCAT11((char)uVar4,bVar1) & 0x4ff) >> 8 != 0) &&
     ((bVar1 == 0x65 || (local_18 = pbVar3, bVar1 == 0x45)))) {
    local_18 = pbVar3 + 2;
    if ((*pbVar2 != 0x2b) && (local_18 = pbVar2, *pbVar2 == 0x2d)) {
      uVar4 = uVar4 | 2;
      local_18 = pbVar3 + 2;
    }
    uVar4 = uVar4 & 0xfffffffb;
    for (; (uVar5 = (uint)*local_18, 0x2f < uVar5 && (uVar5 < 0x3a)); local_18 = local_18 + 1) {
      if (iVar8 < 1000) {
        iVar8 = uVar5 + iVar8 * 10 + -0x30;
      }
      uVar4 = uVar4 | 4;
    }
    if ((uVar4 & 2) != 0) {
      iVar8 = -iVar8;
    }
    local_1c = pbVar3;
    if ((uVar4 & 4) == 0) {
      local_18 = pbVar3;
    }
  }
  iVar8 = iVar8 - local_20;
  if (0x11 < iVar7) {
    iVar8 = iVar8 + iVar7 + -0x11;
    iVar7 = 0x11;
  }
  for (; (0 < iVar7 && (local_3c[iVar7 + -1] == 0x30)); iVar7 = iVar7 + -1) {
    iVar8 = iVar8 + 1;
  }
  local_40 = param_2;
  if (iVar7 == 0) {
    local_28 = 0.0;
    goto LAB_00432cc8;
  }
  local_3c[iVar7] = 0;
  FUN_004336c0(uVar4,&local_28);
  iVar7 = iVar8 + -1 + iVar7;
  if (iVar7 < 0x135) {
    if (iVar7 < -0x134) {
      FUN_0042d8bb(0,extraout_EDX);
      local_28 = (double)CONCAT44(extraout_ECX_00,extraout_ECX_00);
      goto LAB_00432cc8;
    }
    uVar4 = extraout_ECX;
    if (iVar8 != 0) {
      FUN_00433336(extraout_ECX,local_28._4_4_,(undefined4)local_28,local_28._4_4_,iVar8);
      local_28 = (double)extraout_ST0;
      uVar4 = extraout_ECX_01;
    }
    if ((uVar4 & 1) == 0) goto LAB_00432cc8;
  }
  else {
    FUN_0042d8bb(extraout_ECX,extraout_EDX);
    if ((extraout_CL & 1) == 0) {
      local_28 = (double)CONCAT44(DAT_00437d24,DAT_00437d20);
      goto LAB_00432cc8;
    }
    local_28 = (double)CONCAT44(DAT_00437d24,DAT_00437d20);
  }
  local_28 = -local_28;
LAB_00432cc8:
  if (local_40 != (undefined4 *)0x0) {
    *local_40 = local_18;
  }
  return (float10)local_28;
}


