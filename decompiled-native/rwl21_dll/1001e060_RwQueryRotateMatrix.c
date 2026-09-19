// 1001e060 RwQueryRotateMatrix [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * RwQueryRotateMatrix(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  float10 fVar4;
  float fVar5;
  float *pfVar6;
  float fVar7;
  float *pfVar8;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  undefined4 local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined1 local_48;
  undefined1 uStack_47;
  float local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  float fStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  
                    /* 0x1e060  317  RwQueryRotateMatrix */
  if ((((param_1 == (float *)0x0) || (param_2 == (float *)0x0)) || (param_3 == (float *)0x0)) ||
     (param_4 == (float *)0x0)) {
    param_1 = (float *)0x0;
  }
  if (param_1 == (float *)0x0) {
    FUN_1000cba0(1);
    return (float *)0x0;
  }
  local_98 = param_1[6] - param_1[9];
  local_8c = (*param_1 + param_1[5] + param_1[10]) - _DAT_10052184;
  local_94 = param_1[8] - param_1[2];
  local_90 = param_1[1] - param_1[4];
  fVar3 = rwLengthNormaliseVector(param_2,&local_98);
  fVar4 = (float10)fpatan(fVar3,(float10)local_8c);
  *param_3 = (float)(fVar4 * (float10)_DAT_10052190);
  if (((float10)_DAT_10052198 < fVar3) || (0 < (int)local_8c)) goto LAB_1001e1dc;
  if (*param_1 <= param_1[5]) {
    if (param_1[5] <= param_1[10]) goto LAB_1001e1a4;
    local_94 = (param_1[5] + _DAT_10052184) * _DAT_1005219c;
    local_90 = param_1[9] + param_1[6];
    local_98 = param_1[1] + param_1[4];
  }
  else if (*param_1 <= param_1[10]) {
LAB_1001e1a4:
    local_90 = (param_1[10] + _DAT_10052184) * _DAT_1005219c;
    local_98 = param_1[2] + param_1[8];
    local_94 = param_1[9] + param_1[6];
  }
  else {
    local_98 = (*param_1 + _DAT_10052184) * _DAT_1005219c;
    local_94 = param_1[1] + param_1[4];
    local_90 = param_1[2] + param_1[8];
  }
  rwLengthNormaliseVector(param_2,&local_98);
LAB_1001e1dc:
  local_4c = 0x3f800000;
  local_60 = 1.0;
  local_74 = 1.0;
  local_88 = 1.0;
  local_50 = 0.0;
  local_54 = 0.0;
  local_58 = 0.0;
  local_5c = 0;
  local_64 = 0.0;
  local_68 = 0.0;
  local_6c = 0;
  local_70 = 0.0;
  local_78 = 0.0;
  local_7c = 0;
  local_80 = 0.0;
  local_84 = 0.0;
  uStack_47 = 1;
  local_48 = 1;
  RwSubtractVector(&local_88,param_1,&local_88);
  RwSubtractVector(&local_78,param_1 + 4,&local_78);
  RwSubtractVector(&local_68,param_1 + 8,&local_68);
  local_48 = 0;
  uStack_4 = 0;
  local_44 = local_74 * local_60 - local_64 * local_70;
  local_34 = local_70 * local_68 - local_60 * local_78;
  local_24 = local_64 * local_78 - local_74 * local_68;
  local_40 = local_64 * local_80 - local_84 * local_60;
  local_30 = local_60 * local_88 - local_80 * local_68;
  local_20 = local_84 * local_68 - local_64 * local_88;
  local_3c = local_84 * local_70 - local_74 * local_80;
  local_2c = local_80 * local_78 - local_70 * local_88;
  local_1c = local_74 * local_88 - local_84 * local_78;
  uStack_47 = 1;
  uStack_3 = 1;
  local_38 = 0;
  local_28 = 0;
  local_18 = 0;
  local_8c = local_24 * local_80 + local_44 * local_88 + local_34 * local_84;
  if (local_8c != _DAT_10052180) {
    fVar7 = _DAT_10052184 / local_8c;
    local_44 = local_44 * fVar7;
    local_40 = local_40 * fVar7;
    local_3c = local_3c * fVar7;
    local_34 = local_34 * fVar7;
    local_30 = local_30 * fVar7;
    local_2c = local_2c * fVar7;
    local_24 = local_24 * fVar7;
    local_20 = local_20 * fVar7;
    local_1c = fVar7 * local_1c;
  }
  local_14 = -(local_24 * local_50 + local_44 * local_58 + local_34 * local_54);
  fStack_10 = -(local_20 * local_50 + local_30 * local_54 + local_40 * local_58);
  uStack_8 = 0x3f800000;
  pfVar6 = &local_24;
  fStack_c = -(local_1c * local_50 + local_2c * local_54 + local_3c * local_58);
  fVar7 = param_1[0xe];
  fVar5 = param_1[0xd];
  pfVar2 = &local_34;
  pfVar8 = param_4;
  pfVar1 = (float *)FUN_100428a0(&local_14,&local_44,param_1[0xc],param_4);
  pfVar2 = (float *)FUN_100428a0(pfVar1,pfVar2,fVar5,param_4);
  FUN_100428a0(pfVar2,pfVar6,fVar7,pfVar8);
  return param_1;
}


