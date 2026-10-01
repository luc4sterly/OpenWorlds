// 10004700 FUN_10004700 [Global]
// program: RWL21.DLL

void __fastcall FUN_10004700(undefined4 param_1,undefined4 param_2,float *param_3)

{
  float *pfVar1;
  char cVar2;
  float *pfVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  ulonglong uVar6;
  float *pfVar7;
  float *pfVar8;
  float local_44 [17];
  
  pfVar8 = (float *)param_3[0x5d];
  pfVar3 = param_3 + 0x3b;
  pfVar1 = param_3 + 0x4c;
  pfVar7 = pfVar1;
  if (pfVar8 == (float *)0x0) {
    if (*(char *)(param_3 + 0x4b) != '\0') {
      if (*(char *)(param_3 + 0x5c) == '\0') {
        FUN_100510e0(param_1,param_2,pfVar1,param_3);
      }
      else if (*(char *)(param_3 + 0x10) == '\0') {
        FUN_1001c4a0(param_3);
      }
      goto LAB_1000478d;
    }
    pfVar8 = pfVar3;
    if (*(char *)(param_3 + 0x5c) != '\0') {
      FUN_100510e0(param_1,param_2,pfVar3,param_3);
      goto LAB_1000478d;
    }
  }
  else {
    cVar2 = *(char *)(param_3 + 0x5c);
    param_1 = CONCAT31((int3)((uint)param_1 >> 8),cVar2);
    if (*(char *)(param_3 + 0x4b) == '\0') {
      pfVar7 = pfVar3;
      if (cVar2 == '\0') {
        uVar6 = FUN_1001c440(local_44,param_2,pfVar3,(int)pfVar8,local_44);
        param_2 = (undefined4)(uVar6 >> 0x20);
        param_1 = extraout_ECX;
        pfVar7 = pfVar1;
        pfVar8 = local_44;
      }
    }
    else if (cVar2 != '\0') {
      FUN_100510e0(param_1,param_2,pfVar8,param_3);
      goto LAB_1000478d;
    }
  }
  FUN_1001c440(param_1,param_2,pfVar7,(int)pfVar8,param_3);
LAB_1000478d:
  FUN_1002bfe0((int)param_3);
  param_3[0x31] = 0.0;
  param_3[0x30] = 0.0;
  uVar4 = extraout_ECX_00;
  uVar5 = extraout_EDX;
  for (pfVar3 = (float *)param_3[0x5e]; pfVar3 != (float *)0x0; pfVar3 = (float *)pfVar3[0x61]) {
    FUN_10004700(uVar4,uVar5,pfVar3);
    uVar4 = extraout_ECX_01;
    uVar5 = extraout_EDX_00;
  }
  *(undefined1 *)((int)param_3 + 0x12d) = 0;
  *(undefined1 *)((int)param_3 + 0x171) = 0;
  return;
}


