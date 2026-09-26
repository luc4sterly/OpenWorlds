// 00407d27 FUN_00407d27 [Global]
// programa: sfmain.exe

int __fastcall FUN_00407d27(undefined4 param_1,short param_2)

{
  short in_AX;
  int iVar1;
  
  iVar1 = (int)param_2 + (int)in_AX;
  if (iVar1 < -0x8000) {
    return -0x8000;
  }
  if (0x7fff < iVar1) {
    iVar1 = 0x7fff;
  }
  return iVar1;
}


