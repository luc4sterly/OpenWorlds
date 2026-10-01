// 00421dcb FUN_00421dcb [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00421dcb(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 local_28;
  
  if (*(int *)(in_EAX + 0x4e44) == 0) {
    local_28 = 0;
  }
  else {
    local_28 = *(undefined4 *)(*(int *)(in_EAX + 0x4e44) + 8);
  }
  return CONCAT44(param_2,local_28);
}


