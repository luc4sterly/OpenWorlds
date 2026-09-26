// 00430ed8 FUN_00430ed8 [Global]
// programa: sfmain.exe

void __fastcall FUN_00430ed8(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  
  if ((in_EAX & 0x1000) == 0) {
    if ((in_EAX & 0x2000) == 0) {
      if ((in_EAX & 0x4000) != 0) {
        param_2 = 0;
      }
    }
    else {
      in_EAX = 0;
    }
  }
  FUN_004324ba(in_EAX,param_2);
  return;
}


