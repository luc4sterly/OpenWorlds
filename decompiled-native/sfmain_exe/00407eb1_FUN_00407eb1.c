// 00407eb1 FUN_00407eb1 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00407eb1(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  int iVar1;
  undefined4 local_14;
  
  if (in_EAX == 0) {
    FUN_0042b978();
  }
  local_14 = in_EAX;
  if ((int)in_EAX < 0) {
    if ((int)in_EAX < -0x3fffffff) {
      iVar1 = 0;
      goto LAB_00407f67;
    }
    local_14 = ~in_EAX;
  }
  if (local_14._2_2_ == 0) {
    if (local_14._1_1_ == '\0') {
      iVar1 = (byte)(&DAT_00438200)[local_14 & 0xff] + 0x17;
    }
    else {
      iVar1 = (byte)(&DAT_00438200)[(int)local_14 >> 8 & 0xff] + 0xf;
    }
  }
  else if (local_14._3_1_ == '\0') {
    iVar1 = (byte)(&DAT_00438200)[(int)local_14 >> 0x10 & 0xff] + 7;
  }
  else {
    iVar1 = (byte)(&DAT_00438200)[(int)local_14 >> 0x18 & 0xff] - 1;
  }
LAB_00407f67:
  return CONCAT44(param_2,iVar1);
}


