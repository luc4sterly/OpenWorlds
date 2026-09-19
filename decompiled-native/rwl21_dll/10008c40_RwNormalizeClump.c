// 10008c40 RwNormalizeClump [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall RwNormalizeClump(undefined4 param_1,undefined4 param_2,int param_3)

{
  float *pfVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  int iVar3;
  ulonglong uVar4;
  float fVar5;
  float *pfVar6;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c [3];
  float local_50 [3];
  float local_44 [17];
  
                    /* 0x8c40  294  RwNormalizeClump */
  if (param_3 != 0) {
    uVar4 = FUN_1001c440(param_1,param_2,(float *)(param_3 + 0xec),param_3 + 0x130,local_44);
    uVar2 = (undefined4)(uVar4 >> 0x20);
    iVar3 = *(int *)(param_3 + 0x178);
    if (iVar3 != 0) {
      if (iVar3 == 0) {
        FUN_1000cba0(1);
        uVar2 = extraout_EDX_00;
        goto LAB_10008c9b;
      }
      do {
        FUN_1001c500(iVar3 + 0xec,uVar2,(float *)(iVar3 + 0xec),(int)local_44,3);
        uVar2 = extraout_EDX;
LAB_10008c9b:
        iVar3 = *(int *)(iVar3 + 0x184);
      } while (iVar3 != 0);
    }
    *(undefined4 *)(param_3 + 0xc4) = 0;
    RwGetClumpLocalBBox(param_3,local_5c,local_50);
    pfVar6 = &local_68;
    fVar5 = -0.5;
    pfVar1 = (float *)RwAddVector(local_50,local_5c,&local_68);
    RwScaleVector(pfVar1,fVar5,pfVar6);
    FUN_1001c820(local_44,local_68,local_64,local_60,1);
    RwSubtractVector(local_50,local_5c,&local_68);
    if (local_64 <= local_68) {
      local_64 = local_68;
    }
    if (local_64 <= local_60) {
      local_64 = local_60;
    }
    if (local_64 <= _DAT_10052070) {
      local_6c = 1.0;
    }
    else {
      local_6c = _DAT_10052088 / local_64;
    }
    FUN_1001c940(local_44,local_6c,local_6c,local_6c,3);
    FUN_10005ab0(param_3,local_44);
    FUN_1001c4a0(local_44);
    if (param_3 != 0) {
      FUN_1001c500(extraout_ECX,extraout_EDX_01,(float *)(param_3 + 0xec),(int)local_44,1);
      FUN_1001c500(extraout_ECX_00,extraout_EDX_02,(float *)(param_3 + 0x130),(int)local_44,1);
      return param_3;
    }
    FUN_1000cba0(1);
  }
  FUN_1000cba0(1);
  return param_3;
}


