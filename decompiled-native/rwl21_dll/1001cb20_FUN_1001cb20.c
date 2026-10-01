// 1001cb20 FUN_1001cb20 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_1001cb20(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4,float param_5,
            float param_6,int param_7)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  float *pfVar2;
  undefined8 uVar3;
  float *pfVar4;
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
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48;
  undefined1 local_47;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_4;
  undefined1 local_3;
  
  local_44 = param_4[1] * param_4[2] * param_5;
  local_3c = *param_4 * param_4[1] * param_5;
  local_40 = *param_4 * param_4[2] * param_5;
  local_84 = local_3c + param_4[2] * param_6;
  local_80 = local_40 - param_4[1] * param_6;
  local_88 = _DAT_10052184 - (_DAT_10052184 - *param_4 * *param_4) * param_5;
  local_78 = local_3c - param_4[2] * param_6;
  local_47 = 1;
  local_70 = local_44 + *param_4 * param_6;
  local_48 = 0;
  local_7c = 0;
  local_74 = _DAT_10052184 - (_DAT_10052184 - param_4[1] * param_4[1]) * param_5;
  local_68 = local_40 + param_4[1] * param_6;
  local_64 = local_44 - *param_4 * param_6;
  local_6c = 0;
  local_60 = _DAT_10052184 - (_DAT_10052184 - param_4[2] * param_4[2]) * param_5;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0x3f800000;
  if (param_7 == 1) {
    pfVar2 = &local_88;
  }
  else {
    if (param_7 == 2) {
      if (*(char *)(param_3 + 0x10) == '\0') {
        pfVar2 = &local_88;
        pfVar4 = param_3;
LAB_1001ccf7:
        uVar3 = FUN_1005118c(&local_88,param_2,pfVar2,pfVar4,&local_44);
        uVar3 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),&local_44);
        local_3 = 1;
        local_4 = 0;
        param_1 = extraout_ECX_01;
      }
      else {
        uVar3 = FUN_100510e0(&local_88,param_2,&local_88,&local_44);
        param_1 = extraout_ECX;
      }
    }
    else {
      if (param_7 != 3) {
        FUN_1000cba0(2);
        iVar1 = 0;
        goto LAB_1001cd13;
      }
      if (*(char *)(param_3 + 0x10) == '\0') {
        pfVar2 = param_3;
        pfVar4 = &local_88;
        goto LAB_1001ccf7;
      }
      uVar3 = FUN_100510e0(&local_88,param_2,&local_88,&local_44);
      param_1 = extraout_ECX_00;
    }
    param_2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    pfVar2 = (float *)uVar3;
  }
  uVar3 = FUN_100510e0(param_1,param_2,pfVar2,param_3);
  iVar1 = (int)uVar3;
LAB_1001cd13:
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x41) = 1;
    *(undefined1 *)(iVar1 + 0x40) = 0;
  }
  return;
}


