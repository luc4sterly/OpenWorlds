// 0040a743 FUN_0040a743 [Global]
// programa: sfmain.exe

int __fastcall FUN_0040a743(undefined4 param_1,int param_2)

{
  int in_EAX;
  int unaff_EBX;
  
  if ((in_EAX < param_2) && (unaff_EBX < param_2)) {
    if (unaff_EBX <= in_EAX) {
      return in_EAX;
    }
  }
  else {
    if (in_EAX <= param_2) {
      return param_2;
    }
    if (unaff_EBX <= param_2) {
      return param_2;
    }
    if (in_EAX <= unaff_EBX) {
      return in_EAX;
    }
  }
  return unaff_EBX;
}


