// 0043370b FUN_0043370b [Global]
// program: sfmain.exe

void __fastcall FUN_0043370b(undefined4 param_1,uint param_2)

{
  uint in_EAX;
  bool bVar1;
  
  if (in_EAX != 0 || param_2 != 0) {
    if ((param_2 & 0xfff00000) == 0) {
      do {
        bVar1 = CARRY4(in_EAX,in_EAX);
        in_EAX = in_EAX * 2;
        param_2 = param_2 * 2 + (uint)bVar1;
      } while ((param_2 & 0xfff00000) == 0);
    }
    else {
      for (; (param_2 & 0xffe00000) != 0; param_2 = param_2 >> 1) {
      }
    }
  }
  return;
}


