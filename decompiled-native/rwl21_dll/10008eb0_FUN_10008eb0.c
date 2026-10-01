// 10008eb0 FUN_10008eb0 [Global]
// program: RWL21.DLL

void __fastcall FUN_10008eb0(undefined4 param_1,undefined4 param_2,float *param_3)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float *pfVar3;
  undefined3 uVar2;
  
  uVar2 = (undefined3)((uint)param_1 >> 8);
  uVar1 = CONCAT31(uVar2,*(char *)((int)param_3 + 0x12d));
  if ((*(char *)((int)param_3 + 0x12d) == '\0') &&
     (uVar1 = CONCAT31(uVar2,*(char *)((int)param_3 + 0x171)),
     *(char *)((int)param_3 + 0x171) == '\0')) {
    pfVar3 = (float *)param_3[0x5e];
    if (pfVar3 != (float *)0x0) {
      do {
        FUN_10008eb0(uVar1,param_2,pfVar3);
        pfVar3 = (float *)pfVar3[0x61];
        uVar1 = extraout_ECX;
        param_2 = extraout_EDX;
      } while (pfVar3 != (float *)0x0);
      return;
    }
  }
  else {
    FUN_10004700(uVar1,param_2,param_3);
  }
  return;
}


