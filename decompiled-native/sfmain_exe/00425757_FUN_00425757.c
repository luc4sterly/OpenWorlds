// 00425757 FUN_00425757 [Global]
// program: sfmain.exe

uint __fastcall FUN_00425757(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int *in_EAX;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar7;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined8 uVar8;
  undefined1 local_33c;
  undefined4 local_334;
  byte local_330 [4];
  undefined4 local_32c;
  byte local_328 [504];
  undefined1 local_130 [256];
  byte *local_20;
  byte *local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  
  local_20 = local_330;
  local_14 = 0;
  if (param_3 != 0) {
    local_330[0] = 0x80;
    local_330[1] = 0xc9;
    local_330[2] = 0;
    local_330[3] = 1;
    local_32c = Ordinal_8(param_2);
    local_20 = local_328;
    local_14 = 8;
  }
  uVar2 = Ordinal_9(0x81ca);
  *(undefined2 *)local_20 = uVar2;
  uVar4 = Ordinal_8(param_2);
  *(undefined4 *)(local_20 + 4) = uVar4;
  if (param_1 == 0) {
    local_20[8] = 1;
    iVar5 = FUN_0042c5ad();
    local_18._0_1_ = (byte)iVar5;
    local_20[9] = (byte)local_18;
    FUN_004080a4(extraout_ECX_01,&DAT_0045e280);
  }
  else {
    local_130[0] = 0x2a;
    FUN_0042c5c6(extraout_ECX,&DAT_0045e280);
    local_20[8] = 1;
    iVar5 = FUN_0042c5ad();
    local_18._0_1_ = (byte)iVar5;
    local_20[9] = (byte)local_18;
    FUN_004080a4(extraout_ECX_00,local_130);
  }
  local_1c = local_20 + iVar5 + 10;
  if (DAT_0045e230 != '\0') {
    *local_1c = 2;
    iVar5 = FUN_0042c5ad();
    local_18._0_1_ = (byte)iVar5;
    local_1c[1] = (byte)local_18;
    FUN_004080a4(extraout_ECX_02,&DAT_0045e230);
    local_1c = local_1c + iVar5 + 2;
  }
  *local_1c = 3;
  iVar5 = FUN_0042c5ad();
  local_18._0_1_ = (byte)iVar5;
  local_1c[1] = (byte)local_18;
  FUN_004080a4(extraout_ECX_03,&DAT_0045e280);
  local_1c = local_1c + iVar5 + 2;
  uVar4 = extraout_ECX_04;
  uVar7 = extraout_EDX;
  if (DAT_0045e2d0 != '\0') {
    *local_1c = 4;
    iVar5 = FUN_0042c5ad();
    local_18._0_1_ = (byte)iVar5;
    local_1c[1] = (byte)local_18;
    FUN_004080a4(extraout_ECX_05,&DAT_0045e2d0);
    local_1c = local_1c + iVar5 + 2;
    uVar4 = extraout_ECX_06;
    uVar7 = extraout_EDX_00;
  }
  if (DAT_0045e320 != '\0') {
    *local_1c = 5;
    iVar5 = FUN_0042c5ad();
    local_18._0_1_ = (byte)iVar5;
    local_1c[1] = (byte)local_18;
    FUN_004080a4(extraout_ECX_07,&DAT_0045e320);
    local_1c = local_1c + iVar5 + 2;
    uVar4 = extraout_ECX_08;
    uVar7 = extraout_EDX_01;
  }
  *local_1c = 6;
  FUN_00429192(uVar4,uVar7);
  iVar5 = FUN_0042c5ad();
  local_18._0_1_ = (byte)iVar5;
  local_1c[1] = (byte)local_18;
  uVar8 = FUN_00429192(extraout_ECX_09,CONCAT31((int3)((uint)extraout_EDX_02 >> 8),(byte)local_18));
  FUN_004080a4(extraout_ECX_10,(undefined1 *)uVar8);
  local_1c = local_1c + iVar5 + 2;
  if (param_3 == 0) {
    uVar8 = FUN_00429192(extraout_ECX_11,extraout_EDX_03);
    FUN_0042ca26((int)local_130,(byte *)uVar8);
    *local_1c = 8;
    iVar5 = FUN_0042c5ad();
    local_18._0_1_ = (byte)iVar5;
    local_1c[1] = (byte)local_18;
    FUN_004080a4(extraout_ECX_12,local_130);
    local_1c = local_1c + iVar5 + 2;
  }
  *local_1c = 0;
  local_1c[1] = 0;
  iVar5 = (int)(local_1c + (5 - (int)local_20)) >> 0x1f;
  uVar2 = Ordinal_9(((int)(local_1c + (5 - (int)local_20) + (iVar5 * -4 - (uint)(iVar5 << 1 < 0)))
                    >> 2) - 1U & 0xffff);
  *(undefined2 *)(local_20 + 2) = uVar2;
  uVar6 = Ordinal_15(*(undefined2 *)(local_20 + 2));
  uVar6 = local_14 + (uVar6 & 0xffff) * 4 + 4;
  uVar4 = extraout_ECX_13;
  local_18 = uVar6;
  if (param_3 != 0) {
    local_334 = uVar6;
    if ((uVar6 & 4) == 0) {
      local_334 = uVar6 + 4;
    }
    uVar1 = local_334;
    if (uVar6 < local_334) {
      iVar5 = local_334 - uVar6;
      FUN_00408098(extraout_ECX_13,0);
      local_33c = (undefined1)iVar5;
      *(undefined1 *)((int)&local_334 + uVar1 + 3) = local_33c;
      *local_20 = *local_20 | 0x20;
      uVar3 = Ordinal_15(*(undefined2 *)(local_20 + 2));
      uVar6 = Ordinal_9(((int)((iVar5 + (iVar5 >> 0x1f) * -4) - (uint)((iVar5 >> 0x1f) << 1 < 0)) >>
                        2) + (uint)uVar3 & 0xffff);
      *(short *)(local_20 + 2) = (short)uVar6;
      local_18 = uVar1;
      uVar4 = extraout_ECX_14;
    }
  }
  uVar8 = FUN_0042ba46(uVar4,uVar6);
  *in_EAX = (int)uVar8;
  if (*in_EAX == 0) {
    local_10 = 0;
  }
  else {
    FUN_004080a4(extraout_ECX_15,local_330);
    local_10 = local_18;
  }
  return local_10;
}


