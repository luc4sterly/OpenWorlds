// 00407d75 FUN_00407d75 [Global]
// programa: sfmain.exe

int __fastcall FUN_00407d75(undefined4 param_1,short param_2)

{
  short in_AX;
  
  if ((in_AX == -0x8000) && (param_2 == -0x8000)) {
    return 0x7fff;
  }
  return (int)in_AX * (int)param_2 >> 0xf;
}


