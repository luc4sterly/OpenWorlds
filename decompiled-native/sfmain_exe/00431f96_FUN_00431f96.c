// 00431f96 FUN_00431f96 [Global]
// programa: sfmain.exe

longlong __fastcall FUN_00431f96(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  (*(code *)PTR_FUN_0043e808)();
  piVar3 = DAT_0043e524;
  while (piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
    piVar1 = piVar3 + 9;
    piVar3 = (int *)piVar3[2];
    if (iVar2 + -0x2c == *(int *)*piVar1) {
      FUN_00432008(iVar2 + -0x2c);
    }
  }
  (*(code *)PTR_FUN_0043e810)();
  return (ulonglong)param_2 << 0x20;
}


