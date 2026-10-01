// 0042cc34 FUN_0042cc34 [Global]
// program: sfmain.exe

int __fastcall FUN_0042cc34(undefined4 param_1,byte *param_2)

{
  byte *in_EAX;
  int unaff_EBX;
  
  while( true ) {
    if (unaff_EBX == 0) {
      return 0;
    }
    if (*in_EAX != *param_2) break;
    if (*in_EAX == 0) {
      return 0;
    }
    in_EAX = in_EAX + 1;
    param_2 = param_2 + 1;
    unaff_EBX = unaff_EBX + -1;
  }
  return (uint)*in_EAX - (uint)*param_2;
}


