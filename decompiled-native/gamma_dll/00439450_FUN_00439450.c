// 00439450 FUN_00439450 [Global]
// programa: gamma.dll

undefined8 __cdecl FUN_00439450(undefined4 *param_1,undefined4 *param_2,void *param_3,float param_4)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 local_e0 [5];
  undefined4 local_cc [5];
  undefined **local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8 [5];
  undefined4 local_94 [5];
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined **local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [4];
  undefined4 local_4c [4];
  undefined4 local_3c [4];
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  uVar3 = param_2[1];
  switch(param_2[1]) {
  case 0:
    uVar3 = *param_2;
    *param_1 = uVar3;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    param_1[6] = param_2[6];
    return CONCAT44(uVar3,param_1);
  case 1:
  case 4:
  case 5:
  case 6:
    FUN_004393b0(param_2,local_a8);
    FUN_00428df0(local_e0,(int)local_a8);
    FUN_00428e50(local_a8);
    FUN_004393b0(param_3,local_94);
    FUN_00428df0(local_cc,(int)local_94);
    FUN_00428e50(local_94);
    FUN_004292a0(local_cc,(int)local_e0);
    FUN_00429310(&local_80,(int)local_e0,(int)local_cc,param_4);
    uVar3 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar3;
    param_1[2] = local_80;
    param_1[3] = uStack_7c;
    param_1[4] = uStack_78;
    param_1[5] = uStack_74;
    param_1[6] = uStack_70;
    FUN_00428e50(&local_80);
    FUN_00428e50(local_cc);
    FUN_00428e50(local_e0);
    return CONCAT44(extraout_EDX,param_1);
  case 2:
    FUN_004393f0(param_2,&local_6c);
    local_b8 = &PTR_LAB_004732e8;
    local_b4 = local_68;
    local_ac = local_60;
    local_6c = &PTR_LAB_004732e8;
    local_b0 = local_64;
    FUN_004393f0(param_3,local_5c);
    FUN_004294d0(local_4c,(int)local_5c,(int)&local_b8);
    FUN_004295a0(local_3c,param_4,(int)local_4c);
    FUN_00429480(&local_2c,(int)&local_b8,(int)local_3c);
    uVar3 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar3;
    param_1[2] = local_2c;
    param_1[3] = uStack_28;
    param_1[4] = uStack_24;
    param_1[5] = uStack_20;
    return CONCAT44(extraout_EDX_00,param_1);
  case 3:
    fVar1 = (float)param_2[2];
    fVar2 = *(float *)((int)param_3 + 8);
    uVar3 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar3;
    param_1[2] = (fVar2 - fVar1) * param_4 + fVar1;
    return CONCAT44(uVar3,param_1);
  default:
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    return CONCAT44(uVar3,param_1);
  }
}


