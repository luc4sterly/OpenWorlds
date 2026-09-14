// 00436610 FUN_00436610 [Global]
// programa: gamma.dll

void * __cdecl FUN_00436610(void *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined **ppuVar5;
  int iVar6;
  char *pcVar7;
  void *pvVar8;
  int local_8c4;
  undefined1 local_8b2;
  undefined1 uStack_8b1;
  undefined1 uStack_8b0;
  undefined1 uStack_8af;
  undefined1 local_8ae;
  undefined1 local_8ad;
  undefined **local_8ac;
  char local_8a8 [255];
  undefined1 local_7a9;
  undefined **local_7a8;
  char local_7a4 [255];
  undefined1 local_6a5;
  undefined **local_6a4;
  char local_6a0 [255];
  undefined1 local_5a1;
  undefined4 local_5a0;
  undefined4 local_59c [71];
  undefined4 local_480 [71];
  undefined **local_364;
  int local_360 [2];
  undefined **local_358;
  int local_354 [2];
  undefined **local_34c;
  char local_348 [258];
  undefined2 local_246;
  undefined **local_244;
  char local_240 [258];
  undefined2 local_13e;
  undefined **local_13c;
  char acStack_138 [258];
  undefined2 local_36;
  undefined **local_34;
  int local_30 [2];
  undefined ***local_28;
  undefined ***local_24;
  undefined ***local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  
  FUN_0042f460(param_1,&local_8b2,2);
  uVar2 = uStack_8b1;
  uVar1 = local_8b2;
  local_8b2 = uStack_8b1;
  uStack_8b1 = uVar1;
  *(ushort *)(param_2 + 0x214) = CONCAT11(uVar1,uVar2);
  iVar6 = *(int *)((int)param_1 + 4);
  if (((*(byte *)(iVar6 + 0x32) & 5) != 0) || (*(short *)(param_2 + 0x214) < 1)) {
    *(byte *)(iVar6 + 0x32) = *(byte *)(iVar6 + 0x32) & 4;
    if (*(int *)(iVar6 + 0x24) == 0) {
      *(byte *)(iVar6 + 0x32) = *(byte *)(iVar6 + 0x32) | 1;
    }
    if ((*(byte *)(iVar6 + 0x33) & *(byte *)(iVar6 + 0x32)) != 0) {
      local_28 = &local_364;
      local_364 = &PTR_LAB_0046d4fc;
      local_1c = local_360;
      iVar6 = FUN_00450b60(0x1a);
      FUN_00403d80(local_1c,iVar6);
      pcVar7 = (char *)*local_1c;
      *(undefined4 *)pcVar7 = s_ios_base_failure_in_clear_00475b78._0_4_;
      *(undefined4 *)(pcVar7 + 4) = s_ios_base_failure_in_clear_00475b78._4_4_;
      *(undefined4 *)(pcVar7 + 8) = s_ios_base_failure_in_clear_00475b78._8_4_;
      *(undefined4 *)(pcVar7 + 0xc) = s_ios_base_failure_in_clear_00475b78._12_4_;
      *(undefined4 *)(pcVar7 + 0x10) = s_ios_base_failure_in_clear_00475b78._16_4_;
      *(undefined4 *)(pcVar7 + 0x14) = s_ios_base_failure_in_clear_00475b78._20_4_;
      *(undefined2 *)(pcVar7 + 0x18) = s_ios_base_failure_in_clear_00475b78._24_2_;
      FUN_00451670();
    }
    return param_1;
  }
  FUN_0042f460(param_1,&uStack_8b0,4);
  uVar4 = local_8ad;
  uVar3 = local_8ae;
  uVar2 = uStack_8af;
  uVar1 = uStack_8b0;
  uStack_8b0 = local_8ad;
  local_8ad = uVar1;
  uStack_8af = local_8ae;
  local_8ae = uVar2;
  iVar6 = *(int *)((int)param_1 + 4);
  if (((*(byte *)(iVar6 + 0x32) & 5) == 0) &&
     (0 < CONCAT13(uVar1,CONCAT12(uVar2,CONCAT11(uVar3,uVar4))))) {
    local_8ac = &PTR_LAB_00471ff8;
    local_8a8[0] = '\0';
    FUN_0042f460(param_1,(undefined1 *)&local_246,2);
    local_246 = CONCAT11((undefined1)local_246,local_246._1_1_);
    pcVar7 = (char *)FUN_00450b60((int)local_246);
    FUN_0042f460(param_1,pcVar7,(int)local_246);
    FUN_00427410(&local_34c,pcVar7,0xff);
    FUN_0044d6d0(local_8a8,local_348,0xff);
    local_7a9 = 0;
    local_34c = &PTR_LAB_00471ff8;
    FUN_00451780((undefined4 *)pcVar7);
    FUN_0044d6d0((char *)(param_2 + 0x10),local_8a8,0xff);
    *(undefined1 *)(param_2 + 0x10f) = 0;
    if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) {
      return param_1;
    }
    local_7a8 = &PTR_LAB_00471ff8;
    local_7a4[0] = '\0';
    FUN_0042f460(param_1,(undefined1 *)&local_13e,2);
    local_13e = CONCAT11((undefined1)local_13e,local_13e._1_1_);
    pcVar7 = (char *)FUN_00450b60((int)local_13e);
    FUN_0042f460(param_1,pcVar7,(int)local_13e);
    FUN_00427410(&local_244,pcVar7,0xff);
    FUN_0044d6d0(local_7a4,local_240,0xff);
    local_6a5 = 0;
    local_244 = &PTR_LAB_00471ff8;
    FUN_00451780((undefined4 *)pcVar7);
    FUN_0044d6d0((char *)(param_2 + 0x114),local_7a4,0xff);
    *(undefined1 *)(param_2 + 0x213) = 0;
    if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) {
      return param_1;
    }
    FUN_004379a0((void *)(param_2 + 0x218),*(undefined4 **)(param_2 + 0x220),
                 *(undefined4 **)(param_2 + 0x220) + *(int *)(param_2 + 0x21c) * 0x47);
    FUN_00437ad0((void *)(param_2 + 0x218),
                 CONCAT13(local_8ad,CONCAT12(local_8ae,CONCAT11(uStack_8af,uStack_8b0))));
    local_8c4 = 0;
    if (0 < CONCAT13(local_8ad,CONCAT12(local_8ae,CONCAT11(uStack_8af,uStack_8b0)))) {
      ppuVar5 = local_6a4;
      do {
        local_6a4 = ppuVar5;
        FUN_00435730(local_59c);
        FUN_00437a70((void *)(param_2 + 0x218),local_59c);
        FUN_00435970(local_59c);
        local_6a4 = &PTR_LAB_00471ff8;
        local_6a0[0] = '\0';
        FUN_0042f460(param_1,(undefined1 *)&local_36,2);
        local_36 = CONCAT11((undefined1)local_36,local_36._1_1_);
        pcVar7 = (char *)FUN_00450b60((int)local_36);
        FUN_0042f460(param_1,pcVar7,(int)local_36);
        FUN_00427410(&local_13c,pcVar7,0xff);
        FUN_0044d6d0(local_6a0,acStack_138,0xff);
        local_5a1 = 0;
        local_13c = &PTR_LAB_00471ff8;
        FUN_00451780((undefined4 *)pcVar7);
        if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) {
          return param_1;
        }
        FUN_004364e0(param_1,*(int *)(param_2 + 0x21c) * 0x11c + *(int *)(param_2 + 0x220) + -0x11c)
        ;
        FUN_004359a0((void *)(*(int *)(param_2 + 0x21c) * 0x11c + *(int *)(param_2 + 0x220) + -0x11c
                             ),(int)&local_6a4);
        if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) {
          return param_1;
        }
        local_8c4 = local_8c4 + 1;
        local_6a4 = &PTR_LAB_00471ff8;
        ppuVar5 = &PTR_LAB_00471ff8;
      } while (local_8c4 < CONCAT13(local_8ad,CONCAT12(local_8ae,CONCAT11(uStack_8af,uStack_8b0))));
    }
    FUN_0042f460(param_1,(undefined1 *)&local_5a0,4);
    uVar1 = (undefined1)local_5a0;
    uVar2 = local_5a0._1_1_;
    local_5a0._0_2_ = CONCAT11(local_5a0._2_1_,local_5a0._3_1_);
    local_5a0 = CONCAT13(uVar1,CONCAT12(uVar2,(undefined2)local_5a0));
    iVar6 = *(int *)((int)param_1 + 4);
    if ((*(byte *)(iVar6 + 0x32) & 5) != 0) {
      *(byte *)(iVar6 + 0x32) = *(byte *)(iVar6 + 0x32) & 4;
      if (*(int *)(iVar6 + 0x24) == 0) {
        *(byte *)(iVar6 + 0x32) = *(byte *)(iVar6 + 0x32) | 1;
      }
      if ((*(byte *)(iVar6 + 0x33) & *(byte *)(iVar6 + 0x32)) != 0) {
        local_20 = &local_34;
        local_34 = &PTR_LAB_0046d4fc;
        local_14 = local_30;
        iVar6 = FUN_00450b60(0x1a);
        FUN_00403d80(local_14,iVar6);
        pcVar7 = (char *)*local_14;
        *(undefined4 *)pcVar7 = s_ios_base_failure_in_clear_00475b78._0_4_;
        *(undefined4 *)(pcVar7 + 4) = s_ios_base_failure_in_clear_00475b78._4_4_;
        *(undefined4 *)(pcVar7 + 8) = s_ios_base_failure_in_clear_00475b78._8_4_;
        *(undefined4 *)(pcVar7 + 0xc) = s_ios_base_failure_in_clear_00475b78._12_4_;
        *(undefined4 *)(pcVar7 + 0x10) = s_ios_base_failure_in_clear_00475b78._16_4_;
        *(undefined4 *)(pcVar7 + 0x14) = s_ios_base_failure_in_clear_00475b78._20_4_;
        *(undefined2 *)(pcVar7 + 0x18) = s_ios_base_failure_in_clear_00475b78._24_2_;
        FUN_00451670();
      }
      return param_1;
    }
    FUN_004379a0((void *)(param_2 + 0x224),*(undefined4 **)(param_2 + 0x22c),
                 *(undefined4 **)(param_2 + 0x22c) + *(int *)(param_2 + 0x228) * 0x47);
    FUN_00437ad0((void *)(param_2 + 0x224),local_5a0);
    iVar6 = 0;
    if (0 < (int)local_5a0) {
      do {
        FUN_00435730(local_480);
        FUN_00437a70((void *)(param_2 + 0x224),local_480);
        FUN_00435970(local_480);
        pvVar8 = FUN_004364e0(param_1,*(int *)(param_2 + 0x228) * 0x11c + *(int *)(param_2 + 0x22c)
                                      + -0x11c);
        if ((*(byte *)(*(int *)((int)pvVar8 + 4) + 0x32) & 5) != 0) {
          return param_1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)local_5a0);
    }
    return param_1;
  }
  *(byte *)(iVar6 + 0x32) = *(byte *)(iVar6 + 0x32) & 4;
  if (*(int *)(iVar6 + 0x24) == 0) {
    *(byte *)(iVar6 + 0x32) = *(byte *)(iVar6 + 0x32) | 1;
  }
  if ((*(byte *)(iVar6 + 0x33) & *(byte *)(iVar6 + 0x32)) != 0) {
    local_24 = &local_358;
    local_358 = &PTR_LAB_0046d4fc;
    local_18 = local_354;
    iVar6 = FUN_00450b60(0x1a);
    FUN_00403d80(local_18,iVar6);
    pcVar7 = (char *)*local_18;
    *(undefined4 *)pcVar7 = s_ios_base_failure_in_clear_00475b78._0_4_;
    *(undefined4 *)(pcVar7 + 4) = s_ios_base_failure_in_clear_00475b78._4_4_;
    *(undefined4 *)(pcVar7 + 8) = s_ios_base_failure_in_clear_00475b78._8_4_;
    *(undefined4 *)(pcVar7 + 0xc) = s_ios_base_failure_in_clear_00475b78._12_4_;
    *(undefined4 *)(pcVar7 + 0x10) = s_ios_base_failure_in_clear_00475b78._16_4_;
    *(undefined4 *)(pcVar7 + 0x14) = s_ios_base_failure_in_clear_00475b78._20_4_;
    *(undefined2 *)(pcVar7 + 0x18) = s_ios_base_failure_in_clear_00475b78._24_2_;
    FUN_00451670();
  }
  return param_1;
}


