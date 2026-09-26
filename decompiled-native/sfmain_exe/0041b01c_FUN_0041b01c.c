// 0041b01c FUN_0041b01c [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0041b01c(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 *local_20;
  undefined4 local_1c;
  
  local_20 = DAT_0043d678;
  if (((in_EAX == DAT_0043d670) || (in_EAX == DAT_0043d66c)) || (in_EAX == -1)) {
    local_1c = 0x81e;
  }
  else {
    for (; local_20 != (undefined4 *)0x0; local_20 = (undefined4 *)*local_20) {
      if ((0 < *(short *)(local_20 + 1)) && ((in_EAX == local_20[2] || (in_EAX == local_20[3])))) {
        local_1c = CONCAT22((short)((uint)local_20 >> 0x10),*(undefined2 *)((int)local_20 + 6));
        goto LAB_0041b0a3;
      }
    }
    local_1c = 0;
  }
LAB_0041b0a3:
  return CONCAT44(param_2,local_1c);
}


