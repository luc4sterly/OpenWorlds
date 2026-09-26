// 0042e389 FUN_0042e389 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __fastcall FUN_0042e389(undefined4 param_1,LPCVOID param_2)

{
  HANDLE hFile;
  int in_EAX;
  DWORD DVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  DWORD unaff_EBX;
  ulonglong uVar4;
  undefined8 uVar5;
  DWORD DStack_14;
  
  hFile = *(HANDLE *)(_DAT_004e57c8 + in_EAX * 4);
  (*(code *)PTR_FUN_0043e7f0)();
  uVar4 = FUN_0043215d(extraout_ECX,extraout_EDX);
  if (((uVar4 & 0x80) == 0) || (DVar1 = SetFilePointer(hFile,0,(PLONG)0x0,2), DVar1 != 0xffffffff))
  {
    if ((DAT_0043e8ac != (code *)0x0) && (iVar2 = (*DAT_0043e880)(), iVar2 != 0)) {
      DVar1 = (*DAT_0043e8ac)();
      (*(code *)PTR_FUN_0043e7f4)();
      return DVar1;
    }
    BVar3 = WriteFile(hFile,param_2,unaff_EBX,&DStack_14,(LPOVERLAPPED)0x0);
    if (BVar3 != 0) {
      if (unaff_EBX != DStack_14) {
        FUN_0042d8ad(extraout_ECX_01,extraout_EDX_01);
      }
      (*(code *)PTR_FUN_0043e7f4)();
      return DStack_14;
    }
  }
  (*(code *)PTR_FUN_0043e7f4)();
  uVar5 = FUN_00430d8f(extraout_ECX_00,extraout_EDX_00);
  return (DWORD)uVar5;
}


