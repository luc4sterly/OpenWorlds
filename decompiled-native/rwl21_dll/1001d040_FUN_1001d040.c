// 1001d040 FUN_1001d040 [Global]
// program: RWL21.DLL

int __fastcall
FUN_1001d040(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4,int param_5)

{
  float *pfVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 uVar2;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  int iVar4;
  float10 extraout_ST0;
  longlong lVar5;
  undefined8 uVar6;
  float *pfVar7;
  float local_50 [3];
  float local_44 [16];
  undefined1 local_4;
  undefined1 local_3;
  
  if (param_5 == 1) {
    lVar5 = FUN_100510e0(param_4,param_2,param_4,local_44);
    uVar2 = extraout_ECX_00;
    goto LAB_1001d10d;
  }
  if (param_5 == 2) {
    if (*(char *)(param_4 + 0x10) != '\0') {
      lVar5 = FUN_100510e0(param_4,param_2,param_3,local_44);
      uVar2 = extraout_ECX_01;
      goto LAB_1001d10d;
    }
    pfVar1 = param_4;
    pfVar7 = param_3;
    if (*(char *)(param_3 + 0x10) != '\0') {
      lVar5 = FUN_100510e0(param_4,param_2,param_4,local_44);
      uVar2 = extraout_ECX_02;
      goto LAB_1001d10d;
    }
  }
  else {
    if (param_5 != 3) {
      FUN_1000cba0(2);
      lVar5 = (ulonglong)extraout_EDX << 0x20;
      uVar2 = extraout_ECX;
      goto LAB_1001d10d;
    }
    if (*(char *)(param_3 + 0x10) != '\0') {
      lVar5 = FUN_100510e0(param_4,param_2,param_4,local_44);
      uVar2 = extraout_ECX_03;
      goto LAB_1001d10d;
    }
    pfVar1 = param_3;
    pfVar7 = param_4;
    if (*(char *)(param_4 + 0x10) != '\0') {
      lVar5 = FUN_100510e0(param_4,param_2,param_3,local_44);
      uVar2 = extraout_ECX_04;
      goto LAB_1001d10d;
    }
  }
  uVar6 = FUN_1005118c(param_4,param_2,pfVar1,pfVar7,local_44);
  lVar5 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),local_44);
  local_3 = 1;
  local_4 = 0;
  uVar2 = extraout_ECX_05;
LAB_1001d10d:
  pfVar1 = (float *)lVar5;
  iVar4 = 0;
  if (pfVar1 != (float *)0x0) {
    pfVar1 = FUN_1001c150(uVar2,(int)((ulonglong)lVar5 >> 0x20),pfVar1,pfVar1);
    iVar4 = 0;
    if (pfVar1 != (float *)0x0) {
      if (*(char *)(pfVar1 + 0x10) == '\0') {
        RwCrossProduct(pfVar1,pfVar1 + 4,local_50);
        uVar6 = RwDotProduct(extraout_ECX_07,extraout_EDX_01);
        uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
        local_50[0] = (float)extraout_ST0;
        uVar2 = extraout_ECX_08;
      }
      else {
        local_50[0] = 1.0;
        uVar2 = extraout_ECX_06;
        uVar3 = extraout_EDX_00;
      }
      if ((int)local_50[0] < 0x3f666667) {
        iVar4 = 0;
      }
      else {
        uVar6 = FUN_100510e0(uVar2,uVar3,pfVar1,param_3);
        iVar4 = (int)uVar6;
      }
      if (iVar4 == 0) {
        FUN_1000cba0(7);
      }
    }
  }
  return iVar4;
}


