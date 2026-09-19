// 1001db10 RwMultiplyMatrix [Global]
// programa: RWL21.DLL

ulonglong __fastcall
RwMultiplyMatrix(undefined4 param_1,undefined4 param_2,float *param_3,int param_4,float *param_5)

{
  undefined3 uVar2;
  undefined4 uVar1;
  uint extraout_EDX;
  ulonglong uVar3;
  undefined8 uVar4;
  
                    /* 0x1db10  292  RwMultiplyMatrix */
  if (((param_3 == (float *)0x0) || (param_4 == 0)) || (param_5 == (float *)0x0)) {
    FUN_1000cba0(1);
    return (ulonglong)extraout_EDX << 0x20;
  }
  uVar2 = (undefined3)((uint)param_2 >> 8);
  if (*(char *)(param_3 + 0x10) != '\0') {
    uVar3 = FUN_100510e0(param_4,CONCAT31(uVar2,*(char *)(param_3 + 0x10)),(undefined4 *)param_4,
                         param_5);
    return uVar3;
  }
  uVar1 = CONCAT31(uVar2,*(char *)(param_4 + 0x40));
  if (*(char *)(param_4 + 0x40) == '\0') {
    uVar4 = FUN_1005118c(param_4,uVar1,param_3,(float *)param_4,param_5);
    *(undefined1 *)((int)param_5 + 0x41) = 1;
    *(undefined1 *)(param_5 + 0x10) = 0;
    return CONCAT44((int)((ulonglong)uVar4 >> 0x20),param_5);
  }
  uVar3 = FUN_100510e0(param_4,uVar1,param_3,param_5);
  return uVar3;
}


