// 004058b9 FUN_004058b9 [Global]
// programa: gdkup.exe

DWORD FUN_004058b9(void)

{
  int in_EAX;
  BOOL BVar1;
  undefined4 extraout_ECX;
  LPVOID extraout_EDX;
  DWORD extraout_EDX_00;
  LPVOID lpBuffer;
  undefined4 extraout_EDX_01;
  DWORD unaff_EBX;
  undefined8 uVar2;
  DWORD DStack_c;
  
  (*(code *)PTR_FUN_00408b3c)();
  lpBuffer = extraout_EDX;
  if (DAT_00408ba8 != (code *)0x0) {
    uVar2 = (*DAT_00408b80)();
    lpBuffer = (LPVOID)((ulonglong)uVar2 >> 0x20);
    if ((int)uVar2 != 0) {
      (*DAT_00408ba8)();
      (*(code *)PTR_FUN_00408b40)();
      return extraout_EDX_00;
    }
  }
  BVar1 = ReadFile(*(HANDLE *)(DAT_0040b478 + in_EAX * 4),lpBuffer,unaff_EBX,&DStack_c,
                   (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    (*(code *)PTR_FUN_00408b40)();
    uVar2 = FUN_00405609(extraout_ECX,extraout_EDX_01);
    DStack_c = (DWORD)uVar2;
  }
  else {
    (*(code *)PTR_FUN_00408b40)();
  }
  return DStack_c;
}


