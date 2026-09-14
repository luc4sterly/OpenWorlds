// 00435b20 FUN_00435b20 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall
FUN_00435b20(void *this,undefined4 *param_1,short param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  short sVar7;
  float10 fVar8;
  float10 fVar9;
  undefined **local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined **local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined **local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined **local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined **local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined **local_40 [4];
  undefined **local_30 [4];
  undefined **local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = *(int *)((int)this + 0xc);
  iVar4 = param_3 * 0x18;
  iVar5 = param_4 * 0x18;
  sVar7 = *(short *)(iVar1 + iVar5) - (short)*(int *)(iVar1 + iVar4);
  if (sVar7 < 1) {
    FUN_00428df0(param_1,iVar1 + iVar4 + 4);
    return param_1;
  }
  fVar3 = (float)((int)param_2 - *(int *)(iVar1 + iVar4)) / (float)(int)sVar7;
  if (fVar3 <= DAT_00475b10) {
    FUN_00428df0(param_1,iVar4 + 4 + iVar1);
    return param_1;
  }
  if (_DAT_00475b14 <= fVar3) {
    FUN_00428df0(param_1,iVar5 + 4 + iVar1);
    return param_1;
  }
  iVar2 = *(int *)((int)this + 0x10);
  if (iVar2 != 0x10) {
    if (iVar2 == 4) {
      fVar8 = FUN_00429040(iVar4 + 4 + iVar1);
      fVar9 = FUN_00429040(*(int *)((int)this + 0xc) + iVar5 + 4);
      puVar6 = (undefined4 *)
               FUN_00428fe0(param_1,((float)fVar9 - (float)fVar8) * fVar3 + (float)fVar8,
                            DAT_00475b10,DAT_00475b10,DAT_00475b10);
      return puVar6;
    }
    if (iVar2 != 0xc) {
      FUN_00428df0(param_1,iVar4 + 4 + iVar1);
      return param_1;
    }
    FUN_00429010((void *)(iVar4 + 4 + iVar1),&local_60);
    local_8c = local_5c;
    local_90 = &PTR_LAB_004732e8;
    local_60 = &PTR_LAB_004732e8;
    local_88 = local_58;
    local_84 = local_54;
    FUN_00429010((void *)(*(int *)((int)this + 0xc) + iVar5 + 4),&local_50);
    local_80 = &PTR_LAB_004732e8;
    local_7c = local_4c;
    local_74 = local_44;
    local_50 = &PTR_LAB_004732e8;
    local_78 = local_48;
    FUN_004294d0(local_40,(int)&local_80,(int)&local_90);
    FUN_004295a0(local_30,fVar3,(int)local_40);
    FUN_00429480(&local_20,(int)&local_90,(int)local_30);
    local_6c = local_1c;
    local_40[0] = &PTR_LAB_004732e8;
    local_70 = &PTR_LAB_004732e8;
    local_30[0] = &PTR_LAB_004732e8;
    local_68 = local_18;
    local_20 = &PTR_LAB_004732e8;
    local_64 = local_14;
    FUN_00428fe0(param_1,DAT_00475b10,local_1c,local_18,local_14);
    return param_1;
  }
  FUN_00429310(param_1,iVar4 + 4 + iVar1,iVar5 + 4 + iVar1,fVar3);
  return param_1;
}


