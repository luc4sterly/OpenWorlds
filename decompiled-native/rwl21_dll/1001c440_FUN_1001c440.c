// 1001c440 FUN_1001c440 [Global]
// program: RWL21.DLL

ulonglong __fastcall
FUN_1001c440(undefined4 param_1,undefined4 param_2,float *param_3,int param_4,float *param_5)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_3 + 0x10) != '\0') {
    uVar2 = FUN_100510e0(param_4,param_2,(undefined4 *)param_4,param_5);
    return uVar2;
  }
  uVar1 = CONCAT31((int3)((uint)param_2 >> 8),*(char *)(param_4 + 0x40));
  if (*(char *)(param_4 + 0x40) != '\0') {
    uVar2 = FUN_100510e0(param_4,uVar1,param_3,param_5);
    return uVar2;
  }
  uVar3 = FUN_1005118c(param_4,uVar1,param_3,(float *)param_4,param_5);
  *(undefined1 *)((int)param_5 + 0x41) = 1;
  *(undefined1 *)(param_5 + 0x10) = 0;
  return CONCAT44((int)((ulonglong)uVar3 >> 0x20),param_5);
}


