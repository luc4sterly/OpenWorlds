// 0042cfa3 FUN_0042cfa3 [Global]
// program: sfmain.exe

void __fastcall FUN_0042cfa3(undefined4 param_1,char *param_2)

{
  char *in_EAX;
  int unaff_EBX;
  
  for (; (unaff_EBX != 0 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    unaff_EBX = unaff_EBX + -1;
    *in_EAX = *param_2;
    in_EAX = in_EAX + 1;
  }
  for (; unaff_EBX != 0; unaff_EBX = unaff_EBX + -1) {
    *in_EAX = '\0';
    in_EAX = in_EAX + 1;
  }
  return;
}


