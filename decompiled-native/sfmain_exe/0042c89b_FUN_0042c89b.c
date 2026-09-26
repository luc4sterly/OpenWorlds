// 0042c89b FUN_0042c89b [Global]
// programa: sfmain.exe

void FUN_0042c89b(void)

{
  int iVar1;
  undefined1 *extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  undefined1 *extraout_EDX;
  
  FUN_0042f694();
  *extraout_ECX = 0x74;
  do {
    iVar1 = FUN_0042c88f();
    *extraout_EDX = (char)iVar1;
  } while (extraout_EDX + -1 != extraout_ECX);
  *(undefined1 *)(extraout_ECX_00 + 5) = 0x5f;
  iVar1 = FUN_0042c88f();
  *(char *)(extraout_ECX_01 + 6) = (char)iVar1;
  iVar1 = FUN_0042c88f();
  *(undefined1 *)(extraout_ECX_02 + 8) = 0x2e;
  *(undefined1 *)(extraout_ECX_02 + 9) = 0x74;
  *(undefined1 *)(extraout_ECX_02 + 10) = 0x6d;
  *(undefined1 *)(extraout_ECX_02 + 0xb) = 0x70;
  *(undefined1 *)(extraout_ECX_02 + 0xc) = 0;
  *(char *)(extraout_ECX_02 + 7) = (char)iVar1;
  return;
}


