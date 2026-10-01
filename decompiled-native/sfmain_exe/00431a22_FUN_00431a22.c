// 00431a22 FUN_00431a22 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00431a22(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  DWORD DVar1;
  
  if (in_EAX == 0) {
    in_EAX = FUN_00432719(param_1,DAT_0043eac8);
    if (in_EAX != 0) {
      *(undefined1 *)(in_EAX + 0x52) = 1;
    }
  }
  if (in_EAX != 0) {
    *(undefined4 *)(in_EAX + 0xc) = 1;
    DVar1 = GetCurrentThreadId();
    *(DWORD *)(in_EAX + 0xda) = DVar1;
  }
  return CONCAT44(param_2,in_EAX);
}


