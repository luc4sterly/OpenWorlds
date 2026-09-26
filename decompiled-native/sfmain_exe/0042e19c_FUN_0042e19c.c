// 0042e19c FUN_0042e19c [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD FUN_0042e19c(void)

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
  
  (*(code *)PTR_FUN_0043e7f0)();
  lpBuffer = extraout_EDX;
  if (DAT_0043e8a8 != (code *)0x0) {
    uVar2 = (*DAT_0043e880)();
    lpBuffer = (LPVOID)((ulonglong)uVar2 >> 0x20);
    if ((int)uVar2 != 0) {
      (*DAT_0043e8a8)();
      (*(code *)PTR_FUN_0043e7f4)();
      return extraout_EDX_00;
    }
  }
  BVar1 = ReadFile(*(HANDLE *)(_DAT_004e57c8 + in_EAX * 4),lpBuffer,unaff_EBX,&DStack_c,
                   (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    (*(code *)PTR_FUN_0043e7f4)();
    uVar2 = FUN_00430d8f(extraout_ECX,extraout_EDX_01);
    DStack_c = (DWORD)uVar2;
  }
  else {
    (*(code *)PTR_FUN_0043e7f4)();
  }
  return DStack_c;
}


