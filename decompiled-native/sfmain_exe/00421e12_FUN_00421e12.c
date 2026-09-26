// 00421e12 FUN_00421e12 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00421e12(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 local_28;
  
  if (*(int *)(in_EAX + 0x4e44) == 0) {
    local_28 = 0;
  }
  else {
    local_28 = Ordinal_15(*(undefined2 *)(*(int *)(in_EAX + 0x4e44) + 0xe));
    local_28 = local_28 & 1;
  }
  return CONCAT44(param_2,local_28);
}


