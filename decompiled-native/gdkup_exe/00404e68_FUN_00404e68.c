// 00404e68 FUN_00404e68 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00404e68(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_00408b6c)();
  iVar2 = 0;
  iVar1 = 0;
  while( true ) {
    if (DAT_0040b474 * 4 <= iVar1) {
      DAT_0040b478 = FUN_0040677d(DAT_0040b474 * 4,(DAT_0040b474 + 1) * 4);
      DAT_0040b478[DAT_0040b474] = in_EAX;
      DAT_0040b474 = DAT_0040b474 + 1;
      (*(code *)PTR_FUN_00408b70)();
      return CONCAT44(param_2,DAT_0040b474 + -1);
    }
    if (*(int *)((int)DAT_0040b478 + iVar1) == 0) break;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
  }
  *(int *)((int)DAT_0040b478 + iVar1) = in_EAX;
  (*(code *)PTR_FUN_00408b70)();
  return CONCAT44(param_2,iVar2);
}


