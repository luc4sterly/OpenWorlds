// 00436d50 FUN_00436d50 [Global]
// program: gamma.dll

/* WARNING: Type propagation algorithm not settling */

void * __cdecl FUN_00436d50(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  uint uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  void *pvVar14;
  int iVar15;
  short local_4cc;
  int local_4c8;
  undefined4 local_4b0;
  byte local_4a9;
  undefined **local_4a8;
  char local_4a4 [258];
  ushort local_3a2 [3];
  char local_39c [259];
  byte local_299;
  undefined4 local_298 [71];
  undefined4 local_17c [71];
  undefined **local_60;
  int local_5c [2];
  undefined **local_54;
  int local_50 [2];
  undefined **local_48;
  int local_44 [2];
  undefined **local_3c;
  int local_38 [2];
  undefined ***local_30;
  undefined ***local_2c;
  undefined ***local_28;
  undefined ***local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  
  local_4b0 = 0;
  FUN_0042f460(param_1,(undefined1 *)&local_4b0,1);
  if (local_4b0 == 0x7f) {
    FUN_0042f460(param_1,(undefined1 *)((int)&local_4b0 + 1),3);
    uVar9 = (undefined1)local_4b0;
    uVar10 = local_4b0._1_1_;
    local_4b0._0_2_ = CONCAT11(local_4b0._2_1_,local_4b0._3_1_);
    local_4b0 = CONCAT13(uVar9,CONCAT12(uVar10,(undefined2)local_4b0));
    *(int *)(param_2 + 8) = local_4b0;
    FUN_00436610(param_1,param_2);
    return param_1;
  }
  *(int *)(param_2 + 8) = local_4b0;
  FUN_0042f460(param_1,&local_4a9,1);
  iVar11 = *(int *)((int)param_1 + 4);
  if (((*(byte *)(iVar11 + 0x32) & 5) != 0) || (local_4a9 == 0)) {
    *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) & 4;
    if (*(int *)(iVar11 + 0x24) == 0) {
      *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) | 1;
    }
    if ((*(byte *)(iVar11 + 0x33) & *(byte *)(iVar11 + 0x32)) != 0) {
      local_30 = &local_60;
      local_60 = &PTR_LAB_0046d4fc;
      local_20 = local_5c;
      iVar11 = FUN_00450b60(0x1a);
      FUN_00403d80(local_20,iVar11);
      pcVar7 = (char *)*local_20;
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
  local_4a8 = &PTR_LAB_00471ff8;
  local_4a4[0] = '\0';
  FUN_0042f3b0(param_1,(int)&local_4a8);
  FUN_0044d6d0((char *)(param_2 + 0x10),local_4a4,0xff);
  *(undefined1 *)(param_2 + 0x10f) = 0;
  if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) {
    return param_1;
  }
  FUN_0042f460(param_1,(undefined1 *)local_3a2,2);
  iVar11 = *(int *)((int)param_1 + 4);
  if (((*(byte *)(iVar11 + 0x32) & 5) == 0) && (local_3a2[0] != 0)) {
    pbVar12 = (byte *)FUN_00450b60((uint)local_3a2[0]);
    FUN_0042f460(param_1,pbVar12,(uint)local_3a2[0]);
    iVar11 = *(int *)((int)param_1 + 4);
    if (((*(byte *)(iVar11 + 0x32) & 5) == 0) && (local_3a2[0] != 0)) {
      iVar11 = 0;
      uVar8 = (uint)local_3a2[0];
      local_4cc = 0;
      if (local_3a2[0] != 0) {
        local_4cc = 0;
        if (8 < uVar8) {
          do {
            pbVar6 = pbVar12 + iVar11;
            iVar15 = iVar11 + 1;
            iVar13 = iVar11 + 2;
            iVar1 = iVar11 + 3;
            iVar2 = iVar11 + 4;
            iVar3 = iVar11 + 5;
            iVar4 = iVar11 + 6;
            iVar5 = iVar11 + 7;
            iVar11 = iVar11 + 8;
            local_4cc = local_4cc + (ushort)*pbVar6 + (ushort)pbVar12[iVar15] +
                        (ushort)pbVar12[iVar13] + (ushort)pbVar12[iVar1] + (ushort)pbVar12[iVar2] +
                        (ushort)pbVar12[iVar3] + (ushort)pbVar12[iVar4] + (ushort)pbVar12[iVar5];
          } while (iVar11 < (int)(uVar8 - 8));
        }
        for (; iVar11 < (int)uVar8; iVar11 = iVar11 + 1) {
          local_4cc = local_4cc + (ushort)pbVar12[iVar11];
        }
      }
      *(short *)(param_2 + 0x214) = local_4cc;
      FUN_004379a0((void *)(param_2 + 0x218),*(undefined4 **)(param_2 + 0x220),
                   *(undefined4 **)(param_2 + 0x220) + *(int *)(param_2 + 0x21c) * 0x47);
      FUN_00437ad0((void *)(param_2 + 0x218),(uint)local_4a9);
      local_4c8 = 0;
      while( true ) {
        if ((int)(uint)local_4a9 <= local_4c8) {
          FUN_0042f460(param_1,&local_299,1);
          iVar11 = *(int *)((int)param_1 + 4);
          if ((*(byte *)(iVar11 + 0x32) & 5) != 0) {
            *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) & 4;
            if (*(int *)(iVar11 + 0x24) == 0) {
              *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) | 1;
            }
            if ((*(byte *)(iVar11 + 0x33) & *(byte *)(iVar11 + 0x32)) != 0) {
              local_24 = &local_3c;
              local_3c = &PTR_LAB_0046d4fc;
              local_14 = local_38;
              iVar11 = FUN_00450b60(0x1a);
              FUN_00403d80(local_14,iVar11);
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
            FUN_00451780((undefined4 *)pbVar12);
            return param_1;
          }
          FUN_004379a0((void *)(param_2 + 0x224),*(undefined4 **)(param_2 + 0x22c),
                       *(undefined4 **)(param_2 + 0x22c) + *(int *)(param_2 + 0x228) * 0x47);
          FUN_00437ad0((void *)(param_2 + 0x224),(uint)local_299);
          iVar11 = 0;
          while( true ) {
            if ((int)(uint)local_299 <= iVar11) {
              FUN_00451780((undefined4 *)pbVar12);
              return param_1;
            }
            FUN_00435730(local_17c);
            FUN_00437a70((void *)(param_2 + 0x224),local_17c);
            FUN_00435970(local_17c);
            if (iVar11 == 3) {
              iVar13 = 0x10;
            }
            else {
              iVar13 = 4;
            }
            pvVar14 = FUN_00437550(param_1,*(int *)(param_2 + 0x228) * 0x11c +
                                           *(int *)(param_2 + 0x22c) + -0x11c,(uint)local_3a2[0],
                                   pbVar12,iVar13);
            if ((*(byte *)(*(int *)((int)pvVar14 + 4) + 0x32) & 5) != 0) break;
            iVar11 = iVar11 + 1;
          }
          FUN_00451780((undefined4 *)pbVar12);
          return param_1;
        }
        FUN_00435730(local_298);
        FUN_00437a70((void *)(param_2 + 0x218),local_298);
        FUN_00435970(local_298);
        local_3a2[1] = 0x1ff8;
        local_3a2[2] = 0x47;
        local_39c[0] = '\0';
        FUN_0042f3b0(param_1,(int)(local_3a2 + 1));
        if (((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) ||
           (pvVar14 = FUN_00437550(param_1,*(int *)(param_2 + 0x21c) * 0x11c +
                                           *(int *)(param_2 + 0x220) + -0x11c,(uint)local_3a2[0],
                                   pbVar12,0x10),
           (*(byte *)(*(int *)((int)pvVar14 + 4) + 0x32) & 5) != 0)) break;
        FUN_004359a0((void *)(*(int *)(param_2 + 0x21c) * 0x11c + *(int *)(param_2 + 0x220) + -0x11c
                             ),(int)(local_3a2 + 1));
        if (local_4c8 == 0) {
          FUN_0044d6d0((char *)(param_2 + 0x114),local_39c,0xff);
          *(undefined1 *)(param_2 + 0x213) = 0;
        }
        local_4c8 = local_4c8 + 1;
        local_3a2[1] = 0x1ff8;
        local_3a2[2] = 0x47;
      }
      FUN_00451780((undefined4 *)pbVar12);
      return param_1;
    }
    *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) & 4;
    if (*(int *)(iVar11 + 0x24) == 0) {
      *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) | 1;
    }
    if ((*(byte *)(iVar11 + 0x33) & *(byte *)(iVar11 + 0x32)) != 0) {
      local_28 = &local_48;
      local_48 = &PTR_LAB_0046d4fc;
      local_18 = local_44;
      iVar11 = FUN_00450b60(0x1a);
      FUN_00403d80(local_18,iVar11);
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
    FUN_00451780((undefined4 *)pbVar12);
    return param_1;
  }
  *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) & 4;
  if (*(int *)(iVar11 + 0x24) == 0) {
    *(byte *)(iVar11 + 0x32) = *(byte *)(iVar11 + 0x32) | 1;
  }
  if ((*(byte *)(iVar11 + 0x33) & *(byte *)(iVar11 + 0x32)) != 0) {
    local_2c = &local_54;
    local_54 = &PTR_LAB_0046d4fc;
    local_1c = local_50;
    iVar11 = FUN_00450b60(0x1a);
    FUN_00403d80(local_1c,iVar11);
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


