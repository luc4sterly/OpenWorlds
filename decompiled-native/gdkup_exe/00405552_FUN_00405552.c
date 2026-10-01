// 00405552 FUN_00405552 [Global]
// program: gdkup.exe

void __fastcall FUN_00405552(undefined4 param_1,undefined4 *param_2)

{
  int in_EAX;
  undefined4 *unaff_EBX;
  
  if (in_EAX == 2) {
    *param_2 = 0xc0000000;
  }
  else {
    if (in_EAX != 1) {
      *param_2 = 0x80000000;
      *unaff_EBX = 1;
      return;
    }
    *param_2 = 0x40000000;
  }
  *unaff_EBX = 0x80;
  return;
}


