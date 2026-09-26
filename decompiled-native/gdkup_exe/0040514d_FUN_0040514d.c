// 0040514d FUN_0040514d [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_0040514d(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  DWORD DVar1;
  
  if (in_EAX == 0) {
    in_EAX = FUN_00406902(param_1,DAT_00408eac);
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


