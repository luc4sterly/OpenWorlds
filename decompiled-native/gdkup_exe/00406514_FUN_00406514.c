// 00406514 FUN_00406514 [Global]
// program: gdkup.exe

longlong __fastcall FUN_00406514(undefined4 param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  (*(code *)PTR_FUN_00408b54)();
  piVar3 = DAT_00408b28;
  while (piVar3 != (int *)0x0) {
    iVar2 = *piVar3;
    piVar1 = piVar3 + 9;
    piVar3 = (int *)piVar3[2];
    if (iVar2 + -0x2c == *(int *)*piVar1) {
      FUN_00406586(iVar2 + -0x2c);
    }
  }
  (*(code *)PTR_FUN_00408b5c)();
  return (ulonglong)param_2 << 0x20;
}


