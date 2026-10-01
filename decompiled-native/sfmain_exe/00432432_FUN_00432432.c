// 00432432 FUN_00432432 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00432432(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 uStack_4;
  
  uStack_4 = param_2;
  uVar3 = (*(code *)PTR_FUN_0043e7ec)();
  uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
  if (*(uint *)uVar3 < uVar2) {
    return CONCAT44(uStack_4,(int)&uStack_4 - uVar2);
  }
  uVar3 = (*(code *)PTR_FUN_0043e7ec)();
  *(undefined4 *)uVar3 = (int)((ulonglong)uVar3 >> 0x20);
  piVar1 = (int *)(*(code *)PTR_FUN_0043e7ec)();
  return CONCAT44(uStack_4,(int)&uStack_4 - *piVar1);
}


