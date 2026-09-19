// 10012fa0 FUN_10012fa0 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_10012fa0(undefined4 param_1,int param_2,int param_3,int *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  float local_5c;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  int local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float local_14;
  float fStack_10;
  float local_c;
  float fStack_8;
  float local_4;
  
  local_44 = param_3;
  local_50 = 0.0;
  local_4c = 1.0;
  local_48 = 0.0;
  rwLengthNormaliseVector(&local_50,&local_50);
  local_3c = local_50;
  local_38 = local_4c;
  local_34 = local_48;
  pfVar4 = (float *)FUN_1001d770();
  RwTransformPoint(&local_3c,pfVar4);
  iVar5 = FUN_10004a90(param_2,local_3c,local_38,local_34);
  if (iVar5 != 0) {
    iVar6 = FUN_10041c90(*(int *)(param_2 + 0x88),iVar5);
    *(byte *)(iVar6 + 0x48) = *(byte *)(iVar6 + 0x48) | 0x20;
  }
  piVar8 = param_4 + 1;
  local_4 = (float)param_3;
  local_40 = _DAT_10052118 / (float)param_3;
  *param_4 = iVar5;
  do {
    if ((iVar5 == 0) || (iVar6 = local_44 + -1, local_44 == 0)) {
      return iVar5;
    }
    local_54 = 0.0;
    fVar3 = (float)iVar6 / local_4;
    fVar1 = fVar3 - _DAT_10052118;
    local_44 = iVar6;
    local_30 = (float)iVar6;
    fStack_2c = fVar1;
    for (; (iVar5 != 0 && (iVar6 < param_3)); iVar6 = iVar6 + 1) {
      local_50 = fVar1;
      local_4c = fVar3;
      local_48 = local_54;
      rwLengthNormaliseVector(&local_50,&local_50);
      local_3c = local_50;
      local_38 = local_4c;
      local_34 = local_48;
      pfVar4 = (float *)FUN_1001d770();
      RwTransformPoint(&local_3c,pfVar4);
      iVar5 = FUN_10004a90(param_2,local_3c,local_38,local_34);
      if (iVar5 != 0) {
        iVar7 = FUN_10041c90(*(int *)(param_2 + 0x88),iVar5);
        *(byte *)(iVar7 + 0x48) = *(byte *)(iVar7 + 0x48) | 0x20;
      }
      fVar1 = local_40 + fVar1;
      local_54 = local_40 + local_54;
      *piVar8 = iVar5;
      piVar8 = piVar8 + 1;
    }
    fVar1 = _DAT_10052118 - fVar3;
    local_5c = 0.0;
    local_30 = fVar1;
    for (iVar6 = local_44; (iVar5 != 0 && (iVar6 < param_3)); iVar6 = iVar6 + 1) {
      local_50 = local_5c;
      local_4c = fVar3;
      local_48 = fVar1;
      rwLengthNormaliseVector(&local_50,&local_50);
      fStack_28 = local_50;
      fStack_24 = local_4c;
      fStack_20 = local_48;
      pfVar4 = (float *)FUN_1001d770();
      RwTransformPoint(&fStack_28,pfVar4);
      iVar5 = FUN_10004a90(param_2,fStack_28,fStack_24,fStack_20);
      if (iVar5 != 0) {
        iVar7 = FUN_10041c90(*(int *)(param_2 + 0x88),iVar5);
        *(byte *)(iVar7 + 0x48) = *(byte *)(iVar7 + 0x48) | 0x20;
      }
      local_5c = local_40 + local_5c;
      fVar1 = fVar1 - local_40;
      *piVar8 = iVar5;
      piVar8 = piVar8 + 1;
    }
    local_54 = 0.0;
    fVar1 = local_30;
    fVar2 = local_54;
    iVar7 = local_44;
    local_54 = fStack_2c;
    for (iVar6 = local_44; (local_44 = iVar7, fStack_2c = local_54, iVar5 != 0 && (iVar6 < param_3))
        ; iVar6 = iVar6 + 1) {
      local_50 = fVar1;
      local_4c = fVar3;
      local_48 = fVar2;
      rwLengthNormaliseVector(&local_50,&local_50);
      fStack_1c = local_50;
      fStack_18 = local_4c;
      local_14 = local_48;
      pfVar4 = (float *)FUN_1001d770();
      RwTransformPoint(&fStack_1c,pfVar4);
      iVar5 = FUN_10004a90(param_2,fStack_1c,fStack_18,local_14);
      if (iVar5 != 0) {
        iVar7 = FUN_10041c90(*(int *)(param_2 + 0x88),iVar5);
        *(byte *)(iVar7 + 0x48) = *(byte *)(iVar7 + 0x48) | 0x20;
      }
      fVar1 = fVar1 - local_40;
      fVar2 = fVar2 - local_40;
      *piVar8 = iVar5;
      piVar8 = piVar8 + 1;
      iVar7 = local_44;
      local_54 = fStack_2c;
    }
    local_5c = 0.0;
    if (iVar5 == 0) {
      return 0;
    }
    do {
      if (param_3 <= iVar7) break;
      local_50 = local_5c;
      local_48 = local_54;
      local_4c = fVar3;
      rwLengthNormaliseVector(&local_50,&local_50);
      fStack_10 = local_50;
      local_c = local_4c;
      fStack_8 = local_48;
      pfVar4 = (float *)FUN_1001d770();
      RwTransformPoint(&fStack_10,pfVar4);
      iVar5 = FUN_10004a90(param_2,fStack_10,local_c,fStack_8);
      if (iVar5 != 0) {
        iVar6 = FUN_10041c90(*(int *)(param_2 + 0x88),iVar5);
        *(byte *)(iVar6 + 0x48) = *(byte *)(iVar6 + 0x48) | 0x20;
      }
      local_5c = local_5c - local_40;
      local_54 = local_40 + local_54;
      *piVar8 = iVar5;
      piVar8 = piVar8 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar5 != 0);
  } while( true );
}


