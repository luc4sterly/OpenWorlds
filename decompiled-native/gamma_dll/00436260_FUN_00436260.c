// 00436260 FUN_00436260 [Global]
// programa: gamma.dll

void * __cdecl FUN_00436260(void *param_1,int param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  char *pcVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [5];
  undefined **local_24;
  int local_20 [2];
  undefined ***local_18;
  int *local_14;
  
  FUN_0042f460(param_1,param_3,4);
  uVar1 = *param_3;
  *param_3 = param_3[3];
  param_3[3] = uVar1;
  uVar1 = param_3[1];
  param_3[1] = param_3[2];
  param_3[2] = uVar1;
  if ((*(byte *)(*(int *)((int)param_1 + 4) + 0x32) & 5) != 0) {
    return param_1;
  }
  local_48 = 0;
  local_3c = 0;
  local_44 = 0;
  local_40 = 0;
  if (param_2 == 4) {
    FUN_0042f460(param_1,(undefined1 *)&local_48,4);
    uVar1 = (undefined1)local_48;
    uVar3 = local_48._1_1_;
    local_48._0_2_ = CONCAT11(local_48._2_1_,local_48._3_1_);
    local_48._0_3_ = CONCAT12(uVar3,(undefined2)local_48);
    local_48 = CONCAT13(uVar1,(undefined3)local_48);
  }
  else if (param_2 == 0xc) {
    FUN_0042f460(param_1,(undefined1 *)&local_44,4);
    uVar1 = (undefined1)local_44;
    uVar3 = local_44._1_1_;
    local_44._0_2_ = CONCAT11(local_44._2_1_,local_44._3_1_);
    local_44._0_3_ = CONCAT12(uVar3,(undefined2)local_44);
    local_44 = CONCAT13(uVar1,(undefined3)local_44);
    FUN_0042f460(param_1,(undefined1 *)&local_40,4);
    uVar1 = (undefined1)local_40;
    uVar3 = local_40._1_1_;
    local_40._0_2_ = CONCAT11(local_40._2_1_,local_40._3_1_);
    local_40._0_3_ = CONCAT12(uVar3,(undefined2)local_40);
    local_40 = CONCAT13(uVar1,(undefined3)local_40);
    FUN_0042f460(param_1,(undefined1 *)&local_3c,4);
    uVar1 = (undefined1)local_3c;
    uVar3 = local_3c._1_1_;
    local_3c._0_2_ = CONCAT11(local_3c._2_1_,local_3c._3_1_);
    local_3c._0_3_ = CONCAT12(uVar3,(undefined2)local_3c);
    local_3c = CONCAT13(uVar1,(undefined3)local_3c);
  }
  else {
    if (param_2 != 0x10) {
      iVar4 = *(int *)((int)param_1 + 4);
      *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) & 4;
      if (*(int *)(iVar4 + 0x24) == 0) {
        *(byte *)(iVar4 + 0x32) = *(byte *)(iVar4 + 0x32) | 1;
      }
      if ((*(byte *)(iVar4 + 0x33) & *(byte *)(iVar4 + 0x32)) != 0) {
        local_18 = &local_24;
        local_24 = &PTR_LAB_0046d4fc;
        local_14 = local_20;
        iVar4 = FUN_00450b60(0x1a);
        FUN_00403d80(local_14,iVar4);
        pcVar2 = (char *)*local_14;
        *(undefined4 *)pcVar2 = s_ios_base_failure_in_clear_00475b78._0_4_;
        *(undefined4 *)(pcVar2 + 4) = s_ios_base_failure_in_clear_00475b78._4_4_;
        *(undefined4 *)(pcVar2 + 8) = s_ios_base_failure_in_clear_00475b78._8_4_;
        *(undefined4 *)(pcVar2 + 0xc) = s_ios_base_failure_in_clear_00475b78._12_4_;
        *(undefined4 *)(pcVar2 + 0x10) = s_ios_base_failure_in_clear_00475b78._16_4_;
        *(undefined4 *)(pcVar2 + 0x14) = s_ios_base_failure_in_clear_00475b78._20_4_;
        *(undefined2 *)(pcVar2 + 0x18) = s_ios_base_failure_in_clear_00475b78._24_2_;
        FUN_00451670();
      }
      return param_1;
    }
    FUN_0042f460(param_1,(undefined1 *)&local_48,4);
    uVar1 = (undefined1)local_48;
    uVar3 = local_48._1_1_;
    local_48._0_2_ = CONCAT11(local_48._2_1_,local_48._3_1_);
    local_48._0_3_ = CONCAT12(uVar3,(undefined2)local_48);
    local_48 = CONCAT13(uVar1,(undefined3)local_48);
    FUN_0042f460(param_1,(undefined1 *)&local_44,4);
    uVar1 = (undefined1)local_44;
    uVar3 = local_44._1_1_;
    local_44._0_2_ = CONCAT11(local_44._2_1_,local_44._3_1_);
    local_44._0_3_ = CONCAT12(uVar3,(undefined2)local_44);
    local_44 = CONCAT13(uVar1,(undefined3)local_44);
    FUN_0042f460(param_1,(undefined1 *)&local_40,4);
    uVar1 = (undefined1)local_40;
    uVar3 = local_40._1_1_;
    local_40._0_2_ = CONCAT11(local_40._2_1_,local_40._3_1_);
    local_40._0_3_ = CONCAT12(uVar3,(undefined2)local_40);
    local_40 = CONCAT13(uVar1,(undefined3)local_40);
    FUN_0042f460(param_1,(undefined1 *)&local_3c,4);
    uVar1 = (undefined1)local_3c;
    uVar3 = local_3c._1_1_;
    local_3c._0_2_ = CONCAT11(local_3c._2_1_,local_3c._3_1_);
    local_3c._0_3_ = CONCAT12(uVar3,(undefined2)local_3c);
    local_3c = CONCAT13(uVar1,(undefined3)local_3c);
  }
  FUN_00428fe0(local_38,local_48,local_44,local_40,local_3c);
  FUN_00428e20(param_3 + 4,(int)local_38);
  FUN_00428e50(local_38);
  return param_1;
}


