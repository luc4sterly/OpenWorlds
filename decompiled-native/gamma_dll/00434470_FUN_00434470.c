// 00434470 FUN_00434470 [Global]
// programa: gamma.dll

void FUN_00434470(int param_1,undefined4 param_2)

{
  int *this;
  int iVar1;
  int *piVar2;
  int iVar3;
  uint local_84;
  undefined4 local_78 [5];
  undefined **local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined **local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined **local_44 [4];
  undefined **local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24 [5];
  
  local_84 = 1;
  FUN_00428f10(local_78);
  if (*(int *)(param_1 + 4) != 0) {
    for (this = (int *)FUN_0043bce0(*(int *)(param_1 + 4));
        (piVar2 = (int *)FUN_0043bcf0(*(int *)(param_1 + 4)), this != piVar2 && (*this < 3));
        this = this + 7) {
      if ((*this == 2) && (iVar1 = FUN_004196d0(param_2), iVar1 != 0)) {
        FUN_004393f0(this,local_44);
        FUN_00429520(&local_34,(int)local_44,DAT_00475490);
        local_60 = local_30;
        local_54 = &PTR_LAB_00473390;
        local_5c = local_2c;
        local_58 = local_28;
        local_50 = local_30;
        local_48 = local_28;
        local_64 = &PTR_LAB_004732e8;
        local_4c = local_2c;
        local_34 = &PTR_LAB_004732e8;
        local_44[0] = &PTR_LAB_004732e8;
        FUN_00431990(iVar1,(int)&local_54);
        local_64 = &PTR_LAB_004732e8;
        local_54 = &PTR_LAB_00473390;
      }
    }
    while (((int)local_84 < 0x1f &&
           (piVar2 = (int *)FUN_0043bcf0(*(int *)(param_1 + 4)), this != piVar2))) {
      iVar1 = *this;
      iVar3 = FUN_00429880(local_84);
      if (iVar1 < iVar3) {
LAB_004345c2:
        this = this + 7;
      }
      else {
        iVar1 = *this;
        iVar3 = FUN_00429880(local_84);
        if (iVar1 <= iVar3) {
          switch(this[1]) {
          case 4:
          case 5:
          case 6:
            FUN_004393b0(this,local_24);
            FUN_00434610(param_2,local_84,(int)local_24);
            FUN_00428e50(local_24);
          }
          local_84 = local_84 + 1;
          goto LAB_004345c2;
        }
        FUN_00434610(param_2,local_84,(int)local_78);
        local_84 = local_84 + 1;
      }
    }
  }
  for (; (int)local_84 < 0x1f; local_84 = local_84 + 1) {
    FUN_00434610(param_2,local_84,(int)local_78);
  }
  FUN_00428e50(local_78);
  return;
}


