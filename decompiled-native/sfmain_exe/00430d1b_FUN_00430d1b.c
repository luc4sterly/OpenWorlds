// 00430d1b FUN_00430d1b [Global]
// programa: sfmain.exe

void FUN_00430d1b(void)

{
  undefined1 uVar1;
  char *in_EAX;
  undefined1 *extraout_EDX;
  
  while (*in_EAX != '\0') {
    uVar1 = FUN_0043240f();
    *extraout_EDX = uVar1;
    in_EAX = extraout_EDX + 1;
  }
  return;
}


