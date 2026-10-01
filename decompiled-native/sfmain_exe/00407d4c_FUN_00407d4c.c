// 00407d4c FUN_00407d4c [Global]
// program: sfmain.exe

int __fastcall FUN_00407d4c(undefined4 param_1,short param_2)

{
  short in_AX;
  int iVar1;
  
  iVar1 = (int)in_AX - (int)param_2;
  if (iVar1 < -0x8000) {
    return -0x8000;
  }
  if (0x7fff < iVar1) {
    iVar1 = 0x7fff;
  }
  return iVar1;
}


