// 0040592d FUN_0040592d [Global]
// program: gdkup.exe

DWORD __fastcall FUN_0040592d(undefined4 param_1,LPCVOID param_2)

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
  
  hFile = *(HANDLE *)(DAT_0040b478 + in_EAX * 4);
  (*(code *)PTR_FUN_00408b3c)();
  uVar4 = FUN_00405659(extraout_ECX,extraout_EDX);
  if (((uVar4 & 0x80) == 0) || (DVar1 = SetFilePointer(hFile,0,(PLONG)0x0,2), DVar1 != 0xffffffff))
  {
    if ((DAT_00408bac != (code *)0x0) && (iVar2 = (*DAT_00408b80)(), iVar2 != 0)) {
      DVar1 = (*DAT_00408bac)();
      (*(code *)PTR_FUN_00408b40)();
      return DVar1;
    }
    BVar3 = WriteFile(hFile,param_2,unaff_EBX,&DStack_14,(LPOVERLAPPED)0x0);
    if (BVar3 != 0) {
      if (unaff_EBX != DStack_14) {
        FUN_00403848(extraout_ECX_01,extraout_EDX_01);
      }
      (*(code *)PTR_FUN_00408b40)();
      return DStack_14;
    }
  }
  (*(code *)PTR_FUN_00408b40)();
  uVar5 = FUN_00405609(extraout_ECX_00,extraout_EDX_00);
  return (DWORD)uVar5;
}


